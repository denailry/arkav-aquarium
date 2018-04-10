#include "Aquarium.hpp"

Aquarium::Aquarium(int width, int height) {
	this->screen = new LinkedList<Entity>*[height];
	for (int i = 0; i < height; ++i) {
		screen[i] = new LinkedList<Entity>[width];
	}
	this->width = width;
	this->height = height;
}

Aquarium::Aquarium(Aquarium const &aquarium) {
	this->screen = new LinkedList<Entity>*[aquarium.height];
	for (int i = 0; i < height; ++i) {
		screen[i] = new LinkedList<Entity>[width];
	}
	this->width = width;
	this->height = height;
}

Aquarium::~Aquarium() {
	for (int i = 0; i < this->height; ++i) {
		delete screen[i];
	}
	delete screen;
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
		eGuppy->getInfo()->tick(foods, delay);
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

void Aquarium::printScreen() {
	return;
}

void Aquarium::addCoin(Coin *coin) {
	coins.add(coin);
	coin->setSpace(this);
}

void Aquarium::addFood(Food *food) {
	foods.add(food);
	food->setSpace(this);
}

void Aquarium::addGuppy(Guppy *guppy) {
	guppies.add(guppy);
	guppy->setSpace(this);
}

void Aquarium::addPiranha(Piranha *piranha) {
	piranhas.add(piranha);
	piranha->setSpace(this);
}

bool Aquarium::addToScreen(Entity &entity) {
	return true;
}

void Aquarium::setSnail(Snail *snail) {
	this->snail = snail;
	this->snail->setSpace(this);
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

void Aquarium::tick(double delay) {	
	tickCoins(delay);
	tickFoods(delay);
	tickGuppies(delay);
	tickPiranhas(delay);
	tickSnail(delay);
}

bool Aquarium::moveTo(int entityId, int entityType, double newX, double newY) {
	return (newX > 0 && newX < width && newY > 0 && newY < height);
}
void Aquarium::remove(int entityId, int entityType) {
	if (entityType == TYPE_COIN) {
		Element<Coin> *eCoin = coins.getFirst();
		int i = 0;
		while (eCoin != NULL) {
			if (eCoin->getInfo()->getId() == entityId) {\
				coins.remove(i);
				break;
			}
			eCoin = eCoin->getNext();
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