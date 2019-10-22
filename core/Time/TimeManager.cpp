/**
* @license
* F2D are available under the zlib license :
*
* This software is provided 'as-is', without any express or implied
* warranty.In no event will the authors be held liable for any damages
* varising from the use of this software.
*
* Permission is granted to anyone to use this software for any purpose,
*including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions :
*
* 1. The origin of this software must not be misrepresented; you must not
*    claim that you wrote the original software.If you use this software
*    in a product, an acknowledgment in the product documentation would be
*    appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
*    misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
* /

/**
 * @fileoverview GameTime.cpp
 *
 * Manage the game time and fps
 *
 * @author Alexandre Ribeiro de Sá (@alexribeirodesa)
 */

#include "TimeManager.h"

#include "SDL.h"

namespace F2D
{
	float TimeManager::__fps = 0.0f;
	float TimeManager::__deltaTime = 0.0f;
	float TimeManager::scale = 1.0;

	unsigned long TimeManager::__frameCount = 0;
	unsigned long TimeManager::__renderedFrameCount = 0;

	float TimeManager::__smooth = 0.2f;
	unsigned int TimeManager::__getTicks = 0;
	unsigned int TimeManager::__frameTimeDelta = 0;
	unsigned int TimeManager::__frameTimeLast = SDL_GetTicks();

	float TimeManager::__cacheDelta = 0.0f;
	float TimeManager::__cacheUnscaledDelta = 0.0f;

	void TimeManager::Update() {
		__getTicks = SDL_GetTicks();
		__frameTimeDelta = __getTicks - __frameTimeLast;
		__frameTimeLast = __getTicks;

		__deltaTime = __smooth * __frameTimeDelta + (1.0f - __smooth) * __deltaTime;
		__fps = 1000.0f / __deltaTime;

		if(__fps > 0.0f) {
			__cacheUnscaledDelta = 1.0f / __fps;
			__cacheDelta = __cacheUnscaledDelta * scale;
		}

		__frameCount++;
	}

	float TimeManager::FPS() {
		return __fps;
	}

	float TimeManager::Delta() {
		if(__fps == 0.0f) return 0.0f;
		return __cacheDelta;
	}

	float TimeManager::UnscaledDelta() {
		if(__fps == 0.0f) return 0.0f;
		return __cacheUnscaledDelta;
	}

	unsigned long TimeManager::FrameCount() {
		return __frameCount;
	}
}