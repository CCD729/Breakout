#include "Level.h"

using namespace sf;
using namespace gm;

// Constructor
// Takes a 2d array of ints/Enums (indicating what type of brick and where it should be on the "grid" representation of the level)
// and creates a 1d vector (i.e., object list) of all bricks in the level. Should create the brick objects with appropriate x/y position 
// and BrickType and add them to the object list
Level::Level() {

}

void Level::update(sf::RenderWindow& window, float deltaTime) {
	// Maybe updates should be handled in collision..
}

// Render through Object list
void Level::render(sf::RenderWindow& window, float deltaTime) {

}

// Return bricks list's reference for collision detection
std::vector<std::unique_ptr<Brick>>& Level::getBricks() {
	return BrickList;
}

// Resets all bricks in the level back to their default state (alive again with full health)
void Level::reset(int level) {

}

// Destructor
Level::~Level() {

}