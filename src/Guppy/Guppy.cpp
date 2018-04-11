#include "Guppy.hpp"
#include <cmath>
#include <time.h>
#define LAPAR 100
#define KOIN 1
#define MATI 100
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
	setC(15);
	setG(small);
	growthCounter=0;
	setLastFed(this->tickTime);
	setLastCoin(this->tickTime);
	driftLength=10;
	lastDrift = this->tickTime;
	this->setDirRight(true);
	srand(time(NULL));
	setDirection(fRand(0,8*atan(1)));
	if ((getDirection()>=2*atan(1))&&(getDirection()<=6*atan(1))){
		setDirRight(true);
	}
	else {
		setDirRight(false);
	}

	if ((this->dirRight)&&((this->G)==3)){	//menentukan gambar ikan yang dipakai
		this->setImage("ikan.png");
	}
	else if ((this->dirRight)&&((this->G)==2)){
		this->setImage("medium-guppy-right.png");
	}
	else if ((this->dirRight)&&((this->G)==1)){
		this->setImage("large-guppy-right.png");
	}
	else if ((!this->dirRight)&&((this->G)==3)){
		this->setImage("ikan_left.png");
	}
	else if ((!this->dirRight)&&((this->G)==2)){
		this->setImage("medium-guppy-left.png");
	}
	else if ((!this->dirRight)&&((this->G)==1)){
		this->setImage("large-guppy-left.png");
	}
	//this->setDirection(atan(1)*4.0/2.0);
	this->setHunger(false);
	this->setImage("ikan.png");
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
	this->increaseTick();
	if (((this->getTickTime())-lastCoin)>=KOIN){
		lastCoin=(this->getTickTime());
		if ((this->G)==1){
			Coin *a = new Coin(this->getX(),this->getY(),20,20,50);//value untuk koin harus selalu 50 untuk guppy tahap pertama, nanti bisa diubah kalo perlu
			a->setImage("koin-murah.png");
			coins.add(a);
		}else if ((this->G)==2){
			Coin *a = new Coin(this->getX(),this->getY(),20,20,75);//value untuk koin harus selalu 75 untuk guppy tahap kedua, nanti bisa diubah kalo perlu
			a->setImage("koin-sedang.png");
			coins.add(a);
		}else if ((this->G)==3){
			Coin *a = new Coin(this->getX(),this->getY(),20,20,100);//value untuk koin harus selalu 100 untuk guppy tahap ketiga, nanti bisa diubah kalo perlu
			a->setImage("koin-mahal.png");
			coins.add(a);
		}
	}
	
	if (this->hunger){
		if ((this->lastFed)>=LAPAR+MATI){
			this->getSpace()->remove(this->getId(), TYPE_GUPPY);
		}else{
			Food *food = findNearestFood(foods);
			if (this->isAbleToConsume(*food)){
				this->getSpace()->remove(food->getId(), TYPE_FOOD);
				setLastFed(this->tickTime);
				setHunger(false);
				growthCounter++;
				if (((this->tickTime)-(this->lastDrift))>=this->driftLength){
					srand(time(NULL));
					setDirection(fRand(0,8*atan(1)));	//randomize direction
					driftLength = rand() % 3;	//maksimal 7 tick
					lastDrift = this->tickTime;
				}/*
				if (){	//Ikan menabrak dinding akuarium
					setDirection(getDirection()+2*atan(1));
				}*/
				if ((getDirection()>=2*atan(1))&&(getDirection()<=6*atan(1))){
					setDirRight(true);
				}
				else {
					setDirRight(false);
				}

				if ((this->dirRight)&&((this->G)==3)){	//menentukan gambar ikan yang dipakai
					this->setImage("ikan.png");
				}
				else if ((this->dirRight)&&((this->G)==2)){
					this->setImage("medium-guppy-right.png");
				}
				else if ((this->dirRight)&&((this->G)==1)){
					this->setImage("large-guppy-right.png");
				}
				else if ((!this->dirRight)&&((this->G)==3)){
					this->setImage("ikan_left.png");
				}
				else if ((!this->dirRight)&&((this->G)==2)){
					this->setImage("medium-guppy-left.png");
				}
				else if ((!this->dirRight)&&((this->G)==1)){
					this->setImage("large-guppy-left.png");
				}

				//Ngejalanin ikannya, berdasarkan dir yang udah pasti bener:
				double newX = this->getX() + 100*cos(this->getDirection())*delay; //speed bisa diatur2 lah ntar
				double newY = this->getY() + 100*sin(this->getDirection())*delay;
				if (this->getSpace()->moveTo(this->getId(), TYPE_GUPPY, newX, newY)) {
					this->setX(newX);
					this->setY(newY);

				//Update atribut:
					if ((this->lastFed)>=LAPAR){
						setHunger(true);
					}
				}else{
					setDirection(getDirection()+2*atan(1));
				}
			}else{
				//ngejar food, belum implementasi (findNearestFood, setDir, setSpeed)
				if (food != NULL){
					setDirection(atan2(food->getY()-this->getY(), food->getX()-this->getX()));
					if ((getDirection()>=2*atan(1))&&(getDirection()<=6*atan(1))){
						setDirRight(true);
					}
					else {
						setDirRight(false);
					}

					if ((this->dirRight)&&((this->G)==3)){	//menentukan gambar ikan yang dipakai
						this->setImage("ikan.png");
					}
					else if ((this->dirRight)&&((this->G)==2)){
						this->setImage("medium-guppy-right.png");
					}
					else if ((this->dirRight)&&((this->G)==1)){
						this->setImage("large-guppy-right.png");
					}
					else if ((!this->dirRight)&&((this->G)==3)){
						this->setImage("ikan_left.png");
					}
					else if ((!this->dirRight)&&((this->G)==2)){
						this->setImage("medium-guppy-left.png");
					}
					else if ((!this->dirRight)&&((this->G)==1)){
						this->setImage("large-guppy-left.png");
					}

					//Ngejalanin ikannya, berdasarkan dir yang udah pasti bener:
					double newX = this->getX() + 100*cos(this->getDirection())*delay; //speed bisa diatur2 lah ntar
					double newY = this->getY() + 100*sin(this->getDirection())*delay;
					if (this->getSpace()->moveTo(this->getId(), TYPE_GUPPY, newX, newY)) {
						this->setX(newX);
						this->setY(newY);

					//Update atribut:
						if ((this->lastFed)>=LAPAR){
							setHunger(true);
						}
					}else{
						setDirection(getDirection()+2*atan(1));
					}

				}

			}
		}
	}else{
		if (((this->tickTime)-(this->lastDrift))>=this->driftLength){
			srand(time(NULL));
			setDirection(fRand(0,8*atan(1)));	//randomize direction
			driftLength = rand() % 3;	//maksimal 3 tick
			lastDrift = this->tickTime;
		}/*
		if (){	//Ikan menabrak dinding akuarium
			setDirection(getDirection()+2*atan(1));
		}*/
		if ((getDirection()>=2*atan(1))&&(getDirection()<=6*atan(1))){
			setDirRight(true);
		}
		else {
			setDirRight(false);
		}

		if ((this->dirRight)&&((this->G)==1)){	//menentukan gambar ikan yang dipakai
			this->setImage("ikan.png");
		}
		else if ((this->dirRight)&&((this->G)==2)){
			this->setImage("medium-guppy-right.png");
		}
		else if ((this->dirRight)&&((this->G)==3)){
			this->setImage("large-guppy-right.png");
		}
		else if ((!this->dirRight)&&((this->G)==1)){
			this->setImage("ikan_left.png");
		}
		else if ((!this->dirRight)&&((this->G)==2)){
			this->setImage("medium-guppy-left.png");
		}
		else if ((!this->dirRight)&&((this->G)==3)){
			this->setImage("large-guppy-left.png");
		}

		//Ngejalanin ikannya, berdasarkan dir yang udah pasti bener:
		double newX = this->getX() + 100*cos(this->getDirection())*delay; //speed bisa diatur2 lah ntar
		double newY = this->getY() + 100*sin(this->getDirection())*delay;
		if (this->getSpace()->moveTo(this->getId(), TYPE_GUPPY, newX, newY)) {
			this->setX(newX);
			this->setY(newY);

		//Update atribut:
			if ((this->lastFed)>=LAPAR){
				setHunger(true);
			}
		}else{
			setDirection(getDirection()+2*atan(1));
		}
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