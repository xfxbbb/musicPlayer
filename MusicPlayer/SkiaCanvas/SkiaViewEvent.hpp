#pragma once

#include <core/SkCanvas.h>

//from vulkan.hpp
namespace SkiaUi {
#define FlagOperator(Flags, Enum) \
constexpr Flags operator|(Enum bit0, Enum bit1) noexcept \
{ \
	return Flags(bit0) | bit1; \
} \
constexpr Flags operator&(Enum bit0, Enum bit1) noexcept \
{ \
	return Flags(bit0) & bit1; \
} \
constexpr Flags operator^(Enum bit0, Enum bit1) noexcept \
{ \
	return Flags(bit0) ^ bit1; \
} \
constexpr Flags operator~(Enum bits) noexcept \
{ \
	return ~(Flags(bits)); \
}


	template <typename FlagBitsType>
	struct FlagTraits
	{
	};

	template <typename BitType>
	class Flags
	{
	public:
		using MaskType = typename std::underlying_type<BitType>::type;

		// constructors
		constexpr Flags() noexcept : m_mask(0) {}

		constexpr Flags(BitType bit) noexcept : m_mask(static_cast<MaskType>(bit)) {}

		constexpr Flags(Flags<BitType> const& rhs) noexcept = default;

		constexpr explicit Flags(MaskType flags) noexcept : m_mask(flags) {}

		// relational operators
		auto operator<=>(Flags<BitType> const&) const = default;

		// logical operator
		constexpr bool operator!() const noexcept
		{
			return !m_mask;
		}

		// bitwise operators
		constexpr Flags<BitType> operator&(Flags<BitType> const& rhs) const noexcept
		{
			return Flags<BitType>(m_mask & rhs.m_mask);
		}

		constexpr Flags<BitType> operator|(Flags<BitType> const& rhs) const noexcept
		{
			return Flags<BitType>(m_mask | rhs.m_mask);
		}

		constexpr Flags<BitType> operator^(Flags<BitType> const& rhs) const noexcept
		{
			return Flags<BitType>(m_mask ^ rhs.m_mask);
		}

		constexpr Flags<BitType> operator~() const noexcept
		{
			return Flags<BitType>(m_mask ^ FlagTraits<BitType>::allFlags);
		}

		// assignment operators
		constexpr Flags<BitType>& operator=(Flags<BitType> const& rhs) noexcept = default;

		constexpr Flags<BitType>& operator|=(Flags<BitType> const& rhs) noexcept
		{
			m_mask |= rhs.m_mask;
			return *this;
		}

		constexpr Flags<BitType>& operator&=(Flags<BitType> const& rhs) noexcept
		{
			m_mask &= rhs.m_mask;
			return *this;
		}

		constexpr Flags<BitType>& operator^=(Flags<BitType> const& rhs) noexcept
		{
			m_mask ^= rhs.m_mask;
			return *this;
		}

		// cast operators
		explicit constexpr operator bool() const noexcept
		{
			return !!m_mask;
		}

		explicit constexpr operator MaskType() const noexcept
		{
			return m_mask;
		}

	private:

		MaskType m_mask;
	};

	enum class KeyboardModifier :uint32_t {
		NoModifier = 0x00000000,
		ShiftModifier = 0x00000001,
		ControlModifier = 0x04000002,
		AltModifier = 0x08000004,
		MetaModifier = 0x0000008,
		KeypadModifier = 0x00000010,
		GroupSwitchModifier = 0x00000020, //x11 mode
	};

	using KeyboardModifiers = Flags<KeyboardModifier>;
	template <>
	struct FlagTraits<KeyboardModifier>
	{
		enum : uint32_t
		{
			allFlags = uint32_t(KeyboardModifier::NoModifier) | uint32_t(KeyboardModifier::ShiftModifier) | uint32_t(KeyboardModifier::ControlModifier) |
			uint32_t(KeyboardModifier::AltModifier) | uint32_t(KeyboardModifier::MetaModifier)
			| uint32_t(KeyboardModifier::KeypadModifier) | uint32_t(KeyboardModifier::GroupSwitchModifier)
		};
	};
	FlagOperator(KeyboardModifiers, KeyboardModifier)

