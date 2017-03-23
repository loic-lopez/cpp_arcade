//
// snake.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/snake.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 14:52:43 2017 Loïc Lopez
// Last update Thu Mar 23 16:27:53 2017 Matthias Prost
//

#include "SpaceFighter.hpp"

extern "C" IGameModel *createInstanceGame()
{
  return (new SpaceFighter());
}

SpaceFighter::SpaceFighter()
{
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

void SpaceFighter::setMap()
{
  (void)map;
}

void SpaceFighter::getInputs()
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