#include "Tick.hpp"

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
	this->tickTime++;
}