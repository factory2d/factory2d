/**
 * @license
 * F2D are available under the zlib license:
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * varising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 */

 /**
  * @fileoverview Object.h
  *
  * --- FILE NOTES ---
  *
  * @author Alexandre Ribeiro de Sá (@alexribeirodesa)
  */

#ifndef FACTORY2D_OBJECTS_CAMERAOBJECT_H_
#define FACTORY2D_OBJECTS_CAMERAOBJECT_H_

#include "SDL.h"
#include "SDL_opengl.h"
#include <GL\GLU.h>
#include <vector> 

#include "../Math.h"
#include "FactoryObject.h"
#include "../Color.h"

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

		Color backgroundColor = Color(0.5f, 0.5f, 0.5f);
		bool clearColor = true;
	};
}

#endif // FACTORY2D_OBJECTS_CAMERAOBJECT_H_
