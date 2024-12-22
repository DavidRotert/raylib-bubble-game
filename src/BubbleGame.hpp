#ifndef BUBBLEGAME_HPP
#define BUBBLEGAME_HPP

#include <vector>
#include <optional>

#include "Game.hpp"
#include "Player.hpp"
#include "Bubble.hpp"

namespace bubblegame {

class BubbleGame: public engine2d::Game {
    private:
        Player player;
        std::vector<Bubble> bubbles = {};
        int keyPressed = 0;
        int points = 0;
        time_t endTime = 0;

        void init() override;
    protected:
        
        void frameCode() override;
        void drawFrame() override;
    public:
        BubbleGame(int windowWidth, int windowHeight, std::optional<int> targetFps, std::optional<unsigned int> configFlags);
};

}

#endif
