
#pragma once
#include "object.h"
#include <memory>
#include <list>
#include <map>


class Task {
private:
  std::list<std::shared_ptr<Object>> list;
  std::map<std::string, std::shared_ptr<Object>> map;

  Task() = default;

public:
  static Task& getInstance();

  void add(const std::string& name,
           const std::shared_ptr<Object>& obj);

  // タスクを全て消去
  void clear();

  // 死亡したオブジェクトを消去
  void clean();

  void update();
  void draw();
};
