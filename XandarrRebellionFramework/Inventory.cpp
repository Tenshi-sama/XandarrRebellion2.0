#include "Inventory.h"

void Inventory::Init(SDL_Renderer* r) {
	invBox_.LoadTexture(r, SPRITE_LOCATION);
	invBox_.alpha(150);
	invBox_.x(0);
	invBox_.y(460);
	invBox_.scaleX(800);
	invBox_.scaleY(85);

	invBox_.visible(false);
}

void Inventory::HandleEvents(SDL_Event* event, Player* player_) {
	//check if mouse is within the item in the enventory AND clicked (the event passed is mouse click)

	vector<Item *>::iterator invIter = inventory_space_.begin();

	for (; invIter != inventory_space_.end(); invIter++) {
		if (!((*invIter)->getTexture()->texture() == nullptr) && (*invIter)->getVisible() && (event->motion.x >= (*invIter)->getXPos() && event->motion.x <= ((*invIter)->getXPos() + (*invIter)->getWidth())) && (event->motion.y >= (*invIter)->getYPos() && event->motion.y <= ((*invIter)->getYPos() + (*invIter)->getHeight()))) {
			if (player_->getCurrentHealth() < player_->getMaxHealth()) {
				cout << "Player is healed " << (*invIter)->heal() << " health!\n";
				player_->setCurrentHealth(player_->getCurrentHealth() + (*invIter)->heal());
				(*invIter)->setVisible(false);

				invIter = inventory_space_.erase(invIter);
				printInventory(); //this is called twice to reset the inventory screen
				printInventory();

				break;//yes, yes i know, a break; well its either this or problems with the iterator :/
			} else {
				cout << "You're already at full health!\n";
			}

		}
	}
}

void Inventory::Update(WindowManager* w) {
	printInventory(); //this is called twice to reset the inventory screen
	printInventory();
}

void Inventory::Render(WindowManager* w) {
	invBox_.Draw(w->getRenderer());
}

void Inventory::addItem(Item* newItem) {
	current_weight_ += newItem->weight();

	bool uniqueItem = true;

	vector<Item *>::iterator invIter = inventory_space_.begin();

	if (newItem->isStackable() == true && !inventory_space_.empty()) {
		for (; invIter != inventory_space_.end(); invIter++) {
			if (newItem->name() == (*invIter)->name() && !(*invIter)->isFull()) {
				(*invIter)->stackSize((*invIter)->stackSize() + 1);
				uniqueItem = false;

				break;
			}
		}
	}

	if (uniqueItem == true || newItem->isStackable() == false) {
		inventory_space_.push_back(newItem);
	}
}

void Inventory::clearInventory() {
	//inventory_space_.erase(inventory_space_.begin(), inventory_space_.end());
	inventory_space_.clear();
}

void Inventory::removeItem(string itemName) {
	int j = 0;
	bool fullRemove = true;
	vector<Item *> tmpInv(inventory_space_.size() - 1);
	vector<Item *>::iterator invIter;

	for (invIter = inventory_space_.begin(); invIter != inventory_space_.end(); invIter++) {
		if (itemName == (*invIter)->name()) {
			current_weight_ -= (*invIter)->weight();

			if ((*invIter)->isStackable() == true && (*invIter)->stackSize() > 1) {
				fullRemove = false;
				(*invIter)->stackSize((*invIter)->stackSize() - 1);
			} else {
				delete *invIter;
				*invIter = nullptr;
			}

			break;
		}
	}

	if (fullRemove == true) {
		for (invIter = inventory_space_.begin(); invIter != inventory_space_.end(); invIter++) {
			if (*invIter != nullptr) {
				tmpInv.at(j) = *invIter;
				j++;
			}
		}

		inventory_space_.clear();

		inventory_space_ = vector<Item *>(tmpInv);
	}

	printInventory(); //this is called twice to reset the inventory screen
	printInventory();
}

void Inventory::printInventory() {
	vector<Item *>::iterator invIter = inventory_space_.begin();

	unsigned short invItemX = invBox_.x() + 10;
	unsigned short invItemY = invBox_.y() + 20;

	if (invBox_.visible()) {
		invBox_.visible(false);
	} else {
		invBox_.visible(true);
	}

	for (; invIter != inventory_space_.end(); invIter++) {
		(*invIter)->setXPos(invItemX);
		(*invIter)->setYPos(invItemY);

		if (invBox_.visible()) {
			(*invIter)->setVisible(true);
		} else {
			(*invIter)->setVisible(false);
		}

		invItemX += 60;
	}
}

bool Inventory::isFull() const {
	if (current_weight_ >= capacity_) {
		return true;
	} else {
		return false;
	}
}