/* 
 * Class Snail
 *
 * Define snail behaviour as specification
 */ 

#ifndef SNAIL_HPP
#define SNAIL_HPP

#include "../Coin/Coin.hpp"
#include "../Entity/Entity.hpp"
#include "../LinkedList/LinkedList.hpp"

class Snail : public Entity {
private:
	// Find nearest coin
	// Return nearest coin
	// Throw error if size of list of coin is zero
	Coin findNearestCoin(LinkedList<Coin> &coins);

	// Return true if coin is able to consume (inside radius)
	bool isAbleToConsume(Coin const& coin);
public:
	// Constructor
	// Need position x and y
	Snail(int x, int y, int width, int height);

	// On every tick of game
	// Get list of coins
	// Do action corresponding with avaliable coins
	void tick(LinkedList<Coin> const& coins, int delay);
};

#endif