#include "Application.h"

#include "Durian/Events/ApplicationEvent.h"
#include "Durian/log.h"

namespace Durian {
	Application::Application()
	{
	}
	Application::~Application()
	{
	}
	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		DR_TRACE(e);
		while (true);
	}
}