#pragma once

#define DllExport   __declspec( dllexport )

#include "Debug.h"

#include "Math.h"
#include "Game.h"
#include "GameTime.h"
#include "Window.h"
#include "Renderer.h"
#include "Object.h"
#include "Asset.h"
#include "Transform.h"

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
#include "InputManager/TriggerObject.h"