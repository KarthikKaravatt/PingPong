#include "headers/level.h"
#include "headers/ball.h"
#include "headers/player.h"
#include "headers/ai.h"


Level::Level(Player &playerOne, Player &playerTwo, Ball &ball)
    : playerOne(playerOne), playerTwo(playerTwo), ball(ball) {
}

void Level::update(){
  if(this->ball.getVel().x == 0.0f && this->ball.getVel().y == 0.0f) this->ball.push();
  this->playerOne.update(ball.getPos()); 
  this->playerTwo.update(ball.getPos());
  this->ball.update(this->playerOne,this->playerTwo);
  displayScore(this->playerOne.getScore(), this->playerTwo.getScore());
}
void Level::displayScore(int playerOneScore, int playerTwoScore) {
  std::string score =
      std::to_string(playerOneScore) + " - " + std::to_string(playerTwoScore);
  DrawText(score.c_str(), GetScreenWidth() / 2, GetScreenHeight() / 3, 40,
           WHITE);
}
Level::~Level() {
  // Destructor code here
}
