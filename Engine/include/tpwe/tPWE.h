#pragma once

#include <memory>
#include <string>

namespace tPWE
{

struct ApplicationSettings
{
  unsigned int windowWidth = 400;
  unsigned int windowHeight = 400;
  unsigned int pixelWidth = 2;
  unsigned int pixelHeight = 2;
  std::string name = "tPixelWindowEngine application";
};

class Application
{
public:
  virtual void OnAttach() {}
  virtual void OnDetach() {}
  virtual void OnUIRender() {}

  void SetSettings(const ApplicationSettings& applicationSettings) { m_settings = applicationSettings; }
  const ApplicationSettings& GetSettings() const { return m_settings; }

private:
  ApplicationSettings m_settings;
};

};

extern std::shared_ptr<tPWE::Application> CreateApplication(int argc, char** argv);
