
#include "title.h"
#include "cinder/gl/gl.h"
#include "../../Object/task.h"
#include "../../Object/Item/item_manager.h"


using namespace ci;
using namespace ci::app;

Title::Title() {
  font = Font(loadAsset("rounded-l-mplus-1c-bold.ttf"), 100);
  Task::getInstance().add("item_manager",
                          std::make_shared<ItemManager>());
}

void Title::update() {
  updateObject();
}

void Title::draw() {
  drawObject();
  //::drawStringCentered("Title", Vec2f::zero(), Color(1, 1, 1), font);
}
