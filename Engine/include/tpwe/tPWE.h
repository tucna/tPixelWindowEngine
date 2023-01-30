#pragma once

#include <memory>
#include <string>

class tDX::PixelGameEngine;

namespace tPWE
{

struct ApplicationSettings
{
  unsigned int windowWidth = 400;
  unsigned int windowHeight = 400;
  unsigned int rtWidth = 200;
  unsigned int rtHeight = 200;
  unsigned int FPSLock = 0; // 0 = disabled
  std::string name = "tPixelWindowEngine application";
};

class Application
{
public:
  virtual void OnCreate() {}
  virtual void OnFixedUpdate() {}
  virtual void OnUpdate(float fElapsedTime) {};
  virtual void OnFrameRender(float fElapsedTime) {}
  virtual void OnUIRender(float fElapsedTime) {}

  void SetSettings(const ApplicationSettings& applicationSettings) { m_settings = applicationSettings; }
  const ApplicationSettings& GetSettings() const { return m_settings; }

  void SetRenderer(tDX::PixelGameEngine* renderer) { m_renderer = renderer; }
  tDX::PixelGameEngine* GetRenderer() const { return m_renderer; }

  void DisableCustomDrawing() { m_customDrawing = false; }
  bool IsApplicationDrawing() { return m_customDrawing; }

  const tDX::vi2d& GetMousePosition() { return m_mousePosition; }
  void SetMousePosition(const tDX::vi2d& mousePos) { m_mousePosition = mousePos; }

private:
  ApplicationSettings m_settings;
  tDX::PixelGameEngine* m_renderer;
  bool m_customDrawing = true;
  tDX::vi2d m_mousePosition = {0, 0};
};

};

extern std::shared_ptr<tPWE::Application> CreateApplication(int argc, char** argv);
