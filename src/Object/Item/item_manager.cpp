
#include "item_manager.h"
#include "cinder/gl/gl.h"
#include "cinder/Json.h"
#include <sstream>

using namespace ci;
using namespace ci::app;


ItemManager::ItemManager() {
  font = Font(loadAsset("rounded-l-mplus-1c-bold.ttf"), 21);
  loadItems();
}

void ItemManager::loadItems() {
  JsonTree data(loadAsset("data.json"));
  auto Size = data["Materials"].getNumChildren();
  for (size_t i = 0; i < Size; ++i) {
    Item item;
    std::ostringstream item_num;
    item_num << "item" << i;
    item.setName(data["Materials"][item_num.str()]["name"].getValue<std::string>());
    item.setNecessaryNum(data["Materials"][item_num.str()]["nece"].getValue<int>());
    item.setCurrentNum(data["Materials"][item_num.str()]["curr"].getValue<int>());
    items.push_back(item);
  }
}

void ItemManager::setup() {
  int offset = 40;
  for (int i = 0; i < items.size(); ++i) {
    items[i].setPos(Vec2f(-320, -160 + i * offset));
  }
}

void ItemManager::update() {

}

void ItemManager::draw() {
  gl::pushModelView();
  gl::translate(Vec2f(-320, -200));
  gl::drawString("素材名", Vec2f::zero(), Color(1, 0.6, 0), font);
  gl::translate(Vec2f(375, 0));
  gl::drawString("必要数", Vec2f::zero(), Color(1, 0.6, 0), font);
  gl::translate(Vec2f(200, 0));
  gl::drawString("所持数", Vec2f::zero(), Color(1, 0.6, 0), font);
  gl::popModelView();

  for (auto item : items) {
    gl::pushModelView();
    gl::translate(item.getPos());
    gl::drawCube(Vec3f::zero(), Vec3f(5, 5, 5));
    gl::drawString(item.getName(), Vec2f::zero(),
                   Color(1, 1, 1), font);

    gl::translate(Vec2f(400, 0));
    gl::drawString(std::to_string(item.getNecessaryNum()),
                   Vec2f::zero(),
                   Color(1, 1, 1), font);

    gl::translate(Vec2f(200, 0));
    gl::drawString(std::to_string(item.getCurrentNum()),
                   Vec2f::zero(),
                   Color(1, 1, 1), font);
    gl::popModelView();
  }
}
