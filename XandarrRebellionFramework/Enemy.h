#ifndef SRC_ENEMY_H
#define SRC_ENEMY_H

#include "Texture.h"
#include "Window.h"


class Enemy {
private:
	//======================//
	//		Properties		//
	//======================//
	const string SPRITE_LOCATION;
	Texture sprite_;

	unsigned int xp_;
	unsigned int atk_;
	unsigned int def_;
	unsigned int health_;
	unsigned int halfWidth_;
	unsigned int halfHeight_;

	unsigned short hitPercentbase_;
	unsigned short hitPercent_;

public:
	// Ctor and Dtor
	Enemy();
	~Enemy() {};



	//======================//
	//		Behaviours		//
	//======================//
	void Init(SDL_Renderer* r);
	void Update(WindowManager* w);
	void Render(WindowManager* w);
	void MoveLeft(Texture *theSprite);
	void MoveRight(Texture *theSprite);

	void Attack();

	inline void notVisible() { return sprite_.visible(false); }

	// GETTERS
	inline int getXPos() { return sprite_.x(); }
	inline int getYPos() { return sprite_.y(); }
	inline int getWidth() { return sprite_.width(); }
	inline int getHeight() { return sprite_.height(); }
	inline unsigned int getXp() { return xp_; }
	inline unsigned short getAtk() const { return atk_; }
	inline unsigned short getDef() const { return def_; }
	inline unsigned short getHealth() const { return health_; }
	inline bool getIsDead() { if (health_ <= 0) { return true; } else { return false; } }
	inline unsigned short getHitPercentBase() { return hitPercentbase_; }
	inline unsigned short getHitPercent() { return hitPercent_; }

	// SETTERS
	inline void setXPos() { sprite_.x(); }
	inline void setYPos() { sprite_.y(); }
	inline void setWidth() { sprite_.width(); }
	inline void setHeight() { sprite_.height(); }
	inline void setXp(unsigned int newValue) { xp_ = newValue; }
	inline void setAtk(const unsigned short newValue) { atk_ = newValue; }
	inline void setDef(const unsigned short newValue) { def_ = newValue; }
	inline void setHealth(const unsigned short newValue) { health_ = newValue; }
	inline void setHitPercentBase(unsigned short newValue) { hitPercentbase_ = newValue; }
	inline void setHitPercent(unsigned short newValue) { hitPercent_ = newValue; }
};

#endif