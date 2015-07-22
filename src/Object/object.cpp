
#include "object.h"


Object::Object() {}


void Object::setState(const State& state) {
  this->state = state;
}

const Object::State Object::getState() const {
  return state;
}

const bool Object::isAwake() const {
  return state == State::Awake;
}

const bool Object::isActive() const {
  return state == State::Active;
}

const bool Object::isDead() const {
  return state == State::Dead;
}


void Object::setName(const std::string& str) {
  this->name = str;
}

const std::string Object::getName() const {
  return name;
}
