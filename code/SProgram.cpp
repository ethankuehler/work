#include "SProgram.h"



namespace ege {
	void SProgram::attach_shader(GLuint program, GLenum type, const char * code)
	{
		GLuint shader = glCreateShader(type);
		glShaderSource(shader, 1, &code, NULL);
		glCompileShader(shader);
		glAttachShader(program, shader);
		glDeleteShader(shader);
	}

	vector<string> SProgram::getUnifroms()
	{
		return unifroms;
	}

	GLuint SProgram::getUnifLoc(string name)
	{
		
		return glGetUniformLocation(program,name.c_str());
	}

	void SProgram::useProgram()
	{
		glUseProgram(program);
	}

	SProgram SProgram::operator=(const SProgram & other)
	{
		glDeleteProgram(this->program);
		return other;
	}

	SProgram::SProgram(const char* vertextFile,const char* fragmentFile,const char* lable, vector<string> unif)
	{
		ifstream fileReader = ifstream();
		string vertexCode;
		string fragmentCode;
		this->unifroms = unif;

		fileReader.open(vertextFile, std::ios::in);
		if (!fileReader.fail())
		{
			ostringstream oss;
			oss << fileReader.rdbuf();
			vertexCode = oss.str();
			fileReader.close();
		}
		else
		{
			std::cout << "failed to read from file " << vertextFile << '\n';
			exit(10);
		}

		fileReader.open(fragmentFile, std::ios::in);
		if (!fileReader.fail())
		{
			
			ostringstream oss;
			oss << fileReader.rdbuf();
			fragmentCode = oss.str();
			fileReader.close();
		}
		else
		{
			std::cout << "failed to read from file " << fragmentFile << '\n';
			exit(10);
		}

		program = glCreateProgram();
		glObjectLabel(GL_PROGRAM, program, -1, lable);

		attach_shader(program, GL_VERTEX_SHADER, vertexCode.c_str());
		attach_shader(program, GL_FRAGMENT_SHADER,fragmentCode.c_str());

		glLinkProgram(program);
		GLint result;
		glGetProgramiv(program, GL_LINK_STATUS, &result);
		if (result != GL_TRUE) {
			char msg[10240];
			glGetProgramInfoLog(program, 10240, NULL, msg);
			fprintf(stderr, "Linking program failed:\n%s\n", msg);
			abort();
		}

	}


	SProgram::~SProgram()
	{
		glDeleteProgram(program);
	}
}