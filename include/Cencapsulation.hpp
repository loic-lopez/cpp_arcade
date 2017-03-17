//
// Cencapsulation.hpp for encapsulation in /home/prost_m/Rendu/Semestre_4/cpp_arcade/include/
//
// Made by Matthias Prost
// Login   <matthias.prost@epitech.eu@epitech.eu>
//
// Started on  Fri Mar 17 16:22:17 2017 Matthias Prost
// Last update Fri Mar 17 16:36:24 2017 Matthias Prost
//

#ifndef _CENCAPSULATION_HPP_
#define _CENCAPSULATION_HPP_

#include <dlfcn.h>
#include <string>

class   Cencapsulation
{
  public:
    static void         *c_dlopen(const char *filename, int flag);
    static std::string  c_dlerror(void);
    static void         *c_dlsym(void *handle, const char *symbol);
    static int          c_dlclose(void *handle);
};

#endif
