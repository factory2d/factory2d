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
  * @fileoverview FactoryObject.cpp
  *
  * --- FILE NOTES ---
  *
  * @author Alexandre Ribeiro de S� (@alexribeirodesa)
  */

#include "SDL.h"
#include "SDL_opengl.h"
#include <GL\GLU.h>

#include "FactoryObject.h"

namespace F2D
{
	FactoryObject::FactoryObject(std::string n) {
		name = n;
		enabled = true;
		transform = new Transform(this);
	}

	FactoryObject::~FactoryObject() {
		//	tenho que destruir todos os objetos anexados a esse!
	}

	void FactoryObject::Update() {
		//	TODO: there a better way to do that!
		unsigned int totalBehaviours = __behaviours.size();
		unsigned int totalChilds = transform->GetChildCount();
		unsigned int x = 0;

		for(x = 0; x < totalBehaviours; x++) {
			__behaviours[x]->Update();
		}

		for(x = 0; x < totalChilds; x++) {
			transform->GetChild(x)->GetFactoryObject()->Update();
		}
	}

	void FactoryObject::Draw() {
		//	TODO: there a better way to do that!
		unsigned int totalBehaviours = __behaviours.size();
		unsigned int totalChilds = transform->GetChildCount();
		Transform *t;
		Transform *p;
		unsigned int x = 0;

		for(x = 0; x < totalBehaviours; x++) {
			if(__behaviours[x]->enabled)
				__behaviours[x]->Draw();
		}

		for(x = 0; x < totalChilds; x++) {
			if(transform->GetChild(x)->GetFactoryObject()->enabled) {
				t = transform->GetChild(x);
				p = t->GetParent();
				glPushMatrix();

				//if(p != NULL)
				//	glTranslatef(p->GetOrigin().x, p->GetOrigin().y, p->GetOrigin().z);
				//glTranslatef(t->GetPosition().x, t->GetPosition().y, t->GetPosition().z);
				//glRotatef(t->GetRotate().y, 0.0f, 0.0f, 1.0f);
				//glTranslatef(-t->GetOrigin().x, -t->GetOrigin().y, -t->GetOrigin().z);

				// calculate transform matrix and cache it
				// we will only calculate it again if need :3
				t->ApplyTransform();
				glMultMatrixf(glm::value_ptr(t->GetLocalTransform()));

				t->GetFactoryObject()->Draw();
				glPopMatrix();
			}
		}

	}

	void FactoryObject::SetTag(std::string tag) {}

	std::string FactoryObject::GetTag() {
		return std::string();
	}

	void FactoryObject::RemoveTag() {}
	Behaviour * FactoryObject::AddBehaviour(Behaviour * behaviour) {
		behaviour->transform = transform;
		__behaviours.push_back(behaviour);
		return __behaviours.back();
	}
	bool FactoryObject::RemoveBehaviour(std::string name) {
		return false;
	}
}