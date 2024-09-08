#include "OpenGL_Renderer.hpp"
#include "Log.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace Engine
{
	  /*------------------------------*/
	 /*--- Debug source to string ---*/
	/*------------------------------*/
	const char* gl_source_to_string(const GLenum source)
	{
		switch (source)
		{
		case GL_DEBUG_SOURCE_API:				return "DEBUG_SOURCE_API";
		case GL_DEBUG_SOURCE_WINDOW_SYSTEM:		return "DEBUG_SOURCE_WINDOW_SYSTEM";
		case GL_DEBUG_SOURCE_SHADER_COMPILER:	return "DEBUG_SOURCE_SHADER_COMPILER";
		case GL_DEBUG_SOURCE_THIRD_PARTY:		return "DEBUG_SOURCE_THIRD_PARTY";
		case GL_DEBUG_SOURCE_APPLICATION:		return "DEBUG_SOURCE_APPLICATION";
		case GL_DEBUG_SOURCE_OTHER:				return "DEBUG_SOURCE_OTHER";

		default: return "UNKNOWN_DEBUG_SOURCE";
		}
	}


	  /*-------------------------------*/
	 /*--- GL error type to string ---*/
	/*-------------------------------*/
	const char* gl_type_to_string(const GLenum type)
	{
		switch (type)
		{
		case GL_DEBUG_TYPE_ERROR:				return "DEBUG_TYPE_ERROR";
		case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: return "DEBUG_TYPE_DEPRECATED_BEHAVIOR";
		case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:	return "DEBUG_TYPE_UNDEFINED_BEHAVIOR";
		case GL_DEBUG_TYPE_PORTABILITY:			return "DEBUG_TYPE_PORTABILITY";
		case GL_DEBUG_TYPE_PERFORMANCE:			return "DEBUG_TYPE_PERFORMANCE";
		case GL_DEBUG_TYPE_MARKER:				return "DEBUG_TYPE_MARKER";
		case GL_DEBUG_TYPE_PUSH_GROUP:			return "DEBUG_TYPE_PUSH_GROUP";
		case GL_DEBUG_TYPE_POP_GROUP:			return "DEBUG_TYPE_POP_GROUP";
		case GL_DEBUG_TYPE_OTHER:				return "DEBUG_TYPE_OTHER";

		default: return "UNKNOWN_DEBUG_TYPE";
		}
	}


	bool OpenGL_Renderer::init(GLFWwindow* pWindow)
	{
		// Set current context
		glfwMakeContextCurrent(pWindow);

		// Load "glad"
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			LOG_CRITICAL("Failed to initialize GLAD!");
			return false;
		}

		// Print info about OpenGL
		LOG_INFO("OpenGL context initialized:");
		LOG_INFO("  OpenGL Vendor:   {0}", get_vendor_str());
		LOG_INFO("  OpenGL Renderer: {0}", get_renderer_str());
		LOG_INFO("  OpenGL Version:  {0}", get_version_str());

		// Set debug mode
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, nullptr, GL_FALSE);
		glDebugMessageCallback(
			[](GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* useParam)
			{
				switch (severity)
				{
				case GL_DEBUG_SEVERITY_HIGH:
					LOG_ERROR("OpenGL Error: [{0}:{1}]({2}): {3}", gl_source_to_string(source), gl_type_to_string(type), id, message);
					break;
				case GL_DEBUG_SEVERITY_MEDIUM:
					LOG_WARN("OpenGL Warning: [{0}:{1}]({2}): {3}", gl_source_to_string(source), gl_type_to_string(type), id, message);
					break;
				case GL_DEBUG_SEVERITY_LOW:
					LOG_INFO("OpenGL Info: [{0}:{1}]({2}): {3}", gl_source_to_string(source), gl_type_to_string(type), id, message);
					break;
				case GL_DEBUG_SEVERITY_NOTIFICATION:
					LOG_INFO("OpenGL Notification: [{0}:{1}]({2}): {3}", gl_source_to_string(source), gl_type_to_string(type), id, message);
					break;
				default:
					LOG_ERROR("OpenGL Error: [{0}:{1}]({2}): {3} ", gl_source_to_string(source), gl_type_to_string(type), id, message);
				}
			},
			nullptr
		);

		return true;
	}


	void OpenGL_Renderer::draw()
	{

	}


	void OpenGL_Renderer::set_clear_color(
		const float r,
		const float g,
		const float b,
		const float a)
	{
		glClearColor(r, g, b, a);
	}


	void OpenGL_Renderer::clear()
	{
		glClear(
			GL_COLOR_BUFFER_BIT | 
			GL_DEPTH_BUFFER_BIT
		);
	}


	void OpenGL_Renderer::set_viewport(
		const unsigned int width,
		const unsigned int height,
		const unsigned int left_offset,
		const unsigned int bottom_offset
	)
	{
		glViewport(left_offset, bottom_offset, width, height);
	}


	const char* OpenGL_Renderer::get_vendor_str()
	{
		return reinterpret_cast<const char*>(glGetString(GL_VENDOR));
	}


	const char* OpenGL_Renderer::get_renderer_str()
	{
		return reinterpret_cast<const char*>(glGetString(GL_RENDER));
	}


	const char* OpenGL_Renderer::get_version_str()
	{
		return reinterpret_cast<const char*>(glGetString(GL_VERSION));
	}


	void OpenGL_Renderer::enable_depth_testing()
	{
		glEnable(GL_DEPTH_TEST);
	}


	void OpenGL_Renderer::disable_depth_testing()
	{
		glDisable(GL_DEPTH_TEST);
	}
}