#include "headers/level.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include <raylib.h>

#include "headers/ai.h"
#include "headers/ball.h"
#include "headers/player.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

void displayScore(int playerOneScore, int playerTwoScore) {
  std::string score =
      std::to_string(playerOneScore) + " - " + std::to_string(playerTwoScore);
  DrawText(score.c_str(), GetScreenWidth() / 2, GetScreenHeight() / 3, 40,
           WHITE);
}

void windoSizeLimit(int x, int y) {
  if (GetScreenWidth() < x)
    SetWindowSize(x, GetScreenHeight());
  if (GetScreenHeight() < y)
    SetWindowSize(GetScreenWidth(), y);
}

void setup(){
  InitWindow(1920, 1080, "Ping Pong");
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  srand(time(NULL));
  SetWindowMinSize(1280, 720);
}

int main(int argc, char *argv[]) {
  setup();

  Player playerOne = Player("LEFT", WHITE, KEY_W, KEY_S);
  // Player playerTwo = Player("RIGHT", WHITE, KEY_UP, KEY_DOWN);
  Ai playerTwo = Ai("RIGHT", WHITE);
  Ball ball = Ball(10.0f, WHITE);
  Level level = Level(playerOne, playerTwo, ball);
  while (!WindowShouldClose()) {
    windoSizeLimit(1280, 720);
    BeginDrawing();
    level.update();
    ClearBackground(BLACK);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
