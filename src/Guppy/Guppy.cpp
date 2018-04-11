#include "Guppy.hpp"
#include <cmath>
#include <time.h>
#include <iostream>
using namespace std;

#define LAPAR 200
#define KOIN 640
#define MATI 2000
#define NGEGEDEIN 5

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

double distanceWithFood(double pos1X, double pos1Y, double pos2X, double pos2Y) {
	double xDiff = std::abs(pos1X - pos2X);
	double yDiff = std::abs(pos1Y - pos2Y);
	return sqrt(xDiff*xDiff + yDiff*yDiff);
}

Guppy::Guppy(double x, double y, double width, double height) : Fish(x, y, width, height, TYPE_GUPPY) {
	setC(640);
	setG(1);
	growthCounter=0;
	setLastFed(this->tickTime);
	setLastCoin(this->tickTime);
	driftLength=200;
	lastDrift = this->tickTime;
	
	setDirection(fRand(0,8*atan(1)));
	if ((getDirection()>=2*atan(1))&&(getDirection()<=6*atan(1))){
		setDirRight(true);
	}else{
		setDirRight(false);
	}

	if (this->dirRight){	//menentukan gambar ikan yang dipakai
		this->setImage("small-guppy-right.png");
	}else{
		this->setImage("small-guppy_left.png");
	}
	
	this->setHunger(false);
}

//Get & set
int Guppy::getC() const{
	return this->C;
}

