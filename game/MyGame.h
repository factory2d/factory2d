#pragma once
#include "../core/Factory2D.h"

class MyGame :
	public F2D::Game {
public:
	MyGame();
	~MyGame();

	bool Initialize() override;
	void Update() override;
	void Draw() override;
};

