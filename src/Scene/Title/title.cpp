
#include "title.h"
#include "cinder/gl/gl.h"
#include "../../Object/task.h"


using namespace ci;
using namespace ci::app;

Title::Title() {
  font = Font(ci::app::loadAsset("rounded-l-mplus-1c-bold.ttf"), 100);
}

void Title::update() {
  updateObject();
}

void Title::draw() {
  drawObject();
  gl::drawStringCentered("Title", Vec2f::zero(), Color(1, 1, 1), font);
}
