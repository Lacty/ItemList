
#pragma once
#include "../object.h"


class Item : public Object {
private:

public:
  Item() = default;

  void setup() final;
  void update() final;
  void draw() final;
};
