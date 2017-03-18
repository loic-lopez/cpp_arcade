//
// Cencapsulation.cpp for Cencapsulation.cpp in /home/prost_m/Rendu/Semestre_4/cpp_arcade/sources/
//
// Made by Matthias Prost
// Login   <matthias.prost@epitech.eu@epitech.eu>
//
// Started on  Fri Mar 17 16:30:11 2017 Matthias Prost
// Last update Fri Mar 17 17:36:55 2017 Matthias Prost
//

#include "Cencapsulation.hpp"

void	*Cencapsulation::c_dlopen(const char *filename, int flag)
{
  return (dlopen(filename, flag));
}

std::string	Cencapsulation::c_dlerror(void)
{
  return (dlerror());
}

void	*Cencapsulation::c_dlsym(void *handle, const char *symbol)
{
  return (dlsym(handle, symbol));
}

int	Cencapsulation::c_dlclose(void *handle)
{
  return(dlclose(handle));
}

DIR	*Cencapsulation::c_opendir(const char *name)
{
  return (opendir(name));
}

struct dirent	*Cencapsulation::c_readdir(DIR *dirp)
{
  return (readdir(dirp));
}

int	Cencapsulation::c_closedir(DIR *dirp)
{
  return (closedir(dirp));
}

char	*Cencapsulation::c_strstr(char* str, const char* target)
{
  return (strstr(str, target));
}