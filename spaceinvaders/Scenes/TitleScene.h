#pragma once
#include "../../core/Factory2D.h"

class TitleScene :
	public F2D::SceneObject {

private:
	F2D::CameraObject *__camera;
	F2D::FactoryObject *__logoObject;

public:
	TitleScene();
	TitleScene(std::string name);
	~TitleScene();


};

