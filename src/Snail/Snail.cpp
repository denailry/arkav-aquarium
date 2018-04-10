#include "Snail.hpp"
#include <cmath>
#include <stdlib.h>
#include <time.h>

double DIRECTION[2];
int DIR_INDEX;
std::string IMAGE[2];

double distanceWith(double pos1X, double pos1Y, double pos2X, double pos2Y) {
	double xDiff = std::abs(pos1X - pos2X);
	double yDiff = std::abs(pos1Y - pos2Y);
	return sqrt(xDiff*xDiff + yDiff*yDiff);
}

Snail::Snail(double x, double y, double width, double height) : Entity(x, y, width, height, TYPE_SNAIL) {
	srand(time(NULL));
	DIRECTION[0] = 0;
	DIRECTION[1] = atan(1)*4;
	IMAGE[0] = "snail-small-right.png";
	IMAGE[1] = "snail-small-left.png";
	DIR_INDEX = rand() % 2;
	this->setDirection(DIRECTION[DIR_INDEX]);
	this->setImage(IMAGE[DIR_INDEX]);
	return;	
}

Coin& Snail::findNearestCoin(LinkedList<Coin> &coins) {
	Element<Coin>* eCoin = coins.getFirst();
	
	Coin *nearestCoin = eCoin->getInfo();
	double minDistance = distanceWith(
		this->getX(),
		this->getY(),
		nearestCoin->getX(), 
		nearestCoin->getY());

	eCoin = eCoin->getNext();
	while (eCoin != NULL) {
		double distance = distanceWith(
			this->getX(),
			this->getY(),
			eCoin->getInfo()->getX(), 
			eCoin->getInfo()->getY());
		if (distance < minDistance) {
			minDistance = distance;
			nearestCoin = eCoin->getInfo();
		}

		eCoin = eCoin->getNext();
	}

	return *nearestCoin;
}

bool Snail::isAbleToConsume(Coin const& coin) {
	return (this->getSpace())->isExist(coin.getId()) && (
		(coin.getX() > this->getLeft()) && 
		(coin.getX() < this->getRight()) &&
		(coin.getY() > this->getTop()) && 
		(coin.getY() < this->getBottom())
	);
}

void Snail::tick(LinkedList<Coin> const& coins, double delay) {
	double newX = this->getX() + 200*cos(this->getDirection())*delay;
	double newY = this->getY() + 200*sin(this->getDirection())*delay;
	if (this->getSpace()->moveTo(this->getId(), TYPE_SNAIL, newX, newY)) {
		this->setX(newX);
		this->setY(newY);
	} else {
		DIR_INDEX = (DIR_INDEX + 1) % 2;
		this->setDirection(DIRECTION[DIR_INDEX]);
		this->setImage(IMAGE[DIR_INDEX]);
	}
}