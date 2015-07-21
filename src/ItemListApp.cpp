
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "cinder/Camera.h"
#include "cinder/gl/Light.h"

#include "Scene/scene_manager.h"

using namespace ci;
using namespace ci::app;


class ItemListApp : public AppNative {
private:
  Vec3f rotate;

  Vec3f eye;
  Vec3f target;
  CameraPersp camera;

  std::unique_ptr<gl::Light> light;

  SceneManager scene;

public:
  void setup();

  void mouseDown( MouseEvent event );

  void update();
  void draw();
};

void ItemListApp::setup() {
  rotate = Vec3f(180, 0, 0);

  eye = Vec3f(0, 0, 700);
  target = Vec3f::zero();
  camera = CameraPersp(getWindowWidth(), getWindowHeight(),
                       35.f, 0.5f, 800.f);
  camera.lookAt(eye, target);

  light = std::make_unique<gl::Light>(gl::Light::DIRECTIONAL, 0);
  light->setAmbient(Color(0.3, 0.3, 0.3));
  light->setDiffuse(Color(0.8, 0.8, 0.8));
  light->setDirection(Vec3f::zAxis());

  scene = SceneManager(SceneType::Title);

  gl::enable(GL_LIGHTING);
  gl::enableDepthRead();
}

void ItemListApp::mouseDown( MouseEvent event ) {}

void ItemListApp::update() {
  //rotate += Vec3f(0.4, 0.6, 0);
}

void ItemListApp::draw() {
  gl::clear(Color(0, 0, 0));
  gl::setMatrices(camera);
  light->enable();

  gl::pushModelView();
  gl::rotate(rotate);
  scene.draw();
  gl::popModelView();
}

CINDER_APP_NATIVE( ItemListApp, RendererGl )
