#ifndef __FACTORY2D_WINDOW
#define __FACTORY2D_WINDOW

#include <SDL.h>
#include <SDL_opengl.h>
#include <string>

class Window {
private:
	std::string __title = "Factory2D Game";					//	window title
	bool __alowUserResize = false;							//	allow user to resize the window

	SDL_Window* __sdl_window = NULL;
	SDL_GLContext __sdl_context;
public:
	Window();
	~Window();

	bool Initialize();

	std::string& Title();
	void Title(std::string& title);

	SDL_Window* SDLWindow();
	int Width();
	int Height();
};

#endif