#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui_internal.h"

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

    ImGui::Begin("Viewport");

    ImGui::BeginChild("GameRender");
    ImVec2 rtSize = {(float)m_renderTarget->width, (float)m_renderTarget->height};
    ImVec2 wSize = ImGui::GetWindowSize();
    float asp = rtSize.x / rtSize.y;

    rtSize.x = wSize.x;
    rtSize.y = rtSize.x / asp;

    if (rtSize.y > wSize.y)
    {
      rtSize.y = wSize.y;
      rtSize.x = rtSize.y * asp;
    }

    ImVec2 position = (ImGui::GetWindowSize() - rtSize) * 0.5f;

    ImGui::SetCursorPos(position);
    ImGui::Image((void*)m_RTView.Get(), rtSize);
    ImGui::EndChild();

    ImGui::End();

    ImGui::Render();
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

    return true;
  }

  virtual bool OnUserCreate() override
  {
    // Application settings
    sAppName = m_application->GetSettings().name;

    // ImGUI settings
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGui_ImplWin32_Init(GetHWND());
    ImGui_ImplDX11_Init(GetDevice(), GetContext());

    ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    // Other settings
    m_renderTarget = std::make_unique<tDX::Sprite>(m_application->GetSettings().rtWidth, m_application->GetSettings().rtHeight);

    SetDrawTarget(m_renderTarget.get());

    // Viewport
    D3D11_TEXTURE2D_DESC desc = {};
    desc.Width = m_renderTarget->width;
    desc.Height = m_renderTarget->height;
    desc.MipLevels = 1;
    desc.ArraySize = 1;
    desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    desc.SampleDesc.Count = 1;
    desc.Usage = D3D11_USAGE_DEFAULT;
    desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
    desc.CPUAccessFlags = 0;

    D3D11_SUBRESOURCE_DATA subResource = {};
    subResource.pSysMem = m_renderTarget->GetData();
    subResource.SysMemPitch = m_renderTarget->width * 4;
    subResource.SysMemSlicePitch = 0;
    GetDevice()->CreateTexture2D(&desc, &subResource, &m_RTTexture);

    D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
    srvDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
    srvDesc.Texture2D.MipLevels = desc.MipLevels;
    srvDesc.Texture2D.MostDetailedMip = 0;
    GetDevice()->CreateShaderResourceView(m_RTTexture.Get(), &srvDesc, &m_RTView);

    return true;
  }

  virtual bool OnUserUpdate(float fElapsedTime) override
  {
    m_application->OnFrameRender();

    GetContext()->UpdateSubresource(m_RTTexture.Get(), 0, NULL, m_renderTarget->GetData(), m_renderTarget->width * 4, 0);

    return true;
  }

  void AttachApplication(std::shared_ptr<Application> application) { m_application = application; }

private:
  std::shared_ptr<Application> m_application;
  std::unique_ptr<tDX::Sprite> m_renderTarget;

  Microsoft::WRL::ComPtr<ID3D11Texture2D> m_RTTexture;
  Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_RTView;
};

};

int tPWE_Main(int argc, char** argv)
{
  tPWE::WindowEngine engine;
  std::shared_ptr<tPWE::Application> app = CreateApplication(argc, argv);

  app->SetRenderer(&engine);

  if (engine.Construct(app->GetSettings().windowWidth, app->GetSettings().windowHeight, 1, 1))
  {
    engine.AttachApplication(app);
    engine.Start();
  }

  return 0;
}

#ifdef _DEBUG
int main(int argc, char** argv)
{
  tPWE_Main(argc, argv);
}
#else
#include <Windows.h>

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
  tPWE_Main(__argc, __argv);
}
#endif // _DEBUG
