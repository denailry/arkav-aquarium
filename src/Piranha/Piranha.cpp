#include "Piranha.hpp"
#include <cmath>
#include <iostream>

#define LAPAR 2000
#define KOIN 640
#define MATI 2000

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

void Piranha::tick(LinkedList<Guppy> &guppies, LinkedList<Coin> &coins, double delay){	//belum diimplementasi
	bool cek = false;
	
	if (this->hunger){
		if ((this->tickTime - this->lastFed)>=LAPAR+MATI){
			this->getSpace()->remove(this->getId(), TYPE_PIRANHA);
			cek = true;
		}else{
			Guppy *guppy = findNearestGuppy(guppies);

			if (guppy != NULL){
				if (this->isAbleToConsume(*guppy)){
					this->getSpace()->remove(guppy->getId(), TYPE_GUPPY);
					setLastFed(this->tickTime);
					setHunger(false);
					Coin *a = new Coin(this->getX(),this->getY(),20,20,50);//value untuk koin harus selalu 50 untuk guppy tahap pertama, nanti bisa diubah kalo perlu
					a->setImage("diamond_small.png");
					coins.add(a);
			
				}else{	//kalau tidak bisa consume makanan
					//ngejar guppy, belum implementasi (findNearestFood, setDir, setSpeed)
					if (guppy != NULL){
						setDirection(atan2(guppy->getY()-this->getY(), guppy->getX()-this->getX()));
						if ((getDirection()>=2*atan(1))&&(getDirection()<=6*atan(1))){
							setDirRight(true);
						}
						else {
							setDirRight(false);
						}

						if (this->dirRight){	//menentukan gambar ikan yang dipakai
							this->setImage("piranha-left.png");
						}else{
							this->setImage("piranha-right.png");
						}

						//Ngejalanin ikannya, berdasarkan dir yang udah pasti bener:
						double newX = this->getX() + 100*cos(this->getDirection())*delay; //speed bisa diatur2 lah ntar
						double newY = this->getY() + 100*sin(this->getDirection())*delay;
						if (this->getSpace()->moveTo(this->getId(), TYPE_PIRANHA, newX, newY)) {
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
			setDirection(pRand(0,8*atan(1)));	//randomize direction
			driftLength = rand() % 200;	//maksimal 3 tick
			lastDrift = this->tickTime;
		}

		if ((getDirection()>=2*atan(1))&&(getDirection()<=6*atan(1))){
			setDirRight(true);
		}
		else {
			setDirRight(false);
		}

		if (this->dirRight){	//menentukan gambar ikan yang dipakai
			this->setImage("piranha-left.png");
		}else{
			this->setImage("piranha-right.png");
		}

		//Ngejalanin ikannya, berdasarkan dir yang udah pasti bener:
		double newX = this->getX() + 100*cos(this->getDirection())*delay; //speed bisa diatur2 lah ntar
		double newY = this->getY() + 100*sin(this->getDirection())*delay;
		if (this->getSpace()->moveTo(this->getId(), TYPE_PIRANHA, newX, newY)) {
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
