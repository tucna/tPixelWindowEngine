#include <iostream>
#include <memory>

#include "tPWE.h"

//extern tPWE::ApplicationSettings tPWE::appSettings = { 600, 400, 2, 2, "Testing app" };

class TestApp : public tPWE::Application
{
};

tPWE::Application* CreateApplication(int argc, char** argv)
{
  tPWE::ApplicationSettings settings;
  settings.name = "Testing app";

  return new TestApp();
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