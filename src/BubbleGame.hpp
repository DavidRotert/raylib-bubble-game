#ifndef BUBBLEGAME_HPP
#define BUBBLEGAME_HPP

#include "Game.hpp"

#define BUBBLEGAME_WINDOW_HEIGHT 400
#define BUBBLEGAME_WINDOW_WIDTH 800
#define BUBBLEGAME_FPS 60

namespace bubblegame {

class BubbleGame: public rayengine2d::Game {
private:
    const float circleRadius = 25;
    const float circleMarginLeft = 5;
    float circlePositionY = this->circleRadius;

    const float animationTimeInSeconds = 5;
    const float animationDeltaPerSecond = BUBBLEGAME_WINDOW_HEIGHT / animationTimeInSeconds;

protected:
    void frameCode() override;
    void drawFrame() override;
public:
    BubbleGame();
};

}

#endif
