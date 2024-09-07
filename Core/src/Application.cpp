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
        GLFWwindow* window;

        if (!glfwInit())
            return -1;

        window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            return -1;
        }

        glfwMakeContextCurrent(window);
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			LOG_CRITICAL("Failed to initialize GLAD!");
			return false;
		}

        while (!glfwWindowShouldClose(window))
        {
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(window);

            glfwPollEvents();
        }

        glfwTerminate();

		return 0;
	}


	void Application::close()
	{

	}
}


