#include <iostream>
#include <memory>

#include "imgui/imgui.h"
#include "tpwe/tPWE.h"

class TestApp : public tPWE::Application
{
public:
  virtual void OnUIRender()
  {
    ImGui::ShowDemoWindow();

    ImGui::Begin("Viewport");
    ImGui::End();
  }
};

std::shared_ptr<tPWE::Application> CreateApplication(int argc, char** argv)
{
  tPWE::ApplicationSettings settings;
  settings.windowWidth = 1600;
  settings.windowHeight = 900;
  settings.name = "Testing app";

  std::shared_ptr<TestApp> app = std::make_shared<TestApp>();
  app->SetSettings(settings);

  return app;
}
