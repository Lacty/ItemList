
#pragma once
#include "../scene.h"
#include "cinder/gl/gl.h"


class Title : public Scene {
private:
  ci::Font font;

public:
  Title();

  void update();
  void draw();
};