int Guppy::getG() const{
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

void Guppy::setG(int g){
	this->G = g;
}

void Guppy::setLastFed(int lf){
	this->lastFed = lf;
}

void Guppy::setLastCoin(int lc){
	this->lastCoin = lc;
}

//Service
void Guppy::tick(LinkedList<Food> &foods, LinkedList<Coin> &newCoins, double delay){
	bool cek = false;
	cout << 1 << endl;
	if (((this->getTickTime())-lastCoin)>=KOIN){
		cout << 2 << endl;
		lastCoin=(this->getTickTime());
		if ((this->G) == 1){
			cout << 3 << endl;
			Coin *a = new Coin(this->getX(),this->getY(),20,20,50);//value untuk koin harus selalu 50 untuk guppy tahap pertama, nanti bisa diubah kalo perlu
			a->setImage("koin-murah.png");
			newCoins.add(a);
		}else if ((this->G)==2){
			cout << 4 << endl;
			Coin *a = new Coin(this->getX(),this->getY(),20,20,75);//value untuk koin harus selalu 75 untuk guppy tahap kedua, nanti bisa diubah kalo perlu
			a->setImage("koin-sedang.png");
			newCoins.add(a);
		}else if ((this->G)==3){
			cout << 5 << endl;
			Coin *a = new Coin(this->getX(),this->getY(),20,20,100);//value untuk koin harus selalu 100 untuk guppy tahap ketiga, nanti bisa diubah kalo perlu
			a->setImage("koin-mahal.png");
			newCoins.add(a);
		}
	}
	
	if (this->hunger){
		if ((this->tickTime - this->lastFed)>=LAPAR+MATI){
			this->getSpace()->remove(this->getId(), TYPE_GUPPY);
			cek = true;
		}else{
			Food *food = findNearestFood(foods);

			if (food != NULL){
				if (this->isAbleToConsume(*food)){
					this->getSpace()->remove(food->getId(), TYPE_FOOD);
					setLastFed(this->tickTime);
					setHunger(false);
					if (this->G < 3){
						growthCounter++;

						if (growthCounter == NGEGEDEIN){
							if (this->G == 1){
								setG(2);
							}else if (this->G == 2){
								setG(3);
							}
							growthCounter = 0;
						}
					}

				}else{	//kalau tidak bisa consume makanan
					//ngejar food, belum implementasi (findNearestFood, setDir, setSpeed)
					if (food != NULL){
						setDirection(atan2(food->getY()-this->getY(), food->getX()-this->getX()));
						if ((getDirection()>=2*atan(1))&&(getDirection()<=6*atan(1))){
							setDirRight(true);
						}
						else {
							setDirRight(false);
						}

						if ((this->dirRight)&&((this->G)==1)){	//menentukan gambar ikan yang dipakai
							this->setImage("small-guppy-left.png");
						}
						else if ((this->dirRight)&&((this->G)==2)){
							this->setImage("medium-guppy-left.png");
						}
						else if ((this->dirRight)&&((this->G)==3)){
							this->setImage("large-guppy-left.png");
						}
						else if ((!this->dirRight)&&((this->G)==1)){
							this->setImage("small-guppy-right.png");
						}
						else if ((!this->dirRight)&&((this->G)==2)){
							this->setImage("medium-guppy-right.png");
						}
						else if ((!this->dirRight)&&((this->G)==3)){
							this->setImage("large-guppy-right.png");
						}

						//Ngejalanin ikannya, berdasarkan dir yang udah pasti bener:
						double newX = this->getX() + 100*cos(this->getDirection())*delay; //speed bisa diatur2 lah ntar
						double newY = this->getY() + 100*sin(this->getDirection())*delay;
						if (this->getSpace()->moveTo(this->getId(), TYPE_GUPPY, newX, newY)) {
							this->setX(newX);
							this->setY(newY);

						//Update atribut:
							if ((this->tickTime - this->lastFed)>=LAPAR){
								setHunger(true);
							}
						}else{
							setDirection(getDirection()+2*atan(1));
						}
						cek = true;
					}
				}
			}
		}
	}

	if (!cek){
		
		if (((this->tickTime)-(this->lastDrift))>=this->driftLength){
			setDirection(fRand(0,8*atan(1)));	//randomize direction
			driftLength = rand() % 200;	//maksimal 3 tick
			lastDrift = this->tickTime;
		}

		if ((getDirection()>=2*atan(1))&&(getDirection()<=6*atan(1))){
			setDirRight(true);
		}
		else {
			setDirRight(false);
		}

		if ((this->dirRight)&&((this->G)==1)){	//menentukan gambar ikan yang dipakai
			this->setImage("small-guppy-left.png");
		}
		else if ((this->dirRight)&&((this->G)==2)){
			this->setImage("medium-guppy-left.png");
		}
		else if ((this->dirRight)&&((this->G)==3)){
			this->setImage("large-guppy-left.png");
		}
		else if ((!this->dirRight)&&((this->G)==1)){
			this->setImage("small-guppy-right.png");
		}
		else if ((!this->dirRight)&&((this->G)==2)){
			this->setImage("medium-guppy-right.png");
		}
		else if ((!this->dirRight)&&((this->G)==3)){
			this->setImage("large-guppy-right.png");
		}

		//Ngejalanin ikannya, berdasarkan dir yang udah pasti bener:
		double newX = this->getX() + 100*cos(this->getDirection())*delay; //speed bisa diatur2 lah ntar
		double newY = this->getY() + 100*sin(this->getDirection())*delay;
		if (this->getSpace()->moveTo(this->getId(), TYPE_GUPPY, newX, newY)) {
			this->setX(newX);
			this->setY(newY);

		//Update atribut:
			if ((this->tickTime - this->lastFed)>=LAPAR){
				setHunger(true);
			}
		}else{
			setDirection(getDirection()+2*atan(1));
		}
	}
	this->increaseTick();
}

Food* Guppy::findNearestFood(LinkedList<Food> &foods){
	Element<Food>* eFood = foods.getFirst();
	if (eFood != NULL){
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
	}else{
		return NULL;
	}
}

bool Guppy::isAbleToConsume(Food const& food){
	return (this->getSpace())->isExist(food.getId(), TYPE_FOOD) && (
		(food.getX() > this->getLeft()) && 
		(food.getX() < this->getRight()) &&
		(food.getY() > this->getTop()) && 
		(food.getY() < this->getBottom())
	);
}