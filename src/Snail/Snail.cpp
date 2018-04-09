#include "Snail.hpp"
#include <cmath>

double distanceWith(int posX, int posY) {
	int xDiff = abs(this.getX() - posX);
	int yDiff = abs(this.getY() - posY);
	return sqrt(xDiff*xDiff + yDiff*yDiff);
}

Coin Snail::findNearestCoin(LinkedList<Coin> const& coins) {
	Element<Coin> eCoin = coins.first;
	
	Coin nearestCoin = eCoin.getInfo();
	double minDistance = this->distanceWith(
		nearestCoin.getX(), 
		nearestCoin.getY());

	eCoin = eCoin.getNext();
	while (eCoin != null) {
		double distance = this->distanceWith(
			eCoin.getInfo().getX(), 
			eCoin.getInfo().getY());
		if (distance < minDistance) {
			minDistance = distance;
			nearestCoin = eCoin.getInfo();
		}

		eCoin = eCoin.getNext();
	}

	return nearestCoin;
}

bool Snail::isAbleToConsume(Coin const& coin) {
	return (coin != null) && (coin.getX() > this->getLeft() && coin.getX() < this->getRight()
		coin.getY() > this->getTop() && coin.getY() < this->getBottom());
}