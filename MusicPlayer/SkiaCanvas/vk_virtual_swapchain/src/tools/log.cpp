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

#define _CRT_SECURE_NO_WARNINGS

#include "tools/log.h"

#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>

#include <chrono>
#include <ctime> // Required for MSVC.

#include <Windows.h>

namespace core {

    Logger Logger::mInstance = Logger();

    void Logger::init(unsigned level, const char* system, const char* path) {
        mInstance.mLevel = level;
        mInstance.mSystem = system;
        if (path != nullptr) {

            if (FILE* f = fopen(path, "w")) {
                GAPID_INFO("Logging to %s", path);
                mInstance.mFiles.push_back(f);
            } else {
                GAPID_WARNING("Can't open file for logging (%s): %s", path, strerror(errno));
            }
        }
    }

    Logger::Logger() : mLevel(LOG_LEVEL_INFO), mSystem("") { mFiles.push_back(stdout); }

    Logger::~Logger() {
        for (FILE* file : mFiles) {
            fclose(file);
        }
    }

    void Logger::logf(unsigned level, const char* file, unsigned line, const char* format, ...) const {
        va_list args;
        va_start(args, format);
        vlogf(level, file, line, format, args);
        va_end(args);
    }

    void Logger::vlogf(unsigned level, const char* src_file, unsigned src_line, const char* format, va_list args) const {

        // Get the current time with milliseconds precision
        auto t = std::chrono::system_clock::now();
        std::time_t now = std::chrono::system_clock::to_time_t(t);
        std::tm* loc = std::localtime(&now);
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(t.time_since_epoch());

#define LOG_COMMON                                                                                                                                   \
    "%02d:%02d:%02d.%03d %c %s: [%s:%u] ", loc->tm_hour, loc->tm_min, loc->tm_sec, static_cast<int>(ms.count() % 1000), "FEWIDV"[level], mSystem,    \
        src_file, src_line

        {
            va_list args_copy;
            va_copy(args_copy, args);
            char buf[2048];
            snprintf(buf, sizeof(buf), LOG_COMMON);
            OutputDebugStringA(buf);
            vsnprintf(buf, sizeof(buf), format, args_copy);
            OutputDebugStringA(buf);
            OutputDebugStringA("\r\n");
        }

        for (FILE* file : mFiles) {
            va_list args_copy;
            va_copy(args_copy, args);

            // Print out the common part of the log messages
            fprintf(file, LOG_COMMON);

            // Print out the actual log message
            vfprintf(file, format, args_copy);

            // Always finish with a newline
            fprintf(file, "\n");

            // Flush the log to ensure that every message is written out even if the
            // application crashes
            fflush(file);
        }

        if (level == LOG_LEVEL_FATAL) {
            exit(EXIT_FAILURE);
        }
    }

} // namespace core
