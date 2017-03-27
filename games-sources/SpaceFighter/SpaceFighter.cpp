//
// snake.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/snake.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 14:52:43 2017 Loïc Lopez
// Last update Mon Mar 27 18:53:44 2017 Matthias Prost
//

#include "SpaceFighter.hpp"

extern "C" IGameModel *createInstanceGame(std::string const &libname)
{
  return (new SpaceFighter(libname));
}

SpaceFighter::SpaceFighter(std::string const &libname)
{
  this->libraryName = libname;
}

SpaceFighter::SpaceFighter(SpaceFighter const &spaceFighter)
{
  this->libraryName = spaceFighter.libraryName;
}

SpaceFighter &SpaceFighter::operator=(SpaceFighter const &spaceFighter)
{
  if (this != &spaceFighter)
    this->libraryName = spaceFighter.libraryName;
  return (*this);
}

SpaceFighter::~SpaceFighter()
{

}

void  SpaceFighter::wait_second(int toSleep)
{
  clock_t   ticks1, ticks2;

  ticks1 = clock();
  ticks2 = ticks1;
  while ((ticks2 / CLOCKS_PER_SEC - ticks1 / CLOCKS_PER_SEC) < toSleep)
    ticks2 = clock();
}

void SpaceFighter::setMap()
{
}

bool	SpaceFighter::play(ILibraryViewController *libraryInstance,
			       size_t &currentGame, size_t & currentLibrary,
			       bool &exit)
{

  (void)libraryInstance;
  (void)currentGame;
  (void)currentLibrary;
  (void)exit;
  return (true);
}

std::string	SpaceFighter::getGameName()
{
  return ("SpaceFighter");
}
