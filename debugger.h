#pragma once
#ifndef  _DEBUGGER_H
#endif // ! _DEBUGGER_H

class Debugger
{
public:
	Debugger();
	~Debugger();

	void HandleEvent(SDL_Event& _event);
	void Render();

private:
	SDL_Window *mWindow;
	SDL_GLContext mContext;
};
