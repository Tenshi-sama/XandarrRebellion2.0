#ifndef SRC_PLAYER_H
#define SRC_PLAYER_H

#include "Texture.h"
#include "Window.h"


class Player 
{
private:
	//======================//
	//		Properties		//
	//======================//
	const string SPRITE_LOCATION;
	const string SPRITE_LEFT;
	const string SPRITE_RIGHT;
	const string SPRITE_DOWN;
	const string SPRITE_UP;
	Texture sprite_;

	static const int VEL = 4;

	int velX;
	int velY;

	bool MoveRight;
	bool MoveLeft;
	bool MoveUp;
	bool MoveDown;

	// stops the player from moving right, left, up or down
	bool LockRight;
	bool LockLeft;
	bool LockUp;
	bool LockDown;

	unsigned int atk_;
	unsigned int def_;
	unsigned int lvl_;
	unsigned int xp_;
	unsigned int currentHealth_;
	unsigned int maxHealth_;
	unsigned int halfWidth_;
	unsigned int halfHeight_;

	unsigned short agility_;
	unsigned short strength_;
	unsigned short intelligence_;
	unsigned short constitution_;

	bool is_weapon_equipped_;

	//WindowManager* w;
	SDL_Renderer* r;

public:
	// Ctor and Dtor
	Player();
	~Player() {}

	inline int getCurrentHealth() const { return currentHealth_; }
	inline int getMaxHealth() const { return maxHealth_; }
	inline unsigned int getAtk() const { return atk_; }
	inline unsigned short getAgility() const { return agility_; }
	inline unsigned short getStrength() const { return strength_; }
	inline unsigned short getIntelligence() const { return intelligence_; }
	inline unsigned short getConstitution() const { return constitution_; }
	inline bool getIsWeaponEquipped() const { return is_weapon_equipped_; }
	inline unsigned int getLvl() const { return lvl_; }
	inline unsigned int getXp() const { return xp_; }
	//inline string getSpriteLocation() const { return SPRITE_LOCATION; }

	inline bool getLockDown() { return LockDown; }
	inline bool getLockUp() { return LockUp; }
	inline bool getLockLeft() { return LockLeft; }
	inline bool getLockRight() { return LockRight; }
	inline void setLockDown(bool newValue) { LockDown = newValue; }
	inline void setLockUp(bool newValue) { LockUp = newValue; }
	inline void setLockLeft(bool newValue) { LockLeft = newValue; }
	inline void setLockRight(bool newValue) { LockRight = newValue; }

	inline void setCurrentHealth(const unsigned int newValue) { currentHealth_ = newValue; }
	inline void setMaxHealth(const unsigned int newValue) { maxHealth_ = newValue; }
	inline void setAtk(const unsigned int newValue) { atk_ = newValue; }
	inline void setAgility(const unsigned short newValue) { agility_ = newValue; }
	inline void setStrength(const unsigned short newValue) { strength_ = newValue; }
	inline void setIntelligence(const unsigned short newValue) { intelligence_ = newValue; }
	inline void setConstitution(const unsigned short newValue) { constitution_ = newValue; }
	inline void setIsWeaponEquipped(const bool newValue) { is_weapon_equipped_ = newValue; }
	//inline void setSpriteLocation(const string newValue) { SPRITE_LOCATION == newValue; }

	inline void setLvl(const unsigned int newValue) { lvl_ = newValue; }
	inline void addLvl(unsigned int newValue) { lvl_ += newValue; }
	inline void remLvl(const unsigned int newValue) { lvl_ -= newValue; }
	void chkLvl();
	inline void setXp(const unsigned int newValue) { xp_ = newValue; }
	void addXp(unsigned int newValue);
	inline void remXp(const unsigned int newValue) { xp_ -= newValue; }


	inline int getXPos() { return sprite_.x(); }
	inline int getYPos() { return sprite_.y(); }
	inline int getWidth() { return sprite_.width(); }
	inline int getHeight() { return sprite_.height(); }

	inline void setXPos(const int newValue) { sprite_.x(newValue); }
	inline void setYPos(const int newValue) { sprite_.y(newValue); }
	inline void setWidth() { sprite_.width(); }
	inline void setHeight() { sprite_.height(); }

	inline void notVisible() { return sprite_.visible(false); }


	//======================//
	//		Behaviours		//
	//======================//
	void Init(SDL_Renderer* r);
	void HandleEvents(SDL_Event* event);
	void Update(WindowManager* w);
	void Render(WindowManager* w);
};

#endif