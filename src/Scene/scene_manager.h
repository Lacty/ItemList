
#pragma once
#include <memory>
#include "scene.h"
#include "scene_maker.h"


class SceneManager {
private:
  SceneType type;
  SceneMaker maker;
  std::unique_ptr<Scene> scene;

  void create(const SceneType& type);

public:
  SceneManager() = default;

  // 起動してはじめに実行されるシーンを設定
  SceneManager(const SceneType& type);

  void update();
  void draw();
};
