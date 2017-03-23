/*
** GameCoreLibrary.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/GameCoreLibrary.cpp
**
** Made by Loïc Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  sam. mars 18 17:27:22 2017 Loïc Lopez
** Last update sam. mars 18 17:27:22 2017 Loïc Lopez
*/

#include "GameCore.hpp"

void	*GameCore::openLibrary(char const *libraryName)
{
  void	*file;

  file = Cencapsulation::c_dlopen(libraryName, RTLD_LAZY);
  if (!file)
    {
      std::cerr << Cencapsulation::c_dlerror() << std::endl;
      exit(EXIT_FAILURE);
    }
  return (file);
}

load_library_function_type	GameCore::getLibrary(void *library)
{
  load_library_function_type	play_function;

  play_function = reinterpret_cast<load_library_function_type>(Cencapsulation::c_dlsym(library, "loadLibrary"));
  if (!play_function)
    {
      std::cerr << Cencapsulation::c_dlerror() << std::endl;
      exit(EXIT_FAILURE);
    }
  return (play_function);
}

play_function_type	GameCore::getcreateInstanceGameFunction(void *game)
{
  play_function_type	play_function;

  play_function = reinterpret_cast<play_function_type>(Cencapsulation::c_dlsym(game, "createInstanceGame"));
  if (!play_function)
    {
      std::cerr << Cencapsulation::c_dlerror() << std::endl;
      exit(EXIT_FAILURE);
    }
  return (play_function);
}

void	GameCore::fillVector(std::vector<std::string> &vector, char const *folder)
{
  DIR   *dirp;
  struct dirent *entry;

  if ((dirp = Cencapsulation::c_opendir(folder)) == NULL)
    {
      std::cerr << "[ERROR] : opendir problem\n" << std::endl;
      exit(EXIT_FAILURE);
    }
  while ((entry = Cencapsulation::c_readdir(dirp)) != NULL)
    {
      if (entry == NULL)
	exit(EXIT_FAILURE);
      if (entry->d_name[0] != '.' && Cencapsulation::c_strstr(entry->d_name, ".so") != NULL)
	{
	  std::string	folderLibrary = folder;
	  folderLibrary += '/';
	  folderLibrary += entry->d_name;
	  vector.push_back(folderLibrary);
	}
    }
  Cencapsulation::c_closedir(dirp);
  if (vector.size() == 0)
    {
      std::cerr << "ERROR: Unable to find .so library in " << folder << std::endl;
      exit(EXIT_FAILURE);
    }
  std::sort(vector.begin(), vector.end());
}

size_t	GameCore::getCurrentLibrary(std::vector<std::string> const &Library)
{
  size_t	currentLibrary = 0;

  while (currentLibrary < Library.size())
    {
      if (Library.at(currentLibrary) == this->library_name)
	return (currentLibrary);
      currentLibrary++;
    }
  if (currentLibrary == Library.size())
    {
      std::cerr << "ERROR: Unable to find " << this->library_name << std::endl;
      exit(EXIT_FAILURE);
    }
  return (0);
}