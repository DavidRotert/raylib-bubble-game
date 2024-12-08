#ifndef BUBBLEGAME_HPP
#define BUBBLEGAME_HPP

#include <vector>

#include "Game.hpp"
#include "Player.hpp"
#include "Bubble.hpp"

#define BUBBLEGAME_WINDOW_WIDTH 800
#define BUBBLEGAME_WINDOW_HEIGHT 400
#define BUBBLEGAME_FPS 120

namespace bubblegame {

class BubbleGame: public engine2d::Game {
    private:
        const float animationTimeInSeconds = 5;
        const float animationDeltaPerSecond = BUBBLEGAME_WINDOW_HEIGHT / animationTimeInSeconds;

        Player player;
        std::vector<Bubble> bubbles = {};

        Vector2 initialMousePos;

        void init() override;
    protected:
        
        void frameCode() override;
        void drawFrame() override;
    public:
        BubbleGame();
};

}

#endif
