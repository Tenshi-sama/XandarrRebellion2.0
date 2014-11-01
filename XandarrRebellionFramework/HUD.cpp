#include "HUD.h"

void Healthbarout::Init(SDL_Renderer* r) {
	sprite_.name("Health_Outer");
	sprite_.LoadTexture(r, SPRITE_LOCATION);
	sprite_.x(5);
	sprite_.y(5);
}

// Handles all gameplay events
void Healthbarout::HandleEvents(SDL_Event* event) {


}

// From turn five onwards, checks if there has been a winner.
void Healthbarout::Update(WindowManager* w) {

}

void Healthbarout::Render(WindowManager* w) {

	// Draw the ptr_background_texture_image to the Scene2D object within RenderingEngine
	sprite_.Draw(w->getRenderer());
}

void Healthbarin::Init(SDL_Renderer* r) {
	sprite_.name("Health_Inner");
	sprite_.LoadTexture(r, SPRITE_LOCATION);
	sprite_.x(5);
	sprite_.y(5);
}

// Handles all gameplay events
void Healthbarin::HandleEvents(SDL_Event* event) {

	switch (event->type) {
	case SDL_KEYDOWN:


		if (event->key.keysym.sym == SDLK_g) {
			// lower health
			sprite_.x(sprite_.x() - 10);
		}
		if (event->key.keysym.sym == SDLK_h) {
			// raise health
			sprite_.x(sprite_.x() + 10);
		}
		break;
	}

}

// From turn five onwards, checks if there has been a winner.
void Healthbarin::Update(WindowManager* w, Player* p) {
	sprite_.scaleX((float)p->getCurrentHealth() / (float)p->getMaxHealth());
}

void Healthbarin::Render(WindowManager* w) {

	// Draw the ptr_background_texture_image to the Scene2D object within RenderingEngine
	sprite_.Draw(w->getRenderer());
}

void XP::Init(SDL_Renderer* r) {
	text_.x(10);
	text_.y(30);
}

void XP::HandleEvents(SDL_Event* event) {

}

void XP::Update(WindowManager* w) {
	unsigned int xpText = player_.getXp();
	std::stringstream xpTextStream;

	xpTextStream.str("");
	xpTextStream << "XP: " << xpText;

	TTF_Font* font = TTF_OpenFont("_resources\\arial.ttf", 16);
	SDL_Color textColor = { 0, 0, 0 };

	text_.CreateTextureFromText(w->getRenderer(), xpTextStream.str(), font, textColor);
}

void XP::Render(WindowManager* w) {
	text_.Draw(w->getRenderer());
}

void PrintLevel::Init(SDL_Renderer* r) {
	text_.x(10);
	text_.y(50);
}

void PrintLevel::HandleEvents(SDL_Event* event) {

}

void PrintLevel::Update(WindowManager* w) {
	unsigned int lvlText = player_.getXp();
	std::stringstream lvlTextStream;

	lvlTextStream.str("");
	lvlTextStream << "Level: " << lvlText;

	TTF_Font* font = TTF_OpenFont("_resources\\arial.ttf", 16);
	SDL_Color textColor = { 0, 0, 0 };

	text_.CreateTextureFromText(w->getRenderer(), lvlTextStream.str(), font, textColor);
}

void PrintLevel::Render(WindowManager* w) {
	text_.Draw(w->getRenderer());
}