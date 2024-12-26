#ifndef BUBBLEGAME_HPP
#define BUBBLEGAME_HPP

#include <vector>
#include <optional>
#include <memory>

#include "Game.hpp"
#include "Player.hpp"
#include "Bubble.hpp"

namespace bubblegame {

class BubbleGame: public engine2d::Game {
    public:
        BubbleGame(int windowWidth, int windowHeight, std::optional<int> targetFps, std::optional<unsigned int> configFlags):
            engine2d::Game("Bubble Game", windowWidth, windowHeight, targetFps, configFlags) {};
    protected:
        void init() override;
        void frameCode() override;
        void drawFrame() override;
        void cleanUp() override;
    private:
        Player player;
        std::vector<Bubble> bubbles = {};
        int keyPressed = 0;
        int points = 0;
        time_t endTime = 0;
};

}

#endif
