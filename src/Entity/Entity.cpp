#include "Entity.hpp"

Entity::Entity(int x, int y, char type) {
	this->x = x;
	this->y = y;
	this->type = type;
}

void Entity::tick() {
	this->tickTime = tickTime + 1;
}

// Getter
int Entity::getId() const {
	return this->id;
}
int Entity::getX() const {
	return this->x;
}
int Entity::getY() const {
	return this->y;
}
int Entity::getRadX() const {
	return this->radX;
}
int Entity:: getRadY() const {
	return this->radY;
}
int Entity::getLeft() const {
	return this->x - this->radX;
}
int Entity::getRight() const {
	return this->x + this->radX;
}
int Entity::getTop() const {
	return this->y - this->radY;
}
int Entity::getBottom() const {
	return this->y + this->radY;
}

// Setter
void setId(int id) {
	this->id = id;
}
void setX(int x) {
	this->x = x;
}
void setY(int y) {
	this->y = y;
}
void setRadX(int radX) {
	this->radX = radX;
}
void setRadY(int radY) {
	this->radY = radY;
}