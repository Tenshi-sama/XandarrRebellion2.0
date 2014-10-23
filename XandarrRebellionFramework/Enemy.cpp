#include "Enemy.h"

#define SCREEN_WIDTH 800
#define ENEMY_WIDTH 32 
#define STEP 8

Enemy::Enemy() : SPRITE_LOCATION("_resources\\enemy.png")
{
	setHealth(100);
	setAtk(25);
	setXp(50);
}

void Enemy::Init(SDL_Renderer* r)
{
	//sprite_.name("Player");
	sprite_.LoadTexture(r, SPRITE_LOCATION);
	sprite_.x(10);
	sprite_.y(200);
}

// Handles all gameplay events


void Enemy::MoveLeft(Texture *theSprite) {
	theSprite->x(theSprite->x() - STEP);
}


void Enemy::MoveRight(Texture *theSprite) {
	theSprite->x(theSprite->x() + STEP);
}

void Enemy::Attack() {
	cout << "The enemy is attacking!" << endl;
}

// From turn five onwards, checks if there has been a winner.
void Enemy::Update(WindowManager* w)
{
	
}

void Enemy::Render(WindowManager* w) 
{

	// Draw the ptr_background_texture_image to the Scene2D object within RenderingEngine
	sprite_.Draw(w->getRenderer());
}