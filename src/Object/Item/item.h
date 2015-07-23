
#pragma once
#include <string>
#include "cinder/gl/gl.h"


class Item {
private:
  std::string name;
  ci::Vec2f   pos;
  ci::ColorA  color;

  int necessary_num;
  int current_num;

public:
  Item() = default;
  Item(const std::string& name,
       const int& nec,
       const int& cur) {
    setName(name);
    setNecessaryNum(nec);
    setCurrentNum(cur);
  }

  void setName(const std::string& name);
  void setPos(const ci::Vec2f& pos);
  void setColor(const ci::ColorA& color);

  void setNecessaryNum(const int& necessary);
  void setCurrentNum(const int& current);

  std::string getName() const;
  ci::Vec2f   getPos() const;
  ci::ColorA  getColor() const;

  int getNecessaryNum() const;
  int getCurrentNum() const;
};
