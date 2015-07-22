
#include "title.h"
#include "cinder/gl/gl.h"
#include "../../Object/task.h"


using namespace ci;

Title::Title() {
  font = Font(ci::app::loadAsset("rounded-l-mplus-1c-bold.ttf"), 50);
}

void Title::update() {
  updateObject();
}

void Title::draw() {
  drawObject();
  using namespace ci::gl;
  drawStringCentered("私は梁井nice to meet you",
                     Vec2f::zero(),
                     ColorA(1, 1, 1),
                     font);
}
