/*
 * Class Aquarium
 *
 * Collect all of Entities live in the aquarium
 * Coordinate movement and action of Entities
 * corresponding with Entities' position in screen
 */

#ifndef AQUARIUM_HPP
#define AQUARIUM_HPP

#include <vector>
#include "../Entity/Entity.hpp"
#include "../Coin/Coin.hpp"
#include "../Food/Food.hpp"
#include "../Guppy/Guppy.hpp"
#include "../Piranha/Piranha.hpp"
#include "../Snail/Snail.hpp"
#include "../Space/Space.hpp"
#include "../LinkedList/LinkedList.hpp"

class Aquarium : protected Tick, public Space {
private:
	int width;
	int height;
	LinkedList<Entity> **screen;
	LinkedList<Coin> coins;
	LinkedList<Food> foods;
	LinkedList<Guppy> guppies;
	LinkedList<Piranha> piranhas;
	Snail snail;

	// Collected score from collected coins
	int score;

	// Tick for each entities
	// Each of these functions call tick function in each derived Entities
	// And provide corresponding parameter
	void tickCoins();
	void tickFoods();
	void tickGuppies();
	void tickPiranhas();
	void tickSnail();

	// Add Entity to screen
	bool addToScreen(Entity& entity);
public:
	// Constructor
	// Initialize screen
	// Initialize score
	Aquarium(int width, int height);

	// Copy Constructor
	Aquarium(Aquarium const &aquarium);

	// Destructor
	~Aquarium();

	// Print screen to show position of every entities
	void printScreen();

	// Adder
	// First add each entity to screen
	// If true then add to corresponding list
	void addCoin(Coin const &coin);
	void addFood(Food const &food);
	void addGuppy(Guppy const& guppy);
	void addPiranha(Piranha const& piranha);
	void setSnail(Snail const& snail);

	// Getter
	LinkedList<Coin> getCoins() const;
	LinkedList<Food> getFoods() const;
	LinkedList<Guppy> getGuppies() const;
	LinkedList<Piranha> getPiranhas() const;
	Snail getSnail() const;

	// Implementation of Tick
	// Call all tick functions
	void tick();

	// Implementation of Space
	bool moveTo(int entityId, int entityType, int newX, int newY) {
		return true;
	}
	void remove(int entityId, int entityType) {
		return;
	}
};

#endif