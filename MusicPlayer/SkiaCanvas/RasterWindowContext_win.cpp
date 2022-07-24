/*
 * Copyright 2016 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/core/SkSurface.h"
#include "src/core/SkAutoMalloc.h"
#include "RasterWindowContext.h"
#include "WindowContextFactory_win.h"

#include <Windows.h>

using sk_app::RasterWindowContext;
using sk_app::DisplayParams;

using DrawCallBack = std::function<void(void*, size_t, int, int)>;

namespace {

	class RasterWindowContext_win : public RasterWindowContext {
	public:

		RasterWindowContext_win(const DisplayParams&, DrawCallBack fun);

		sk_sp<SkSurface> getBackbufferSurface() override;
		void swapBuffers() override;
		bool isValid() override { return true; }
		void resize(int w, int h) override;
		void setDisplayParams(const DisplayParams& params) override;

	protected:
		sk_sp<SkSurface> fBackbufferSurface;
		DrawCallBack _fun;

		SkPixmap _sk_pixmap;
		std::unique_ptr<std::byte[]> _pixmap_pr;

	private:
		using INHERITED = RasterWindowContext;
	};

	RasterWindowContext_win::RasterWindowContext_win(const DisplayParams& params, DrawCallBack fun)
		:INHERITED(params), _fun{ fun }{
	}

	void RasterWindowContext_win::setDisplayParams(const DisplayParams& params) {
		fDisplayParams = params;
	}

	void RasterWindowContext_win::resize(int w, int h) {
		if ((fWidth == w && fHeight == h) || w <=0 || h <= 0) {
			return;
		}
		fWidth = w;
		fHeight = h;
		fBackbufferSurface.reset();
		//kRGBA_8888_SkColorType
		SkImageInfo sk_img_info = SkImageInfo::Make(w, h, SkColorType::kN32_SkColorType, SkAlphaType::kUnpremul_SkAlphaType);
		int size = sk_img_info.width() * sk_img_info.height() * sk_img_info.bytesPerPixel();
		_pixmap_pr = std::make_unique<std::byte[]>(size);
		_sk_pixmap = SkPixmap{ sk_img_info, _pixmap_pr.get(), (size_t)sk_img_info.width() * sk_img_info.bytesPerPixel() };
		fBackbufferSurface = SkSurface::MakeRasterDirect(_sk_pixmap);
	}

	sk_sp<SkSurface> RasterWindowContext_win::getBackbufferSurface() { return fBackbufferSurface; }

	void RasterWindowContext_win::swapBuffers() {
		if (_fun) {
			SkImageInfo sk_img_info = _sk_pixmap.info();
			_fun(_sk_pixmap.writable_addr(), _sk_pixmap.computeByteSize(), sk_img_info.width(), sk_img_info.height());
		}
		
	}

}  // anonymous namespace

namespace sk_app {
	namespace window_context_factory {

		std::unique_ptr<WindowContext> MakeRasterForWin(const DisplayParams& params, DrawCallBack fun) {
			std::unique_ptr<WindowContext> ctx(new RasterWindowContext_win(params, fun));
			if (!ctx->isValid()) {
				ctx = nullptr;
			}
			return ctx;
		}

	}  // namespace window_context_factory
}  // namespace sk_app
