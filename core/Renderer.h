#ifndef __FACTORY2D_RENDERER
#define __FACTORY2D_RENDERER

#include "Window.h"

namespace F2D
{
	class Renderer {
	private:
		Renderer();
		~Renderer();

	public:
		static Window* window;
		static bool integerPosition;

		static void Begin();
		static void End();
	};
}

#endif