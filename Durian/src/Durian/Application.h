#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Durian {
	class DURIAN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}