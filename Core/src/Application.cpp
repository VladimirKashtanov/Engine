#include "Application.hpp"
#include "Log.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace Engine
{
	Application::Application()
	{
		LOG_INFO("Starting Application");
	}


	Application::~Application()
	{
		LOG_INFO("Closing Application");
	}


	void Application::draw()
	{

	}


	int Application::start(unsigned int window_width, unsigned int window_height, const char* window_title)
	{
        
		return 0;
	}


	void Application::close()
	{

	}
}


