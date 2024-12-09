#ifndef BUBBLEGAME_HPP
#define BUBBLEGAME_HPP

#include <vector>

#include "Game.hpp"
#include "Player.hpp"
#include "Bubble.hpp"

#define BUBBLEGAME_WINDOW_WIDTH 800
#define BUBBLEGAME_WINDOW_HEIGHT 400
#define BUBBLEGAME_FPS 60

namespace bubblegame {

class BubbleGame: public engine2d::Game {
    private:
        Player player;
        std::vector<Bubble> bubbles = {};
        int keyPressed = 0;

        void init() override;
    protected:
        
        void frameCode() override;
        void drawFrame() override;
    public:
        BubbleGame(int windowWidth, int windowHeight, int targetFps);
};

}

#endif
