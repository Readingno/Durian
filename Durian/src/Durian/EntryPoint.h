#pragma once

#ifdef DR_PLATFORM_WINDOWS

// A function define in CLIENT which return the application we are running
extern Durian::Application* Durian::CreateApplication();

int main(int argc, char** argv)
{
	Durian::Log::Init();
	DR_CORE_WARN("Initialized Log!");
	DR_CORE_INFO("Hello!");
	int a = 5;
	DR_INFO("a = {0}", a);

	auto app = Durian::CreateApplication();
	app->Run();
	delete app;
}

#endif // DR_PLATFORM_WINDOWS
