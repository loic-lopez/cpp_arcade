//
// Snake.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/Snake.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 14:55:07 2017 Loïc Lopez
// Last update Sun Apr  9 16:45:47 2017 Matthias Prost
//

#include "Snake.hpp"

extern "C" IGameModel *createInstanceGame(std::string const &libname)
{
  return (new Snake(libname));
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

Snake::Snake(std::string const &libname)
{
  this->libraryName =  libname;
  this->Map = new arcade::GetMap[sizeof(arcade::GetMap)
				 + (35 * 35 * sizeof(arcade::TileType))];

  this->Map->height = 35;
  this->Map->width = 35;
  this->Map->type = arcade::CommandType::PLAY;
  for (int i = 0; i < this->Map->height * this->Map->width; i++)
      this->Map->tile[i] = arcade::TileType::EMPTY;
  initSnake(&this->_snake, this->Map->height, this->Map->width);
  this->applePosition = -1;
  this->popApple = false;
  this->score = 0;
  this->alreadyLaunch = false;
  this->last_key = SaveCommand::LEFT;
}

void			Snake::setMap()
{
  int   			i;
  int 			lenght = this->Map->width * this->Map->height;

  i = -1;
  while (++i < lenght)
    {
      if (i % this->Map->width == 0 || i / this->Map->width == 0
	  || i % this->Map->width == this->Map->width - 1
	  || i / this->Map->width == this->Map->height - 1)
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
  while (++i < lenght)
    {
      if (this->Map->tile[i] == arcade::TileType::BLOCK)
	libraryInstance->drawSquare(this->Map->width, i % this->Map->width,
				    i / this->Map->width, Color::CYAN);
      else
	libraryInstance->drawSquare(this->Map->width, i % this->Map->width,
				    i / this->Map->width, Color::BLACK);
    }
  libraryInstance->drawSquare(this->Map->width, this->_snake.at(0).x,
			      this->_snake.at(0).y, Color::SNAKE_HEAD);
  for (size_t j = 1; j < this->_snake.size(); j++)
    libraryInstance->drawSquare(this->Map->width, this->_snake.at(j).x,
				this->_snake.at(j).y, Color::SNAKE_BODY);
  if (this->applePosition > -1)
    libraryInstance->drawSquare(this->Map->width, this->applePosition % this->Map->width,
				this->applePosition / this->Map->width, Color::APPLE);
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
      newNode.x = (uint16_t) (snake->at(snake->size() - 1).x);
      newNode.y = (uint16_t) (snake->at(snake->size() - 1).y);
      snake->push_back(newNode);
      popApple = false;
    }
  else
    return;
}

static void	restartSnake(std::vector<arcade::Position> *_snake,
				ILibraryViewController *libraryInstance,
				arcade::GetMap *Map, bool &popApple)
{
  libraryInstance->clear();
  _snake->clear();
  initSnake(_snake, Map->height, Map->width);
  Map->type = arcade::CommandType::PLAY;
  popApple = false;
}

ChangeCommandType	Snake::play(ILibraryViewController *libraryInstance,
				     size_t &currentGame, size_t &currentLibrary,
				     bool &exit, std::string const &playerName)
{
  ChangeCommandType action = ChangeCommandType::STANDBY;
  this->Map->type = arcade::CommandType::PLAY;
  std::chrono::time_point<std::chrono::system_clock> start, end;
  long long int elapsed_milliseconds;

  start = std::chrono::system_clock::now();
  if (!this->alreadyLaunch)
    {
      libraryInstance->initScreen(this->getGameName(), playerName);
      this->setMap();
      this->alreadyLaunch = true;
    }
  while (libraryInstance->getKey(&this->Map->type, action, exit))
    {
      end = std::chrono::system_clock::now();
      elapsed_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
      if (this->Map->type == arcade::CommandType::SHOOT)
	this->Map->type = (arcade::CommandType)this->last_key;
      this->drawMap(libraryInstance);
      eatApple(this, this->Map, &this->_snake, this->popApple, this->applePosition);
      if (headIsOnAWallOrSelf(this->Map, this->_snake.at(0).x,
			      this->_snake.at(0).y, this->_snake))
      	{
          this->score = 0;
  	  restartSnake(&this->_snake, libraryInstance, this->Map, this->popApple);
        	  while (libraryInstance->getKey(&this->Map->type, action, exit))
  	    {
  	      if (this->Map->type == arcade::CommandType::RESTART)
  		{
  		  this->alreadyLaunch = true;
  		  this->score = 0;
  		  action = ChangeCommandType::RESTART;
  		  this->last_key = SaveCommand::LEFT;
  		  return (action);
  		}
  	      else if (action == ChangeCommandType::NEXT_LIBRARY
  		       || action == ChangeCommandType::PREV_LIBRARY
  		       || action == ChangeCommandType::PREV_GAME
  		       || action == ChangeCommandType::NEXT_GAME
  		       || action == ChangeCommandType::DISPLAY_MENU)
  		break;
        	      libraryInstance->gameOver(this->score);
        	      libraryInstance->refresh();
      	    }
      	  if (exit) break;
      	}
      if (this->Map->type != arcade::CommandType::PLAY && elapsed_milliseconds > 70)
	{
	  SnakeAlgorithm(this->Map, &this->_snake, &this->last_key);
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
      else if (action == ChangeCommandType::DISPLAY_MENU) break;
      else if (this->Map->type == arcade::CommandType::RESTART)
	{
	  restartSnake(&this->_snake, libraryInstance, this->Map, this->popApple);
	  this->alreadyLaunch = true;
	  this->score = 0;
	  this->last_key = SaveCommand::LEFT;
	}
      libraryInstance->displayScore(this->Map->width, this->getGameName(),
					libraryInstance->getLibraryName(), this->score);
      libraryInstance->displayPlayerName();
      libraryInstance->refresh();
    }
  libraryInstance->endScreen();
  return (action);
}

std::string Snake::getGameName()
{
  return ("Snake");
}
