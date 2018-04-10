#include "Guppy.hpp"
#include <cmath>
#define LAPAR 20
#define KOIN 20
#define MATI 20
#define NGEGEDEIN 5

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
void Guppy::tick(LinkedList<Food> &foods, LinkedList<Coin> &coins, double delay){
	Food *food = findNearestFood(foods);
	if (((this->getTickTime())-lastCoin)>=KOIN){
		lastCoin=(this->getTickTime());
		if ((this->G)==1){
			Coin *a = new Coin(this->getX(),this->getY(),20,20,50);//value untuk koin harus selalu 50 untuk guppy tahap pertama
			a->setImage("koin-murah.png");
			coins.add(a);
		}else if ((this->G)==2){
			Coin *a = new Coin(this->getX(),this->getY(),20,20,75);//value untuk koin harus selalu 75 untuk guppy tahap kedua
			a->setImage("koin-sedang.png");
			coins.add(a);
		}else if ((this->G)==3){
			Coin *a = new Coin(this->getX(),this->getY(),20,20,100);//value untuk koin harus selalu 100 untuk guppy tahap ketiga
			a->setImage("koin-mahal.png");
			coins.add(a);
		}
	}
	if (this->hunger){
		if ((this->lastFed)>=LAPAR+MATI){
			this->getSpace()->remove(this->getId(), TYPE_GUPPY);
		}
		else{
			if (this->isAbleToConsume(*food)){
				this->getSpace()->remove(food->getId(), TYPE_FOOD);
				setLastFed(this->tickTime);
				setHunger(false);
				
			}
		}
	}else{
		
	}
}

Food* Guppy::findNearestFood(LinkedList<Food> &foods){
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

	return nearestFood;
}

bool Guppy::isAbleToConsume(Food const& food){ //belum diimplementasi
	return (this->getSpace())->isExist(food.getId(), TYPE_FOOD) && (
		(food.getX() > this->getLeft()) && 
		(food.getX() < this->getRight()) &&
		(food.getY() > this->getTop()) && 
		(food.getY() < this->getBottom())
	);
}