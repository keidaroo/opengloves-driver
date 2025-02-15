#pragma once

#include "opengloves_interface.h"

class ICommunicationManager {
 public:
  virtual void BeginListener(std::function<void(const og::Input&)> callback) = 0;

  virtual void WriteOutput(const og::Output& output) = 0;

  virtual ~ICommunicationManager() = default;
};