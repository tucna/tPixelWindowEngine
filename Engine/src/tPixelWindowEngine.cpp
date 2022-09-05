#include "imgui.h"
#include "imgui_impl_dx11.h"
#include "imgui_impl_win32.h"

#include "tpge/tPixelGameEngine.h"

namespace tPWE
{

class WindowEngine : public tDX::PixelGameEngine
{
public:
  WindowEngine()
  {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
  }

  virtual bool OnEngineConstruction() override
  {
    return true;
  }

  virtual bool OnUserUpdateEndFrame(float fElapsedTime) override
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

  virtual bool OnUserCreate() override
  {
    ImGui_ImplWin32_Init(GetHWND());
    ImGui_ImplDX11_Init(GetDevice(), GetContext());

    ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    // Called once at the start, so create things here
    return true;
  }

  virtual bool OnUserUpdate(float fElapsedTime) override
  {
    return true;
  }
};

};

int main(int argc, char** argv)
{
  tPWE::WindowEngine engine;
  if (engine.Construct(400, 400, 2, 2))
    engine.Start();

  return 0;
}