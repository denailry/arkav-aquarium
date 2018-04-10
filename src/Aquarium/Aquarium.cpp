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

void Aquarium::tickSnail(double delay) {
	this->snail->tick(coins, delay);
}

void Aquarium::printScreen() {
	return;
}

void Aquarium::addCoin(Coin &coin) {
	coins.add(coin);
	// addToScreen(coin);
}

void Aquarium::addFood(Food &food) {
	foods.add(food);
	// addToScreen(food);
}

void Aquarium::addGuppy(Guppy &guppy) {
	guppies.add(guppy);
	// addToScreen(guppy);
}

void Aquarium::addPiranha(Piranha &piranha) {
	piranhas.add(piranha);
	// addToScreen(piranha);
}

bool Aquarium::addToScreen(Entity &entity) {
	return true;
}

void Aquarium::setSnail(Snail *snail) {
	this->snail = snail;
	// addToScreen(snail);
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

void Aquarium::tick(double delay) 
{	return;
}

bool Aquarium::moveTo(int entityId, int entityType, int newX, int newY) {
	return false;
}
void Aquarium::remove(int entityId, int entityType) {
	return;
}
bool Aquarium::isExist(int entityId) {
	return false;
}