#include "Guppy.hpp"

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
void Guppy::tick(LinkedList<Food> const& foods, double delay){	//belum diimplementasi
	
}

Food findNearestFood(LinkedList<Food> const& foods){
	Element<Food>* eFood = foods.getFirst();
	
	Food nearestFood = eFood->getInfo();
	double minDistance = distanceWith(
		this->getX(),
		this->getY(),
		nearestFood.getX(), 
		nearestFood.getY());

	eFood = eFood->getNext();
	while (eFood != NULL) {
		double distance = distanceWith(
			this->getX(),
			this->getY(),
			eFood->getInfo().getX(), 
			eFood->getInfo().getY());
		if (distance < minDistance) {
			minDistance = distance;
			nearestFood = eFood->getInfo();
		}

		eFood = eFood->getNext();
	}

	return nearestFood;
}

bool isAbleToConsume(Food const& food){ 
	return (this->getSpace())->isExist(food.getId()) && (
		(coin.getX() > this->getLeft()) && 
		(coin.getX() < this->getRight()) &&
		(coin.getY() > this->getTop()) && 
		(coin.getY() < this->getBottom())
	);
}