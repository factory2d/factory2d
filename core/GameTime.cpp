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
 * Manage our time time.
 *
 * @author @alexribeirodesa (Alexandre Ribeiro de Sá)
 */

#include "GameTime.h"

#include "SDL.h"

namespace F2D
{
	float GameTime::__fps = 0.0f;
	float GameTime::__deltaTime = 0.0f;
	float GameTime::scale = 1.0;

	float GameTime::__smooth = 0.2f;
	unsigned int GameTime::__getTicks = 0;
	unsigned int GameTime::__frameTimeDelta = 0;
	unsigned int GameTime::__frameTimeLast = SDL_GetTicks();

	void GameTime::Update() {
		__getTicks = SDL_GetTicks();
		__frameTimeDelta = __getTicks - __frameTimeLast;
		__frameTimeLast = __getTicks;

		__deltaTime = __smooth * __frameTimeDelta + (1.0f - __smooth) * __deltaTime;
		__fps = 1000.0f / __deltaTime;
	}

	float GameTime::FPS() {
		return __fps;
	}

	// TODO: CACHE DT / UCDT
	float GameTime::Delta() {
		if(__fps == 0.0f) return 0.0f;
		return 1.0f / (__fps * scale);
	}

	float GameTime::UnscaledDelta() {
		if(__fps == 0.0f) return 0.0f;
		return 1.0f / __fps;
	}
}