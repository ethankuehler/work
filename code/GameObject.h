#pragma once
#include "SProgram.h"
#include "glad.h"
#include "glm\glm.hpp"
#include "glm\gtc\type_ptr.hpp"
#include "glm\gtx\transform.hpp"

using glm::vec3;
using glm::mat4;

namespace ege {
	class GameObject
	{
	protected:
		SProgram *prog;
		vec3 objectPosition;

		vec3* model;

	public:
		GameObject();
		~GameObject();
	};

}