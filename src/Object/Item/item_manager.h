
#pragma once
#include "../object.h"
#include "item.h"
#include <vector>


class ItemManager : public Object {
private:
  std::vector<Item> items;
  ci::Font font;

  void loadItems();

public:
  ItemManager();

  void setup() final;
  void update() final;
  void draw() final;
};
