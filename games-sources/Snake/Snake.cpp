//
// Snake.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/Snake.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 14:55:07 2017 Loïc Lopez
// Last update Fri Mar 24 08:41:38 2017 Yassir Jabbari
//

#include <array>
#include "Snake.hpp"

extern "C" IGameModel *createInstanceGame(std::string const &libname)
{
  return (new Snake(libname));
}

Snake::Snake(std::string const &libname)
{
  this->libraryName =  libname;
  arcade::Position	pos;

  if ((this->Map = (arcade::GetMap *)malloc(sizeof(arcade::GetMap) + (35 * 35 * sizeof(arcade::TileType))))== NULL)
    {
      std::cerr << "Error: can't allocate memory to create map" << std::endl;
      exit(EXIT_FAILURE);
    }
  this->Map->height = 35;
  this->Map->width = 35;
  this->Map->type = arcade::CommandType::PLAY;
  for (int i = 0; i < this->Map->height * this->Map->width; ++i)
      this->Map->tile[i] = arcade::TileType::EMPTY;
  pos.x = this->Map->width / 2;
  pos.y = this->Map->height / 2;
  for (int i = 0; i < 4; ++i)
    {
      this->_snake.push_back(pos);
      pos.x += 1;
    }
}

Snake &Snake::operator=(Snake const &snake)
{
  if (this != &snake)
    this->libraryName = snake.libraryName;
  return (*this);
}

Snake::~Snake()
{
}

Snake::Snake(Snake const &snake)
{
  this->libraryName = snake.libraryName;
}

void			Snake::setMap()
{
  int   			i;
  int 			lenght = this->Map->width * this->Map->height;

  i = -1;
  while (++i < lenght)
    {
      if (i % this->Map->width == 0 || i / this->Map->width == 0
	  || i / this->Map->width == this->Map->width - 1
	  || i % this->Map->width  == this->Map->width - 1)
	this->Map->tile[i] = arcade::TileType::BLOCK;
    }
}

void			Snake::drawMap(ILibraryViewController *libraryInstance)
{
  int   			i;
  int 			lenght = this->Map->width * this->Map->height;

  i = -1;
  while (++i < lenght)
    {
      if (i % this->Map->width == 0 || i / this->Map->width == 0
	  || i / this->Map->width == this->Map->width - 1
	  || i % this->Map->width  == this->Map->width - 1)
	libraryInstance->drawSquare(i % this->Map->width, i / this->Map->width, Color::MAGENTA);
      else
	libraryInstance->drawSquare(i % this->Map->width, i / this->Map->width, Color::YELLOW);
    }
  for (size_t j = 0; j < this->_snake.size(); j++)
    libraryInstance->drawSquare(this->_snake.at(j).x, this->_snake.at(j).y, Color::RED);
}

void Snake::getInputs()
{
}

void  Snake::wait_second()
{
  clock_t   ticks1, ticks2;

  ticks1 = clock();
  ticks2 = ticks1;
  while ((ticks2 / (CLOCKS_PER_SEC / 1000) - ticks1 / (CLOCKS_PER_SEC / 1000)) < 125)
    ticks2 = clock();
}

bool	Snake::play(ILibraryViewController *libraryInstance,
			size_t &currentGame, size_t &currentLibrary,
			bool &exit)
{
  ChangeCommandType action = ChangeCommandType::STANDBY;
  size_t i = 0;

  libraryInstance->initScreen(this->getGameName());
  this->setMap();
  while (libraryInstance->getKey(&this->Map->type, action, exit))
    {
      if (i == this->_snake.size())
	i = 0;
      if (this->Map->type != arcade::CommandType::PLAY)
      	for (int j = _snake.size() - 1; j > 0 ; j--)
	  {
	    this->_snake.at(j).x = this->_snake.at(j - 1).x;
	    this->_snake.at(j).y = this->_snake.at(j - 1).y;
	  }
      if (action == ChangeCommandType::NEXT_LIBRARY)
        {
          currentLibrary++;
          break;
        }
      else if (action == ChangeCommandType::PREV_LIBRARY)
        {
          currentLibrary--;
          break;
        }
      else if (this->Map->type == arcade::CommandType::GO_UP)
	  this->_snake.at(0).y--;
      else if (this->Map->type == arcade::CommandType::GO_DOWN)
	  this->_snake.at(0).y++;
      else if (this->Map->type == arcade::CommandType::GO_LEFT)
	  this->_snake.at(0).x--;
      else if (this->Map->type == arcade::CommandType::GO_RIGHT)
	  this->_snake.at(0).x++;
      this->drawMap(libraryInstance);
      libraryInstance->displayText(this->getGameName(), libraryInstance->getLibraryName());
      libraryInstance->refresh();
      if (libraryInstance->getLibraryName() == "Ncurses")
      	this->wait_second();
      i++;
    }
  libraryInstance->endScreen();
  (void)currentGame;
  return (true);
}

std::string Snake::getGameName()
{
  return ("Snake");
}
