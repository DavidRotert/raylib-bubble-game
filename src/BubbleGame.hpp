#ifndef BUBBLEGAME_GAME
#define BUBBLEGAME_GAME

#include "rayengine/Game2d.hpp"
#include "./Player.hpp"

namespace bubblegame {

class BubbleGame: public rayengine::Game2d {
    public:
        BubbleGame(): rayengine::Game2d("Bubble Game", 800, 400, std::nullopt, FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT) {};

    protected:
        virtual void init() override;
        void frameCode() override;
        void drawFrame() override;
        virtual void cleanUp() override;

        Player player;
        int keyPressed = 0;
};

}

#endif
