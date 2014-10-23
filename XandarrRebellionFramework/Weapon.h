#ifndef WEAPON_H
#define WEAPON_H

#include "Texture.h"
#include "Window.h"
#include <iostream>
#include <string>

using namespace std;

class Weapon
{
private:
	string name_;
	string description_;
	unsigned int worth_;
	unsigned short weight_;
	//unsigned short stack_size_;
	//unsigned short max_stack_size_;
	unsigned short attack_power_;
	unsigned short agility_;
	unsigned short attack_rate_;
	bool is_one_handed_;

public:
	Weapon() {}
	Weapon::~Weapon() {}

	//inline bool getIsFull() const { return (max_stack_size_ - stack_size_ == 0); }
	//inline bool getIsStackable() const { return (max_stack_size_ > 1); }
	inline const string& getName() const { return name_; }
	inline unsigned int getWorth() const { return worth_; }
	inline unsigned short getWeight() const { return weight_; }
	//inline unsigned short getStackSize() const { return stack_size_; }
	inline const string& getDescription() const { return description_; }
	//inline unsigned short getMaxStackSize() const { return max_stack_size_; }
	inline unsigned short getAttackPower() const { return attack_power_; }
	inline unsigned short getAgility() const { return agility_; }
	inline unsigned short getAttackRate() const { return attack_rate_; }
	inline bool getIsOneHanded() const { return is_one_handed_; }

	inline void setName(const string& newValue) { name_ = newValue; }
	inline void setDescription(const string& newValue) { description_ = newValue; }
	inline void setWorth(const unsigned int newValue) { worth_ = newValue; }
	inline void setWeight(const unsigned short newValue) { weight_ = newValue; }
	//inline void setStackSize(const unsigned short newValue) { stack_size_ = newValue; }
	//inline void setMaxStackSize(const unsigned short newValue) { max_stack_size_ = newValue; }
	inline void setAttackPower(const unsigned short newValue) { attack_power_ = newValue; }
	inline void setAgility(const unsigned short newValue) { agility_ = newValue; }
	inline void setAttackRate(const unsigned short newValue) { attack_rate_ = newValue; }
	inline void setIsOneHanded(const bool newValue) { is_one_handed_ = newValue; }

	virtual void printInfo() = 0;
};

#endif