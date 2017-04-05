//
// snake.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/snake.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 14:52:43 2017 Loïc Lopez
// Last update Wed Apr  5 16:27:42 2017 Matthias Prost
//

#include "SolarFox.hpp"

extern "C" IGameModel *createInstanceGame(std::string const &libname)
{
  return (new SolarFox(libname));
}

static void   initShip(arcade::Position *ship, int height, int width)
{
  ship->x = (uint16_t) (width / 2);
  ship->y = (uint16_t) (height / 2) - 1;
}

SolarFox::SolarFox(std::string const &libname)
{
  this->libraryName = libname;
  this->Map = new arcade::GetMap[sizeof(arcade::GetMap)
				 + (45 * 60 * sizeof(arcade::TileType))];

  this->Map->height = 45;
  this->Map->width = 60;
  for (int i = 0; i < this->Map->height * this->Map->width; i++)
      this->Map->tile[i] = arcade::TileType::EMPTY;
  initShip(&this->_ship, this->Map->height, this->Map->width);
  this->alreadyLaunch = false;
  this->ennemy1_pos = 1 + this->Map->width * 1;
  this->ennemy2_pos = 58 + this->Map->width * 43;
  this->Map->tile[ennemy1_pos] = arcade::TileType::EVIL_DUDE;
  this->Map->tile[ennemy2_pos] = arcade::TileType::EVIL_DUDE;
  this->direction = 0;
  this->score = 0;
}

SolarFox::SolarFox(SolarFox const &SolarFox)
{
  this->libraryName = SolarFox.libraryName;
  this->last_key = SaveCommand::LEFT;
  this->score = 0;
}

SolarFox &SolarFox::operator=(SolarFox const &SolarFox)
{
  if (this != &SolarFox)
    this->libraryName = SolarFox.libraryName;
  return (*this);
}

SolarFox::~SolarFox()
{

}

void SolarFox::drawMap(ILibraryViewController *libraryInstance)
{
  int   i;
  int   size = this->Map->height * this->Map->width;

  i = -1;
  while (++i < size)
    {
      if (this->Map->tile[i] == arcade::TileType::BLOCK)
	       libraryInstance->drawSquare(this->Map->width, i % this->Map->width,
           i / this->Map->width, Color::CYAN);
      else if (this->Map->tile[i] == arcade::TileType::POWERUP)
     	   libraryInstance->drawSquare(this->Map->width, i % this->Map->width,
           i / this->Map->width, Color::YELLOW);
      else if (this->Map->tile[i] == arcade::TileType::EVIL_DUDE)
         libraryInstance->drawSquare(this->Map->width, i % this->Map->width,
            i / this->Map->width, Color::RED);
      else
	       libraryInstance->drawSquare(this->Map->width, i % this->Map->width,
           i / this->Map->width, Color::BLACK);
    }
  libraryInstance->drawSquare(this->Map->width, this->_ship.x, this->_ship.y, Color::BLUE);
}

void SolarFox::setMap()
{
  int   			i;
  int 			size = this->Map->width * this->Map->height;

  i = -1;
  while (++i < size)
  {
    if ((((i % this->Map->width) % 2 == 0 && (i / this->Map->width) % 2 == 0
          && i % this->Map->width > 12 && i % this->Map->width < 20
          && i / this->Map->width > 10 && i / this->Map->width < 35)
          || ((i % this->Map->width) % 2 == 0 && (i / this->Map->width) % 2 == 0
          && i % this->Map->width > 40 && i % this->Map->width < 48
          && i / this->Map->width > 10 && i / this->Map->width < 35))
          || (((i % this->Map->width) % 2 == 0 && (i / this->Map->width) % 2 == 0
          && i % this->Map->width > 15 && i % this->Map->width < 45
          && i / this->Map->width > 8 && i / this->Map->width < 15)
          || ((i % this->Map->width) % 2 == 0 && (i / this->Map->width) % 2 == 0
          && i % this->Map->width > 15 && i % this->Map->width < 45
          && i / this->Map->width > 30 && i / this->Map->width < 38)))
      this->Map->tile[i] = arcade::TileType::POWERUP;
    i++;
  }
  i = -1;
  while (++i < size)
    {
      if (i % this->Map->width == 0 || i / this->Map->width == 0
          || i % this->Map->width == this->Map->width - 1
          || i / this->Map->width == this->Map->height - 1)
        this->Map->tile[i] = arcade::TileType::BLOCK;
    }
}

void Play()
{

}

static int  verif(arcade::GetMap *map)
{
  int   i;

  while (++i != map->width * map->height)
    if (map->tile[i] == arcade::TileType::POWERUP)
      return (1);
  return (0);
}

