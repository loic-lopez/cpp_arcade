//
// Snake.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/Snake.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 14:55:07 2017 Loïc Lopez
// Last update Fri Mar 31 16:43:19 2017 Matthias Prost
//

#include <array>
#include <random>
#include "Snake.hpp"

extern "C" IGameModel *createInstanceGame(std::string const &libname, bool const &display)
{
  return (new Snake(libname, display));
}

Snake &Snake::operator=(Snake const &snake)
{
  if (this != &snake)
    this->libraryName = snake.libraryName;
  return (*this);
}

static void   initSnake(std::vector<arcade::Position> *snake, int height, int width)
{
  arcade::Position	pos;

  pos.x = (uint16_t) (width / 2);
  pos.y = (uint16_t) (height / 2);
  for (int i = 0; i < 4; i++)
    {
      snake->push_back(pos);
      pos.x += 1;
    }
}

Snake::~Snake()
{
}

Snake::Snake(Snake const &snake)
{
  this->libraryName = snake.libraryName;
  this->last_key = SaveCommand::LEFT;
  this->score = 0;
}

Snake::Snake(std::string const &libname, bool const &display)
{
  this->libraryName =  libname;
  this->display = display;
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
  initSnake(&this->_snake, this->Map->height, this->Map->width);
  this->applePosition = -1;
  this->popApple = false;
  this->score = 0;
  this->alreadyLaunch = false;
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

static	void	setApple(arcade::GetMap *map, bool &popApple, int &applePosition)
{
  int   x;
  int   y;

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

void			Snake::drawMap(ILibraryViewController *libraryInstance)
{
  int   			i;
  int				lenght = this->Map->width * this->Map->height;

  i = -1;
  setApple(this->Map, this->popApple, this->applePosition);
  if (this->display)
    {
      while (++i < lenght)
	{
	  if (i % this->Map->width == 0 || i / this->Map->width == 0
	      || i / this->Map->width == this->Map->width - 1
	      || i % this->Map->width  == this->Map->width - 1)
	    libraryInstance->drawSquare(i % this->Map->width,
					i / this->Map->width, Color::CYAN);
	  else
	    libraryInstance->drawSquare(i % this->Map->width,
					i / this->Map->width, Color::BLACK);
	}
      libraryInstance->drawSquare(this->_snake.at(0).x,
				  this->_snake.at(0).y, Color::BLUE);
      for (size_t j = 1; j < this->_snake.size(); j++)
	libraryInstance->drawSquare(this->_snake.at(j).x,
				    this->_snake.at(j).y, Color::RED);
      if (this->applePosition > -1)
	libraryInstance->drawSquare(this->applePosition % this->Map->width,
				    this->applePosition / this->Map->width, Color::GREEN);
    }
  if (libraryInstance->getLibraryName() == "Ncurses")
    this->wait_second(75);
  else if (libraryInstance->getLibraryName() == "SFML")
    this->wait_second(67);
}

void  Snake::wait_second(int toSleep)
{
  clock_t   ticks1, ticks2;

  ticks1 = clock();
  ticks2 = ticks1;
  while ((ticks2 / (CLOCKS_PER_SEC / 1000) - ticks1
					     / (CLOCKS_PER_SEC / 1000)) < toSleep)
    ticks2 = clock();
}

static	bool	headIsOnAWallOrSelf(arcade::GetMap *map, uint16_t head_x_pos,
					      uint16_t head_y_pos,
					      std::vector<arcade::Position> snake)
{
  int   			i;
  int 			lenght = map->width * map->height;

  i = -1;
  if (map->type == arcade::CommandType::PLAY)
    return (false);
  while (++i < lenght)
    {
      if ((map->tile[i] == arcade::TileType::BLOCK && head_x_pos == 0) ||
       (map->tile[i] == arcade::TileType::BLOCK && head_y_pos == 0) ||
       (map->tile[i] == arcade::TileType::BLOCK && head_y_pos == map->height - 1) ||
       (map->tile[i] == arcade::TileType::BLOCK && head_x_pos == map->width - 1))
	      return (true);
    }
  for (size_t j = 1; j < snake.size(); ++j)
    {
      if (head_x_pos == snake.at(j).x && head_y_pos == snake.at(j).y)
	     return (true);
    }
  return (false);
}

int          Snake::getScore()
{
  return (this->score);
}

void         Snake::setScore(int value)
{
  this->score += value;
}

static	void 	eatApple(IGameModel *game, arcade::GetMap *map,
				   std::vector<arcade::Position> *snake,
				   bool &popApple, int &applePosition)
{
  if (applePosition == (snake->at(0).x + map->width * snake->at(0).y))
    {
      game->setScore(100);
      arcade::Position	newNode;
      map->tile[applePosition] = arcade::TileType::EMPTY;
      newNode.x = (uint16_t) (snake->at(snake->size() - 1).x + 1);
      newNode.y = (uint16_t) (snake->at(snake->size() - 1).y + 1);
      snake->push_back(newNode);
      popApple = false;
    }
  else
    return;
}

ChangeCommandType	Snake::play(ILibraryViewController *libraryInstance,
				     size_t &currentGame, size_t &currentLibrary,
				     bool &exit)
{
  ChangeCommandType action = ChangeCommandType::STANDBY;
  this->Map->type = arcade::CommandType::PLAY;
  this->last_key = SaveCommand::LEFT;
  if (!this->alreadyLaunch)
    {
      if (this->display)
      	libraryInstance->initScreen(this->getGameName());
      this->setMap();
      this->alreadyLaunch = true;
    }
  while (libraryInstance->getKey(&this->Map->type, action, exit))
    {
      if (this->Map->type == arcade::CommandType::RESTART)
	this->Map->type = (arcade::CommandType)this->last_key;
      this->drawMap(libraryInstance);
      eatApple(this, this->Map, &this->_snake, this->popApple, this->applePosition);
      if (headIsOnAWallOrSelf(this->Map, this->_snake.at(0).x,
			      this->_snake.at(0).y, this->_snake))
	{
	  if (this->display)
	    libraryInstance->clear();
	  this->_snake.clear();
	  initSnake(&this->_snake, this->Map->height, this->Map->width);
	  this->Map->type = arcade::CommandType::PLAY;
	  this->popApple = false;
	  while (libraryInstance->getKey(&this->Map->type, action, exit))
	    {
	      if (this->Map->type == arcade::CommandType::RESTART)
		{
		  this->alreadyLaunch = true;
		  this->score = 0;
		  action = ChangeCommandType::RESTART;
		  return (action);
		}
	      else if (action == ChangeCommandType::NEXT_LIBRARY) break;
	      else if (action == ChangeCommandType::PREV_LIBRARY) break;
	      if (this->display)
		{
		  libraryInstance->gameOver(this->score);
		  libraryInstance->refresh();
		}
	    }
	  if (exit) break;
	}
      if (this->Map->type != arcade::CommandType::PLAY)
	{
	  for (size_t j = _snake.size() - 1; j > 0 ; j--)
	    {
	      this->_snake.at(j).x = this->_snake.at(j - 1).x;
	      this->_snake.at(j).y = this->_snake.at(j - 1).y;
	    }
	  if ((this->Map->type == arcade::CommandType::GO_UP
	       && this->last_key != SaveCommand::DOWN) ||
	       (this->Map->type == arcade::CommandType::GO_DOWN
		&& this->last_key == SaveCommand::UP))
	    {
	      this->_snake.at(0).y--;
	      this->last_key = SaveCommand::UP;
	    }
	  else if ((this->Map->type == arcade::CommandType::GO_DOWN
		    && this->last_key != SaveCommand::UP) ||
		    (this->Map->type == arcade::CommandType::GO_UP
		     && this->last_key == SaveCommand::DOWN))
	    {
	      this->_snake.at(0).y++;
	      this->last_key = SaveCommand::DOWN;
	    }
	  else if ((this->Map->type == arcade::CommandType::GO_LEFT
		    && this->last_key != SaveCommand::RIGHT) ||
		    (this->Map->type == arcade::CommandType::GO_RIGHT
		     && this->last_key == SaveCommand::LEFT))
	    {
	      this->_snake.at(0).x--;
	      this->last_key = SaveCommand::LEFT;
	    }
	  else if ((this->Map->type == arcade::CommandType::GO_RIGHT
		    && this->last_key != SaveCommand::LEFT) ||
		    (this->Map->type == arcade::CommandType::GO_LEFT
		     && this->last_key == SaveCommand::RIGHT))
	    {
	      this->_snake.at(0).x++;
	      this->last_key = SaveCommand::RIGHT;
	    }
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
      if (this->display)
	{
	  libraryInstance->displayScore(this->getGameName(),
					libraryInstance->getLibraryName(), this->score);
	  libraryInstance->refresh();
	}
    }
  if (this->display)
    libraryInstance->endScreen();
  return (action);
}

std::string Snake::getGameName()
{
  return ("Snake");
}
