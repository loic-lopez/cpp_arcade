//
// Shoots.cpp for cpp_arcade in /home/prost_m/Rendu/Semestre_4/cpp_arcade/games-sources/SolarFox
//
// Made by Matthias Prost
// Login   <matthias.prost@epitech.eu>
//
// Started on  Thu Apr  6 18:13:45 2017 Matthias Prost
// Last update Fri Apr  7 19:00:42 2017 Matthias Prost
//

#include "SolarFox.hpp"

void  player_shoot(arcade::GetMap *map, std::vector<shoot> *shoots, arcade::Position *_ship, SaveCommand *last_key)
{
  shoot tmp_shoot;

  tmp_shoot.is_ennemy = false;
  tmp_shoot.count = 0;
  tmp_shoot.pos = _ship->x + map->width * _ship->y;
  tmp_shoot.direction = static_cast<Shoot_direction>(*last_key);
  map->tile[tmp_shoot.pos] = arcade::TileType::MY_SHOOT;
  shoots->push_back(tmp_shoot);
}

void  refresh_shoot(SolarFox *solarfox, arcade::GetMap *map, std::vector<shoot> *shoots)
{
  size_t   i;
  int   x;
  int   y;

  i = -1;
  while (++i < shoots->size())
  {
    x = shoots->at(i).pos % map->width;
    y = shoots->at(i).pos / map->width;

    if (shoots->at(i).type != arcade::TileType::EVIL_SHOOT
    && shoots->at(i).type != arcade::TileType::EVIL_DUDE
    && shoots->at(i).type != arcade::TileType::MY_SHOOT
    && shoots->at(i).is_ennemy == true)
      map->tile[shoots->at(i).pos] = shoots->at(i).type;
    else
      map->tile[shoots->at(i).pos] = arcade::TileType::EMPTY;
    if (shoots->at(i).count == 6 && shoots->at(i).is_ennemy == false)
    {
      shoots->erase(shoots->begin() + i);
      break;
    }
    if (x >= map->width - 3 || x <= 2)
    {
      shoots->erase(shoots->begin() + i);
      break;
    }
    if ((y >= map->height - 3 || y <= 2) && shoots->at(i).is_ennemy == false)
    {
      shoots->erase(shoots->begin() + i);
      break;
    }
    if (shoots->at(i).direction == Shoot_direction::UP)
      y--;
    else if (shoots->at(i).direction == Shoot_direction::DOWN)
      y++;
    else if (shoots->at(i).direction == Shoot_direction::LEFT)
      x--;
    else if (shoots->at(i).direction == Shoot_direction::RIGHT)
      x++;
    shoots->at(i).count++;
    shoots->at(i).pos = x + map->width * y;
    shoots->at(i).type = map->tile[shoots->at(i).pos];
    if (map->tile[shoots->at(i).pos] == arcade::TileType::POWERUP && shoots->at(i).is_ennemy == false)
      {
        map->tile[shoots->at(i).pos] = arcade::TileType::EMPTY;
        solarfox->setScore(100);
        shoots->erase(shoots->begin() + i);
        break;
      }
    if (shoots->at(i).is_ennemy == false)
      map->tile[shoots->at(i).pos] = arcade::TileType::MY_SHOOT;
    if (shoots->at(i).is_ennemy == true)
      map->tile[shoots->at(i).pos] = arcade::TileType::EVIL_SHOOT;
  }
}

void  Ennemy2_shoot(arcade::GetMap *map, std::vector<shoot> *shoots, int ennemy2_pos)
{
  shoot tmp_shoot2;

  tmp_shoot2.is_ennemy = true;
  tmp_shoot2.count = 0;
  tmp_shoot2.pos = (ennemy2_pos % map->width) - 2 + map->width * (ennemy2_pos / map->width);
  tmp_shoot2.direction = Shoot_direction::LEFT;
  map->tile[tmp_shoot2.pos] = arcade::TileType::EVIL_SHOOT;
  shoots->push_back(tmp_shoot2);
}

void  Ennemy1_shoot(arcade::GetMap *map, std::vector<shoot> *shoots, int ennemy1_pos)
{
  shoot tmp_shoot;

  tmp_shoot.is_ennemy = true;
  tmp_shoot.count = 0;
  tmp_shoot.pos = (ennemy1_pos % map->width) + 2 + map->width * (ennemy1_pos / map->width);
  tmp_shoot.direction = Shoot_direction::RIGHT;
  map->tile[tmp_shoot.pos] = arcade::TileType::EVIL_SHOOT;
  shoots->push_back(tmp_shoot);
}

void  Ennemy(int &ennemy1_pos, int &ennemy2_pos, arcade::GetMap *map, int &direction1, int &direction2)
{
  int x;
  int y;
  int i;

  map->tile[ennemy2_pos] = arcade::TileType::BLOCK;
  map->tile[ennemy1_pos] = arcade::TileType::BLOCK;

  x = ennemy1_pos % map->width;
  y = ennemy1_pos / map->width;
  if (y >= map->height - 3)
    direction1 = -1;
  else if (y <= 2)
    direction1 = 0;
  if (direction1 == 0)
    y++;
  else if (direction1 == -1)
    y--;
  i = x + map->width * y;
  ennemy1_pos = i;
  map->tile[ennemy1_pos] = arcade::TileType::EVIL_DUDE;

  x = ennemy2_pos % map->width;
  y = ennemy2_pos / map->width;
  if (y >= map->height - 3)
    direction2 = -1;
  else if (y <= 2)
    direction2 = 0;
  if (direction2 == 0)
    y++;
  else if (direction2 == -1)
    y--;
  i = x + map->width * y;
  ennemy2_pos = i;
  map->tile[ennemy2_pos] = arcade::TileType::EVIL_DUDE;
}
