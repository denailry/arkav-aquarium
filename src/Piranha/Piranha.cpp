#include "Piranha.hpp"

Piranha::Piranha(double x, double y, double width, double height) : Fish(x, y, width, height, TYPE_PIRANHA){
	setLastFed(this->tickTime); 
}

int Piranha::getLastFed() const{
	return this->lastFed;
}

void Piranha::setLastFed(int lf){
	this->lastFed = lf;
}

void Piranha::tick(LinkedList<Guppy> const& guppies, double delay){	//belum diimplementasi
}

Guppy Piranha::findNearestGuppy(LinkedList<Guppy> const& guppies){
	Element<Guppy>* eGuppy = guppies.getFirst();
	
	Guppy nearestGuppy = eGuppy->getInfo();
	double minDistance = distanceWith(
		this->getX(),
		this->getY(),
		nearestGuppy.getX(), 
		nearestGuppy.getY());

	eGuppy = eGuppy->getNext();
	while (eGuppy != NULL) {
		double distance = distanceWith(
			this->getX(),
			this->getY(),
			eGuppy->getInfo().getX(), 
			eGuppy->getInfo().getY());
		if (distance < minDistance) {
			minDistance = distance;
			nearestGuppy = eGuppy->getInfo();
		}

		eGuppy = eGuppy->getNext();
	}

	return nearestGuppy;
}
    
bool Piranha::isAbleToConsume(Guppy const& guppy){
	return (this->getSpace())->isExist(guppy.getId()) && (
		(coin.getX() > this->getLeft()) && 
		(coin.getX() < this->getRight()) &&
		(coin.getY() > this->getTop()) && 
		(coin.getY() < this->getBottom())
	);
}
