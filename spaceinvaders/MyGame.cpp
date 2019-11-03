#include "MyGame.h"
#include "Scenes/TitleScene.h"
#include "Scenes/GameScene.h"

MyGame::MyGame() {}
MyGame::~MyGame() {}

TitleScene* titleScene;

bool MyGame::Initialize() {
	// configure our windows
	F2D::WindowManager::Title("factory2D Space Invader DEMO");
	F2D::WindowManager::Resizable(false);
	F2D::WindowManager::Width(480);
	F2D::WindowManager::Height(640);
	F2D::WindowManager::Initialize();

	// configure our input
	// create a new controller
	F2D::Controller *controller1 = F2D::InputManager::Push(new F2D::Controller("player"));

	// axis
	F2D::AxisAction *axisX = (F2D::AxisAction*)controller1->Push(new F2D::AxisAction("x"));
	axisX->Push(new F2D::KeyboardTrigger("keyboard arrow", F2D::F2D_KEYBOARD_LEFT, F2D::F2D_KEYBOARD_RIGHT));
	axisX->Push(new F2D::KeyboardTrigger("keyboard", F2D::F2D_KEYBOARD_A, F2D::F2D_KEYBOARD_D));

	// attack button
	F2D::ButtonAction *actionBtn = (F2D::ButtonAction*)controller1->Push(new F2D::ButtonAction("attack"));
	actionBtn->Push(new F2D::KeyboardTrigger("keyboard", ' '));	// primary button
	actionBtn->Push(new F2D::KeyboardTrigger("keyboard", 'z'));	// alternative button

	// create a new scene
	titleScene = new TitleScene("scene1");
	F2D::SceneManager::Load(titleScene);

	// create the scene camera

	return false;
}

void MyGame::Update() {
	Game::Update();
}

void MyGame::Draw() {
	Game::Draw();
}
