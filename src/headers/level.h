#pragma once

#include "ball.h"
#include "player.h"

class Level {
public:
  Level(Player &playerOne, Player &playerTwo, Ball &ball);
  Level(Level &&) = default;
  Level(const Level &) = default;
  Level &operator=(Level &&) = default;
  Level &operator=(const Level &) = default;
  ~Level();
  void update();

private:
  Player playerOne, playerTwo;
  Ball ball;
  void displayScore(int playerOneScore, int playerTwoScore);
};
