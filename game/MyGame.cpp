#include "MyGame.h"

MyGame::MyGame() {}
MyGame::~MyGame() {}

F2D::SceneObject* scene1;

F2D::SpriteObject* object1;
F2D::SpriteObject* object2;

bool MyGame::Initialize() {
	Game::Initialize();

	//	teste
	F2D::TagManager::SetTag("teste", NULL);

	F2D::Picture *p = new F2D::Picture();
	p->Load("Assets/256.png");
	p->Load("Assets/256.png");
	p->Load("Assets/256.png");

	//F2D::AssetManager::LoadPicture("256.png", F2D::PNG);
	//F2D::AssetManager::LoadPicture("256.PNG", F2D::PNG);

	//	cria a cena
	scene1 = new F2D::SceneObject("scene1");
	F2D::SceneManager::Load(scene1);

	//	cria objetos da cena
	object1 = new F2D::SpriteObject("object1");
	object1->p = p;
	object1->GetUUID();
	object1->transform->origin->x = object1->transform->origin->y = 32.0f;
	object1->transform->position->x = object1->transform->position->y = 100.0f;
	object1->transform->rotate->y = 45.0f;
	object1->transform->SetParent(scene1->transform);

	object2 = new F2D::SpriteObject("object2");
	object2->p = p;
	object2->transform->origin->x = object2->transform->origin->y = 32.0f;
	object2->transform->position->x = object2->transform->position->y = 100.0f;
	object2->transform->rotate->y = 15.0f;
	object2->transform->SetParent(object1->transform);

	//	cria a camera da cena
	F2D::CameraObject* camera1 = new F2D::CameraObject("camera1");
	camera1->viewport = new F2D::Rect(0.0f, 0.0f, 1.0f, 1.0f);
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
