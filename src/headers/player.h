#pragma once
#include <raylib.h>
#include <string>
class Player {
public:
  Player(std::string pos, Color color, int upKey, int downKey);
  Player(Player &&) = default;
  Player(const Player &) = default;
  Player &operator=(Player &&) = default;
  Player &operator=(const Player &) = default;
  ~Player();
  virtual void update(Vector2 ballPos);
  Rectangle getRec();
  int getScore();
  void scoreGoal();

protected:
  Rectangle playerShape;
  float speed;
  Color color;
  std::string pos;
  int score;
  int upKey, downKey;
  void move();
  int calcPosX();
};
