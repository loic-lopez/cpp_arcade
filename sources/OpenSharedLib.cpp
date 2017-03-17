//
// OpenSharedLib.cpp for arcade in /home/jabbar_y/rendu/cpp_arcade/sources
// 
// Made by Yassir Jabbari
// Login   <jabbar_y@epitech.net>
// 
// Started on  Fri Mar 17 16:24:45 2017 Yassir Jabbari
// Last update Fri Mar 17 16:41:30 2017 Yassir Jabbari
//

#include <dlfcn.h>
#include <iostream>

int		OpenSharedLib(std::string libName, std::string funcName)
{
  IAssistant *(*external_func)(); // Pointer of function of funcName
  void *handle;
  
  if (libName.empty() || funcName.empty())
    return (-1);
  handle = dlopen(libName.c_str(), RTLD_LAZY);
  if (!handle)
    {
      dlerror();
      return (-1);
    }
  external_func = reinterpret_cast<IAssistant *(*)()>(dlsym(handle, funcName.c_str()));
  if (!external_func)
    {
      dlerror();
      return (-1);
    }
  IAssistant *bob = external_func();
  bob->talk() // Call the function talk()
  dlclose(handle);
  return (0);
}
