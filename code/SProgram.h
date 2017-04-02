#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "glad.h"


using std::ifstream;
using std::ostringstream;
using std::string;
using std::vector;
namespace ege {
	class SProgram
	{
	protected:
		GLuint program;
		void attach_shader(GLuint program, GLenum type, const char * code);
		vector<string> unifroms;
	public:
		vector<string> getUnifroms();
		GLuint getUnifLoc(string);
		void useProgram();
		//warning!! both will point to same program in gpu memory
		SProgram operator = (const SProgram &other);
		SProgram(const char* vertextFile, const char* fragmentFile,const char* lable, vector<string> unif);
		~SProgram();
	};
}