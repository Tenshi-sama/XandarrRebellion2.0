#ifndef KATANA_H
#define KATANA_H

#include "Melee.h"


class Katana : public Melee
{
private:
	const string SPRITE_LOCATION;
	Texture katana_sprite_;

public:
	Katana();
	~Katana(){};

	void Init(SDL_Renderer* r);
	void HandleEvents(SDL_Event* event);
	void Update(WindowManager* w);
	void Render(WindowManager* w);
	void printInfo();
};

#endif