
/*
 * Copyright 2016 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef WindowContextFactory_win_DEFINED
#define WindowContextFactory_win_DEFINED

#include <Windows.h>

#include <memory>
#include <functional>

using DrawCallBack = std::function<void(void*, size_t,int,int)>;

namespace sk_app {

	class WindowContext;
	struct DisplayParams;

	namespace window_context_factory {

		std::unique_ptr<WindowContext> MakeVulkanOfflineForWin(const DisplayParams&, DrawCallBack = nullptr);
		
		std::unique_ptr<WindowContext> MakeRasterForWin(const DisplayParams&, DrawCallBack = nullptr);

	}  // namespace window_context_factory

}  // namespace sk_app

#endif
