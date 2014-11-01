#include "Item.h"

#define TILE_HEIGHT 32
#define TILE_WIDTH 32

void Item::Init(SDL_Renderer* r) {
	sprite_.LoadTexture(r, SPRITE_LOCATION);
	sprite_.x(TILE_WIDTH * 12);
	sprite_.y(TILE_HEIGHT * 3);
}

void Item::HandleEvents(SDL_Event* event) {

}

void Item::Update(WindowManager* w) {

}

void Item::Render(WindowManager* w) {
	sprite_.Draw(w->getRenderer());
}