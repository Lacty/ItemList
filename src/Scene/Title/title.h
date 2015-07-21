
#pragma once
#include "../scene.h"


class Title : public Scene {
private:
    ci::Font font;

public:
  Title();

  void update();
  void draw();
};
