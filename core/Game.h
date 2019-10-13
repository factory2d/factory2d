#ifndef __FACTORY2D_GAME
#define __FACTORY2D_GAME

#include "Debug.h"

namespace F2D
{
	class Game {
	private:
		bool __quit = false;

	public:
		Game();
		~Game();

		virtual bool Initialize();
		virtual void Update();
		virtual void Draw();

		void Run();
	};
}

#endif