#ifndef __FACTORY2D_GAME
#define __FACTORY2D_GAME

#include "GameTime.h"

class Game {
private:
	bool __quit = false;
	GameTime* __time;

public:
	Game();
	~Game();

	virtual bool Initialize();
	virtual void Update();
	virtual void Draw();

	void Run();
};

#endif