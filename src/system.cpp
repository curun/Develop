
#include "system.hpp"

System::System()
{
  m_pDisplay = NULL;
}

bool
System::Init()
{
  return CreatWindow(1024, 768, "Test System");
}

void
System::Run()
{
  XEvent e;
  
  while (true) {

    XNextEvent(m_pDisplay, &e);

    if (e.type == KeyPress)
        break;

  }

}

void
System::Destroy()
{

}

bool
System::CreatWindow(int width, int height, std::string title)
{

  // Me conecto a XServer
  m_pDisplay = XOpenDisplay(NULL);
  if( !m_pDisplay ){
    std::cout << "Error conect to X Server" << std::endl;
    return ERROR;
  }

  // Consigo la ventana por default del systema
  auto root = DefaultRootWindow( m_pDisplay );
  int screenId = DefaultScreen( m_pDisplay );
  unsigned long border = BlackPixel(m_pDisplay, screenId);
  unsigned long background = WhitePixel(m_pDisplay, screenId);

  m_Window = XCreateSimpleWindow( m_pDisplay , // display
                                 root , // Parent
                                 0 , // X
                                 0 , // Y
                                 width ,
                                 height,
                                 1,// border_width
                                 border,
                                 background
                               );

  XSelectInput( m_pDisplay,
                m_Window,
                ExposureMask | KeyPressMask);

  XMapWindow(m_pDisplay, m_Window);


  return NO_ERROR;
}
