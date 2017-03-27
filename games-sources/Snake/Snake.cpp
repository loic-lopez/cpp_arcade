//
// Snake.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/Snake.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 14:55:07 2017 Loïc Lopez
// Last update Mon Mar 27 16:15:30 2017 Matthias Prost
//

#include <array>
#include <random>
#include "Snake.hpp"

extern "C" IGameModel *createInstanceGame(std::string const &libname)
{
  return (new Snake(libname));
}

Snake::Snake(std::string const &libname)
{
  this->libraryName =  libname;
  arcade::Position	pos;

  if ((this->Map = (arcade::GetMap *)malloc(sizeof(arcade::GetMap) + (35 * 35 * sizeof(arcade::TileType))))== NULL)
    {
      std::cerr << "Error: can't allocate memory to create map" << std::endl;
      exit(EXIT_FAILURE);
    }
  this->Map->height = 35;
  this->Map->width = 35;
  this->Map->type = arcade::CommandType::PLAY;
  for (int i = 0; i < this->Map->height * this->Map->width; ++i)
      this->Map->tile[i] = arcade::TileType::EMPTY;
  pos.x = (uint16_t) (this->Map->width / 2);
  pos.y = (uint16_t) (this->Map->height / 2);
  for (int i = 0; i < 4; ++i)
    {
      this->_snake.push_back(pos);
      pos.x += 1;
    }
}

Snake &Snake::operator=(Snake const &snake)
{
  if (this != &snake)
    this->libraryName = snake.libraryName;
  return (*this);
}

Snake::~Snake()
{
}

Snake::Snake(Snake const &snake)
{
  this->libraryName = snake.libraryName;
}

void			Snake::setMap()
{
  int   			i;
  int 			lenght = this->Map->width * this->Map->height;

  i = -1;
  while (++i < lenght)
    {
      if (i % this->Map->width == 0 || i / this->Map->width == 0
	  || i / this->Map->width == this->Map->width - 1
	  || i % this->Map->width  == this->Map->width - 1)
	this->Map->tile[i] = arcade::TileType::BLOCK;
    }
}

void			Snake::drawMap(ILibraryViewController *libraryInstance)
{
  int   			i;
  int				lenght = this->Map->width * this->Map->height;

  i = -1;
  while (++i < lenght)
    {
      if (i % this->Map->width == 0 || i / this->Map->width == 0
	  || i / this->Map->width == this->Map->width - 1
	  || i % this->Map->width  == this->Map->width - 1)
	libraryInstance->drawSquare(i % this->Map->width, i / this->Map->width, Color::CYAN);
      else
	{
	  libraryInstance->drawSquare(i % this->Map->width, i / this->Map->width, Color::BLACK);
	}
    }
  libraryInstance->drawSquare(this->_snake.at(0).x, this->_snake.at(0).y, Color::BLUE);
  for (size_t j = 1; j < this->_snake.size(); j++)
    libraryInstance->drawSquare(this->_snake.at(j).x, this->_snake.at(j).y, Color::RED);
  if (libraryInstance->getLibraryName() == "Ncurses")
    this->wait_second();
}

void  Snake::wait_second()
{
  clock_t   ticks1, ticks2;

  ticks1 = clock();
  ticks2 = ticks1;
  while ((ticks2 / (CLOCKS_PER_SEC / 1000) - ticks1 / (CLOCKS_PER_SEC / 1000)) < 85)
    ticks2 = clock();
}

static	bool headIsOnAWallOrSelf(arcade::GetMap *map, uint16_t head_x_pos, uint16_t head_y_pos, std::vector<arcade::Position> snake)
{
  int   			i;
  int 			lenght = map->width * map->height;

  i = -1;
  while (++i < lenght)
    {
      if ((map->tile[i] == arcade::TileType::BLOCK && head_x_pos == 0) ||
       (map->tile[i] == arcade::TileType::BLOCK && head_y_pos == 0) ||
       (map->tile[i] == arcade::TileType::BLOCK && head_y_pos == map->height - 1) ||
       (map->tile[i] == arcade::TileType::BLOCK && head_x_pos == map->width - 1))
	return (true);
    }
  (void)snake;
  // a taf

  for (size_t j = 1; j < snake.size(); ++j)
    {
      if (head_x_pos == snake.at(j).x && head_y_pos == snake.at(j).y)
	return (true);
    }
  return (false);
}

