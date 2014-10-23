#include "levelOne.h"


void LevelOne::Init(SDL_Renderer* r)
{
	tile_.name("LevelOne");
	tile_.LoadTexture(r, SPRITE_LOCATION);
	tile_.x(0);
	tile_.y(0);
}



// From turn five onwards, checks if there has been a winner.
void LevelOne::Update(WindowManager* w) 
{

}

void LevelOne::Render(WindowManager* w) 
{
	const int LEVEL_WIDTH = 1800;
	const int LEVEL_HEIGHT = 1600;
	const int TILE_SIZE = 32; //square tile: 40 px x 40 px
	const int TOTAL_TILE_SPRITES= 6;

	//tile sprites

	const int TILE_BLUE = 0;
	const int TILE_RED	= 1;
	const int TILE_WHITE = 2;
	const int TILE_GREY = 3;
	const int TILE_GREEN = 4;
	const int TILE_BLACK = 5;

	/*
	int map[LEVEL_WIDTH * LEVEL_HEIGHT] = {
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
	};
	*/

	int numColumns = LEVEL_WIDTH / TILE_SIZE;
    int numRows = LEVEL_HEIGHT / TILE_SIZE;

	 for (int i = 0; i < numColumns*numRows; ++i)
        {
            int x = i%numColumns;
            int y = i / numColumns;
 
            tile_.x(x*TILE_SIZE);
            tile_.y(y*TILE_SIZE);
 
            tile_.Draw(w->getRenderer());
        }
	
}