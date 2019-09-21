#ifndef __FACTORY2D_SCENEMANAGER
#define __FACTORY2D_SCENEMANAGER

#include <string>
#include <vector> 
#include "../FactoryObjects/SceneObject.h"

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

#endif