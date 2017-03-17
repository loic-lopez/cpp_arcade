//
// snake.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/snake.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 14:52:43 2017 Loïc Lopez
// Last update jeu. mars 16 14:52:43 2017 Loïc Lopez
//

#include "SpaceFighter.hpp"

extern "C" IGameModel *Play(std::string const &libraryName)
{
  return (new SpaceFighter(libraryName));
}

SpaceFighter::SpaceFighter(std::string const &libraryName)
{
  this->libraryName = libraryName;
  this->characterPosition = {3, 3};
  this->map[0] = 0;
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

void	SpaceFighter::setCharacterPosition(std::array<int, 2> &position)
{
  (void)position;
}

std::array<int, 2> &SpaceFighter::getCharacterPosition()
{
  return (this->characterPosition);
}

void SpaceFighter::setMap(std::map<int, int> &map)
{
  (void)map;
}

std::map<int, int>	&SpaceFighter::getMap()
{
  return (this->map);
}

void SpaceFighter::getInputs()
{

}

void SpaceFighter::changeLibrary(std::string const &libraryName)
{
  (void)libraryName;
}