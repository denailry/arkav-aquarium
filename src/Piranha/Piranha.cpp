#include "Piranha.hpp"

Piranha::Piranha(int x, int y) : Fish(x,y,TYPE_PIRANHA){
	setLastFed(this->tickTime); 
}

int Piranha::getLastFed() const{
	return this->lastFed;
}

void Piranha::setLastFed(int lf) const{
	this->lastFed = lf;
}

void tick(LinkedList<Guppy> const& guppies){	//belum diimplementasi
}

Guppy findNearestGuppy(LinkedList<Guppy> const& guppies){	//belum diimplementasi
	Guppy gup(3,4);
	return gup;
}
    
bool isAbleToConsume(Guppy const& guppy){	//belum diimplementasi
	return true;
}