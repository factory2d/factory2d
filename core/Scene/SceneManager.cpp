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
  * @fileoverview SceneManager.cpp
  *
  * Manage the game scenes
  *
  * @author Alexandre Ribeiro de Sá (@alexribeirodesa)
  */

#include "SceneManager.h"
#include "../Objects/CameraObject.h"
#include "../Renderer.h"
 
namespace F2D
{
	std::vector <SceneObject*>SceneManager::__scenes = {};

	SceneManager::SceneManager() {}
	SceneManager::~SceneManager() {}

	unsigned int SceneManager::Count() {
		return __scenes.size();
	}

	void SceneManager::Load(SceneObject * scene) {
		__scenes.push_back(scene);
	}

	void SceneManager::Unload(std::string name) {}

	void SceneManager::Unload(SceneObject * scene) {}

	SceneObject* SceneManager::GetActiveScenes() {
		return nullptr;
	}

	SceneObject* SceneManager::GetSceneAt(unsigned int index) {
		if(index >= 0 && index < __scenes.size())
			return __scenes[index];

		return nullptr;
	}

	void SceneManager::Update() {
		unsigned int totalScenes = __scenes.size();

		for(unsigned int x = 0; x < totalScenes; x++) {
			if(__scenes[x]->enabled)
				__scenes[x]->Update();
		}
	}

	void SceneManager::Draw() {
		unsigned int totalCameras = CameraObject::Count();
		unsigned int totalScenes = __scenes.size();

		CameraObject* c;

		for(unsigned int cam = 0; cam < totalCameras; cam++) {
			c = CameraObject::GetCameraAt(cam);

			if(c->enabled) {
				CameraObject::SetActiveCamera(c);

				Renderer::Begin();
				for(unsigned int scn = 0; scn < totalScenes; scn++) {
					if(__scenes[scn]->enabled)
						__scenes[scn]->Draw();
				}
				Renderer::End();
			}
		}
	}
}