//
// snake.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/snake.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 14:52:43 2017 Loïc Lopez
// Last update Fri Mar 31 15:50:39 2017 Matthias Prost
//

#include "SolarFox.hpp"

extern "C" IGameModel *createInstanceGame(std::string const &libname, bool const &display)
{
  return (new SolarFox(libname, display));
}

SolarFox::SolarFox(std::string const &libname, bool const &display)
{
  this->libraryName = libname;
  this->display = display;
}

SolarFox::SolarFox(SolarFox const &SolarFox)
{
  this->libraryName = SolarFox.libraryName;
}

SolarFox &SolarFox::operator=(SolarFox const &SolarFox)
{
  if (this != &SolarFox)
    this->libraryName = SolarFox.libraryName;
  return (*this);
}

SolarFox::~SolarFox()
{

}

void  SolarFox::wait_second(int toSleep)
{
  clock_t   ticks1, ticks2;

  ticks1 = clock();
  ticks2 = ticks1;
  while ((ticks2 / CLOCKS_PER_SEC - ticks1 / CLOCKS_PER_SEC) < toSleep)
    ticks2 = clock();
}

void drawMap(ILibraryViewController *libraryInstance)
{
  (void)libraryInstance;
}

void SolarFox::setMap()
{
}

void Play()
{

}

int         SolarFox::getScore()
{
  return (this->score);
}

void         SolarFox::setScore(int value)
{
  this->score =+ value;
}

ChangeCommandType	SolarFox::play(ILibraryViewController *libraryInstance,
			       size_t &currentGame, size_t & currentLibrary,
			       bool &exit)
{

  (void)libraryInstance;
  (void)currentGame;
  (void)currentLibrary;
  (void)exit;
  return (ChangeCommandType::STANDBY);
}

std::string	SolarFox::getGameName()
{
  return ("SolarFox");
}
