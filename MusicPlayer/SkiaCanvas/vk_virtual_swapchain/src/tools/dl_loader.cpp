/*
 * Copyright (C) 2017 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "tools/dl_loader.h"
#include "tools/log.h"
#include <windows.h>
#include <iostream>

namespace {

    // load defs
    void* load() { return nullptr; }

    template <typename... ConstCharPtrs>
    void* load(const char* name, ConstCharPtrs... fallback_names) {
        void* ret = nullptr;

        ret = reinterpret_cast<void*>(LoadLibraryExA(name, NULL, 0));

        if (ret == nullptr) {
            return load(fallback_names...);
        }
        return ret;
    }

    template <typename... ConstCharPtrs>
    void* must_load(const char* name, ConstCharPtrs... fallback_names) {
        void* res = load(name, fallback_names...);
        if (res == nullptr) {
            GAPID_FATAL("Can't load library %s: %d", name, GetLastError());
        }
        return res;
    }

    void* resolve(void* handle, const char* name) { return reinterpret_cast<void*>(GetProcAddress(reinterpret_cast<HMODULE>(handle), name)); }

    void close(void* lib) {
        if (lib != nullptr) {
            FreeLibrary(reinterpret_cast<HMODULE>(lib));
        }
    }
} // anonymous namespace

namespace core {
    template <typename... ConstCharPtrs>
    DlLoader::DlLoader(const char* name, ConstCharPtrs... fallback_names) : mLibrary(must_load(name, fallback_names...)) {}

    DlLoader::~DlLoader() { close(mLibrary); }

    void* DlLoader::lookup(const char* name) { return resolve(mLibrary, name); }

    bool DlLoader::can_load(const char* lib_name) {
        if (void* lib = load(lib_name)) {
            close(lib);
            return true;
        }
        return false;
    }

#define CC const char*
#define DL(...) template DlLoader::DlLoader(__VA_ARGS__)
    DL(CC _1);
    DL(CC _1, CC _2);
    DL(CC _1, CC _2, CC _3);
    DL(CC _1, CC _2, CC _3, CC _4);
    DL(CC _1, CC _2, CC _3, CC _4, CC _5);
#undef DL
#undef CC

} // namespace core
