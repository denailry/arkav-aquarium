#include "Snail.hpp"
#include <cmath>

double distanceWith(int pos1X, int pos1Y, int pos2X, int pos2Y) {
	int xDiff = std::abs(pos1X - pos2X);
	int yDiff = std::abs(pos1Y - pos2Y);
	return sqrt(xDiff*xDiff + yDiff*yDiff);
}

Snail::Snail(int x, int y, int width, int height) : Entity(x, y, width, height, TYPE_SNAIL) {
	return;	
}

Coin Snail::findNearestCoin(LinkedList<Coin> &coins) {
	Element<Coin>* eCoin = coins.getFirst();
	
	Coin nearestCoin = eCoin->getInfo();
	double minDistance = distanceWith(
		this->getX(),
		this->getY(),
		nearestCoin.getX(), 
		nearestCoin.getY());

	eCoin = eCoin->getNext();
	while (eCoin != NULL) {
		double distance = distanceWith(
			this->getX(),
			this->getY(),
			eCoin->getInfo().getX(), 
			eCoin->getInfo().getY());
		if (distance < minDistance) {
			minDistance = distance;
			nearestCoin = eCoin->getInfo();
		}

		eCoin = eCoin->getNext();
	}

	return nearestCoin;
}

bool Snail::isAbleToConsume(Coin const& coin) {
	return (this->getSpace())->isExist(coin.getId()) && (
		(coin.getX() > this->getLeft()) && 
		(coin.getX() < this->getRight()) &&
		(coin.getY() > this->getTop()) && 
		(coin.getY() < this->getBottom())
	);
}

void Snail::tick(LinkedList<Coin> const& coins, int delay) {
	// int newX = this->getX() + 5*cos(0)*1;
	// int newY = y + 5*sin(0)*1;
	// this->getSpace()->moveTo(this->getId(), this->)
	return;
}