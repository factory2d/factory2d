#include "CameraObject.h"

namespace F2D
{
	std::vector <CameraObject*>CameraObject::__cameras = {};
	CameraObject* CameraObject::__activeCamera;

	CameraObject::CameraObject(std::string name) : FactoryObject(name) {
		__cameras.push_back(this);
	}

	CameraObject::~CameraObject() {}

	void CameraObject::Update() {}

	void CameraObject::Draw() {}

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