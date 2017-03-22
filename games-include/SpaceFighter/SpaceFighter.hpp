/*
** SpaceFighter.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/SpaceFighter.hpp.hpp
**
** Made by Loïc Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  jeu. mars 16 16:02:17 2017 Loïc Lopez
** Last update jeu. mars 16 16:02:17 2017 Loïc Lopez
*/

#ifndef SPACEFIGHTER_HPP__
# define SPACEFIGHTER_HPP__

#include <iostream>
#include "../interface/IGameModel.hpp"

extern "C" IGameModel *Play();

class SpaceFighter : public IGameModel
{
 private:
  std::string	libraryName;
  std::array<int, 2>	characterPosition;
  std::map<int, int>	map;

 public:
  SpaceFighter();
  SpaceFighter(SpaceFighter const &);
  SpaceFighter &operator=(SpaceFighter const &);
  virtual ~SpaceFighter();

  // Methods
  virtual void	setCharacterPosition(std::array<int, 2> &position);
  virtual std::array<int, 2> &getCharacterPosition();
  virtual void setMap(std::map<int, int> &);
  virtual std::map<int, int>	&getMap();
  virtual void getInputs();
  virtual void changeLibrary(std::string const &);
  virtual bool	play(ILibraryViewController *library, size_t &currentGame, size_t &currentLibrary, bool &);
};

#endif /* SPACEFIGHTER_HPP__ */