#include <iostream>

#include "tpge/tPixelGameEngine.h"

class Example : public tDX::PixelGameEngine
{
public:
  Example()
  {
    sAppName = "Example";
  }

public:
  bool OnUserCreate() override
  {
    // Called once at the start, so create things here
    return true;
  }

  bool OnUserUpdate(float fElapsedTime) override
  {
    // called once per frame
    for (int x = 0; x < ScreenWidth(); x++)
      for (int y = 0; y < ScreenHeight(); y++)
        Draw(x, y, tDX::Pixel(rand() % 255, rand() % 255, rand() % 255));

    DrawString(5, 5, "TUCNA");

    return true;
  }
};

int main()
{
  Example demo;
  if (demo.Construct(250, 250, 4, 4))
    demo.Start();

  return 0;
}
