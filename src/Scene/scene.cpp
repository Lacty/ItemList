
#include "scene.h"


void Scene::updateObject() {}

void Scene::drawObject() {}


void Scene::setSceneType(const SceneType& type) {
  this->type = type;
}

SceneType Scene::getSceneType() const {
  return type;
}
