//
// SFML.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/SFML.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:07:20 2017 Loïc Lopez
// Last update Tue Mar 21 17:50:44 2017 Yassir Jabbari
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

void	SFMLViewController::loadScreen()
{
  sf::RenderWindow window;

  window.create(sf::VideoMode(800, 600), "Test");
  while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
	  {
	    if (event.type == sf::Event::KeyPressed)
	      {
		if (event.key.code == sf::Keyboard::Escape)
		    window.close();
	      }
	    if (event.type == sf::Event::Closed)
	      window.close();
	    window.clear(sf::Color::Black);
	    window.display();
	  }
    }
}
