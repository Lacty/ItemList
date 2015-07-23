
#include "task.h"


Task& Task::getInstance() {
  static Task task;
  return task;
}


void Task::add(const std::string& name,
               const std::shared_ptr<Object>& obj) {
  obj->setName(name);
  list.emplace_back(obj);
  map.emplace(name, obj);
}

void Task::clear() {
  list.clear();
  map.clear();
}

void Task::clean() {
  auto itr = map.begin();
  while (itr != map.end()) {
    if (itr->second->isDead()) {
      itr = map.erase(itr);
      continue;
    }
    else {
      ++itr;
    }
  }
  list.remove_if([](const std::weak_ptr<Object>& obj) {
    return obj.lock()->isDead();
  });
}

void Task::update() {
  auto itr = list.begin();
  while (itr != list.end()) {
    if (itr->get()->isAwake()) {
      itr->get()->setup();
      itr->get()->setState(Object::State::Active);
      ++itr;
      continue;
    }
    if (itr->get()->isDead()) {
      ++itr;
      Task::getInstance().clean();
      continue;
    }
    itr->get()->update();
    ++itr;
  }
}

void Task::draw() {
  for (auto& itr : list) {
    itr->draw();
  }
}
