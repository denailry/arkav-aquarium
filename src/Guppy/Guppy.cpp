#include "Guppy.hpp"
#include <cmath>

double distanceWithFood(double pos1X, double pos1Y, double pos2X, double pos2Y) {
	double xDiff = std::abs(pos1X - pos2X);
	double yDiff = std::abs(pos1Y - pos2Y);
	return sqrt(xDiff*xDiff + yDiff*yDiff);
}

Guppy::Guppy(double x, double y, double width, double height) : Fish(x, y, width, height, TYPE_GUPPY) {
	setC(15);
	setG(small);
	setLastFed(this->tickTime);
	setLastCoin(this->tickTime);
}

//Get & set
int Guppy::getC() const{
	return this->C;
}

growth Guppy::getG() const{
	return this->G;
}

int Guppy::getLastFed() const{
	return this->lastFed;
}

int Guppy::getLastCoin() const{
	return this->lastCoin;
}

void Guppy::setC(int c){
	this->C = c;
}

void Guppy::setG(growth g){
	this->G = g;
}

void Guppy::setLastFed(int lf){
	this->lastFed = lf;
}

void Guppy::setLastCoin(int lc){
	this->lastCoin = lc;
}

//Service
void Guppy::tick(LinkedList<Food> const& foods, LinkedList<Coin> &newCoins, double delay){	//belum diimplementasi
	
}

Food& Guppy::findNearestFood(LinkedList<Food> &foods){
	Element<Food>* eFood = foods.getFirst();
	
	Food *nearestFood = eFood->getInfo();
	double minDistance = distanceWithFood(
		this->getX(),
		this->getY(),
		nearestFood->getX(), 
		nearestFood->getY());

	eFood = eFood->getNext();
	while (eFood != NULL) {
		double distance = distanceWithFood(
			this->getX(),
			this->getY(),
			eFood->getInfo()->getX(), 
			eFood->getInfo()->getY());
		if (distance < minDistance) {
			minDistance = distance;
			nearestFood = eFood->getInfo();
		}

		eFood = eFood->getNext();
	}

	return *nearestFood;
}

bool Guppy::isAbleToConsume(Food const& food){ //belum diimplementasi
	return (this->getSpace())->isExist(food.getId(), TYPE_FOOD) && (
		(food.getX() > this->getLeft()) && 
		(food.getX() < this->getRight()) &&
		(food.getY() > this->getTop()) && 
		(food.getY() < this->getBottom())
	);
}