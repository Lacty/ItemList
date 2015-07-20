
#include "scene_maker.h"
#include "Title/title.h"

#include <functional>
#include <unordered_map> // 検索かける際mapより高速


std::unique_ptr<Scene> SceneMaker::create(const SceneType& type) const {
  using namespace std;
  unordered_map<SceneType, function<unique_ptr<Scene>()>> list = {
    { SceneType::Title, []{ return make_unique<Title>(); } }
  };

  // データの大きさが不定なのでmoveを使用する
  return std::move((list.find(type)->second)());
}
