#pragma once
#ifndef __APPLICATION_HPP
#define __APPLICATION_HPP


namespace Engine
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		Application(const Application&)				= delete;
		Application(Application&&)					= delete;
		Application& operator=(const Application&)	= delete;
		Application& operator=(Application&&)		= delete;

		virtual int start(unsigned int window_width, unsigned int window_height, const char* window_title);
		void close();

		virtual void onUpdate() {}
		virtual void onUIDraw() {}
		virtual void onMouseButtonEvent() {}

	private:
		void draw();
	};
}


#endif // __APPLICATION_HPP