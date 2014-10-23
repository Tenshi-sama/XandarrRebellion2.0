#include "TextWindow.h"

TTF_Font* font = TTF_OpenFont( "_resources\\SHOWG.ttf", 36 );
SDL_Color textColor = { 0, 0, 0 }; // RGB value for Black
//SDL_Renderer* r = w->getRenderer();

void TextWindow::Init(SDL_Renderer* r) {

	textBox_.LoadTexture(r, SPRITE_LOCATION);
	textBox_.alpha(150);
	textBox_.x(0);
	textBox_.y(0);
	textBox_.scaleX((const float)2.7);

	//text_.x(320);
	//text_.y(20);

	//TextOutput("<no text>");
}

void TextWindow::HandleEvents(SDL_Event* event) {

}

void TextWindow::Update(WindowManager* w) {

}

void TextWindow::Render(WindowManager* w) {
	textBox_.Draw(w->getRenderer());
	//text_.Draw(w->getRenderer());
}