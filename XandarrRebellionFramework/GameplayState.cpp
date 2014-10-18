#include "GameplayState.h"
////////////////////////////////////////
// TEMP REMOVE ITEM2
////////////////////////////////////////
////////////////////////////////////////
// TEMP REMOVE ITEM2
////////////////////////////////////////
////////////////////////////////////////
// TEMP REMOVE ITEM2
////////////////////////////////////////
////////////////////////////////////////
// TEMP REMOVE ITEM2
////////////////////////////////////////
////////////////////////////////////////
// TEMP REMOVE ITEM2
////////////////////////////////////////
////////////////////////////////////////
// TEMP REMOVE ITEM2
////////////////////////////////////////
////////////////////////////////////////
// TEMP REMOVE ITEM2
////////////////////////////////////////
////////////////////////////////////////
// TEMP REMOVE ITEM2
////////////////////////////////////////
////////////////////////////////////////
// TEMP REMOVE ITEM2
////////////////////////////////////////

// Creates a new instance of Board and OutputPanel and loads the requisite
// resources for the Gameplay State.
void GameplayState::Init(WindowManager* w) {

	SDL_Renderer* wRend = w->getRenderer();
	cout << "|-->GameplayState::Init() Invoked" << endl;

	level_.Init(wRend);
	inventory_.Init(wRend);
	textWindow_.Init(wRend);
	player_.Init(wRend);
	enemy_.Init(wRend);
	npc_.Init(wRend);
	item1_.Init(wRend);

	////////////////////////////////////////
	// TEMP REMOVE ITEM2
	////////////////////////////////////////
	item2_.Init(wRend);
	Healthbarin_.Init(wRend);
	Healthbarout_.Init(wRend);
	xp_.Init(wRend);
	printLevel_.Init(wRend);

	item1_.name("Potion1");

	////////////////////////////////////////
	// TEMP REMOVE ITEM2
	////////////////////////////////////////
	item2_.name("Potion2");
	
	state_life_timer_.Start();
}

void GameplayState::Clean() {
	cout << "|-->GameplayState::Clean() Invoked" << endl;
}

// Handles all gameplay events
void GameplayState::HandleEvents(SDL_Event* event) {

	player_.HandleEvents(event); //Player events
	//enemy_.HandleEvents(event);

	switch (event->type) {
	case SDL_MOUSEBUTTONDOWN:
		if (event->button.button == SDL_BUTTON_LEFT) {
			cout << "|--> Mouse Click(" << event->button.x << ", " << event->button.y << ") | Current State: GameplayState" << endl;

			if (collide(&player_, &enemy_)) {
				while (player_.getCurrentHealth() > 0 && enemy_.getHealth() > 0) {
					enemy_.setHealth(enemy_.getHealth() - player_.getAtk());
					cout << "Enemy Health = " << enemy_.getHealth() << endl;
				}

				if (enemy_.getHealth() == 0) {
					enemy_.notVisible();
					cout << "Enemy down!!!\n";

					////////////////////////////////////////
					// TEMP REMOVE ITEM 2
					////////////////////////////////////////
					item2_.setXPos(enemy_.getXPos());
					item2_.setYPos(enemy_.getYPos());
					player_.addXp(enemy_.getXp());
				}
			}
		}
		break;

	case SDL_KEYDOWN:
		/*if (event->key.keysym.sym == SDLK_f) {
			cout << "|--> Toggle Fullscreen" << endl;
			if (w->isFullscreen()) {
			w->isFullscreen(false);
			} else {
			w->isFullscreen(true);
			}
			}*/
		if (event->key.keysym.sym == SDLK_r) {
			GameStateManager::setCurrentState(GAMESTATE_GAMEPLAY);
		}

		if (event->key.keysym.sym == SDLK_ESCAPE) {
			SDL_Quit();
		}

		if (event->key.keysym.sym == SDLK_i) {
			inventory_.printInventory();
		}

		break;
	}
}

