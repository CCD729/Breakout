#ifndef LEVEL_H
#define LEVEL_H

#include "Brick.h"
#include<memory>
#include<vector>

namespace gm {
    class Level :
        public GameObject
    {
    protected:
        // Grid size needs to be determined
        int grid[9][10];
        std::vector<std::unique_ptr<Brick>> BrickList;
        int brickHeight = 0;
        int brickWidth = 0;
        int row, column = 0;
    public:
        Level(int levelGrid[9][10], float LevelWidth, float LevelHeight, int row, int column);

        virtual void update(sf::RenderWindow& window, float deltaTime) override;

        virtual void render(sf::RenderWindow& window, float deltaTime) override;

        std::vector<std::unique_ptr<Brick>>& getBricks();

        void reset();
        
        ~Level();

    };
}
#endif

