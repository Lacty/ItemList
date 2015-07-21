
#include "title.h"
#include "cinder/gl/gl.h"
#include "../../Utility/utility.h"


using namespace ci;

Title::Title() {
  font = Font(ci::app::loadAsset("rounded-l-mplus-1c-regular.ttf"), 50);
}

void Title::update() {}

void Title::draw() {
    //gl::drawCube(Vec3f::zero(),
    //             Vec3f(50, 50, 50));
    ly::drawStringCenterdUtf8("あばば", Vec2f::zero(), ColorA(1, 1, 1), font);
}