static	void	setApple(ILibraryViewController *libraryInstance, arcade::GetMap *map, bool &popApple, int &applePosition)
{
  int   x;
  int   y;

  (void)libraryInstance;
  if (!popApple)
    {
      x = rand() % map->width - 1;
      y = rand() % map->height - 1;
      while (x <= 0 || x == map->width)
        x = rand() % map->width - 1;
      while (y <= 0 || y == map->height)
        y = rand() % map->height - 1;

      applePosition = x + map->width * y;
      map->tile[applePosition] = arcade::TileType::POWERUP;
      popApple = true;
    }
}

static	void 	eatApple(ILibraryViewController *lib, arcade::GetMap *map, std::vector<arcade::Position> *snake, bool &popApple, int &applePosition)
{
  if (applePosition == (snake->at(0).x + map->width * snake->at(0).y))
    {
      lib->setScore(100);
      arcade::Position	newNode;
      map->tile[applePosition] = arcade::TileType::EMPTY;
      newNode.x = snake->at(snake->size() - 1).x + 1;
      newNode.y = snake->at(snake->size() - 1).y + 1;
      snake->push_back(newNode);
      popApple = false;
    }
  else
    return;
}

bool	Snake::play(ILibraryViewController *libraryInstance,
			size_t &currentGame, size_t &currentLibrary,
			bool &exit)
{
  int   i;
  ChangeCommandType action = ChangeCommandType::STANDBY;
  bool	popApple = false;
  int 	applePosition = -1;

  i = 3;
  libraryInstance->initScreen(this->getGameName());
  this->setMap();
  while (libraryInstance->getKey(&this->Map->type, action, exit))
    {
      setApple(libraryInstance, this->Map, popApple, applePosition);
      this->drawMap(libraryInstance);
      libraryInstance->drawSquare(applePosition % this->Map->width, applePosition / this->Map->width, Color::GREEN);
      eatApple(libraryInstance, this->Map, &this->_snake, popApple, applePosition);
      if (headIsOnAWallOrSelf(this->Map, this->_snake.at(0).x, this->_snake.at(0).y, this->_snake))
	{
	  libraryInstance->endScreen();
	  std::cout << "YOU LOOSE BITCH" << std::endl;
	  return (false);
	}
      if (this->Map->type != arcade::CommandType::PLAY)
      	for (size_t j = _snake.size() - 1; j > 0 ; j--)
	  {
	    this->_snake.at(j).x = this->_snake.at(j - 1).x;
	    this->_snake.at(j).y = this->_snake.at(j - 1).y;
	  }
      if (action == ChangeCommandType::NEXT_LIBRARY)
        {
          currentLibrary++;
          break;
        }
      else if (action == ChangeCommandType::PREV_LIBRARY)
        {
          currentLibrary--;
          break;
        }
      else if ((this->Map->type == arcade::CommandType::GO_UP && i != 2) ||
      (this->Map->type == arcade::CommandType::GO_DOWN && i == 1))
        {
	  this->_snake.at(0).y--;
	  i = 1;
        }
      else if ((this->Map->type == arcade::CommandType::GO_DOWN && i != 1) ||
      (this->Map->type == arcade::CommandType::GO_UP && i == 2))
        {
	  this->_snake.at(0).y++;
          i = 2;
        }
      else if ((this->Map->type == arcade::CommandType::GO_LEFT && i != 4) ||
      (this->Map->type == arcade::CommandType::GO_RIGHT && i == 3))
        {
	  this->_snake.at(0).x--;
          i = 3;
        }
      else if ((this->Map->type == arcade::CommandType::GO_RIGHT && i != 3) ||
      (this->Map->type == arcade::CommandType::GO_LEFT && i == 4))
        {
	  this->_snake.at(0).x++;
	  i = 4;
        }
      libraryInstance->displayScore(this->getGameName(), libraryInstance->getLibraryName());
      libraryInstance->refresh();
    }
  libraryInstance->endScreen();
  (void)currentGame;
  return (true);
}

std::string Snake::getGameName()
{
  return ("Snake");
}
