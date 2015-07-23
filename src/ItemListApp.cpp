
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "MyLib/mouse.h"
#include "MyLib/window_size.h"

#include "cinder/Camera.h"
#include "cinder/gl/Light.h"

#include "Scene/scene_manager.h"

using namespace ci;
using namespace ci::app;


class ItemListApp : public AppNative {
private:
  Vec3f eye;
  Vec3f target;
  CameraPersp camera;

  std::unique_ptr<gl::Light> light;

  SceneManager scene;

public:
  void setup();

  void mouseDown(MouseEvent event) {
    Mouse::getInstance().PushEvent(event);
  }
  void mouseUp(MouseEvent event) {
    Mouse::getInstance().PullEvent(event);
  }
  void mouseMove(MouseEvent event) {
    Mouse::getInstance().MoveEvent(event);
  }
  void mouseDrag(MouseEvent event) {
    Mouse::getInstance().MoveEvent(event);
  }

  void update();
  void draw();
};

void ItemListApp::setup() {
  setWindowSize(int(WindowSize::Width),
                int(WindowSize::Height));

  eye = Vec3f(0, 0, 700);
  target = Vec3f::zero();
  camera = CameraPersp(getWindowWidth(), getWindowHeight(),
                       35.f, 0.5f, 800.f);
  camera.lookAt(eye, target);

  light = std::make_unique<gl::Light>(gl::Light::DIRECTIONAL, 0);
  light->setAmbient(Color(0.3, 0.3, 0.3));
  light->setDiffuse(Color(0.8, 0.8, 0.8));
  light->setDirection(-Vec3f::zAxis());

  scene = SceneManager(SceneType::Title);

  gl::enable(GL_LIGHTING);
  gl::enableDepthRead();
}

void ItemListApp::update() {
  scene.update();
}

void ItemListApp::draw() {
  gl::clear(Color(0, 0, 0));
  gl::setMatrices(camera);
  light->enable();

  gl::pushModelView();
  gl::rotate(Vec3f(180, 0, 0));
  scene.draw();
  gl::popModelView();
}

CINDER_APP_NATIVE( ItemListApp, RendererGl )
