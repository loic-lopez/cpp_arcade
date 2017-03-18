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
#include <sys/types.h>
#include <dirent.h>
#include <string>
#include <cstring>

class   Cencapsulation
{
  public:
  	static	void		*c_dlopen(const char *filename, int flag);
  	static	std::string 	c_dlerror(void);
  	static	void		*c_dlsym(void *handle, const char *symbol);
  	static	int		c_dlclose(void *handle);
	static	DIR		*c_opendir(const char *name);
  	static	struct dirent	*c_readdir(DIR *dirp);
  	static	int 		c_closedir(DIR *dirp);
  	static	char		*c_strstr(char* str, const char* target );
};

#endif
