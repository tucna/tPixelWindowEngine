#pragma once

#include "tpge/tPixelGameEngine.h"

namespace tPWE
{

class WindowEngine : public tDX::PixelGameEngine
{
public:
  WindowEngine();

  virtual bool OnEngineConstruction() override;
  virtual bool OnUserUpdateEndFrame(float fElapsedTime) override;
  virtual bool OnUserCreate() override;
  virtual bool OnUserUpdate(float fElapsedTime) override;

  void AttachApplication(Application* application) { m_application = application; }

private:
  Application* m_application;
};

};