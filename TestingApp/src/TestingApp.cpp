#include <iostream>
#include <memory>

#include "imgui/imgui.h"
#include "tpge/tPixelGameEngine.h"
#include "tpwe/tPWE.h"

class TestApp : public tPWE::Application
{
public:
  virtual void OnUIRender() override
  {
    ImGui::ShowDemoWindow();
  }

  virtual void OnFrameRender() override
  {
    tDX::PixelGameEngine renderer = *GetRenderer();

    for (int x = 0; x < renderer.GetDrawTargetWidth(); x++)
      for (int y = 0; y < renderer.GetDrawTargetHeight(); y++)
        renderer.Draw(x, y, tDX::Pixel(rand() % 255, rand() % 255, rand() % 255));

    renderer.DrawString(5, 5, "TUCNA");
  }
};

std::shared_ptr<tPWE::Application> CreateApplication(int argc, char** argv)
{
  tPWE::ApplicationSettings settings;
  settings.windowWidth = 1600;
  settings.windowHeight = 900;
  settings.rtWidth = 800;
  settings.rtHeight = 600;
  settings.name = "Testing app";

  std::shared_ptr<TestApp> app = std::make_shared<TestApp>();
  app->SetSettings(settings);

  return app;
}
