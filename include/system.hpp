#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <iostream>
#include <X11/X.h>
#include <X11/Xlib.h>

#include "InputManager.hpp"
#include "Graphic.hpp"

#define ERROR  true
#define NO_ERROR false

class System
{
public:
  System();

  bool Init();
  void Run();
  void Destroy();

private:

  bool CreatWindow(int , int , std::string );

private:
  Window    m_Window;
  Display * m_pDisplay;
};


#endif
