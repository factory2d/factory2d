#pragma once

#define DllExport   __declspec( dllexport )

#include "math.h"
#include "Game.h"
#include "GameTime.h"
#include "Window.h"
#include "Renderer.h"
#include "Object.h"
#include "Transform.h"

#include "FactoryObjects/FactoryObject.h"
#include "FactoryObjects/SceneObject.h"
#include "FactoryObjects/CameraObject.h"

#include "FactoryObjects/TextureObject.h"
#include "FactoryObjects/Texture2D.h"
#include "FactoryObjects/SpriteObject.h"

#include "ResourceManager/ResourceManager.h"
#include "SceneManager/SceneManager.h"