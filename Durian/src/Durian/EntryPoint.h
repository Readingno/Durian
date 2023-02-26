#pragma once

#ifdef DR_PLATFORM_WINDOWS

// A function define in CLIENT which return the application we are running
extern Durian::Application* Durian::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Durian::CreateApplication();
	app->Run();
	delete app;
}

#endif // DR_PLATFORM_WINDOWS
