#include "MyGame.h"

MyGame::MyGame() {}
MyGame::~MyGame() {}

F2D::SceneObject* scene1;
F2D::CameraObject* camera1;
F2D::CameraObject* camera2;
F2D::FactoryObject* center;
F2D::FactoryObject* object1;
F2D::FactoryObject* object2;
F2D::FactoryObject* sprite1;

bool MyGame::Initialize() {
	// configure our windows
	F2D::WindowManager::Title("My Game Sample");
	F2D::WindowManager::Resizable(true);
	F2D::WindowManager::Width(640);
	F2D::WindowManager::Height(480);
	F2D::WindowManager::Initialize();
	F2D::Renderer::VSync(false);

	// configure our input
	// create a new controller
	F2D::Controller *controller1 = F2D::InputManager::Push(new F2D::Controller("player"));

	// axis
	F2D::AxisAction *axisX = (F2D::AxisAction*)controller1->Push(new F2D::AxisAction("x"));
	axisX->Push(new F2D::KeyboardTrigger("keyboard arrow", F2D::F2D_KEYBOARD_LEFT, F2D::F2D_KEYBOARD_RIGHT));
	axisX->Push(new F2D::KeyboardTrigger("keyboard", F2D::F2D_KEYBOARD_A, F2D::F2D_KEYBOARD_D));
	axisX->Push(new F2D::KeyboardTrigger("mouse", F2D::F2D_MOUSE_LEFT, F2D::F2D_MOUSE_RIGHT));
	axisX->Push(new F2D::KeyboardTrigger("mouse wheel", F2D::F2D_MOUSE_WLEFT, F2D::F2D_MOUSE_WRIGHT));
	F2D::AxisAction *axisY = (F2D::AxisAction*)controller1->Push(new F2D::AxisAction("y"));
	axisY->Push(new F2D::KeyboardTrigger("keyboard arrow", F2D::F2D_KEYBOARD_UP, F2D::F2D_KEYBOARD_DOWN));
	axisY->Push(new F2D::KeyboardTrigger("keyboard", F2D::F2D_KEYBOARD_W, F2D::F2D_KEYBOARD_S));
	axisY->Push(new F2D::KeyboardTrigger("mouse wheel", F2D::F2D_MOUSE_WUP, F2D::F2D_MOUSE_WDOWN));

	// attack button
	F2D::ButtonAction *actionBtn = (F2D::ButtonAction*)controller1->Push(new F2D::ButtonAction("attack"));
	actionBtn->Push(new F2D::KeyboardTrigger("keyboard", 'p'));	// primary button
	actionBtn->Push(new F2D::KeyboardTrigger("keyboard", 'e'));	// alternative button

	// load our game assets
	// load a picture into the memory
	F2D::SpriteAsset *p;
	p = F2D::AssetManager::Load<F2D::SpriteAsset>("Assets/256_orange.png"); // load the picture and put in cache
	p = F2D::AssetManager::Load<F2D::SpriteAsset>("Assets/256_orange.png"); // loading the same picture, we will use the cached

	// create a new scene
	scene1 = new F2D::SceneObject("scene1");
	F2D::SceneManager::Load(scene1);

	// create objects inside the scene
	center = new F2D::FactoryObject("center");
	center->transform->origin = { 8.0f, 8.0f, 0.0f };
	center->transform->position = { 0.0f, 0.0f, 0.0f };
	center->transform->SetParent(scene1->transform);
	center->AddBehaviour(new F2D::SpriteBehaviour(F2D::AssetManager::Load<F2D::SpriteAsset>("Assets/center.png")));
	center->material.blend = F2D::F2D_BLEND_ALPHA;

	object1 = new F2D::FactoryObject("object1");
	object1->transform->origin = { 50.0f, 50.0f, 0.0f };
	object1->transform->position = { 0.0f, 0.0f, 0.0f };
	object1->transform->angle = 0.0f;
	object1->transform->SetParent(scene1->transform);
	object1->AddBehaviour(new F2D::SpriteBehaviour(F2D::AssetManager::Load<F2D::SpriteAsset>("Assets/256_orange.png")));
	//sprite1->width = 100.0f; sprite1->height = 100.0f;		// set sprite render size

	object2 = new F2D::FactoryObject("object2");
	object2->transform->origin = { 25.0f, 25.0f, 0.0f };
	object2->transform->position = { 200.0f, 200.0f, 0.0f };
	object2->transform->angle = { 0.0f };
	object2->transform->SetParent(object1->transform);
	object2->AddBehaviour(new F2D::SpriteBehaviour(F2D::AssetManager::Load<F2D::SpriteAsset>("Assets/256_green.png")));
	object2->material.blend = F2D::F2D_BLEND_MULTIPLY;
	//object2->material.color.a = 0.5f;
	//sprite2->width = 50.0f; sprite2->height = 50.0f;		// set sprite render size

	sprite1 = new F2D::FactoryObject("spriteSheet");
	sprite1->transform->origin = { 25.0f, 25.0f, 0.0f };
	sprite1->transform->position = { 200.0f, 200.0f, 0.0f };
	sprite1->transform->angle = { 0.0f };
	sprite1->transform->SetParent(scene1->transform);
	F2D::SpriteAsset *spriteSheet = F2D::AssetManager::Load<F2D::SpriteAsset>("Assets/shaun.png");
	spriteSheet->sprites = { {0, 0, 36, 48}, {36, 0, 36, 48}, {72, 0, 36, 48} };
	spriteSheet->animation = { {"idle", {{0, 0.25f}, {1, 0.25f}, {0, 0.25f}, {2, 0.25f}} } };
	F2D::SpriteBehaviour *spriteBehaviour = (F2D::SpriteBehaviour*)sprite1->AddBehaviour(new F2D::SpriteBehaviour(spriteSheet));
	//spriteSheet->
	//spriteSheet->AddBehaviour());
	

	// create the scene camera
	camera1 = new F2D::CameraObject("camera1");
	camera1->viewport = { 0.0f, 0.0f, 1.0f, 1.0f };
	camera1->backgroundColor = { 1.0f, 0.0f, 1.0f };
	camera1->transform->position = { 0.0f, 0.0f, 0.0f };
	camera1->transform->SetParent(scene1->transform);
	
	camera2 = new F2D::CameraObject("camera2");
	camera2->viewport = { 0.0f, 0.0f, 0.45f, 0.45f };
	camera2->backgroundColor = { 1.0f, 0.0f, 0.0f };
	camera2->clearColor = true;
	camera2->transform->position = { 0.0f, 0.0f, 0.0f };
	camera2->transform->SetParent(object2->transform);




	// WIP STUFF, IGNORE IT FOR NOW!!
	// I'm using this space to test new stuff, the game must work with
	// this, but, the feature can have some issues os just didn't work
	// yet... Sorry for that xD
	// tag test, not working yet, just to test the tag listing
	F2D::TagManager::SetTag("teste", nullptr);

	return false;
}

void MyGame::Update() {
	// input
	float axisX = F2D::InputManager::GetAxis("player", "x") * 100.0f;
	float axisY = F2D::InputManager::GetAxis("player", "y") * 100.0f;

	object1->transform->Translate(axisX, axisY, 0.0f);
	object1->transform->Rotate(5.0f);
	object2->transform->Rotate(15.0f);

	Game::Update();
}

void MyGame::Draw() {
	Game::Draw();
}
