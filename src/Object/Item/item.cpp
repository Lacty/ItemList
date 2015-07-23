
#include "item.h"
#include "cinder/gl/gl.h"


void Item::setup() {}

void Item::update() {}

void Item::draw() {
  using namespace ci::gl;
  drawString("Item", ci::Vec2f::zero());
}
