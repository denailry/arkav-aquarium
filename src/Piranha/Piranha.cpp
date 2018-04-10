#include "Piranha.hpp"

Piranha::Piranha(int x, int y, int width, int height) : Fish(x, y, width, height, TYPE_PIRANHA){
	setLastFed(this->tickTime); 
}

int Piranha::getLastFed() const{
	return this->lastFed;
}

void Piranha::setLastFed(int lf){
	this->lastFed = lf;
}

void Piranha::tick(LinkedList<Guppy> const& guppies, int delay){	//belum diimplementasi
}

Guppy Piranha::findNearestGuppy(LinkedList<Guppy> const& guppies){	//belum diimplementasi
	Guppy gup(3, 4, 3, 4);
	return gup;
}
    
bool Piranha::isAbleToConsume(Guppy const& guppy){	//belum diimplementasi
	return true;
}
