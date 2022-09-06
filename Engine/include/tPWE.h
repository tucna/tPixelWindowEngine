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
/*
class Plugin
{
public:
  virtual void OnAttach() {}
  virtual void OnDetach() {}
  virtual void OnUIRender() {}
};
*/
class Application
{
public:
  void SetSettings(const ApplicationSettings& applicationSettings)
  {
    m_settings = applicationSettings;
  }

  ~Application() {}

  virtual void OnAttach() {}
  virtual void OnDetach() {}
  virtual void OnUIRender() {}

  const ApplicationSettings& GetSettings() const
  {
    return m_settings;
  }

  /*
  template<typename T>
  void AttachPlugin()
  {
    static_assert(std::is_base_of<Plugin, T>::value, "Pushed type is not subclass of Plugin!");
    m_plugins.emplace_back(std::make_shared<T>())->OnAttach();
  }
  */
private:
  ApplicationSettings m_settings;

  //std::vector<std::shared_ptr<Plugin>> m_plugins;
};

};

extern tPWE::Application* CreateApplication(int argc, char** argv);

