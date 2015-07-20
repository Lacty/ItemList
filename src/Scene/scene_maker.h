
#pragma once
#include "scene.h"
#include <memory>


class SceneMaker {
public:
  SceneMaker() = default;

  std::unique_ptr<Scene> create(const SceneType& type) const;
};
