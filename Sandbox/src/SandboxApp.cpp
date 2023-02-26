#include "Durian.h"

class Sandbox : public Durian::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Durian::Application* Durian::CreateApplication()
{
	return new Sandbox();
}