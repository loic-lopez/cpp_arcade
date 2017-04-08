/*
** SolarFoxProtocol.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/SolarFoxProtocol.cpp
**
** Made by Loïc Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  sam. avr. 08 13:14:11 2017 Loïc Lopez
** Last update sam. avr. 08 13:14:11 2017 Loïc Lopez
*/

#include "SolarFox.hpp"

void	SolarFoxAlgorithmProtocol(arcade::GetMap *Map, SaveCommand *last_key)
{
  if (Map->type == arcade::CommandType::GO_UP)
    {
      *last_key = SaveCommand::UP;
    }
  else if (Map->type == arcade::CommandType::GO_DOWN)
    {
      *last_key = SaveCommand::DOWN;
    }
  else if (Map->type == arcade::CommandType::GO_LEFT)
    {
      *last_key = SaveCommand::LEFT;
    }
  else if (Map->type == arcade::CommandType::GO_RIGHT)
    {
      *last_key = SaveCommand::RIGHT;
    }
  else if (Map->type == arcade::CommandType::SHOOT)
    {
      if (*last_key == SaveCommand::RIGHT)
	*last_key = SaveCommand::RIGHT;
      else if (*last_key == SaveCommand::LEFT)
	*last_key = SaveCommand::LEFT;
      else if (*last_key == SaveCommand::UP)
	*last_key = SaveCommand::UP;
      else if (*last_key == SaveCommand::DOWN)
	*last_key = SaveCommand::DOWN;
    }
}

void	solarFoxActionsProtocol(arcade::GetMap *Map, arcade::Position *ship,
				    SaveCommand *last_key, std::vector<shoot> *shoots)
{
  if (Map->type == arcade::CommandType::SHOOT)
      player_shoot(Map, shoots, ship, last_key);
  else if (Map->type == arcade::CommandType::PLAY)
    {
      if (*last_key == SaveCommand::RIGHT)
	ship->x++;
      else if (*last_key == SaveCommand::LEFT)
	ship->x--;
      else if (*last_key == SaveCommand::UP)
	ship->y--;
      else if (*last_key == SaveCommand::DOWN)
	ship->y++;
    }
}

void	SolarFox::playProtocol()
{
  arcade::CommandType commandType = arcade::CommandType::PLAY;

  this->setMap();
  while (std::cin.read(reinterpret_cast<char *>(&commandType), sizeof(arcade::CommandType)))
    {
      this->Map->type = commandType;
      if (commandType == arcade::CommandType::GET_MAP)
	{
	  std::cout.write(reinterpret_cast<const char*>(&this->Map->type), sizeof(arcade::CommandType));
	  std::cout.write(reinterpret_cast<const char*>(&this->Map->width), sizeof(uint16_t));
	  std::cout.write(reinterpret_cast<const char*>(&this->Map->height), sizeof(arcade::CommandType));
	  std::cout.write(reinterpret_cast<const char*>(&this->Map->tile), sizeof(arcade::TileType) * this->Map->height * this->Map->width);
	}
      else if (commandType == arcade::CommandType::WHERE_AM_I)
	{
	  this->whereAmI =
	   new arcade::WhereAmI[sizeof(arcade::WhereAmI) + 1 * sizeof(arcade::Position)];
	  this->whereAmI->lenght = 1;
	  this->whereAmI->type = commandType;
	  this->whereAmI->position[0].x = this->_ship.x;
	  this->whereAmI->position[0].y = this->_ship.y;
	  std::cout.write(reinterpret_cast<const char*>(&this->whereAmI->type),
			  sizeof(arcade::CommandType));
	  std::cout.write(reinterpret_cast<const char*>(&this->whereAmI->lenght),
			  sizeof(uint16_t));
	  std::cout.write(reinterpret_cast<const char*>(&this->whereAmI->position),
			  sizeof(arcade::Position) * this->whereAmI->lenght);
	  delete this->whereAmI;
	}
      else
	{
	  SolarFoxAlgorithmProtocol(this->Map, &this->last_key);
	  solarFoxActionsProtocol(this->Map, &this->_ship, &this->last_key, &this->shoots);
	}
      refresh_shoot(this, this->Map, &this->shoots);
    }
}

extern "C" void	Play(void)
{
  IGameModel	*gameModel = new SolarFox("");

  std::string line;
  gameModel->playProtocol();
}