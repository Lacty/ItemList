
#pragma once
#include <string>


class Object {
public:
  enum class State {
    Awake,
    Active,
    Dead
  };

  Object();

  void setState(const State& state);
  const State getState() const;

  const bool isAwake() const;
  const bool isActive() const;
  const bool isDead() const;

  void setName(const std::string& str);
  const std::string getName() const;

  virtual void setup() = 0;
  virtual void update() = 0;
  virtual void draw() = 0;

protected:
  std::string name;
  State state;
};
