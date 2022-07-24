#pragma once

#include "WindowContext.h"
#include <tools/sk_app/DisplayParams.h>
#include <tools/sk_app/win/WindowContextFactory_win.h>
#include <memory>
#include <core/SkImage.h>
#include <core/SkSurface.h>
#include <core/SkCanvas.h>
#include "CommType.h"
#include <optional>

namespace SkiaUi {

	class SkiaDraw
	{
	public:
		SkiaDraw(RenderType type = RenderType::Cpu);
		SkiaDraw(const SkiaDraw&) = delete;
		SkiaDraw& operator=(const SkiaDraw&) = delete;
		virtual ~SkiaDraw();

		std::optional<std::byte*> draw(int width, int height, std::function<void(SkCanvas&)> fun);
		void reset(int width, int height);

	private:
		std::byte* _buffer{ nullptr };
		size_t _buffer_size;
		int _width;
		int _height;
		std::unique_ptr<sk_app::WindowContext> _draw_context;

	};
}

