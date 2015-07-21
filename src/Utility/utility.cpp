
#include "utility.h"
#include "cinder/Unicode.h"


using namespace ci;

void widen(const std::string& src, std::wstring& dest) {
  wchar_t* wcs = new wchar_t[src.length() + 1];
  mbstowcs(wcs, src.c_str(), src.length() + 1);
  dest = wcs;
  delete[] wcs;
}

void ly::drawStringCenterdUtf8(const std::string& str,
                               const ci::Vec2f& pos,
                               const ci::ColorA& color,
                               const ci::Font& font) {
  std::wstring wstr;
  widen(str, wstr);
  gl::drawStringCentered(toUtf8((char16_t*)wstr.c_str()),
                         pos, color, font);
}