static void  Ennemy(int &ennemy1_pos, int &ennemy2_pos, arcade::GetMap *map, int &direction)
{
  int x;
  int y;
  int i;

  map->tile[ennemy2_pos] = arcade::TileType::EMPTY;
  map->tile[ennemy1_pos] = arcade::TileType::EMPTY;

  x = ennemy1_pos % map->width;
  y = ennemy1_pos / map->width;
  if (y >= map->height - 2)
    direction = -1;
  else if (y <= 1)
    direction = 0;
  if (direction == 0)
    y++;
  else if (direction == -1)
    y--;
  i = x + map->width * y;
  ennemy1_pos = i;
  map->tile[ennemy1_pos] = arcade::TileType::EVIL_DUDE;

  x = ennemy2_pos % map->width;
  y = ennemy2_pos / map->width;
  if (direction == 0)
    y--;
  else if (direction == -1)
    y++;
  i = x + map->width * y;
  ennemy2_pos = i;
  map->tile[ennemy2_pos] = arcade::TileType::EVIL_DUDE;
}

static	void 	PowerUp(IGameModel *game, arcade::GetMap *map,
				   arcade::Position *ship)
{
  (void)game;
  if (map->tile[ship->x + map->width * ship->y] == arcade::TileType::POWERUP)
    {
      map->tile[ship->x + map->width * ship->y] = arcade::TileType::EMPTY;
      game->setScore(100);
    }
  else
    return;
}

static	bool	Ship_collision(arcade::GetMap *map, uint16_t pos_x,
					      uint16_t pos_y)
{
  int   			i;
  int 			lenght = map->width * map->height;

  i = -1;
  if (map->type == arcade::CommandType::PLAY)
    return (false);
  while (++i < lenght)
    {
      if ((map->tile[i] == arcade::TileType::BLOCK && pos_x == 0) ||
       (map->tile[i] == arcade::TileType::BLOCK && pos_y == 0) ||
       (map->tile[i] == arcade::TileType::BLOCK && pos_y == map->height - 1) ||
       (map->tile[i] == arcade::TileType::BLOCK && pos_x == map->width - 1))
	      return (true);
    }
  return (false);
}

int         SolarFox::getScore()
{
  return (this->score);
}

void         SolarFox::setScore(int value)
{
  this->score += value;
}

ChangeCommandType	SolarFox::play(ILibraryViewController *libraryInstance,
			       size_t &currentGame, size_t & currentLibrary,
			       bool &exit)
{
  ChangeCommandType action = ChangeCommandType::STANDBY;
  this->Map->type = arcade::CommandType::PLAY;
  std::chrono::time_point<std::chrono::system_clock> start, end;
  long long int elapsed_milliseconds;
  if (!this->alreadyLaunch)
    {
      libraryInstance->initScreen(this->getGameName());
      this->setMap();
      this->alreadyLaunch = true;
    }
  while (libraryInstance->getKey(&this->Map->type, action, exit))
  {
    end = std::chrono::system_clock::now();
    elapsed_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    if (this->Map->type == arcade::CommandType::RESTART)
     this->Map->type = (arcade::CommandType)this->last_key;
    this->drawMap(libraryInstance);
    PowerUp(this, this->Map, &this->_ship);
    if (Ship_collision(this->Map, this->_ship.x, this->_ship.y))
    {
      break;
    }
    if (this->Map->type == arcade::CommandType::RESTART)
      {
        this->alreadyLaunch = true;
        this->score = 0;
        action = ChangeCommandType::RESTART;
        return (action);
      }
      if (this->Map->type != arcade::CommandType::PLAY && elapsed_milliseconds > 75)
      {
        SolarFoxAlgorithm(this->Map, &this->_ship, &this->last_key);
        Ennemy(this->ennemy1_pos, this->ennemy2_pos, this->Map, this->direction);
        start = end;
      }
    if (action == ChangeCommandType::NEXT_LIBRARY)
      {
        currentLibrary++;
        this->alreadyLaunch = false;
        break;
      }
    else if (action == ChangeCommandType::PREV_LIBRARY)
      {
        currentLibrary--;
        this->alreadyLaunch = false;
        break;
      }
    else if (action == ChangeCommandType::PREV_GAME)
      {
        currentGame--;
        break;
      }
    else if (action == ChangeCommandType::NEXT_GAME)
      {
        currentGame++;
        break;
      }
    if (verif(this->Map) == 0)
      break;
    libraryInstance->displayScore(this->Map->width, this->getGameName(),
				libraryInstance->getLibraryName(), this->score);
    libraryInstance->refresh();
  }
  libraryInstance->endScreen();
  return (action);
}

std::string	SolarFox::getGameName()
{
  return ("SolarFox");
}

void  SolarFox::playProtocol()
{

}
