#pragma once

#include "Event.h"

#include <sstream>

namespace Hammer {

	class HAMMER_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_Width(width),m_Height(height) {}

		inline unsigned int GetWidth()const { return m_Width; }
		inline unsigned int GetHeigth()const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << m_Height;
			return ss.str();
		}

		EVNET_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		unsigned int m_Width, m_Height;
	};

	class HAMMER_API WindowCloseEvent : public Event
	{
	public:
		AppTickEvent() {}

		EVNET_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class HAMMER_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}

		EVNET_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class HAMMER_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}

		EVNET_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}