//
// SFML.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/SFML.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:07:20 2017 Loïc Lopez
// Last update Mon Mar 27 18:56:01 2017 Matthias Prost
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
  this->score = 0;
}

void	SFMLViewController::drawMenu()
{
}

void  SFMLViewController::setScore(int score)
{
  this->score = score;
}

int  SFMLViewController::getScore()
{
  return (this->score);
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
          else if (event.key.code == sf::Keyboard::Up)
            *commandType = arcade::CommandType::GO_UP;
          else if (event.key.code == sf::Keyboard::Down)
            *commandType = arcade::CommandType::GO_DOWN;
          else if (event.key.code == sf::Keyboard::Left)
            *commandType = arcade::CommandType::GO_LEFT;
          else if (event.key.code == sf::Keyboard::Right)
            *commandType = arcade::CommandType::GO_RIGHT;
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
  this->window.clear(sf::Color::Black);
  this->rectangle.setSize(sf::Vector2f(20, 20));
}

void	SFMLViewController::displayScore(std::string const &Game, std::string const &libraryName) const
{
  (void)Game;
  (void)libraryName;
}

void  SFMLViewController::endScreen()
{
  this->window.close();
}

#include <iostream>

void	SFMLViewController::drawSquare(int x, int y, Color const &color)
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
  this->rectangle.setPosition(x * 20 + 600, y * 20 + 100);
  this->window.draw(this->rectangle);
}

void  SFMLViewController::refresh()
{
  this->window.display();
  this->window.clear();
}

std::string	SFMLViewController::getLibraryName()
{
  return ("SFML");
}
