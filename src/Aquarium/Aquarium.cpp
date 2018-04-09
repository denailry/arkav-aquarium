#include "Aquarium.hpp";

Aquarium::Aquarium(int width, int height) {
	this->screen = new LinkedList<Entity>[height];
	for (int i = 0; i < height; ++i) {
		screen[i] = new LinkedList<Entity>[width];
	}
	this->width = width;
	this->height = height;
}

Aquarium::Aquarium(Aquarium const &aquarium) {
	this->screen = new LinkedList<Entity>[aquarium.height];
	for (int i = 0; i < height; ++i) {
		screen[i] = new LinkedList<Entity>[width];
	}
	this->width = width;
	this->height = height;
}

Aquarium::~Aquarium() {
	for (int i = 0; i < this->height; ++i) {
		for (int j = 0; j < this->width; ++j) {
			delete screen[i][j];
		}
	}
}

void Aquarium::printScreen() {
	return;
}

void Aquarium::addCoin(Coin const &coin) {
	coins.add(coin);
	addToScreen(coin);
}

void Aquarium::addFood(Food const &food) {
	foods.add(food);
	addToScreen(food);
}

void Aquarium::addGuppy(Guppy const& guppy) {
	guppies.add(guppy);
	addToScreen(guppy);
}

void Aquarium::addPiranha(Piranha const& piranha) {
	piranhas.add(piranha);
	addToScreen(piranha);
}

void Aquarium::setSnail(Snail const& snail) {
	this->snail = snail;
	addToScreen(snail);
}

LinkedList<Coin> Aquarium::getCoins() const {
	return this->coins;
}

LinkedList<Food> Aquarium::getFoods() const {
	return this->foods;
}

LinkedList<Guppy> Aquarium::getGuppies() const {
	return this->guppies;
}

LinkedList<Piranha> Aquarium::getPiranhas() const {
	return this->piranhas;
}

Snail Aquarium::getSnail() const {
	return this->snail;
}

void Aquarium::tick() {
	return;
}

bool Aquarium::moveTo(int entityId, int entityType, int newX, int newY) {
	return false;
}
void remove(int entityId, int entityType) {
	return;
}