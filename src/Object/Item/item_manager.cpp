
#include "item_manager.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;


ItemManager::ItemManager() {
  font = Font(loadAsset("rounded-l-mplus-1c-bold.ttf"), 21);
  items.push_back({ "ボディ2　6s", 8, 0 });
  items.push_back({ "リアクト2　6s", 8, 0 });
  items.push_back({ "マインド2　6s", 8, 0 });
  items.push_back({ "スピリタ3　6s", 4, 0 });
  items.push_back({ "ナイト　ウィン　6s", 12, 0 });
  items.push_back({ "ナイト　6s", 12, 0 });
  items.push_back({ "スティ　6s", 8, 0 });
  items.push_back({ "ウィン　スティ　6s", 4, 0 });
}

Item ItemManager::create() {
  Item item;

  return item;
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
