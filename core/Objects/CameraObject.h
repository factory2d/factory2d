#ifndef __FACTORY2D_CAMERAOBJECT
#define __FACTORY2D_CAMERAOBJECT

#include "SDL.h"
#include "SDL_opengl.h"
#include <GL\GLU.h>
#include <vector> 

#include "../Math.h"
#include "FactoryObject.h"

namespace F2D
{
	class CameraObject :
		public FactoryObject {
	private:
		static std::vector <CameraObject*> __cameras;
		static CameraObject* __activeCamera;

	public:
		CameraObject() {};
		CameraObject(std::string name);
		~CameraObject();

		void Update() override;
		void Draw() override;

		Rect* viewport = new Rect(0.0f, 0.0f, 1.0f, 1.0f);

		static unsigned int Count();
		static CameraObject* GetCameraAt(unsigned int index);
		static CameraObject* GetActiveCamera();
		static void SetActiveCamera(CameraObject *camera);
	};
}

#endif