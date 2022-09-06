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
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGui::StyleColorsDark();

  //sAppName = appSettings.name;
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

  ImGui::ShowDemoWindow();

  ImGui::Render();
  ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

  return true;
}

bool WindowEngine::OnUserCreate()
{
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
  tPWE::WindowEngine engine;
  engine.AttachApplication(CreateApplication(argc, argv));

  //if (engine.Construct(tPWE::appSettings.windowWidth, tPWE::appSettings.windowHeight, tPWE::appSettings.pixelHeight, tPWE::appSettings.pixelWidth))
  //  engine.Start();

  return 0;
}