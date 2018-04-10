#include "Entity.hpp"

Entity::Entity(double x, double y, double width, double height, char type) {
	this->radX = width/2;
	this->radY = height/2;
	this->x = x;
	this->y = y;
	this->type = type;
}

void Entity::tick(int delay) {
	this->tickTime = tickTime + 1;
}

// Getter
int Entity::getId() const {
	return this->id;
}
double Entity::getX() const {
	return this->x;
}
double Entity::getY() const {
	return this->y;
}
double Entity::getRadX() const {
	return this->radX;
}
double Entity:: getRadY() const {
	return this->radY;
}
double Entity::getLeft() const {
	return this->x - this->radX;
}
double Entity::getRight() const {
	return this->x + this->radX;
}
double Entity::getTop() const {
	return this->y - this->radY;
}
double Entity::getBottom() const {
	return this->y + this->radY;
}
Space* Entity::getSpace() const {
	return this->space;
}

// Setter
void Entity::setId(int id) {
	this->id = id;
}
void Entity::setX(double x) {
	this->x = x;
}
void Entity::setY(double y) {
	this->y = y;
}
void Entity::setRadX(double radX) {
	this->radX = radX;
}
void Entity::setRadY(double radY) {
	this->radY = radY;
}
void Entity::setSpace(Space* space) {
	this->space = space;
}