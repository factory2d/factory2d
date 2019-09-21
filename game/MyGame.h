#pragma once
#include "../core/Factory2D.h"

class MyGame :
	public Game {
public:
	MyGame();
	~MyGame();

	bool Initialize() override;
	void Update() override;
	void Draw() override;
};

