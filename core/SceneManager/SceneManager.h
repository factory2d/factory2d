#ifndef FACTORY2D_SCENEMANAGER_SCENEMANAGER_H_
#define FACTORY2D_SCENEMANAGER_SCENEMANAGER_H_

#include "../FactoryObjects/SceneObject.h"

#include <string>
#include <vector> 

namespace F2D
{
	class SceneManager {
	private:
		static std::vector <SceneObject*> __scenes;

		SceneManager();
		~SceneManager();

	public:
		static unsigned int Count();
		static void Load(SceneObject* scene);
		static void Unload(std::string name);
		static void Unload(SceneObject* scene);
		static SceneObject* GetActiveScenes();
		static SceneObject* GetSceneAt(unsigned int index);
		static void Update();
		static void Draw();
	};
}

#endif // FACTORY2D_SCENEMANAGER_SCENEMANAGER_H_