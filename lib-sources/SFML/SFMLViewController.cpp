//
// SFML.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/SFML.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:07:20 2017 Loïc Lopez
// Last update Thu Mar 23 19:58:24 2017 Matthias Prost
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

  (void)commandType;
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
          if (event.key.code == sf::Keyboard::Num2)
            action = ChangeCommandType::PREV_LIBRARY;
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

void	SFMLViewController::drawSquare(int x, int y, Color const &color)
{
  (void)color;
  (void)x;
  (void)y;
  this->rectangle.setSize(sf::Vector2f(20, 20));
  this->window.clear();
  this->window.draw(this->rectangle);
}

void  SFMLViewController::refresh()
{
  this->window.display();
}

std::string	SFMLViewController::getLibraryName()
{
  return ("SFML");
}