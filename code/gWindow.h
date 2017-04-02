#pragma once
#include "SDL2-2.0.5\include\SDL.h"
#include "glad.h"
typedef enum screenSize
{
	FULL_SCREEN,
	WINDOW_SCREEN
};


class gWindow
{
protected:
	int SCREEN_FULLSCREEN = 0;
	int SCREEN_WIDTH = 960;
	int SCREEN_HEIGHT = 540;

	void init_window(const char * caption);

	static void APIENTRY openglCallbackFunction(
		GLenum source,
		GLenum type,
		GLuint id,
		GLenum severity,
		GLsizei length,
		const GLchar* message,
		const void* userParam
	);

	static void sdl_die(const char * message);

public:
	gWindow(screenSize size);
	~gWindow();

	SDL_Window *window;
	SDL_Event e;
	SDL_GLContext maincontext;
};

