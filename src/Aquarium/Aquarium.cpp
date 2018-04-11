#include "Aquarium.hpp"
#include <iostream>

Aquarium::Aquarium(int width, int top, int bottom) {
	// this->screen = new LinkedList<Entity>*[height];
	// for (int i = 0; i < height; ++i) {
	// 	screen[i] = new LinkedList<Entity>[width];
	// }
	this->width = width;
	this->top = top;
	this->bottom = bottom;
	this->money = 0;
	this->objectCounter = 0;
	this->coinNumber = 0;
	this->foodNumber = 0;
	this->guppyNumber = 0;
	this->piranhaNumber = 0;
}

// Aquarium::Aquarium(Aquarium const &aquarium) {
// 	// this->screen = new LinkedList<Entity>*[aquarium.height];
// 	// for (int i = 0; i < height; ++i) {
// 	// 	screen[i] = new LinkedList<Entity>[width];
// 	// }
// 	// this->width = aquarium.;
// 	// this->height = top;
// 	// this->height = 
// 	// this->money = 0;
// }

Aquarium::~Aquarium() {
	// for (int i = 0; i < this->height; ++i) {
	// 	delete screen[i];
	// }
	// delete screen;
}

void Aquarium::tickCoins(double delay) {
	Element<Coin> *eCoin = coins.getFirst();
	while (eCoin != NULL) {
		eCoin->getInfo()->tick(delay);
		eCoin = eCoin->getNext();
	}
}

void Aquarium::tickFoods(double delay) {
	Element<Food> *eFood = foods.getFirst();
	while (eFood != NULL) {
		eFood->getInfo()->tick(delay);
		eFood = eFood->getNext();
	}
}

void Aquarium::tickGuppies(double delay) {
	Element<Guppy> *eGuppy = guppies.getFirst();
	while (eGuppy != NULL) {
		eGuppy->getInfo()->tick(foods, coins, delay);
		eGuppy = eGuppy->getNext();
	}
}

void Aquarium::tickPiranhas(double delay) {
	Element<Piranha> *ePiranha = piranhas.getFirst();
	while (ePiranha != NULL) {
		ePiranha->getInfo()->tick(guppies, delay);
		ePiranha = ePiranha->getNext();
	}
}

void Aquarium::tickSnail(double delay) {
	this->snail->tick(coins, delay);
}

// void Aquarium::printScreen() {
// 	return;
// }

void Aquarium::addCoin(Coin *coin) {
	coins.add(coin);
	coin->setSpace(this);
	coin->setId(this->objectCounter);
	this->objectCounter++;
	this->coinNumber++;
}

void Aquarium::addFood(Food *food) {
	foods.add(food);
	food->setSpace(this);
	food->setId(this->objectCounter);
	this->objectCounter++;
	this->foodNumber++;
}

void Aquarium::addGuppy(Guppy *guppy) {
	guppies.add(guppy);
	guppy->setSpace(this);
	guppy->setId(this->objectCounter);
	this->objectCounter++;
	this->guppyNumber++;
}

void Aquarium::addPiranha(Piranha *piranha) {
	piranhas.add(piranha);
	piranha->setSpace(this);
	piranha->setId(this->objectCounter);
	this->objectCounter++;
	this->piranhaNumber++;
}

bool Aquarium::addToScreen(Entity &entity) {
	return true;
}

void Aquarium::setSnail(Snail *snail) {
	this->snail = snail;
	this->snail->setSpace(this);
	this->snail->setId(this->objectCounter);
	this->objectCounter++;
}

LinkedList<Coin>& Aquarium::getCoins() {
	return this->coins;
}

LinkedList<Food>& Aquarium::getFoods() {
	return this->foods;
}

LinkedList<Guppy>& Aquarium::getGuppies() {
	return this->guppies;
}

LinkedList<Piranha>& Aquarium::getPiranhas() {
	return this->piranhas;
}

Snail& Aquarium::getSnail() {
	return *(this->snail);
}

int Aquarium::getWidth() {
	return this->width;
}
int Aquarium::getTop() {
	return this->top;
}
int Aquarium::getBottom() {
	return this->bottom;
}

bool Aquarium::buy(int price) {
	if (money < price) {
		return false;
	}
	money = money - price;
	return true;
}

void Aquarium::tick(double delay) {	
	tickCoins(delay);
	tickFoods(delay);
	tickGuppies(delay);
	tickPiranhas(delay);
	tickSnail(delay);
}

bool Aquarium::moveTo(int entityId, int entityType, double newX, double newY) {
	return (newX > 0 && newX < width && newY > this->top && newY < this->bottom);
}
void Aquarium::remove(int entityId, int entityType) {
	if (entityType == TYPE_COIN) {
		Element<Coin> *eCoin = coins.getFirst();
		int i = 0;
		while (eCoin != NULL) {
			if (eCoin->getInfo()->getId() == entityId) {
				this->money += eCoin->getInfo()->getValue();
				this->coinNumber--;
				coins.remove(i);
				break;
			}
			eCoin = eCoin->getNext();
			i++;
		}
	} else if (entityType == TYPE_FOOD) {
		Element<Food> *eFood = foods.getFirst();
		int i = 0;
		while (eFood != NULL) {
			if (eFood->getInfo()->getId() == entityId) {
				this->foodNumber--;
				foods.remove(i);
				break;
			}
			eFood = eFood->getNext();
			i++;
		}
	} else if (entityType == TYPE_GUPPY) {
		Element<Guppy> *eGuppy = guppies.getFirst();
		int i = 0;
		while (eGuppy != NULL) {
			if (eGuppy->getInfo()->getId() == entityId) {
				this->guppyNumber--;
				guppies.remove(i);
				break;
			}
			eGuppy = eGuppy->getNext();
			i++;
		}
	} else if (entityType == TYPE_PIRANHA) {
		Element<Piranha> *ePiranha = piranhas.getFirst();
		int i = 0;
		while (ePiranha != NULL) {
			if (ePiranha->getInfo()->getId() == entityId) {
				this->piranhaNumber--;
				piranhas.remove(i);
				break;
			}
			ePiranha = ePiranha->getNext();
			i++;
		}
	}
}

bool Aquarium::isExist(int entityId, int entityType) {
	if (entityType == TYPE_COIN) {
		Element<Coin> *eCoin = coins.getFirst();
		while (eCoin != NULL) {
			if (eCoin->getInfo()->getId() == entityId) {
				return true;
			}
			eCoin = eCoin->getNext();
		}
	}
	return false;
}