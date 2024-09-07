#include "../includes/Application.hpp"

#include <memory>


class AppEditor : public Engine::Application
{
	void onUpdate() override
	{

	}


	void onMouseButtonEvent() override
	{

	}


	void onUIDraw() override
	{
		
	}
};


int main()
{
	auto pAppEditor = std::make_unique<AppEditor>();
	int returnCode = pAppEditor->start(1024, 768, "App Editor");
	return returnCode;
}