		enum class MouseButton :uint32_t {
		NoButton = 0x00000000,
		LeftButton = 0x00000001,
		RightButton = 0x00000002,
		MiddleButton = 0x00000004
	};

	using MouseButtons = Flags<MouseButton>;
	template <>
	struct FlagTraits<MouseButton>
	{
		enum : uint32_t
		{
			allFlags = uint32_t(MouseButton::NoButton) | uint32_t(MouseButton::LeftButton) | uint32_t(MouseButton::RightButton) |
			uint32_t(MouseButton::MiddleButton)
		};
	};
	FlagOperator(MouseButtons, MouseButton)

		enum class FocusReason {
		MouseFocusReason,
		TabFocusReason,
		BacktabFocusReason,
		ActiveWindowFocusReason,
		PopupFocusReason,
		ShortcutFocusReason,
		MenuBarFocusReason,
		OtherFocusReason,
		NoFocusReason
	};

	enum class ScrollPhase {
		NoScrollPhase = 0,
		ScrollBegin,
		ScrollUpdate,
		ScrollEnd,
		ScrollMomentum
	};

	struct SkiaEvent {
		enum class Type {
			None = 0,                               // invalid event
			Timer = 1,                              // timer event
			MouseButtonPress = 2,                   // mouse button pressed
			MouseButtonRelease = 3,                 // mouse button released
			MouseButtonDblClick = 4,                // mouse button double click
			MouseMove = 5,                          // mouse move
			KeyPress = 6,                           // key pressed
			KeyRelease = 7,                         // key released
			FocusIn = 8,                            // keyboard focus received
			FocusOut = 9,                           // keyboard focus lost
			FocusAboutToChange = 23,                // keyboard focus is about to be lost
			Enter = 10,                             // mouse enters widget
			Leave = 11,                             // mouse leaves widget
			Paint = 12,                             // paint widget
			Move = 13,                              // move widget
			Resize = 14,                            // resize widget
			Show = 17,                              // widget is shown
			Hide = 18,                              // widget is hidden
			Wheel = 19								// mouse wheel
		};
		SkiaEvent(Type type) :_type{ type } {
		}
		virtual ~SkiaEvent() {}
		Type type() const { return _type; }
	private:
		Type _type;
	};

	struct SkiaInputEvent :SkiaEvent {

	public:
		SkiaInputEvent(Type type, KeyboardModifiers modifiers = KeyboardModifier::NoModifier) :SkiaEvent{ type },
			modState{ modifiers }, ts{ std::chrono::system_clock::now().time_since_epoch().count() }{
		}

		KeyboardModifiers modifiers() const { return modState; }
		unsigned long long timestamp() const { return ts; }
	protected:
		KeyboardModifiers modState;
		long long ts;
	};

	struct SkiaFocusEvent :SkiaEvent {

		SkiaFocusEvent(Type type, FocusReason reason = FocusReason::OtherFocusReason) :SkiaEvent{ type }, _focus_reason{ reason }{

		}
		inline bool gotFocus() const { return type() == Type::FocusIn; }
		inline bool lostFocus() const { return type() == Type::FocusOut; }
		FocusReason getFocusReason() {
			return _focus_reason;
		}
	private:
		FocusReason _focus_reason;
	};

	struct SkiaPaintEvent :SkiaEvent {
		SkiaPaintEvent(SkCanvas& canvas) :SkiaEvent{ Type::Paint }, _sk_canvas{ canvas } {}

		SkCanvas& getCanvas() {
			return _sk_canvas;
		}

	private:
		SkCanvas& _sk_canvas;
	};
	struct SkiaMoveEvent :SkiaEvent {
		SkiaMoveEvent(const SkPoint& pos, const SkPoint& oldPos) :SkiaEvent{ Type::Move }, p{ pos }, oldp{ oldPos }{}
	public:
		const SkPoint& pos() const { return p; }
		const SkPoint& oldPos() const { return oldp; }
	protected:
		SkPoint p;
		SkPoint oldp;
	};


