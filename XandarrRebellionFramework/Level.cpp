#include "Level.h"

#define TILE_HEIGHT 32
#define TILE_WIDTH 32

void Level::Init(SDL_Renderer* r)
{
	level_.LoadTexture(r, LEVEL_LOCATION);
	level_.x(0);
	level_.y(0);
	
	hitbox1.getTexture()->LoadTexture(r, BOX_LOCATION);
	hitbox1.setXPos(TILE_WIDTH*2);
	hitbox1.setYPos(TILE_HEIGHT*5);
	//hitbox1.getTexture()->scaleY(16);

	cout << "hitbox1 initialized at x:" << hitbox1.getXPos() << " y:" << hitbox1.getYPos() << endl;


	hitBox_.push_back(&hitbox1);

	//hitBoxHolder_ = new HitBoxHolder();
	//createBox_ = new HitBoxCreator("wall", 100, 100);
}

// From turn five onwards, checks if there has been a winner.
void Level::Update(WindowManager* w)
{
	//if (Player* SPRITE_LOCATION)
}

void Level::Render(WindowManager* w)
{
	level_.Draw(w->getRenderer());
	hitbox1.getTexture()->Draw(w->getRenderer());
}