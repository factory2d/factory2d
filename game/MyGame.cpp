#include "MyGame.h"

MyGame::MyGame() {}
MyGame::~MyGame() {}

F2D::SceneObject* scene1;
F2D::CameraObject* camera1;
F2D::CameraObject* camera2;
F2D::FactoryObject* center;
F2D::FactoryObject* object1;
F2D::FactoryObject* object2;

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
	F2D::PictureAsset *p;
	p = F2D::AssetManager::Load<F2D::PictureAsset>("Assets/256_orange.png"); // load the picture and put in cache
	p = F2D::AssetManager::Load<F2D::PictureAsset>("Assets/256_orange.png"); // loading the same picture, we will use the cached

	// create a new scene
	scene1 = new F2D::SceneObject("scene1");
	F2D::SceneManager::Load(scene1);

	// create objects inside the scene
	center = new F2D::FactoryObject("center");
	center->transform->SetOrigin(8.0f, 8.0f, 0.0f);
	center->transform->SetPosition(0.0f, 0.0f, 0.0f);
	center->transform->SetParent(scene1->transform);
	center->AddBehaviour(new F2D::SpriteBehaviour(F2D::AssetManager::Load<F2D::PictureAsset>("Assets/center.png")));

	object1 = new F2D::FactoryObject("object1");
	object1->transform->SetOrigin(50.0f, 50.0f, 0.0f);
	object1->transform->SetPosition(0.0f, 0.0f, 0.0f);
	object1->transform->SetRotate(0.0f);
	object1->transform->SetParent(scene1->transform);
	F2D::SpriteBehaviour *sprite1 = (F2D::SpriteBehaviour*)object1->AddBehaviour(new F2D::SpriteBehaviour(F2D::AssetManager::Load<F2D::PictureAsset>("Assets/256_orange.png")));
	sprite1->width = 100.0f; sprite1->height = 100.0f;		// set sprite render size

	object2 = new F2D::FactoryObject("object2");
	object2->transform->SetOrigin(25.0f, 25.0f, 0.0f);
	object2->transform->SetPosition(200.0f, 200.0f, 0.0f);
	object2->transform->SetRotate(0.0f);
	object2->transform->SetParent(object1->transform);
	F2D::SpriteBehaviour *sprite2 = (F2D::SpriteBehaviour*)object2->AddBehaviour(new F2D::SpriteBehaviour(F2D::AssetManager::Load<F2D::PictureAsset>("Assets/256_green.png")));
	sprite2->width = 50.0f; sprite2->height = 50.0f;		// set sprite render size

	// create the scene camera
	camera1 = new F2D::CameraObject("camera1");
	camera1->viewport = new F2D::Rect(0.0f, 0.0f, 1.0f, 1.0f);
	camera1->backgroundColor = F2D::Color(0.25f, 0.25f, 0.25f);
	camera1->transform->SetPosition(0.0f, 0.0f, 0.0f);
	camera1->transform->SetParent(scene1->transform);
	
	camera2 = new F2D::CameraObject("camera2");
	camera2->viewport = new F2D::Rect(0.0f, 0.0f, 0.45f, 0.45f);
	camera2->backgroundColor = F2D::Color(1.0f, 0.0f, 0.0f);
	camera2->clearColor = true;
	camera2->transform->SetPosition(0.0f, 0.0f, 0.0f);
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
