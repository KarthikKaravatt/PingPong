#include "headers/player.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <ostream>
#include <raylib.h>
#include <string>

constexpr float width = 20.0f;
constexpr float height = 75.0f;

Player::Player(std::string pos, Color color, int upKey, int downKey)
    : pos{pos}, color{color}, speed{800.0f}, upKey{upKey}, downKey{downKey},
      score{0} {
  assert(pos == "LEFT" || pos == "RIGHT");
  float posX = (pos == "LEFT") ? 0 : GetScreenWidth() - width;
  this->playerShape = {posX, static_cast<float>(GetScreenHeight()) / 2, width,
                       height};
}

Rectangle Player::getRec() { return this->playerShape; }

void Player::update() {
  move();
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

void Player::move() {
  float screenHeight = static_cast<float>(GetScreenHeight());
  if (IsKeyDown(upKey)) {
    this->playerShape.y -= this->speed * GetFrameTime();
  }
  if (IsKeyDown(downKey)) {
    this->playerShape.y += this->speed * GetFrameTime();
  }
  this->playerShape.y =
      std::clamp(playerShape.y, 0.0f, screenHeight - playerShape.height);
}

int Player::getScore() { return this->score; }
void Player::scoreGoal() { ++this->score; }

Player::~Player() {}
