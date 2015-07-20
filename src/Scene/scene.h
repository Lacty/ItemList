
#pragma once


enum class SceneType {
  Title,
  Main
};

class Scene {
protected:
  SceneType type;

  void updateObject();
  void drawObject();

public:
  void setSceneType(const SceneType& type);
  SceneType getSceneType() const;

  virtual void update() = 0;
  virtual void draw() = 0;
};
