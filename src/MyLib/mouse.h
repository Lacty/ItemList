
#pragma once
#include "cinder/app/MouseEvent.h"
#include <set>


class Mouse {
public:
  struct MouseStatus {
    bool isPush;
    bool isPress;
    bool isPull;
  };

  static Mouse& getInstance();

  void flashInput();

  ci::Vec2i   Pos();
  MouseStatus Left();
  MouseStatus Right();

  void MoveEvent(ci::app::MouseEvent event);
  void PushEvent(ci::app::MouseEvent event);
  void PullEvent(ci::app::MouseEvent event);

private:
  Mouse();

  ci::Vec2i   pos;
  MouseStatus left, right;
};