void GameplayState::Update(WindowManager* w) {
	player_.Update(w);
	Healthbarin_.Update(w, &player_);
	xp_.Update(w);
	printLevel_.Update(w);
	inventory_.Update(w);

	if (collide(&player_, &enemy_)) {
		/*
		switch (w->getEvent()->type) {
		case SDL_MOUSEBUTTONDOWN:
		if (w->getEvent()->button.button == SDL_BUTTON_LEFT) {
		while (player_.getBaseHealth() > 0 && enemy_.getHealth() > 0){
		enemy_.setHealth(enemy_.getHealth() - player_.getBaseAttack());
		cout << "Enemy Health = " << enemy_.getHealth() << endl;
		}
		}
		}
		*/
		//enemy_.Moving(false);
		//enemy_.Attack();

		if (player_.getCurrentHealth() <= 0) {
			player_.notVisible();
			SDL_Quit();
		}

		if (player_.getCurrentHealth() > 0 && enemy_.getHealth() > 0) {
			if (((state_life_timer_.getTicks() % 1000) <= 20)) {
				player_.setCurrentHealth(player_.getCurrentHealth() - enemy_.getAtk());
				cout << "Player Health = " << player_.getCurrentHealth() << endl;
			}
		}
	} else {
		//enemy_.Moving(true);
	}

	if (collide(&player_, &npc_)) {
		npc_.Moving(false);
		npc_.Speech(w->getRenderer());
	} else {
		npc_.Moving(true);
	}

	////////////////////////////////////////
	// NEED TO FIX ITEM COLLIDES
	////////////////////////////////////////
	if (item1_.isVisible() && collide(&player_, &item1_)) {
		cout << "item1_ added to inventory\n";
		inventory_.addItem(item1_);
		item1_.notVisible();
	}

	if (item2_.isVisible() && collide(&player_, &item2_)) {
		cout << "item2_ added to inventory\n";
		inventory_.addItem(item2_);
		item2_.notVisible();
	}

	if (collide(&player_, &level_.getHitbox())) {
		player_.Update(w);
		Healthbarin_.Update(w, &player_);

		//The sides of the rectangles
		int leftA, leftB;
		int rightA, rightB;
		int topA, topB;
		int bottomA, bottomB;

		//Calculate the sides of rect A
		leftA = player_.getXPos();
		rightA = player_.getXPos() + player_.getWidth();
		topA = player_.getYPos();
		bottomA = player_.getYPos() + player_.getHeight();

		//Calculate the sides of rect B
		leftB = level_.getHitbox().getXPos();
		rightB = level_.getHitbox().getXPos() + level_.getHitbox().getWidth();
		topB = level_.getHitbox().getYPos();
		bottomB = level_.getHitbox().getYPos() + level_.getHitbox().getHeight();

		// checks if the player has collided with the bottom of the hitbox
		// and stops the player from moving up
		if ((topA == bottomB || (topA < bottomB && topA >topB)) && (leftA < rightB && leftA > leftB)) {
			cout << "collided with bottom of hitbox" << endl;
			player_.setLockUp(true);
		} else {
			player_.setLockUp(false);
		}

		// checks if the player has collided with the top of the hitbox
		// and stops the player from movind down
		if ((bottomA == topB || (bottomA > topB && bottomA < bottomB)) && (leftA < rightB && leftA > leftB)) {
			cout << "collided with top of hitbox" << endl;
			player_.setLockDown(true);
		} else {
			player_.setLockDown(false);
		}

		// checks if the player has collided with the left of the hitbox
		// and stops the player from moving right
		if ((rightA == leftB || (rightA > leftB && rightA < rightB)) && (topA < bottomB && topA > topB)) {
			cout << "collided with left of hitbox" << endl;
			player_.setLockRight(true);
		} else {
			player_.setLockRight(false);
		}

		// checks if the player has collided with the left of the hitbox
		// and stops the player from moving left
		if ((leftA == rightB || (leftA < rightB && leftA > leftB)) && (topA < bottomB && topA > topB)) {
			cout << "collided with right of hitbox" << endl;
			player_.setLockLeft(true);
		} else {
			player_.setLockLeft(false);
		}
	}
}

