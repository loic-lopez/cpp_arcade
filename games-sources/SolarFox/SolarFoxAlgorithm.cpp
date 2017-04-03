//
// SolarFoxAlgorithm.cpp for arcade in /home/prost_m/Rendu/Semestre_4/cpp_arcade/games-sources/SolarFox/
//
// Made by Matthias Prost
// Login   <matthias.prost@epitech.eu@epitech.eu>
//
// Started on  Mon Apr  3 02:19:47 2017 Matthias Prost
// Last update Mon Apr  3 17:28:57 2017 Matthias Prost
//

#include "SolarFox.hpp"

void	SolarFoxAlgorithm(arcade::GetMap *Map, arcade::Position *ship, SaveCommand *last_key)
{
  if ((Map->type == arcade::CommandType::GO_UP
       && *last_key != SaveCommand::DOWN) ||
      (Map->type == arcade::CommandType::GO_DOWN
       && *last_key == SaveCommand::UP))
    {
      ship->y--;
      *last_key = SaveCommand::UP;
    }
  else if ((Map->type == arcade::CommandType::GO_DOWN
	    && *last_key != SaveCommand::UP) ||
	   (Map->type == arcade::CommandType::GO_UP
	    && *last_key == SaveCommand::DOWN))
    {
      ship->y++;
      *last_key = SaveCommand::DOWN;
    }
  else if ((Map->type == arcade::CommandType::GO_LEFT
	    && *last_key != SaveCommand::RIGHT) ||
	   (Map->type == arcade::CommandType::GO_RIGHT
	    && *last_key == SaveCommand::LEFT))
    {
      ship->x--;
      *last_key = SaveCommand::LEFT;
    }
  else if ((Map->type == arcade::CommandType::GO_RIGHT
	    && *last_key != SaveCommand::LEFT) ||
	   (Map->type == arcade::CommandType::GO_LEFT
	    && *last_key == SaveCommand::RIGHT))
    {
      ship->x++;
      *last_key = SaveCommand::RIGHT;
    }
  else if (Map->type == arcade::CommandType::SHOOT)
    {
      std::cout << "Done!" << std::endl;
      Map->type = (arcade::CommandType)*last_key;
    }
}
