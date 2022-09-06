#include "imgui.h"
#include "imgui_impl_dx11.h"
#include "imgui_impl_win32.h"

#include "tpge/tPixelGameEngine.h"

#include "../include/tPWE.h"

#include "tPWEInterface.h"

namespace tPWE
{

WindowEngine::WindowEngine()
{

}

bool WindowEngine::OnEngineConstruction()
{
  return true;
}

bool WindowEngine::OnUserUpdateEndFrame(float fElapsedTime)
{
  ImGui_ImplDX11_NewFrame();
  ImGui_ImplWin32_NewFrame();
  ImGui::NewFrame();

  ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());

  m_application->OnUIRender();

  ImGui::Render();
  ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

  return true;
}

bool WindowEngine::OnUserCreate()
{
  sAppName = m_application->GetSettings().name;

  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGui::StyleColorsDark();

  ImGui_ImplWin32_Init(GetHWND());
  ImGui_ImplDX11_Init(GetDevice(), GetContext());

  ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;

  // Called once at the start, so create things here
  return true;
}

bool WindowEngine::OnUserUpdate(float fElapsedTime)
{
  return true;
}

};

int main(int argc, char** argv)
{
  tPWE::Application* app = CreateApplication(argc, argv);
  tPWE::WindowEngine engine;

  if (engine.Construct(app->GetSettings().windowWidth, app->GetSettings().windowHeight, app->GetSettings().pixelHeight, app->GetSettings().pixelWidth))
  {
    engine.AttachApplication(app);
    engine.Start();
  }

  return 0;
}