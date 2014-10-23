#ifndef SRC_GAMEPLAYSTATE_H
#define SRC_GAMEPLAYSTATE_H

#include "GameState.h"
#include "GameStateManager.h"
#include "Button.h"
#include "Player.h"
#include "Enemy.h"
#include "NPC.h"
#include "HUD.h"
#include "Level.h"
#include "Item.h"
#include "TextWindow.h"
#include "HitBox.h"
#include "Inventory.h"


// Fourth and final GameState of the applicatoin
class GameplayState : public GameState 
{
private:
	//======================//
	//		Properties		//
	//======================//
	Player player_;
	Enemy enemy_;
	NPC npc_;
	Item item1_;
	Item item2_;
	TextWindow textWindow_;
	Level level_;
	HitBox hitbox_;
	Healthbarout Healthbarout_;
	Healthbarin Healthbarin_;
	XP xp_;
	PrintLevel printLevel_;
	Inventory inventory_;
	
	Timer state_life_timer_;
	unsigned int tmpTime;

	WindowManager* w;

	//======================//
	//		Behaviours		//
	//======================//

public:

	//GameplayState() : ptr_background_texture_(nullptr), is_winner_(false) {}

	// Gameplay state initialization method
	virtual void Init(WindowManager* w);

	// Gameplay state event handler method
	virtual void Clean();

	// Gameplay state event handler method
	virtual void HandleEvents(SDL_Event* event); 
	virtual void HandleEvents(WindowManager* w){}

	// Gameplay state logic update method
	virtual void Update(WindowManager* w);

	// Gameplay state render method
	virtual void Render(WindowManager* w);

	bool collide(Player* a, Enemy* b);
	bool collide(Player* a, NPC* b);
	bool collide(Player* a, Item* b);
	bool collide(Player* a, HitBox* b);
};
 
#endif