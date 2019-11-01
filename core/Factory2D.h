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
  * @author Alexandre Ribeiro de Sá (@alexribeirodesa)
  */

#ifndef FACTORY2D_FACTORY2D_H_
#define FACTORY2D_FACTORY2D_H_

#define DllExport   __declspec( dllexport )

#include "Debug.h"
#include "Game.h"
#include "Serializable.h"

/* MATH */
#include "Math.h"
#include "Transform.h"

/* OBJECTS */
#include "Object.h"
#include "Objects/FactoryObject.h"
#include "Objects/SpriteObject.h"

/* BEHAVOUR */
#include "Behavior/Behaviour.h"
#include "Behavior/SpriteBehaviour.h"
#include "Behavior/TweenBehaviour.h"

/* ASSETS */
#include "Asset/Asset.h"
#include "Asset/AssetManager.h"
#include "Asset/PictureAsset.h"

/* INPUT */
#include "Input/InputManager.h"
#include "Input/Controller.h"
#include "Input/Action.h"
#include "Input/AxisAction.h"
#include "Input/ButtonAction.h"
#include "Input/Trigger.h"
#include "Input/KeyboardTrigger.h"

/* MATERIAL */
#include "Color.h"

/* SCENE */
#include "Scene/SceneManager.h"
#include "Scene/SceneObject.h"

/* RENDER */
#include "Renderer.h"
#include "Objects/CameraObject.h"

/* TAG*/
#include "TagManager/TagManager.h"

/* TIME */
#include "Time/TimeManager.h"

/* WINDOW */
#include "Window/WindowManager.h"

#endif // FACTORY2D_FACTORY2D_H_
