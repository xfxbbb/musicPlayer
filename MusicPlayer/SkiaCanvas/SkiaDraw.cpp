#include "SkiaDraw.h"

namespace SkiaUi {

	SkiaDraw::SkiaDraw(RenderType type)
	{
		sk_app::DisplayParams params;
		// MakeRasterForWin  MakeVulkanOfflineForWin
		if (type == RenderType::Cpu) {
			_draw_context = sk_app::window_context_factory::MakeRasterForWin(
				params, [this](void* buffer, size_t size, int width, int height) {
					_buffer = reinterpret_cast<std::byte*>(buffer);
					_buffer_size = size;
					_width = width;
					_height = height;
				});
		} else { //Gpu
			_draw_context = sk_app::window_context_factory::MakeVulkanOfflineForWin(
				params, [this](void* buffer, size_t size, int width, int height) {
					_buffer = reinterpret_cast<std::byte*>(buffer);
					_buffer_size = size;
					_width = width;
					_height = height;
				});
		}
	}

	SkiaDraw::~SkiaDraw()
	{
	}

	std::optional<std::byte*> SkiaDraw::draw(int width, int height, std::function<void(SkCanvas&)> fun)
	{
		if (_width < width || _height < height) {
			_width = width;
			_height = height;
			_draw_context->resize(_width, _height);
		}
		auto surface = _draw_context->getBackbufferSurface();
		if (surface) {
			SkCanvas* skcanvas = surface->getCanvas();
			skcanvas->save();
			fun(*skcanvas);
			if (width != _width || height != _height) {
				skcanvas->clipRect(SkRect::MakeXYWH(0, 0, _width, _height));
			}
			skcanvas->restore();
			surface->flushAndSubmit();
			_draw_context->swapBuffers();
			return _buffer;
		} else {
			return std::nullopt;
		}

	}
	void SkiaDraw::reset(int width, int height)
	{
		if (width != _width || height != _height) {
			_width = width;
			_height = height;
			_draw_context->resize(_width, _height);
		}
	}
}
