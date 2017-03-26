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

bool  SFMLViewController::getKey(Key &action, bool &exit)
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
            action = ILibraryViewController::Key::NEXT_GAME;
          if (event.key.code == sf::Keyboard::Num2)
            action = ILibraryViewController::Key::PREV_GAME;
        }
    }
  return (true);
}

// A changer pour les jeux et enlever la boucle
void	SFMLViewController::initScreen(std::string const &name)
{
  this->window.create(sf::VideoMode::getDesktopMode(), name.c_str());
}

void	SFMLViewController::displayText(std::string const &Game, std::string const &libraryName) const
{
  (void)Game;
  (void)libraryName;
}

void  SFMLViewController::endScreen()
{
  this->window.close();
}

void	SFMLViewController::drawMap(int mapsize_x, int mapsize_y)
{
  (void)mapsize_x;
  (void)mapsize_y;
}

void  SFMLViewController::setUserXY(int x, int y)
{
  this->user_x = x;
  this->user_y = y;
}

int  SFMLViewController::getUserX()
{
  return (this->user_x);
}

int  SFMLViewController::getUserY()
{
  return (this->user_y);
}

void  SFMLViewController::refresh()
{
  this->window.clear();
  this->window.display();
}

std::string	SFMLViewController::getLibraryName()
{
  return ("SFML");
}