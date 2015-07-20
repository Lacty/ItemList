
#include "title.h"
#include "cinder/gl/gl.h"


void Title::update() {}

void Title::draw() {
    ci::gl::drawCube(ci::Vec3f::zero(),
                     ci::Vec3f(50, 50, 50));
}
