//
// pacman.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/pacman.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 14:55:07 2017 Loïc Lopez
// Last update Tue Mar 21 21:17:40 2017 Matthias Prost
//

#include <array>
#include "Snake.hpp"

extern "C" IGameModel *Play()
{
  return (new Snake());
}

Snake::Snake()
{
  this->characterPosition = {3, 3};
  this->map[0] = 0;
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

void Snake::setMap(std::map<int, int> &map)
{
  (void)map;
}

std::map<int, int>	&Snake::getMap()
{
  return (this->map);
}

void Snake::getInputs()
{
}

void Snake::changeLibrary(std::string const &libraryName)
{
  (void)libraryName;
}

bool	Snake::play(ILibraryViewController *libraryInstance,
			       size_t &currentGame, size_t &currentLibrary)
{
  int key = 0;

  libraryInstance->initScreen();
  while(libraryInstance->getEscapeKey(key) == true)
    {
      if (key == 1)
        {
          currentLibrary++;
          break;
        }
      else if (key == 2)
        {
          currentLibrary--;
          break;
        }
      libraryInstance->displayText("Snek");
    }
  libraryInstance->endScreen();
  (void)currentGame;
  return (true);
}
