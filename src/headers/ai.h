#include "player.h"
#include <compare>
#include <raylib.h>
class Ai : public Player {
public:
  Ai(std::string pos, Color color);
  void update(Vector2 ballPos) override;
  void scoreGoal();
private:
  void move(Vector2 ballPos);
};
