#pragma once

#ifdef WIN32
  #define BrickEngine_EXPORT __declspec(dllexport)
#else
  #define BrickEngine_EXPORT
#endif

BrickEngine_EXPORT void BrickEngine();
