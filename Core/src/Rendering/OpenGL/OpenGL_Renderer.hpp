#pragma once
#ifndef __OPENGL_RENDERER_HPP
#define __OPENGL_RENDERER_HPP


struct GLFWwindow;

namespace Engine
{
	class OpenGL_Renderer
	{
	public:
		  /*-------------*/
		 /*--- Init  ---*/
		/*-------------*/
		static bool init(GLFWwindow* pWindow);

		  /*-----------------*/
		 /*--- Rendering ---*/
		/*-----------------*/
		static void draw();

		  /*-----------------------*/
		 /*--- Set clear color ---*/
		/*-----------------------*/
		static void set_clear_color(
			const float r,
			const float g, 
			const float b, 
			const float a
		);

		  /*--------------------*/
		 /*--- Clear buffer ---*/
		/*--------------------*/
		static void clear();

		  /*--------------------*/
		 /*--- Set viewport ---*/
		/*--------------------*/
		static void set_viewport(
			const unsigned int width,
			const unsigned int height,
			const unsigned int left_offset   = 0,
			const unsigned int bottom_offset = 0
		);

		  /*-------------------------*/
		 /*--- Enable depth test ---*/
		/*-------------------------*/
		static void enable_depth_testing();


		  /*--------------------------*/
		 /*--- Disable depth test ---*/
		/*--------------------------*/
		static void disable_depth_testing();
		
		  /*------------------*/
		 /*--- Get vendor ---*/
		/*------------------*/
		static const char* get_vendor_str();

		  /*--------------------*/
		 /*--- Get renderer ---*/
		/*--------------------*/
		static const char* get_renderer_str();

		  /*-------------------*/
		 /*--- Get version ---*/
		/*-------------------*/
		static const char* get_version_str();
	};
}


#endif // __OPENGL_RENDERER_HPP