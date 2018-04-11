#include "Piranha.hpp"
#include <cmath>
#include <iostream>

double pRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

double distanceWithGuppy(double pos1X, double pos1Y, double pos2X, double pos2Y) {
	double xDiff = std::abs(pos1X - pos2X);
	double yDiff = std::abs(pos1Y - pos2Y);
	return sqrt(xDiff*xDiff + yDiff*yDiff);
}

Piranha::Piranha(double x, double y, double width, double height) : Fish(x, y, width, height, TYPE_PIRANHA){
		setLastFed(this->tickTime);
		driftLength=200;
		lastDrift = this->tickTime;
		
		setDirection(pRand(0,8*atan(1)));
		if ((getDirection()>=2*atan(1))&&(getDirection()<=6*atan(1))){
			setDirRight(true);
		}else{
			setDirRight(false);
		}

		if (this->dirRight){	//menentukan gambar ikan yang dipakai
			this->setImage("piranha-right.png");
		}else{
			this->setImage("piranha-left.png");
		}
		
		this->setHunger(false);
}

int Piranha::getLastFed() const{
	return this->lastFed;
}

void Piranha::setLastFed(int lf){
	this->lastFed = lf;
}

void Piranha::tick(LinkedList<Guppy> const& guppies, LinkedList<Coin> &coins, double delay){	//belum diimplementasi
}

Guppy* Piranha::findNearestGuppy(LinkedList<Guppy> &guppies){
	Element<Guppy>* eGuppy = guppies.getFirst();
	if (eGuppy != NULL){
		Guppy *nearestGuppy = eGuppy->getInfo();
		double minDistance = distanceWithGuppy(
			this->getX(),
			this->getY(),
			nearestGuppy->getX(), 
			nearestGuppy->getY());

		eGuppy = eGuppy->getNext();
		while (eGuppy != NULL) {
			double distance = distanceWithGuppy(
				this->getX(),
				this->getY(),
				eGuppy->getInfo()->getX(), 
				eGuppy->getInfo()->getY());
			if (distance < minDistance) {
				minDistance = distance;
				nearestGuppy = eGuppy->getInfo();
			}

			eGuppy = eGuppy->getNext();
		}
		return nearestGuppy;
	}else{
		return NULL;
	}
}
    
bool Piranha::isAbleToConsume(Guppy const& guppy){	//belum diimplementasi
	return (this->getSpace())->isExist(guppy.getId(), TYPE_GUPPY) && (
		(guppy.getX() > this->getLeft()) && 
		(guppy.getX() < this->getRight()) &&
		(guppy.getY() > this->getTop()) && 
		(guppy.getY() < this->getBottom())
	);
}
