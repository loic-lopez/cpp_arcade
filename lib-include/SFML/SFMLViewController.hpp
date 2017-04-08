//
// SFML.hpp for cpp_arcade in /home/lopez_i/cpp_arcade/SFML.hpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:07:20 2017 Loïc Lopez
// Last update Sat Apr  8 13:46:33 2017 Matthias Prost
//

#ifndef SFMLCONTROLLER_HPP__
# define SFMLCONTROLLER_HPP__

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../interface/ILibraryViewController.hpp"
#include <iostream>
#include <cstdlib>

extern "C" ILibraryViewController	*loadLibrary();

class SFMLViewController : public ILibraryViewController
{
private:
  sf::RenderWindow window;
  // sf::RectangleShape rectangle;
  int   windowsize_x;
  int   windowsize_y;
  sf::SoundBuffer bufferLose;
  sf::SoundBuffer bufferMercy;
  sf::SoundBuffer bufferSoundTrack;
  sf::Sound	Lose;
  sf::Sound Restart;
  sf::Sound SoundTrack;
  sf::Font      regular;
  sf::Text      _game;
  sf::Text      _library;
  sf::Text      _score;
  sf::Text      _game_over;
  sf::Text     _win;
  sf::Text      _key;
  bool 		playGameOver;
  std::string	functionCaller;
  sf::Music 	deathComes;
  sf::Texture	backgroundTexture;
  sf::Sprite	backgroundSprite;
  std::vector<sf::Texture> Textures;
  arcade::CommandType   keySave;
  arcade::CommandType   lastKey;

 public:
  virtual ~SFMLViewController();
  SFMLViewController();

  // Methods
  virtual void drawSquare(int width, int x, int y, Color const &color);
  virtual void drawMenu(size_t &currentGame, std::vector<std::string> const &games, bool &exit);
  virtual bool getKey(arcade::CommandType *commandType, ChangeCommandType &action, bool &exit);
  virtual void initScreen(std::string const &name);
  virtual void displayScore(int width, std::string const &, std::string const &, int);
  virtual void endScreen();
  virtual void refresh();
  virtual void clear();
  virtual void gameOver(int);
  virtual void win(int);
  virtual std::string	getLibraryName();
};

void   Fill_textures(std::vector<sf::Texture> *Textures);

#endif /* SFMLCONTROLLER_HPP__ */
