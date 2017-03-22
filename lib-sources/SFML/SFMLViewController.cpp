//
// SFML.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/SFML.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:07:20 2017 Loïc Lopez
// Last update Wed Mar 22 13:15:52 2017 Matthias Prost
//

#include "SFMLViewController.hpp"

extern "C" ILibraryViewController	*loadLibrary()
{
  return new SFMLViewController();
}

SFMLViewController::~SFMLViewController()
{
}

SFMLViewController::SFMLViewController()
{
}

void	SFMLViewController::drawMenu()
{
}

void	SFMLViewController::drawCharacter(std::array<int, 2> &position)
{
  (void)position;
}

void	SFMLViewController::drawMap(std::map<int, int> &map)
{
  (void)map;
}

bool  SFMLViewController::getEscapeKey(int &key, bool &exit)
{
  sf::Event event;

  while (this->window.pollEvent(event))
    {
      if (event.type == sf::Event::KeyPressed)
        {
          if (event.key.code == sf::Keyboard::Escape)
	         {
      	     exit = true;
      	     return (false);
      	   }
          if (event.key.code == sf::Keyboard::Up)
            key = 1;
          if (event.key.code == sf::Keyboard::Down)
            key = 2;
        }
    }
  return (true);
}

// A changer pour les jeux et enlever la boucle
void	SFMLViewController::initScreen()
{
  this->window.create(sf::VideoMode(800, 600), "Test");
}

void  SFMLViewController::displayText(std::string const &msg)
{
  (void)msg;
  this->window.clear(sf::Color::Black);
	this->window.display();
}

void  SFMLViewController::endScreen()
{
  this->window.close();
}
