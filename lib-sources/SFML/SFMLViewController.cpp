//
// SFML.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/SFML.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:07:20 2017 Loïc Lopez
// Last update Mon Apr  3 16:08:23 2017 Matthias Prost
//

#include "SFMLViewController.hpp"

extern "C" ILibraryViewController	*loadLibrary()
{
  return (new SFMLViewController());
}

SFMLViewController::~SFMLViewController()
{
}

SFMLViewController::SFMLViewController()
{
  this->windowsize_x = sf::VideoMode::getDesktopMode().width;
  this->windowsize_y = sf::VideoMode::getDesktopMode().height;
}

void	SFMLViewController::drawMenu(size_t &currentGame)
{
  (void)currentGame;
}

bool  SFMLViewController::getKey(arcade::CommandType *commandType, ChangeCommandType &action, bool &exit)
{
  sf::Event event;

  while (this->window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
	{
	  exit = true;
	  return (false);
	}
      if (event.type == sf::Event::KeyPressed)
        {
          if (event.key.code == sf::Keyboard::Escape)
	    {
	      exit = true;
	      return (false);
	    }
          if (event.key.code == sf::Keyboard::Num3)
            action = ChangeCommandType::NEXT_LIBRARY;
          else if (event.key.code == sf::Keyboard::Num2)
            action = ChangeCommandType::PREV_LIBRARY;
          else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
            action = ChangeCommandType::PREV_GAME;
          else if (event.key.code == sf::Keyboard::Num5)
            action = ChangeCommandType::NEXT_GAME;
          else if (event.key.code == sf::Keyboard::Up)
            *commandType = arcade::CommandType::GO_UP;
          else if (event.key.code == sf::Keyboard::Down)
            *commandType = arcade::CommandType::GO_DOWN;
          else if (event.key.code == sf::Keyboard::Left)
            *commandType = arcade::CommandType::GO_LEFT;
          else if (event.key.code == sf::Keyboard::Right)
            *commandType = arcade::CommandType::GO_RIGHT;
          else if (event.key.code == sf::Keyboard::Return)
            *commandType = arcade::CommandType::SHOOT;
          else if (event.key.code == sf::Keyboard::Space)
            *commandType = arcade::CommandType::RESTART;
        }
    }
  return (true);
}

// A changer pour les jeux et enlever la boucle

void	SFMLViewController::initScreen(std::string const &name)
{
  this->window.create(sf::VideoMode::getDesktopMode(), name.c_str());
  sf::Vector2u size = this->window.getSize();
  this->mapsize_x = size.x;
  this->mapsize_y = size.y;
  this->rectangle.setSize(sf::Vector2f(15, 15));
}

void	SFMLViewController::displayScore(int width, std::string const &Game, std::string const &libraryName, int score)
{
  sf::Font      font;
  sf::Text      _game;
  sf::Text      _library;
  sf::Text      _score;

  if (!font.loadFromFile("lib-sources/SFML/Fonts/Roboto-Regular.ttf"))
      std::cout << "ERROR: cannot found Roboto-Regular.ttf in lib-sources/SFML/Fonts/ make sure it exist" << std::endl;

  _game.setFont(font);
  _game.setString(Game);
  _game.setCharacterSize(24);
  _game.setFillColor(sf::Color::White);
  _game.setPosition(24 + (this->windowsize_x + (width * 15) + 75) / 2, 24 + (this->windowsize_y / 9));

  _library.setFont(font);
  _library.setString(libraryName);
  _library.setCharacterSize(24);
  _library.setFillColor(sf::Color::White);
  _library.setPosition(24 + (this->windowsize_x + (width * 15) + 75) / 2, 24 + (this->windowsize_y / 6));

  _score.setFont(font);
  _score.setString("Score: " + std::to_string(score));
  _score.setCharacterSize(24);
  _score.setFillColor(sf::Color::White);
  _score.setPosition(24 + (this->windowsize_x + (width * 15) + 375) / 2, 24 + (this->windowsize_y / 9));

  this->window.draw(_game);
  this->window.draw(_library);
  this->window.draw(_score);
}

void  SFMLViewController::endScreen()
{
  this->window.close();
}

void	SFMLViewController::drawSquare(int width, int x, int y, Color const &color)
{
  if (color == Color::BLUE)
    this->rectangle.setFillColor(sf::Color(33, 150, 243));
  else if (color == Color::BLACK)
    this->rectangle.setFillColor(sf::Color(0, 0, 0));
  else if (color == Color::MAGENTA)
    this->rectangle.setFillColor(sf::Color(233, 30, 99));
  else if (color == Color::RED)
    this->rectangle.setFillColor(sf::Color(244, 67, 54));
  else if (color == Color::GREEN)
    this->rectangle.setFillColor(sf::Color(76, 175, 80));
  else if (color == Color::CYAN)
    this->rectangle.setFillColor(sf::Color(0, 188, 212));
  else if (color == Color::YELLOW)
    this->rectangle.setFillColor(sf::Color(255, 193, 7));
  this->rectangle.setPosition((x * 15) + (this->windowsize_x - (width * 15)) / 2, (y * 15) + (this->windowsize_y / 7));
  this->window.draw(this->rectangle);
}

void  SFMLViewController::refresh()
{
  this->window.display();
  this->window.clear(sf::Color::Black);
}

std::string	SFMLViewController::getLibraryName()
{
  return ("SFML");
}

void  SFMLViewController::gameOver(int score)
{
  sf::Font      font;
  sf::Text      _game_over;
  sf::Text      _key;
  sf::Text      _score;

  if (!font.loadFromFile("lib-sources/SFML/Fonts/Roboto-Regular.ttf"))
      std::cout << "ERROR: cannot found Roboto-Regular.ttf in lib-sources/SFML/Fonts/ make sure it exist" << std::endl;

  _game_over.setFont(font);
  _game_over.setString("Game Over");
  _game_over.setCharacterSize(24);
  _game_over.setFillColor(sf::Color::Red);
  _game_over.setPosition(((this->windowsize_x) - (4 * 24)) / 2, 24 + (this->windowsize_y / 9));

  _key.setFont(font);
  _key.setString("Press Space to restart");
  _key.setCharacterSize(24);
  _key.setFillColor(sf::Color::White);
  _key.setPosition(((this->windowsize_x) - (9 * 24)) / 2, 24 + (this->windowsize_y / 5));

  _score.setFont(font);
  _score.setString("Score: " + std::to_string(score));
  _score.setCharacterSize(24);
  _score.setFillColor(sf::Color::White);
  _score.setPosition(((this->windowsize_x) - ((2 + std::to_string(score).length() - 1) * 24)) / 2, 24 + (this->windowsize_y / 7));

  this->window.draw(_game_over);
  this->window.draw(_key);
  this->window.draw(_score);
}

void SFMLViewController::clear()
{
  this->window.display();
  this->window.clear(sf::Color::Black);
}
