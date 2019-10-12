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
  * @fileoverview Factory2D.h
  *
  * Factory2D core include
  *
  * @author @alexribeirodesa (Alexandre Ribeiro de Sá)
  */

#ifndef FACTORY2D_FACTORY2D_H_
#define FACTORY2D_FACTORY2D_H_

#define DllExport   __declspec( dllexport )

#include "Debug.h"

#include "Math.h"
#include "Game.h"
#include "GameTime.h"
#include "Renderer.h"
#include "Object.h"
#include "Asset.h"
#include "Transform.h"

/* WINDOW */
#include "WindowManager/WindowManager.h"

/* TAG*/
#include "TagManager/TagManager.h"

/* ASSETS */
#include "AssetManager/AssetManager.h"
#include "AssetManager/Picture.h"

/* SCENE */
#include "SceneManager/SceneManager.h"

/* OBJECTS */
#include "FactoryObjects/FactoryObject.h"
#include "FactoryObjects/SceneObject.h"
#include "FactoryObjects/CameraObject.h"
#include "FactoryObjects/TextureObject.h"
#include "FactoryObjects/SpriteObject.h"

/* INPUT */
#include "InputManager/InputManager.h"
#include "InputManager/ControllerObject.h"
#include "InputManager/ActionObject.h"
#include "InputManager/AxisObject.h"
#include "InputManager/ButtonObject.h"
#include "InputManager/TriggerObject.h"

#endif // FACTORY2D_FACTORY2D_H_
