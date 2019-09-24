#include "SceneManager.h"
#include "../FactoryObjects/CameraObject.h"
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

		for(unsigned int x = 0; x < __scenes.size(); x++) {
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
					__scenes[scn]->Draw();
				}
				Renderer::End();
			}
		}
	}
}