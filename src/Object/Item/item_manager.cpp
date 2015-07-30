
#include "item_manager.h"
#include "cinder/gl/gl.h"
#include "cinder/Json.h"
#include "../../MyLib/mouse.h"
#include "../../MyLib/window_size.h"
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

void ItemManager::saveItems() {
  JsonTree data;
  data = JsonTree::makeObject("Materials");

  for (int i = 0; i < items.size(); ++i) {
    std::ostringstream item_num;
    item_num << "item" << i;
    JsonTree item = JsonTree::makeObject(item_num.str());
    item.addChild(JsonTree("name", items[i].getName()));
    item.addChild(JsonTree("nece", items[i].getNecessaryNum()));
    item.addChild(JsonTree("curr", items[i].getCurrentNum()));
    data.addChild(item);
  }

  data.write(getAppPath() / "../../../../assets/data.json", JsonTree::WriteOptions().createDocument(true));
}

void ItemManager::setup() {
  Vec2f init_pos = Vec2f(-320, -160);
  int offset = 40;
  for (int i = 0; i < items.size(); ++i) {
    items[i].setPos(Vec2f(init_pos.x, init_pos.y + i * offset));
  }
}

void ItemManager::update() {
  if (Mouse::getInstance().Left().isPush) {
    mouse_pos = Vec3f((Mouse::getInstance().Pos().x - int(WindowSize::Width) / 2) * 1.1f,
                      (Mouse::getInstance().Pos().y - int(WindowSize::Height) / 2) * 1.1f, 0);
    console() << mouse_pos << std::endl;;
    for (int i = 0; i < items.size(); ++i) {
      if (mouse_pos.y > items[i].getPos().y - 5 && mouse_pos.y < items[i].getPos().y - 5 + 40) {
        items[i].setCurrentNum(items[i].getCurrentNum() + 1);
      }
      saveItems();
    }
  } else
  if (Mouse::getInstance().Right().isPush) {
    mouse_pos = Vec3f((Mouse::getInstance().Pos().x - int(WindowSize::Width) / 2) * 1.1f,
                      (Mouse::getInstance().Pos().y - int(WindowSize::Height) / 2) * 1.1f, 0);
    console() << mouse_pos << std::endl;;
    for (int i = 0; i < items.size(); ++i) {
      if (mouse_pos.y > items[i].getPos().y - 5 && mouse_pos.y < items[i].getPos().y - 5 + 40) {
        items[i].setCurrentNum(items[i].getCurrentNum() - 1);
      }
      saveItems();
    }
  }
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

    gl::pushModelView();
    gl::translate(Vec2f(35, 0));
    gl::drawStrokedRect(Rectf(0, 0, (160 / item.getNecessaryNum()) * item.getCurrentNum(), 10));
    gl::popModelView();

    gl::translate(Vec2f(200, 0));
    gl::drawString(std::to_string(item.getCurrentNum()),
                   Vec2f::zero(),
                   Color(1, 1, 1), font);
    gl::popModelView();
  }
}