void GameplayState::Render(WindowManager* w) {

	//NOTE:
	// The order in which call draw is the order the objects are rendered.
	// Your player was being drawn first than the background, meaning the
	// the background was being drawn on top of it. Be careful of your
	// draw order!

	// Player
	level_.Render(w);
	enemy_.Render(w);
	inventory_.Render(w);
	npc_.Render(w);
	item1_.Render(w);
	item2_.Render(w);
	player_.Render(w);
	textWindow_.Render(w);
	Healthbarin_.Render(w);
	Healthbarout_.Render(w);
	xp_.Render(w);
	printLevel_.Render(w);
}

bool GameplayState::collide(Player* a, Enemy* b) {
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = a->getXPos();
	rightA = a->getXPos() + a->getWidth();
	topA = a->getYPos();
	bottomA = a->getYPos() + a->getHeight();

	//Calculate the sides of rect B
	leftB = b->getXPos();
	rightB = b->getXPos() + b->getWidth();
	topB = b->getYPos();
	bottomB = b->getYPos() + b->getHeight();//If any of the sides from A are outside of B

	if (bottomA <= topB) {
		return false;
	}

	if (topA >= bottomB) {
		return false;
	}

	if (rightA <= leftB) {
		return false;
	}

	if (leftA >= rightB) {
		return false;
	}

	return true;
}

bool GameplayState::collide(Player* a, NPC* b) {
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = a->getXPos();
	rightA = a->getXPos() + a->getWidth();
	topA = a->getYPos();
	bottomA = a->getYPos() + a->getHeight();

	//Calculate the sides of rect B
	leftB = b->getXPos();
	rightB = b->getXPos() + b->getWidth();
	topB = b->getYPos();
	bottomB = b->getYPos() + b->getHeight();//If any of the sides from A are outside of B

	if (bottomA <= topB) {
		return false;
	}

	if (topA >= bottomB) {
		return false;
	}

	if (rightA <= leftB) {
		return false;
	}

	if (leftA >= rightB) {
		return false;
	}

	return true;
}

bool GameplayState::collide(Player* a, Item* b) {
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = a->getXPos();
	rightA = a->getXPos() + a->getWidth();
	topA = a->getYPos();
	bottomA = a->getYPos() + a->getHeight();

	//Calculate the sides of rect B
	leftB = b->getXPos();
	rightB = b->getXPos() + b->getWidth();
	topB = b->getYPos();
	bottomB = b->getYPos() + b->getHeight();//If any of the sides from A are outside of B

	if (bottomA <= topB) {
		return false;
	}

	if (topA >= bottomB) {
		return false;
	}

	if (rightA <= leftB) {
		return false;
	}

	if (leftA >= rightB) {
		return false;
	}

	return true;
}

bool GameplayState::collide(Player* a, HitBox* b) {
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = a->getXPos();
	rightA = a->getXPos() + a->getWidth();
	topA = a->getYPos();
	bottomA = a->getYPos() + a->getHeight();

	//Calculate the sides of rect B
	leftB = b->getXPos();
	rightB = b->getXPos() + b->getWidth();
	topB = b->getYPos();
	bottomB = b->getYPos() + b->getHeight();//If any of the sides from A are outside of B

	if (bottomA <= topB) {
		a->setLockDown(false);
		return false;
	}

	if (topA >= bottomB) {
		a->setLockUp(false);
		return false;
	}

	if (rightA <= leftB) {
		a->setLockRight(false);
		return false;
	}

	if (leftA >= rightB) {
		a->setLockLeft(false);
		return false;
	}

	return true;
}