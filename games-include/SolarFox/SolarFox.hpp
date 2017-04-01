/*
** SolarFox.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/SolarFox.hpp.hpp
**
** Made by Loïc Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  jeu. mars 16 16:02:17 2017 Loïc Lopez
** Last update Fri Mar 31 15:53:40 2017 Matthias Prost
*/

#ifndef SolarFox_HPP__
# define SolarFox_HPP__

#include <iostream>
#include "../interface/IGameModel.hpp"

extern "C" IGameModel *createInstanceGame(std::string const &libname);

class SolarFox : public IGameModel
{
 private:
  std::string	libraryName;
  int   pos_x;
  int   pos_y;
  int   score;
  virtual void  wait_second(int);

 public:
  SolarFox(std::string const &libname);
  SolarFox(SolarFox const &);
  SolarFox &operator=(SolarFox const &);
  virtual ~SolarFox();

  // Methods
  virtual void setMap();
  virtual void drawMap(ILibraryViewController *libraryInstance);
  virtual ChangeCommandType	play(ILibraryViewController *library, size_t &currentGame, size_t &currentLibrary, bool &);
  virtual int  getScore();
  virtual void setScore(int);
  virtual std::string getGameName();
  virtual void  playProtocol(void);
};

#endif /* SolarFox_HPP__ */
