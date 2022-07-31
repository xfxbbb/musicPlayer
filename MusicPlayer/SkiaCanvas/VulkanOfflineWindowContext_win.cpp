
/*
 * Copyright 2016 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifdef SK_VULKAN

#include "include/gpu/vk/GrVkVulkan.h"

#include "WindowContextFactory_win.h"

#include "VulkanOfflineWindowContext.h"
#include "tools/sk_app/win/Window_win.h"

#include "src/gpu/vk/GrVkInterface.h"
#include "src/gpu/vk/GrVkUtil.h"

#include "tools/gpu/vk/VkTestUtils.h"

#include <Windows.h>
#include <swapchain.h>

extern "C" {
	extern VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL VirtualSwapchainGetInstanceProcAddr(VkInstance instance, const char* funcName);
	extern VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL VirtualSwapchainGetDeviceProcAddr(VkDevice dev, const char* funcName);
}

namespace sk_app {
	namespace window_context_factory {

		std::unique_ptr<WindowContext> MakeVulkanOfflineForWin(const DisplayParams& params, DrawCallBack fun) {

			PFN_vkGetInstanceProcAddr instProc = VirtualSwapchainGetInstanceProcAddr;
			PFN_vkGetDeviceProcAddr devProc = VirtualSwapchainGetDeviceProcAddr;

			auto createVkSurface = [instProc](VkInstance instance) -> VkSurfaceKHR {
				VkSurfaceKHR surface;
				swapchain::vkCreateVirtualSurface(instance, nullptr, nullptr, &surface);
				return surface;
			};

			auto canPresent = [instProc](VkInstance instance, VkPhysicalDevice physDev, uint32_t queueFamilyIndex) {
				return true;
			};

			std::unique_ptr<WindowContext> ctx =
				std::make_unique<VulkanOfflineWindowContext>(params, createVkSurface, canPresent, instProc, devProc, fun);
			if (!ctx->isValid()) {
				return nullptr;
			}
			return ctx;
		}

	} // namespace window_context_factory
} // namespace sk_app

#endif