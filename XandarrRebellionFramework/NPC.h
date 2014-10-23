#ifndef SRC_NPC_H
#define SRC_NPC_H

#include "Texture.h"
#include "Timer.h"
#include "Window.h"


class NPC 
{
private:
	//======================//
	//		Properties		//
	//======================//
	const string SPRITE_LOCATION;
	Texture sprite_;
	Texture text_;
	Texture text2_;
	Texture text3_;
	Texture text4_;
	
	Timer state_life_timer_;

public:
	// Ctor and Dtor
	NPC() : SPRITE_LOCATION("_resources/npc.png"){}
	~NPC(){};

	//======================//
	//		Behaviours		//
	//======================//
	void Init(SDL_Renderer* r);
	//void HandleEvents(SDL_Event* event);
	void Update(WindowManager* w);
	void Render(WindowManager* w);
	void MoveLeft(Texture *theSprite);
	void MoveRight(Texture *theSprite);

	bool Moving(bool);

	void Speech(SDL_Renderer* r);

	inline void notVisible() { return text_.visible(false); }

	inline int getXPos() { return sprite_.x(); }
	inline int getYPos() { return sprite_.y(); }
	inline int getWidth() { return sprite_.width(); }
	inline int getHeight() { return sprite_.height(); }

	inline void setXPos() { sprite_.x(); }
	inline void setYPos() { sprite_.y(); }
	inline void setWidth() { sprite_.width(); }
	inline void setHeight() { sprite_.height(); }
};

#endif