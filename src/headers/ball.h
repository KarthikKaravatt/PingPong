#pragma once
#include "player.h"
#include <raylib.h>
class Ball {
public:
  Ball(float radius, Color color);
  Ball(Ball &&) = default;
  Ball(const Ball &) = default;
  Ball &operator=(Ball &&) = default;
  Ball &operator=(const Ball &) = default;
  ~Ball();

  void update(Player& playerOne, Player& PlayerTwo);
  void push();

private:
  Vector2 center;
  Vector2 velocity;
  float radius;
  float speed;
  Color color;
  void move(Vector2 movement, Player& playerOne, Player& playerTwo);
  void reset();
  
};

