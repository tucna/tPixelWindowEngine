#include <iostream>

#include "tpge/tPixelGameEngine.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_dx11.h"
#include "imgui/imgui_impl_win32.h"

class Example : public tDX::PixelGameEngine
{
public:
  Example()
  {
    sAppName = "Example";

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
  }

public:
  bool OnUserUpdateEndFrame(float fElapsedTime)
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

  bool OnUserCreate() override
  {
    ImGui_ImplWin32_Init(GetHWND());
    ImGui_ImplDX11_Init(GetDevice(), GetContext());

    ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;

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
  if (demo.Construct(400, 400, 2, 2))
    demo.Start();

  return 0;
}
