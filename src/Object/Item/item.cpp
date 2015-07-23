
#include "item.h"


void Item::setName(const std::string& name) {
  this->name = name;
}

void Item::setPos(const ci::Vec2f& pos) {
  this->pos = pos;
}

void Item::setColor(const ci::ColorA& color) {
  this->color = color;
}

void Item::setNecessaryNum(const int& necessary) {
  this->necessary_num = necessary;
}

void Item::setCurrentNum(const int& current) {
  this->current_num = current;
}

std::string Item::getName() const {
  return name;
}

ci::Vec2f Item::getPos() const {
  return pos;
}

ci::ColorA Item::getColor() const {
  return color;
}

int Item::getNecessaryNum() const {
  return necessary_num;
}

int Item::getCurrentNum() const {
  return current_num;
}
