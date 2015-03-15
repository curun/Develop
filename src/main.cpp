#include <iostream>

#include "system.hpp"


int main(void)
{

  System * system = new System();

  if( system->Init() == ERROR )
    return 0;

  system->Run();

  system->Destroy();
  
  return 0;
}
