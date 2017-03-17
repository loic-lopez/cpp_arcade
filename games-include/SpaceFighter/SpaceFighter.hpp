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

extern "C" IGameModel *Play(std::string const &libraryName);

class SpaceFighter : public IGameModel
{
 private:
  std::string	libraryName;

 public:
  SpaceFighter(std::string const &);
  SpaceFighter(SpaceFighter const &);
  SpaceFighter &operator=(SpaceFighter const &);
  virtual ~SpaceFighter();
};

#endif /* SPACEFIGHTER_HPP__ */