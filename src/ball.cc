#include "headers/ball.h"
#include "headers/player.h"
#include <cstdlib>
#include <iostream>
#include <raylib.h>
#include <string>

Ball::Ball(float radius, Color color)
    : radius{radius}, color{color}, speed{400.0f} {
  this->center = {(static_cast<float>(GetScreenWidth()) / 2),
                  (static_cast<float>(GetScreenHeight()) / 2)};
  this->velocity = {0.0f, 0.0f};
}

void Ball::update(Player &playerOne, Player &playerTwo) {
  // have to do this or else ball gets stuck in rectagnle
  if (CheckCollisionCircleRec(this->center, this->radius, playerOne.getRec())) {
    this->center.x = this->radius + playerOne.getRec().width;
    this->velocity.x *= -1;
    this->velocity.x += 25;
    this->velocity.y += (this->velocity.y < 0) ? -25 : 25;
  }
  if (CheckCollisionCircleRec(this->center, this->radius, playerTwo.getRec())) {
    this->center.x = GetScreenWidth() - this->radius - playerTwo.getRec().width;
    this->velocity.x *= -1;
    this->velocity.x -= 25;
    this->velocity.y += (this->velocity.y < 0) ? -25 : 25;
  }
  move(this->velocity, playerOne, playerTwo);
  DrawCircleV(this->center, this->radius, this->color);
}

void Ball::push() {
  int num1 = rand() % 2;
  int num2 = rand() % 2;
  this->velocity.x = (num1 == 1) ? -this->speed : this->speed;
  this->velocity.y = (num2 == 1) ? this->speed : -this->speed;
}

void Ball::move(Vector2 movement, Player &playerOne, Player &playerTwo) {
  this->center.x += movement.x * GetFrameTime();
  this->center.y += movement.y * GetFrameTime();
  if (this->center.y <= this->radius && this->velocity.y < 0)
    this->velocity.y *= -1;
  if (this->center.y + this->radius >= GetScreenHeight() &&
      this->velocity.y > 0)
    this->velocity.y *= -1;
  if (this->center.x < radius) {
    playerTwo.scoreGoal();
    reset();
  }
  if (this->center.x > GetScreenWidth() - radius) {
    playerOne.scoreGoal();
    reset();
  }
}

void Ball::reset() {
  std::cout << "reset\n";
  this->velocity = {0.0f, 0.0f};
  this->center.x = static_cast<float>(GetScreenWidth()) / 2;
  this->center.y = static_cast<float>(GetScreenHeight()) / 2;
  push();
}

Vector2 Ball::getPos(){
  return this->center;
}

Ball::~Ball() {}
