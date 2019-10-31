#include "CameraObject.h"

namespace F2D
{
	std::vector <CameraObject*>CameraObject::__cameras = {};
	CameraObject* CameraObject::__activeCamera;

	CameraObject::CameraObject(std::string name) : FactoryObject(name) {
		__cameras.push_back(this);
	}

	CameraObject::~CameraObject() {}

	void CameraObject::Update() {
		FactoryObject::Update();
	}

	void CameraObject::Draw() {
		FactoryObject::Draw();
		// just for debug
		/*
		glBegin(GL_QUADS);
		glColor3f(1.f, 1.f, 1.f); glVertex2f(-10.0f, -10.0f);
		glColor3f(1.f, 1.f, 1.f); glVertex2f( 10.0f, -10.0f);
		glColor3f(1.f, 1.f, 1.f); glVertex2f( 10.0f,  10.0f);
		glColor3f(1.f, 1.f, 1.f); glVertex2f(-10.0f,  10.0f);
		glEnd();
		*/
	}

	unsigned int CameraObject::Count() {
		return __cameras.size();;
	}

	CameraObject * CameraObject::GetCameraAt(unsigned int index) {
		if(index >= 0 && index < __cameras.size())
			return __cameras[index];

		return nullptr;
	}

	CameraObject * CameraObject::GetActiveCamera() {
		return __activeCamera;
	}

	void CameraObject::SetActiveCamera(CameraObject * camera) {
		__activeCamera = camera;
	}
}