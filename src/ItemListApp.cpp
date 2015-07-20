
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "cinder/Camera.h"

#include "Scene/scene_manager.h"

using namespace ci;
using namespace ci::app;


class ItemListApp : public AppNative {
private:
  Vec3f rotate;

  Vec3f eye;
  Vec3f target;
  CameraPersp camera;

  SceneManager scene;

public:
  void setup();

  void mouseDown( MouseEvent event );

  void update();
  void draw();
};

void ItemListApp::setup() {
  rotate = Vec3f::zero();

  eye = Vec3f(0, 0, 700);
  target = Vec3f::zero();
  camera = CameraPersp(getWindowWidth(), getWindowHeight(),
                       35.f, 0.5f, 800.f);
  camera.lookAt(eye, target);

  scene = SceneManager(SceneType::Title);
}

void ItemListApp::mouseDown( MouseEvent event ) {}

void ItemListApp::update() {
  rotate += Vec3f(0.4, 0.6, 0);
}

void ItemListApp::draw() {
  gl::clear(Color(0, 0, 0));
  gl::setMatrices(camera);

  gl::pushModelView();
  gl::rotate(rotate);
  scene.draw();
  gl::popModelView();
}

CINDER_APP_NATIVE( ItemListApp, RendererGl )
