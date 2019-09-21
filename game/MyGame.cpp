#include "MyGame.h"

MyGame::MyGame() {}
MyGame::~MyGame() {}

SceneObject* scene1;

SpriteObject* object1;
SpriteObject* object2;

bool MyGame::Initialize() {
	Game::Initialize();

	//	teste
	ResourceManager::Load("256.png");

	//	cria a cena
	scene1 = new SceneObject("scene1");
	SceneManager::Load(scene1);

	//	cria objetos da cena
	object1 = new SpriteObject("object1");
	object1->transform->origin->x = object1->transform->origin->y = 32.0f;
	object1->transform->position->x = object1->transform->position->y = 100.0f;
	object1->transform->rotate->y = 45.0f;
	object1->transform->SetParent(scene1->transform);

	object2 = new SpriteObject("object2");
	object2->transform->origin->x = object2->transform->origin->y = 32.0f;
	object2->transform->position->x = object2->transform->position->y = 100.0f;
	object2->transform->rotate->y = 15.0f;
	object2->transform->SetParent(object1->transform);

	//	cria a camera da cena
	CameraObject* camera1 = new CameraObject("camera1");
	camera1->viewport = new Rect(0.0f, 0.0f, 1.0f, 1.0f);
	camera1->transform->SetParent(scene1->transform);

	return false;
}

void MyGame::Update() {
	object1->transform->rotate->y += 1.0f;
	if(object1->transform->rotate->y >= 360.0f)
		object1->transform->rotate->y -= 360.0f;

	object2->transform->rotate->y = object1->transform->rotate->y;

	Game::Update();
}

void MyGame::Draw() {
	Game::Draw();
}
