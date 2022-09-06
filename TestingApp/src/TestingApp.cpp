#include <iostream>
#include <memory>

#include "imgui/imgui.h"
#include "tPWE.h"

//extern tPWE::ApplicationSettings tPWE::appSettings = { 600, 400, 2, 2, "Testing app" };

class TestApp : public tPWE::Application
{
public:
  virtual void OnUIRender()
  {
    ImGui::ShowDemoWindow();
  }
};

tPWE::Application* CreateApplication(int argc, char** argv)
{
  tPWE::ApplicationSettings settings;
  settings.name = "Testing app";

  TestApp* app = new TestApp();
  app->SetSettings(settings);

  return app;
}

/*
Walnut::Application* Walnut::CreateApplication(int argc, char** argv)
{
  Walnut::ApplicationSpecification spec;
  spec.Name = "Walnut Example";

  Walnut::Application* app = new Walnut::Application(spec);
  app->PushLayer<ExampleLayer>();
  app->SetMenubarCallback([app]()
    {
      if (ImGui::BeginMenu("File"))
      {
        if (ImGui::MenuItem("Exit"))
        {
          app->Close();
        }
        ImGui::EndMenu();
      }
    });
  return app;
}
*/