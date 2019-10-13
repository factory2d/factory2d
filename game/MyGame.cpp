#include "MyGame.h"

MyGame::MyGame() {}
MyGame::~MyGame() {}

F2D::SceneObject* scene1;

F2D::SpriteObject* object1;
F2D::SpriteObject* object2;

bool MyGame::Initialize() {
	Game::Initialize();

	// tag test, not working yet, just to test the tag listing
	F2D::TagManager::SetTag("teste", NULL);

	// create a new controller
	F2D::ControllerObject *controller1 = new F2D::ControllerObject("player");
	F2D::AxisObject *axisX = new F2D::AxisObject("x");
	F2D::AxisObject *axisY = new F2D::AxisObject("y");
	F2D::ButtonObject *actionBtn = new F2D::ButtonObject("attack");
	controller1->Push(axisX);
	controller1->Push(axisY);
	controller1->Push(actionBtn);


	// load a picture into the memory
	F2D::Picture *p = new F2D::Picture();
	p = F2D::AssetManager::Load<F2D::Picture>("Assets/256.png"); // load the picture and put in cache
	p = F2D::AssetManager::Load<F2D::Picture>("Assets/256.png"); // loading the same picture, we will use the cached

	// create a new scene
	scene1 = new F2D::SceneObject("scene1");
	F2D::SceneManager::Load(scene1);

	// create objects inside the scene
	object1 = new F2D::SpriteObject("object1");
	object1->p = p;
	object1->GetUUID();
	object1->transform->SetOrigin(32.0f, 32.0f, 0.0f);
	object1->transform->SetPosition(100.0f, 100.0f, 0.0f);
	object1->transform->SetRotate(0.0f, 45.0f, 0.0f);
	object1->transform->SetParent(scene1->transform);

	object2 = new F2D::SpriteObject("object2");
	object2->p = p;
	object2->transform->SetOrigin(32.0f, 32.0f, 0.0f);
	object2->transform->SetPosition(100.0f, 100.0f, 0.0f);
	object2->transform->SetRotate(0.0f, 15.0f, 0.0f);
	object2->transform->SetParent(object1->transform);

	// create the scene camera
	F2D::CameraObject* camera1 = new F2D::CameraObject("camera1");
	camera1->viewport = new F2D::Rect(0.0f, 0.0f, 1.0f, 1.0f);
	camera1->transform->SetParent(scene1->transform);

	return false;
}

void MyGame::Update() {
	object1->transform->Rotate(0.0f, 5.0f, 0.0f);
	object2->transform->Rotate(0.0f, 1.0f, 0.0f);
	/*
	object1->transform->rotate->y += 1.0f;
	if(object1->transform->rotate->y >= 360.0f)
		object1->transform->rotate->y -= 360.0f;

	object2->transform->rotate->y = object1->transform->rotate->y;
	*/
	Game::Update();
}

void MyGame::Draw() {
	Game::Draw();
}
