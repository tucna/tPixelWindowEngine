#include "imgui.h"
#include "imgui_impl_dx11.h"
#include "imgui_impl_win32.h"
#include "tpge/tPixelGameEngine.h"
#include "tpwe/tPWE.h"

namespace tPWE
{

class WindowEngine : public tDX::PixelGameEngine
{
public:
  //virtual bool OnEngineConstruction() override;
  virtual bool OnUserUpdateEndFrame(float fElapsedTime) override
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

  virtual bool OnUserCreate() override
  {
    sAppName = m_application->GetSettings().name;

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGui_ImplWin32_Init(GetHWND());
    ImGui_ImplDX11_Init(GetDevice(), GetContext());

    ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    return true;
  }

  virtual bool OnUserUpdate(float fElapsedTime) override
  {
    return true;
  }

  void AttachApplication(std::shared_ptr<Application> application) { m_application = application; }

private:
  std::shared_ptr<Application> m_application;
};

};

int main(int argc, char** argv)
{
  tPWE::WindowEngine engine;
  std::shared_ptr<tPWE::Application> app = CreateApplication(argc, argv);

  if (engine.Construct(app->GetSettings().windowWidth, app->GetSettings().windowHeight, app->GetSettings().pixelHeight, app->GetSettings().pixelWidth))
  {
    engine.AttachApplication(app);
    engine.Start();
  }

  return 0;
}
