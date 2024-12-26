#include <optional>

#include "raylib.h"
//#include "rlgl.h"
#include "raymath.h"

#include "BubbleGame.hpp"

int main() {
    bubblegame::BubbleGame game = bubblegame::BubbleGame(800, 400, std::nullopt, FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
    
    return game.gameLoop();
}
