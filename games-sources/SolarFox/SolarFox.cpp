//
// snake.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/snake.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 14:52:43 2017 Loïc Lopez
// Last update Sat Apr  1 23:45:29 2017 Matthias Prost
//

#include "SolarFox.hpp"

extern "C" IGameModel *createInstanceGame(std::string const &libname)
{
  return (new SolarFox(libname));
}

SolarFox::SolarFox(std::string const &libname)
{
  this->libraryName = libname;
  if ((this->Map = (arcade::GetMap *)malloc(sizeof(arcade::GetMap) + (35 * 35 * sizeof(arcade::TileType))))== NULL)
    {
      std::cerr << "Error: can't allocate memory to create map" << std::endl;
      exit(EXIT_FAILURE);
    }
    this->Map->height = 50;
    this->Map->width = 50;
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

void SolarFox::drawMap(ILibraryViewController *libraryInstance)
{
  libraryInstance->drawSquare(1, 1, Color::RED);
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
  ChangeCommandType action = ChangeCommandType::STANDBY;
  libraryInstance->initScreen(this->getGameName());
  while (libraryInstance->getKey(&this->Map->type, action, exit))
  {

  }
  libraryInstance->endScreen();
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

void  SolarFox::playProtocol()
{

}
