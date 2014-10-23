#include "Katana.h"

Katana::Katana() 
{
	setName("Katana");
	setMovementSpeed(50);
	setAttackPower(25);
	setAttackRate(50);
	setDescription("An old asian sword.");
	setIsOneHanded(false);
	setWeight(10);
	setWorth(250);
	SPRITE_LOCATION : "_resources\\katana2.png";
}

void Katana::Init(SDL_Renderer* r)
{
	//sprite_.name("Katana");	
	katana_sprite_.height(74);
	katana_sprite_.width(74);
	katana_sprite_.LoadTexture(r, SPRITE_LOCATION);
	katana_sprite_.x(100);
	katana_sprite_.y(100);
	
}

void Katana::Update(WindowManager* w)
{
	
}

void Katana::Render(WindowManager* w)
{
	// Draw the ptr_background_texture_image to the Scene2D object within RenderingEngine
	//katana_sprite_.Draw(w->getRenderer());
}

void Katana::printInfo() {

}