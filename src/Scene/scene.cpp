
#include "scene.h"
#include "../Object/task.h"


void Scene::updateObject() {
  Task::getInstance().update();
}

void Scene::drawObject() {
  Task::getInstance().draw();
}


void Scene::setSceneType(const SceneType& type) {
  this->type = type;
}

SceneType Scene::getSceneType() const {
  return type;
}
