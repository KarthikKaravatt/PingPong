#include "headers/ai.h"
#include "headers/player.h"
#include <cassert>
#include <iostream>
#include <raylib.h>

constexpr float width = 20.0f;
constexpr float height = 75.0f;

Ai::Ai(std::string pos, Color color) : Player(pos, color, 0, 0) {
  // similar to Player class but no input 
  assert(pos == "LEFT" || pos == "RIGHT");
  float posX = (pos == "LEFT") ? 0 : GetScreenWidth() - width;
  this->playerShape = {posX, static_cast<float>(GetScreenHeight()) / 2, width,
                       height};
}

void Ai::update(Vector2 ballPos) {
  // same as the Player class but with ball pos as parmeter 
  move(ballPos);
  DrawRectangleRec(this->playerShape, color);
  if (IsWindowResized()) {
    this->playerShape.x = (this->pos == "LEFT") ? 0 : GetScreenWidth() - width;
    if (this->playerShape.y + this->playerShape.height >= GetScreenHeight()) {
      this->playerShape.y = GetScreenHeight() - this->playerShape.height;
    } else if (this->playerShape.y < 0) {
      this->playerShape.y = 0;
    }
  }
}

void Ai::move(Vector2 ballPos) {
  // find which direction the paddle needs to travel
  // paddle should follow the ball's position
  // add this value to the current position of the paddle
  float newY = this->playerShape.y + ((ballPos.y > this->playerShape.y)
                                          ? speed * GetFrameTime()
                                          : -speed * GetFrameTime());
  // determine if the new position is inside the bounds
  // max with 0 and the min of the screen hieght and new position
  this->playerShape.y = std::max(
      0.0f, std::min(GetScreenHeight() - this->playerShape.height, newY));
}
