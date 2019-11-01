#include <iostream>
#include "MyGame.h"

int main(int argc, char* argv[]) {
	MyGame* g = new MyGame();
	g->Initialize();
	g->Run();

	return 0;
}