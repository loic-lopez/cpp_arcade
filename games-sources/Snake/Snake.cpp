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

  if ((this->Map = (arcade::GetMap *)malloc(sizeof(arcade::GetMap) + (50 * 50 * sizeof(arcade::TileType))))== NULL)
    {
      std::cerr << "Error: can't allocate memory to create map" << std::endl;
      exit(EXIT_FAILURE);
    }
  this->Map->height = 50;
  this->Map->width = 50;
  this->Map->type = arcade::CommandType::PLAY;
  for (int i = 0; i < this->Map->height * this->Map->width; ++i)
      this->Map->tile[i] = arcade::TileType::EMPTY;
  pos.x = 0;
  pos.y = 0;
  for (int i = 0; i < 3; ++i)
    {
      this->_snake.push_back(pos);
      pos.x += 10;
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

  libraryInstance->initScreen(this->getGameName());
  this->setMap();
  while(libraryInstance->getKey(&this->Map->type, action, exit))
    {
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
	{
	  /*
	  libraryInstance->setUserXY(this->_snake[0].first, this->_snake[0].second);
	  if (this->_snake[0].second <= 0)
	    break;
	  this->_snake[0].second--;
	   */
      	}
      else if (this->Map->type == arcade::CommandType::GO_DOWN)
	{
	  /*
	  libraryInstance->setUserXY(this->_snake[0].first,
					 this->_snake[0].second);
	  if (this->_snake[0].second >= 41)
	    break;
	    */
      	}
      else if (this->Map->type == arcade::CommandType::GO_LEFT)
      	{
	  /*
	  libraryInstance->setUserXY(this->_snake[0].first,
					 this->_snake[0].second);
	  if (this->_snake[0].first <= 0)
	    break;
	  this->_snake[0].first--;
	  */
      	}
      else if (this->Map->type == arcade::CommandType::GO_RIGHT)
      	{
	  /*
	  libraryInstance->setUserXY(this->_snake[0].first,
					 this->_snake[0].second);
	  if (this->_snake[0].first >= 64)
	    break;
	  this->_snake[0].first++;
	  */
      	}
      this->drawMap(libraryInstance);
      libraryInstance->displayText(this->getGameName(), libraryInstance->getLibraryName());
      libraryInstance->refresh();
      if (libraryInstance->getLibraryName() == "Ncurses")
      	this->wait_second();
    }
  libraryInstance->endScreen();
  (void)currentGame;
  return (true);
}

std::string Snake::getGameName()
{
  return ("Snake");
}
