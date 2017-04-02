#include "gWindow.h"
#include "SProgram.h"
#include "Sqare.h"
#include <cstdlib>
#include <cstdio>




int main(int argc, char* args[])
{
	gWindow* foo = new gWindow(WINDOW_SCREEN);
	
	bool quit = false;
	while (!quit) {

		SDL_GL_SwapWindow(foo->window);
		while (SDL_PollEvent(&foo->e)) {
			if (foo->e.type == SDL_QUIT) {
				quit = true;
			}
		}

	}


	return 0;
}