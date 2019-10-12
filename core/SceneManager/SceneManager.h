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
  * @fileoverview SceneManager.h
  *
  * Manage game scenes.
  *
  * @author @alexribeirodesa (Alexandre Ribeiro de Sá)
  */

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