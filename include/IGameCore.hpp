//
// IGameCore.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/IGameCore.hpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 17:56:32 2017 Loïc Lopez
// Last update Fri Mar 17 18:37:02 2017 Matthias Prost
//

#ifndef IGAMECORE_HPP__
# define IGAMECORE_HPP__

#include <string>
#include "Cencapsulation.hpp"
#include "IGameModel.hpp"
#include "ILibraryViewController.hpp"

typedef IGameModel *(*play_function_type)(std::string const &);
typedef ILibraryViewController *(*load_library_function_type)(void);

class IGameCore
{
private:
  virtual void  *openLibrary(char const *) = 0;
  virtual play_function_type getPlayFunction(void *) = 0;
  virtual load_library_function_type getLibrary(void *) = 0;
 public:
  virtual void	GameLauncher() = 0;
  virtual ~IGameCore() {}
};

#endif /* IGAMECORE_HPP__ */
