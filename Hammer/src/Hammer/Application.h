#pragma once

#include "Core.h"

namespace Hammer {

	class HAMMER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};
	// ��client�ж���
	Application* CreateApplication();
}

