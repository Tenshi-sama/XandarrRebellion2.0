#include "Player.h"

#define ENEMY_WIDTH 100
#define ENEMY_HEIGHT 100
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 544
#define TILE_HEIGHT 32
#define TILE_WIDTH 32
#define SPRITE_WIDTH 32
#define SPRITE_HEIGHT 32
#define STEP 8

Player::Player() : SPRITE_LOCATION("_resources\\Player_.png"), SPRITE_UP("_resources\\PlayerUp.png"),
SPRITE_DOWN("_resources\\PlayerDown.png"),
SPRITE_LEFT("_resources\\PlayerLeft.png"),
SPRITE_RIGHT("_resources\\PlayerRight.png"),
velX(8), velY(8), MoveRight(false),
MoveLeft(false), MoveUp(false), MoveDown(false),
LockRight(false), LockLeft(false), LockUp(false),
LockDown(false), xp_(10) {
	setCurrentHealth(100);
	setMaxHealth(100);
	setAtk(10);
	setAgility(5);
	setStrength(5);
	setIntelligence(5);
	setConstitution(5);
	setHitPercentBase(70);
	setIsWeaponEquipped(false);
}

void Player::Init(SDL_Renderer* r) {
	sprite_.LoadTexture(r, SPRITE_LOCATION);
	sprite_.x(TILE_WIDTH * 2);
	sprite_.y(TILE_HEIGHT * 3);
}

// Handles all gameplay events
void Player::HandleEvents(SDL_Event* event) {
	//cout << "Update! ... MovingLeft is: " << movingLeft << endl;

	switch (event->type) {
	case SDL_KEYDOWN:
		// Change States when Escape is pressed
		if (event->key.keysym.sym == SDLK_w || event->key.keysym.sym == SDLK_UP) {
			// move functionality for up
			//position_y--;
			MoveUp = true;
		}
		if (event->key.keysym.sym == SDLK_s || event->key.keysym.sym == SDLK_DOWN) {
			// move functionality for down
			MoveDown = true;
		}
		if (event->key.keysym.sym == SDLK_a || event->key.keysym.sym == SDLK_LEFT) {
			// move functionality for left strafe
			MoveLeft = true;
		}
		if (event->key.keysym.sym == SDLK_d || event->key.keysym.sym == SDLK_RIGHT) {
			// move functionality for right strafe
			MoveRight = true;
		}
		if (event->key.keysym.sym == SDLK_SPACE) {
			cout << "Space pressed" << endl;
			//base_attack
			/*if (is_weapon_equipped_ == false)
			{
			base_attack_;
			}

			if ((is_weapon_equipped_ == true) && current_weapon_)
			{
			current_weapon_->getAttackPower();
			}*/
		}
		break;

	case SDL_KEYUP:
		if (event->key.keysym.sym == SDLK_w || event->key.keysym.sym == SDLK_UP) {
			// move functionality for up
			//position_y--;
			MoveUp = false;
		}
		if (event->key.keysym.sym == SDLK_s || event->key.keysym.sym == SDLK_DOWN) {
			// move functionality for down
			MoveDown = false;
		}
		if (event->key.keysym.sym == SDLK_a || event->key.keysym.sym == SDLK_LEFT) {
			// move functionality for left strafe
			MoveLeft = false;
		}
		if (event->key.keysym.sym == SDLK_d || event->key.keysym.sym == SDLK_RIGHT) {
			// move functionality for right strafe
			MoveRight = false;
		}
		break;
	}

	if (MoveRight && !LockRight) {
		if (sprite_.x() <= SCREEN_WIDTH - SPRITE_WIDTH) {
			//sprite_.visible(false);
			//sprite_.LoadTexture(r, SPRITE_RIGHT);
			sprite_.x(sprite_.x() + velX);
			//setSpriteLocation("_resources\\PlayerRight");
			//cout << "SPRITE_LOCATION is now: " << SPRITE_LOCATION << endl;
		}
	}
	if (MoveLeft && !LockLeft) {
		if (sprite_.x() >= SCREEN_WIDTH - SCREEN_WIDTH) {
			sprite_.x(sprite_.x() - velX);
			//setSpriteLocation("_resources\\PlayerLeft");
		}
	}
	if (MoveDown && !LockDown) {
		if (sprite_.y() <= SCREEN_HEIGHT - SPRITE_HEIGHT) {
			sprite_.y(sprite_.y() + velY);
			//setSpriteLocation("_resources\\PlayerDown");
		}
	}
	if (MoveUp && !LockUp) {
		if (sprite_.y() >= SCREEN_HEIGHT - SCREEN_HEIGHT) {
			//sprite_.LoadTexture(r, SPRITE_UP);
			//sprite_.x(sprite_.x());
			sprite_.y(sprite_.y() - velY);
			//setSpriteLocation("_resources\\PlayerForward");
		}
	}
}

// From turn five onwards, checks if there has been a winner.
void Player::Update(WindowManager* w) {
	//update hit percent
	hitPercent_ = (rand() % getHitPercentBase() + 1) + strength_ + atk_;

	//SPRITE_LOCATION;
}

void Player::Render(WindowManager* w) {

	// Draw the ptr_background_texture_image to the Scene2D object within RenderingEngine
	sprite_.Draw(w->getRenderer());


}

void Player::addXp(unsigned int newValue) {
	for (unsigned int i = 0; i < newValue; i++) {
		xp_++;
		chkLvl();
	}
}

void Player::chkLvl() {
	if ((getXp() % 1000) == 0) {
		addLvl(1);
		cout << "you leveled!!\n";
	}
}