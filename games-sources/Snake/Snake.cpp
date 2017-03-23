//
// Snake.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/Snake.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 14:55:07 2017 Loïc Lopez
// Last update Thu Mar 23 17:41:24 2017 Matthias Prost
//

#include <array>
#include "Snake.hpp"

extern "C" IGameModel *createInstanceGame()
{
  return (new Snake());
}

Snake::Snake()
{
  this->characterPosition = {3, 3};
  this->pos_x = 35;
  this->pos_y = 25;
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

void	Snake::setCharacterPosition(std::array<int, 2> &position)
{
  (void)position;
}

std::array<int, 2> &Snake::getCharacterPosition()
{
  return (this->characterPosition);
};

void Snake::setMap()
{
  int   y, x;

  x = -1;
  y = -1;
  while (++y != 70)
  {
    while (++x != 50)
      this->map[y][x] = 0;
    x = -1;
  }
}

void Snake::getInputs()
{
}

bool	Snake::play(ILibraryViewController *libraryInstance,
			size_t &currentGame, size_t &currentLibrary,
			bool &exit)
{
  ILibraryViewController::Key	action = ILibraryViewController::Key::STANDBY;

  libraryInstance->initScreen(this->getGameName());
  setMap();
  libraryInstance->setUserXY(this->pos_x, this->pos_y);
  while(libraryInstance->getKey(action, exit))
    {
      if (action == ILibraryViewController::Key::NEXT_GAME)
        {
          currentLibrary++;
          break;
        }
      else if (action == ILibraryViewController::Key::PREV_GAME)
        {
          currentLibrary--;
          break;
        }
      else if (action == ILibraryViewController::Key::UP)
      {
        libraryInstance->setUserXY(this->pos_x, this->pos_y + 1);
        this->pos_y++;
      }
      else if (action == ILibraryViewController::Key::DOWN)
      {
        libraryInstance->setUserXY(this->pos_x, this->pos_y - 1);
        this->pos_y--;
      }
      else if (action == ILibraryViewController::Key::LEFT)
      {
        libraryInstance->setUserXY(this->pos_x - 1, this->pos_y);
        this->pos_x--;
      }
      else if (action == ILibraryViewController::Key::RIGHT)
      {
        libraryInstance->setUserXY(this->pos_x + 1, this->pos_y);
        this->pos_x++;
      }
      libraryInstance->refresh();
    }
  libraryInstance->endScreen();
  (void)currentGame;
  return (true);
}

std::string Snake::getGameName()
{
  return ("Snake");
}