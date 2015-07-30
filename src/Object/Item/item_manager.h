
#pragma once
#include "../object.h"
#include "item.h"
#include <vector>


class ItemManager : public Object {
private:
  std::vector<Item> items;
  ci::Font font;
  cinder::Vec3f mouse_pos;

  void loadItems();
  void saveItems();

public:
  ItemManager();

  void setup() final;
  void update() final;
  void draw() final;
};
