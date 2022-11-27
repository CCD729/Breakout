#ifndef LEVEL_H
#define LEVEL_H

#include "GameObject.h"
#include "Brick.h"
#include<memory>
#include<vector>

namespace gm {
    class Level :
        public GameObject
    {
    protected:
        // Grid size needs to be determined
        //int grid[x][y];
        std::vector<std::unique_ptr<Brick>> BrickList;
        int brickHeight = 0;
        int brickWidth = 0;
        int row, column = 0;
    public:
        Level();

        virtual void update(sf::RenderWindow& window, float deltaTime) override;

        virtual void render(sf::RenderWindow& window, float deltaTime) override;

        std::vector<std::unique_ptr<Brick>>& getBricks();

        void reset(int level);
        
        ~Level();

    };
}
#endif

