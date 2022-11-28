#include "Level.h"

using namespace sf;
using namespace gm;

// Brick Type
BrickType normal_brick = {
1,
sf::Color::White,
50
};
BrickType hard_brick = {
	2,
	sf::Color::Cyan,
	125
};
BrickType tough_brick = {
	3,
	sf::Color::Blue,
	200
};

// Constructor
// Takes a 2d array of ints/Enums (indicating what type of brick and where it should be on the "grid" representation of the level)
// and creates a 1d vector (i.e., object list) of all bricks in the level. Should create the brick objects with appropriate x/y position 
// and BrickType and add them to the object list
Level::Level(int levelGrid[9][10], float LevelWidth, float LevelHeight, int row, int column) : row(row), column(column) {
	// Load grid
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 10; j++) {
			grid[i][j] = levelGrid[i][j];
		}
	}
	brickHeight = int(LevelHeight / row);
	brickWidth = int(LevelWidth / column);
	// Load level data into brickList (temp 9*10 270*640)
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			switch (grid[i][j]) {
				case 3: {// tough_brick
					  std::unique_ptr<Brick> newBrick(new Brick(Vector2f(float(j * brickWidth), float(i * brickHeight + 30)), Vector2f(float(brickWidth), float(brickHeight)), &tough_brick));
					  BrickList.push_back(std::move(newBrick));
					  break;
				}
				case 2: {// hard_brick
					std::unique_ptr<Brick> newBrick(new Brick(Vector2f(float(j * brickWidth), float(i * brickHeight + 30)), Vector2f(float(brickWidth), float(brickHeight)), &hard_brick));
					BrickList.push_back(std::move(newBrick));
					break; 
				}
				case 1: { // normal_brick
					std::unique_ptr<Brick> newBrick(new Brick(Vector2f(float(j * brickWidth), float(i * brickHeight + 30)), Vector2f(float(brickWidth), float(brickHeight)), &normal_brick));
					BrickList.push_back(std::move(newBrick));
					break; 
				}
			}
		}
	}
}

void Level::update(sf::RenderWindow& window, float deltaTime) {
	// Maybe updates should be handled in collision..
}

// Render through Object list
void Level::render(sf::RenderWindow& window, float deltaTime) {
	for (int i = 0; i < int(BrickList.size()); i++) {
		BrickList[i].get()->render(window, deltaTime);
	}
}

// Return bricks list's reference for collision detection
std::vector<std::unique_ptr<Brick>>& Level::getBricks() {
	return BrickList;
}

// Resets all bricks in the level back to their default state (alive again with full health)
void Level::reset() {
	BrickList.clear();
	// Load level data into brickList
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			switch (grid[i][j]) {
				case 3: {// tough_brick
					std::unique_ptr<Brick> newBrick(new Brick(Vector2f(float(j * brickWidth), float(i * brickHeight + 30)), Vector2f(float(brickWidth), float(brickHeight)), &tough_brick));
					BrickList.push_back(std::move(newBrick));
					break;
				}
				case 2: {// hard_brick
					std::unique_ptr<Brick> newBrick(new Brick(Vector2f(float(j * brickWidth), float(i * brickHeight + 30)), Vector2f(float(brickWidth), float(brickHeight)), &hard_brick));
					BrickList.push_back(std::move(newBrick));
					break;
				}
				case 1: { // normal_brick
					std::unique_ptr<Brick> newBrick(new Brick(Vector2f(float(j * brickWidth), float(i * brickHeight + 30)), Vector2f(float(brickWidth), float(brickHeight)), &normal_brick));
					BrickList.push_back(std::move(newBrick));
					break;
				}
			}
		}
	}
}

// Destructor
Level::~Level() {

}