#include "Guppy.hpp"

Guppy::Guppy(int x, int y, int width, int height) : Fish(x, y, width, height, TYPE_GUPPY) {
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
void Guppy::tick(LinkedList<Food> const& foods){	//belum diimplementasi

}

Food findNearestFood(LinkedList<Food> const& foods){	//belum diimplementasi
	Food f(1, 2, 3, 4);
	return f;
}

bool isAbleToConsume(Food const& food){ //belum diimplementasi
	return true;
}