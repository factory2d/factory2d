/**
 * @license
 */

 /**
  * @fileoverview Base Factory2D Objects
  *
  * Base scene objects
  *
  * @author @alexribeirodesa (Alexandre Ribeiro de Sá)
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
		for(unsigned int x = 0; x < transform->GetChildCount(); x++) {
			transform->GetChild(x)->GetFactoryObject()->Update();
		}
	}

	void FactoryObject::Draw() {
		//	TODO: there a better way to do that!
		Transform *t;
		Transform *p;

		for(unsigned int x = 0; x < transform->GetChildCount(); x++) {
			t = transform->GetChild(x);
			p = t->GetParent();
			glPushMatrix();

			//	TODO: cache the matrix transform and just update when need
			if(p != NULL)
				glTranslatef(p->GetOrigin()->x, p->GetOrigin()->y, p->GetOrigin()->z);
			glTranslatef(t->GetPosition()->x, t->GetPosition()->y, t->GetPosition()->z);
			glRotatef(t->GetRotate()->y, 0.0f, 0.0f, 1.0f);
			glTranslatef(-t->GetOrigin()->x, -t->GetOrigin()->y, -t->GetOrigin()->z);

			t->GetFactoryObject()->Draw();
			glPopMatrix();
		}

	}

	void FactoryObject::SetTag(std::string tag) {}

	std::string FactoryObject::GetTag() {
		return std::string();
	}

	void FactoryObject::RemoveTag() {}

	std::string FactoryObject::Serialize() {
		return std::string();
	}
	bool FactoryObject::Deserialize() {
		return false;
	}
}