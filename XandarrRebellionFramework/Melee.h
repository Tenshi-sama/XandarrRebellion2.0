#ifndef MELEE_H
#define MELEE_H

#include "Window.h"
#include "Texture.h"
#include <string>

class Melee
{
private:
	string name_;
	string description_;
	unsigned int worth_;
	unsigned short weight_;
	unsigned short attack_power_;
	unsigned short movement_speed_;
	unsigned short attack_rate_;
	bool is_one_handed_;

public:
	Melee() {}
	Melee::~Melee() {}

	//Getters
	inline const string& getName() const { return name_; }
	inline unsigned int getWorth() const { return worth_; }
	inline unsigned short getWeight() const { return weight_; }
	inline const string& getDescription() const { return description_; }
	inline unsigned short getAttackPower() const { return attack_power_; }
	inline unsigned short getMovementSpeed() const { return movement_speed_; }
	inline unsigned short getAttackRate() const { return attack_rate_; }
	inline bool getIsOneHanded() const { return is_one_handed_; }

	//Setters
	inline void setName(const string& newValue) { name_ = newValue; }
	inline void setDescription(const string& newValue) { description_ = newValue; }
	inline void setWorth(const unsigned int newValue) { worth_ = newValue; }
	inline void setWeight(const unsigned short newValue) { weight_ = newValue; }
	inline void setAttackPower(const unsigned short newValue) { attack_power_ = newValue; }
	inline void setMovementSpeed(const unsigned short newValue) { movement_speed_ = newValue; }
	inline void setAttackRate(const unsigned short newValue) { attack_rate_ = newValue; }
	inline void setIsOneHanded(const bool newValue) { is_one_handed_ = newValue; }

	virtual void printInfo() = 0;

	virtual void Init(SDL_Renderer* r) = 0;
};

#endif