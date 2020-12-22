#include <imgui.h>
#include <imgui_impl_sdl.h>
#include <SDL.h>
#include <SDL_opengl.h>

#include <iostream>
#include <stdio.h>
#include "base.h"
#include "cpu.h"
#include "mmu.h"
#include "gb.h"
#include "debugger.h"


int main(int argn, char *argc[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		cout << "Error: " << SDL_GetError();
		exit;
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);


	Debugger debugger;
	SDL_Event event;
	bool done = false;
	
	while (true) {
		
		while (SDL_PollEvent(&event))
		{
			debugger.HandleEvent(event);
			
			if (event.type == SDL_QUIT)
				done = true;
		}
		
		debugger.Render();
	}

	SDL_Quit();

	/*
    GB gb;
    gb.PowerUp(argc[1], argc[2]);
	*/

    //return 0;
}

