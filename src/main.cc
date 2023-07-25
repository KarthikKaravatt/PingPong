#include "headers/ball.h"
#include "headers/player.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <raylib.h>
#include <string>

void displayScore(int playerOneScore, int playerTwoScore) {
  std::string score = std::to_string(playerOneScore) + " - " +
                      std::to_string(playerTwoScore);
  DrawText(score.c_str(), GetScreenWidth() / 2, GetScreenHeight() / 3, 40,
           WHITE);
}

int main(int argc, char *argv[]) {
  InitWindow(1920, 1080, "Ping Pong");
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  srand(time(NULL));
  SetWindowMinSize(1280, 720);
  Player playerOne = Player("LEFT", WHITE, KEY_W, KEY_S);
  Player playerTwo = Player("RIGHT", WHITE, KEY_UP, KEY_DOWN);
  Ball ball = Ball(10.0f, WHITE);
  ball.push();
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    ball.update(playerOne, playerTwo);
    playerOne.update();
    playerTwo.update();
    displayScore(playerOne.getScore(), playerTwo.getScore());
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
