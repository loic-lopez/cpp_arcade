/*
** ArcadeColor.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/ArcadeColor.hpp
**
** Made by Loïc Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  dim. mars 26 16:54:00 2017 Loïc Lopez
** Last update Tue Mar 28 15:39:59 2017 Matthias Prost
*/

#ifndef ARCADE_COLOR_HPP__
# define ARCADE_COLOR_HPP__

enum class 	Color : int
{
  MAGENTA	= 	5,
  YELLOW 	= 	3,
  BLUE		=	4,
  RED		=	1,
  GREEN		=	2,
  BLACK		=	0,
  CYAN		=	6
};

enum class	ChangeCommandType : int
{
  STANDBY	=	0,
  NEXT_LIBRARY	=	1,
  PREV_LIBRARY	=	2,
  NEXT_GAME	=	3,
  PREV_GAME	=	4,
  RESTART	=	5
};

enum class  SaveCommand : int
{
  UP = 2,
  DOWN = 3,
  LEFT = 4,
  RIGHT = 5,
};

#endif
