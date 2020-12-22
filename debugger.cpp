#include "imgui.h"
#include "imgui_impl_sdl.h"
#include <stdio.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include "base.h"
#include "debugger.h"

Debugger::Debugger() 
{
	SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI);
	mWindow = SDL_CreateWindow("Dear ImGui SDL2+OpenGL3 example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, window_flags);
	mContext = SDL_GL_CreateContext(mWindow);

	SDL_GL_MakeCurrent(mWindow, mContext);
	SDL_GL_SetSwapInterval(1); // Enable vsync

	ImGui_ImplSdl_Init(mWindow);
}

Debugger::~Debugger()
{
	ImGui_ImplSdl_Shutdown();
	
	SDL_GL_DeleteContext(mContext);
	SDL_DestroyWindow(mWindow);
}

void Debugger::HandleEvent(SDL_Event& _event)
{
	ImGui_ImplSdl_ProcessEvent(&_event);
}

void Debugger::Render()
{
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui_ImplSdl_NewFrame(mWindow);
	//ImGui::NewFrame();

	// TODO: all controls
	glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
	glClearColor(1, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	ImGui::Render();

	SDL_GL_SwapWindow(mWindow);
}