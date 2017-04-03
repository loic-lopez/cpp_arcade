//
// snake.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/snake.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 14:52:43 2017 Loïc Lopez
// Last update Mon Apr  3 03:58:15 2017 Matthias Prost
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
  if ((this->Map = (arcade::GetMap *)malloc(sizeof(arcade::GetMap) + (45 * 60 * sizeof(arcade::TileType))))== NULL)
    {
      std::cerr << "Error: can't allocate memory to create map" << std::endl;
      exit(EXIT_FAILURE);
    }
  this->Map->height = 45;
  this->Map->width = 60;
  for (int i = 0; i < this->Map->height * this->Map->width; i++)
      this->Map->tile[i] = arcade::TileType::EMPTY;
  initShip(&this->_ship, this->Map->height, this->Map->width);
  this->alreadyLaunch = false;
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

void  SolarFox::wait_second(int toSleep)
{
  clock_t   ticks1, ticks2;

  ticks1 = clock();
  ticks2 = ticks1;
  while ((ticks2 / (CLOCKS_PER_SEC / 1000) - ticks1
					     / (CLOCKS_PER_SEC / 1000)) < toSleep)
    ticks2 = clock();
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
      else
	       libraryInstance->drawSquare(this->Map->width, i % this->Map->width,
           i / this->Map->width, Color::BLACK);
    }
  libraryInstance->drawSquare(this->Map->width, this->_ship.x, this->_ship.y, Color::BLUE);
  if (libraryInstance->getLibraryName() == "Ncurses")
    this->wait_second(95);
  else if (libraryInstance->getLibraryName() == "SFML")
    this->wait_second(85);
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
  if (!this->alreadyLaunch)
    {
      libraryInstance->initScreen(this->getGameName());
      this->setMap();
      this->alreadyLaunch = true;
    }
  while (libraryInstance->getKey(&this->Map->type, action, exit))
  {
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
    if (this->Map->type != arcade::CommandType::PLAY)
      SolarFoxAlgorithm(this->Map, &this->_ship, &this->last_key);
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
