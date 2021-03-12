#pragma once

#include "Variables.h"

void reveal(int i, int j);

class LButton
{
	public:
		LButton();
		void setPosition( int x, int y );
		void handleEvent( SDL_Event* e );
		void render(int i, int j);
	private:
		SDL_Point mPosition;
};
