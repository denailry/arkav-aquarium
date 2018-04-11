#include "Tick.hpp"
#include <cmath>

Tick::Tick() {
	this->tickTime = 0;
}

int Tick::getTickTime() {
	return this->tickTime;
}

void Tick::resetTickTime() {
	this->tickTime = 0;
}

void Tick::increaseTick() {
	this->tickTime = (this->tickTime + 1) % 2147483647;
}

int Tick::diff(int tickTime) {
	return (abs(this->tickTime - tickTime));
}