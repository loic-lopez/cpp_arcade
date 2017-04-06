//
// Vector2f.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/Vector2f.hpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. avr. 06 22:44:25 2017 Loïc Lopez
// Last update jeu. avr. 06 22:44:25 2017 Loïc Lopez
//

#ifndef GLVERTEX2F_HPP__
# define GLVERTEX2F_HPP__

#include <cmath>
class Vector2f
{
 public:
  float x;
  float y;

  Vector2f(float x, float y);
  float GetLenght() const;
  void Normalize();
};

#endif