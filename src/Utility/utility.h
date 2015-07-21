
#pragma onc
#include <string>
#include "cinder/gl/gl.h"


// string -> wtring 変換
void widen(const std::string& src, std::wstring& dest);

namespace ly {
  void drawStringCenterdUtf8(const std::string& str,
                             const ci::Vec2f& pos,
                             const ci::ColorA& color,
                             const ci::Font& font);
}