	struct SkiaResizeEvent :SkiaEvent {
	public:
		SkiaResizeEvent(const SkSize& size, const SkSize& oldSize) :SkiaEvent{ Type::Resize }, s{ size }, olds{ oldSize }{}
		~SkiaResizeEvent() {}

		const SkSize& size() const { return s; }
		const SkSize& oldSize()const { return olds; }
	protected:
		SkSize s, olds;
	};


	struct SkiaShowEvent :SkiaEvent {
		SkiaShowEvent() :SkiaEvent{ Type::Show } {}
	};
	struct SkiaHideEvent :SkiaEvent {
		SkiaHideEvent() :SkiaEvent{ Type::Hide } {}
	};
	struct SkiaTimerEvent :SkiaEvent {
	public:
		explicit SkiaTimerEvent(int timerId) :SkiaEvent{ Type::Timer }, _id{ timerId } {}
		~SkiaTimerEvent() {}
		int timerId() const { return _id; }
	protected:
		int _id;
	};



	struct SkiaMouseEvent :SkiaInputEvent {

		SkiaMouseEvent(Type type, const SkPoint& localPos, const SkPoint& windowPos, MouseButton button,
			MouseButtons buttons, KeyboardModifiers modifiers) :SkiaInputEvent{ type ,modifiers }, l{ localPos },
			w{ windowPos }, b{ button }, mouseState{ buttons }{}

		~SkiaMouseEvent() {}

		SkPoint pos() const { return l; }
		SkPoint globalPos() const { return w; }
		int x() const { return l.x(); }
		int y() const { return static_cast<int>(std::round(l.y())); }
		int globalX() const { return static_cast<int>(std::round(w.x())); }
		int globalY() const { return static_cast<int>(std::round(w.y())); }

		MouseButton button() const { return b; }
		MouseButtons buttons() const { return mouseState; }

	protected:
		SkPoint l, w;
		MouseButton b;
		MouseButtons mouseState;
	};

	struct SkiaWheelEvent :SkiaInputEvent {

		SkiaWheelEvent(SkPoint pos, SkPoint globalPos, SkPoint pixelDelta, SkPoint angleDelta,
			MouseButtons buttons, KeyboardModifiers modifiers, ScrollPhase phase,
			bool inverted) :SkiaInputEvent{ Type::Wheel,modifiers }, g{ globalPos }, p{ pos },
			pixelD{ pixelDelta },
			angleD{ angleDelta }, mouseState{ buttons }, ph{ phase }, invertedScrolling{ inverted }{};


		SkPoint pixelDelta() const { return pixelD; }
		SkPoint angleDelta() const { return angleD; }

		SkPoint position() const { return p; }
		SkPoint globalPosition() const { return g; }

		MouseButtons buttons() const { return mouseState; }

		ScrollPhase phase() const { return ph; }
		bool inverted() const { return invertedScrolling; }


	protected:
		SkPoint p;
		SkPoint g;
		SkPoint pixelD;
		SkPoint angleD;
		MouseButtons mouseState = MouseButton::NoButton;
		bool invertedScrolling;
		ScrollPhase ph;

	};

	struct SkiaKeyEvent :SkiaInputEvent {
	public:
		SkiaKeyEvent(Type type, int key, KeyboardModifiers modifiers,
			unsigned nativeScanCode, unsigned nativeVirtualKey, unsigned nativeModifiers, const std::string& text,
			bool autorep, int count) :
			SkiaInputEvent{ type ,modifiers }, k{ key }, nVirtualKey{ nativeVirtualKey },
			nScanCode{ nativeScanCode }, nModifiers{ nativeModifiers }, txt{ text }, autor{ autorep }, c{ count }
		{}

		int key() const { return k; }

		std::string text() const { return txt; }
		bool isAutoRepeat() const { return autor; }
		int count() const { return int(c); }

		unsigned nativeScanCode() const { return nScanCode; }
		unsigned nativeVirtualKey() const { return nVirtualKey; }
		unsigned nativeModifiers() const { return nModifiers; }

	protected:
		std::string txt;
		int k;
		unsigned nScanCode;
		unsigned nVirtualKey;
		unsigned nModifiers;
		int c;
		bool autor;
	};
}

