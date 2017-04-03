//
// snake.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/snake.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 14:52:43 2017 Loïc Lopez
// Last update Mon Apr  3 02:02:30 2017 Matthias Prost
//

#include "SolarFox.hpp"

extern "C" IGameModel *createInstanceGame(std::string const &libname)
{
  return (new SolarFox(libname));
}

SolarFox::SolarFox(std::string const &libname)
{
  this->libraryName = libname;
  if ((this->Map = (arcade::GetMap *)malloc(sizeof(arcade::GetMap) + (45 * 60 * sizeof(arcade::TileType))))== NULL)
    {
      std::cerr << "Error: can't allocate memory to create map" << std::endl;
      exit(EXIT_FAILURE);
    }
  this->Map->height = 45;
  this->Map->width = 60;
  for (int i = 0; i < this->Map->height * this->Map->width; i++)
      this->Map->tile[i] = arcade::TileType::EMPTY;
  this->alreadyLaunch = false;
}

SolarFox::SolarFox(SolarFox const &SolarFox)
{
  this->libraryName = SolarFox.libraryName;
  this->score = 0;
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
  while ((ticks2 / (CLOCKS_PER_SEC / 1000) - ticks1
					     / (CLOCKS_PER_SEC / 1000)) < toSleep)
    ticks2 = clock();
}

void SolarFox::drawMap(ILibraryViewController *libraryInstance)
{
  int   i;
  int   size = this->Map->height * this->Map->width;

  i = -1;
  while (++i < size)
    {
      if (this->Map->tile[i] == arcade::TileType::BLOCK)
	       libraryInstance->drawSquare(i % this->Map->width - 15,
           i / this->Map->width, Color::CYAN);
      else
	       libraryInstance->drawSquare(i % this->Map->width - 15,
           i / this->Map->width, Color::BLACK);
    }
  if (libraryInstance->getLibraryName() == "Ncurses")
    this->wait_second(75);
  else if (libraryInstance->getLibraryName() == "SFML")
    this->wait_second(67);
}

void SolarFox::setMap()
{
  int   			i;
  int 			size = this->Map->width * this->Map->height;

  i = -1;
  while (++i < size)
    {
      if (i % this->Map->width == 0 || i / this->Map->width == 0
    || i % this->Map->width == this->Map->width - 1
    || i / this->Map->width == this->Map->height - 1)
      this->Map->tile[i] = arcade::TileType::BLOCK;
    }
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
  if (!this->alreadyLaunch)
    {
      libraryInstance->initScreen(this->getGameName());
      this->setMap();
      this->alreadyLaunch = true;
    }
  while (libraryInstance->getKey(&this->Map->type, action, exit))
  {
    this->drawMap(libraryInstance);
    if (this->Map->type == arcade::CommandType::RESTART)
      {
        this->alreadyLaunch = true;
        this->score = 0;
        action = ChangeCommandType::RESTART;
        return (action);
      }
    if (action == ChangeCommandType::NEXT_LIBRARY)
      {
        currentLibrary++;
        this->alreadyLaunch = false;
        break;
      }
    else if (action == ChangeCommandType::PREV_LIBRARY)
      {
        currentLibrary--;
        this->alreadyLaunch = false;
        break;
      }
    else if (action == ChangeCommandType::PREV_GAME)
      {
        currentGame--;
        break;
      }
    else if (action == ChangeCommandType::NEXT_GAME)
      {
        currentGame++;
        break;
      }
    libraryInstance->refresh();
  }
  libraryInstance->endScreen();
  (void)libraryInstance;
  (void)currentGame;
  (void)currentLibrary;
  (void)exit;
  return (action);
}

std::string	SolarFox::getGameName()
{
  return ("SolarFox");
}

void  SolarFox::playProtocol()
{

}
