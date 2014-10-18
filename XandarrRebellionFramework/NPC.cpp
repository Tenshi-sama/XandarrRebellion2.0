#include "NPC.h"

#define SCREEN_WIDTH 800
#define NPC_WIDTH 32 
#define STEP 10

void NPC::Init(SDL_Renderer* r) {
	//sprite_.name("Player");
	sprite_.LoadTexture(r, SPRITE_LOCATION);
	sprite_.x(0);
	sprite_.y(300);

	text_.x(320);
	text_.y(20);

	text2_.x(320);
	text2_.y(20);

	text3_.x(320);
	text3_.y(40);

	text4_.x(320);
	text4_.y(20);

	state_life_timer_.Start();
}


void NPC::MoveLeft(Texture *theSprite) {
	theSprite->x(theSprite->x() - STEP);
}


void NPC::MoveRight(Texture *theSprite) {
	theSprite->x(theSprite->x() + STEP);
}

// From turn five onwards, checks if there has been a winner.
void NPC::Update(WindowManager* w) {

}

bool NPC::Moving(bool moveControl) {
	static bool movingLeft = true;

	if (moveControl) {
		//cout << "Update! ... MovingLeft is: " << movingLeft << endl;
		if (movingLeft) {
			if (sprite_.x() >= SCREEN_WIDTH - SCREEN_WIDTH) {
				MoveLeft(&sprite_);
			} else {
				movingLeft = false;
			}
		} else {
			if (sprite_.x() <= SCREEN_WIDTH - NPC_WIDTH) {
				MoveRight(&sprite_);
			} else {
				movingLeft = true;
			}
		}

		return true;
	} else {
		return false;
	}
}

void NPC::Render(WindowManager* w) {
	// Draw the ptr_background_texture_image to the Scene2D object within RenderingEngine
	sprite_.Draw(w->getRenderer());
	text_.Draw(w->getRenderer());
	text2_.Draw(w->getRenderer());
	text3_.Draw(w->getRenderer());
	text4_.Draw(w->getRenderer());
}

void NPC::Speech(SDL_Renderer* r) {
	//cout << "The NPC is talking" << endl;

	TTF_Font* font = TTF_OpenFont("_resources\\arial.ttf", 18);
	SDL_Color textColor = { 0, 0, 0 };

	text_.CreateTextureFromText(r, "You're in a prison!", font, textColor);
	if (((state_life_timer_.getTicks() % 5000) <= 20)) {
		text_.visible(false);
		text2_.CreateTextureFromText(r, "Your first task is to collect", font, textColor);
		text3_.CreateTextureFromText(r, "the potion bottle", font, textColor);
	}
	if (((state_life_timer_.getTicks() % 5000) <= 20)) {
		text2_.visible(false);
		text3_.visible(false);
		text4_.CreateTextureFromText(r, "Collect the potion bottle", font, textColor);
	}
}