#ifndef TEXTWINDOW_H
#define TEXTWINDOW_H

#include "Texture.h"
#include "Window.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class TextWindow
{
protected:
	Texture textBox_;
	Texture text_;
	const string SPRITE_LOCATION;
	
	//std::stringstream ss;

public:
	TextWindow() : SPRITE_LOCATION("_resources\\blank.png") {}
	~TextWindow() {}

	void Init(SDL_Renderer* r);
	void HandleEvents(SDL_Event* event);
	void Update(WindowManager* w);
	void Render(WindowManager* w);	
};

#endif