#include "Coin.hpp"
#include <cmath>

Coin::Coin(double x, double y, double width, double height, int nilai) : Item(x, y, width, height, TYPE_COIN){
	value = nilai;
	this->setDirection(atan(1)*4.0/2.0);
	this->setImage("koin-mahal.png");
}

int Coin::getValue(){ //mendapatkan nilai koin
	return value;
} 

void Coin::tick(double delay) {
	double newX = this->getX() + 250*cos(this->getDirection())*delay;
	double newY = this->getY() + 250*sin(this->getDirection())*delay;
	if (this->getSpace()->moveTo(this->getId(), TYPE_SNAIL, newX, newY)) {
		this->setX(newX);
	 	this->setY(newY);
	}
}