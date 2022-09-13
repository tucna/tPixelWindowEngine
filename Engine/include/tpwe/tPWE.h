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
  std::string name = "tPixelWindowEngine application";
};

class Application
{
public:
  virtual void OnFrameRender() {}
  virtual void OnUIRender() {}
  virtual void OnCreate() {}

  void SetSettings(const ApplicationSettings& applicationSettings) { m_settings = applicationSettings; }
  const ApplicationSettings& GetSettings() const { return m_settings; }

  void SetRenderer(tDX::PixelGameEngine* renderer) { m_renderer = renderer; }
  const tDX::PixelGameEngine* GetRenderer() const { return m_renderer; }

  void DisableCustomDrawing() { m_customDrawing = false; }
  bool IsApplicationDrawing() { return m_customDrawing; }

private:
  ApplicationSettings m_settings;
  tDX::PixelGameEngine* m_renderer;
  bool m_customDrawing = true;
};

};

extern std::shared_ptr<tPWE::Application> CreateApplication(int argc, char** argv);
