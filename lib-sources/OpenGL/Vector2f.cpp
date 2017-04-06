//
// Vector2f.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/Vector2f.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. avr. 06 22:44:25 2017 Loïc Lopez
// Last update jeu. avr. 06 22:44:25 2017 Loïc Lopez
//

#include "Vector2f.hpp"

Vector2f::Vector2f(float x, float y)
{
  this->x = x;
  this->y = y;
}

float	Vector2f::GetLenght() const
{
  return sqrt(this->x*this->x + this->y * this->y);
}

void	Vector2f::Normalize()
{
  float l = GetLenght();
  this->x /= l;
  this->y /= l;
}