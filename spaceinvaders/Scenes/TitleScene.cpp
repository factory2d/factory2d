#include "TitleScene.h"

void TITLESCREEN_LOGOTWEEN_FUNC(float value) {
	std::cout << value << std::endl;
}

TitleScene::TitleScene() {}

TitleScene::TitleScene(std::string name) : 
	F2D::SceneObject(name) {
	float x = 256.0f;
	// create our scene objects
	__camera = new F2D::CameraObject("camera");

	__logoObject = new F2D::FactoryObject("game logo");
	__logoObject->transform->SetParent(this->transform);
	__logoObject->transform->origin = { 228.0f, 95.0f, 0.0f };
	__logoObject->AddBehaviour(new F2D::SpriteBehaviour("Assets/gamelogo.png"));

	__logoObject->AddBehaviour(new F2D::TweenBehaviour({
		{ __logoObject->transform->position.x, 0.0f, 0.0f},
		{ __logoObject->transform->position.y, 0.0f, 240.0f}
	}));
}

TitleScene::~TitleScene() {}

