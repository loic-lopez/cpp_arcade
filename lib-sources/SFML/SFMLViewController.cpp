//
// SFML.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/SFML.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:07:20 2017 Loïc Lopez
// Last update Fri Apr  7 14:16:26 2017 Matthias Prost
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
  this->playGameOver = false;
  this->rectangle.setSize(sf::Vector2f(15, 15));
  if (!this->bufferLose.loadFromFile("assets/Die_Die_Die.ogg"))
    std::cerr << "ERROR: cannot found Die_Die_Die.ogg in assets/ make sure it exist" << std::endl;
  if (!this->bufferMercy.loadFromFile("assets/Mercy.ogg"))
    std::cerr << "ERROR: cannot found Mercy.ogg in assets/ make sure it exist" << std::endl;
  if (!regular.loadFromFile("lib-sources/SFML/Fonts/Roboto-Regular.ttf"))
    std::cerr << "ERROR: cannot found Roboto-Regular.ttf in lib-sources/SFML/Fonts/ make sure it exist" << std::endl;
  if (!deathComes.openFromFile("assets/Death_comes.ogg"))
    std::cerr << "ERROR: cannot found Death_comes.ogg in assets/ make sure it exist" << std::endl;
  if (!backgroundTexture.loadFromFile("assets/BackgroundArcade.jpg"))
    std::cerr << "ERROR: cannot found Death_comes.ogg in assets/ make sure it exist" << std::endl;
  this->Lose.setBuffer(this->bufferLose);
  this->Restart.setBuffer(this->bufferMercy);
  this->_game.setFont(this->regular);
  this->_game.setCharacterSize(24);
  this->_game.setFillColor(sf::Color::White);
  this->_library.setFont(this->regular);
  this->_library.setCharacterSize(24);
  this->_library.setFillColor(sf::Color::White);
  this->_score.setFont(this->regular);
  this->_score.setCharacterSize(24);
  this->_score.setFillColor(sf::Color::White);
  this->_game_over.setFont(regular);
  this->_game_over.setString("Game Over");
  this->_game_over.setCharacterSize(24);
  this->_game_over.setFillColor(sf::Color::Red);
  this->_game_over.setPosition((this->windowsize_x / 2) - (3 * 24) + 8, 24 + (this->windowsize_y / 9));
  this->_key.setFont(regular);
  this->_key.setString("Press 8 to restart");
  this->_key.setCharacterSize(24);
  this->_key.setFillColor(sf::Color::White);
  this->_key.setPosition(((this->windowsize_x) - (9 * 24)) / 2, 24 + (this->windowsize_y / 5));
  this->functionCaller = "OTHER";
  this->backgroundSprite.setTexture(this->backgroundTexture);
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
          else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
	    {
	      *commandType = arcade::CommandType::RESTART;
	      this->playGameOver = false;
        this->Restart.setVolume(50);
        this->Restart.play();
	    }
	  else if (event.key.code == sf::Keyboard::Num9)
	    {
	      this->playGameOver = false;
	      action = ChangeCommandType::DISPLAY_MENU;
	      this->Lose.stop();
	      this->deathComes.stop();
	    }
        }
    }
  return (true);
}

// A changer pour les jeux et enlever la boucle

void	SFMLViewController::initScreen(std::string const &name)
{
  this->window.create(sf::VideoMode::getDesktopMode(), name.c_str());

  if (this->functionCaller == "OTHER")
    this->deathComes.play();
}

void	SFMLViewController::displayScore(int width, std::string const &Game, std::string const &libraryName, int score)
{
  (void) width;
  this->_game.setString(Game);
  this->_game.setPosition((this->windowsize_x / 2) - 48, 24 + this->windowsize_y / 200);

  this->_library.setString(libraryName);
  this->_library.setPosition((this->windowsize_x / 2) - 48, 24 + (this->windowsize_y / 30));

  this->_score.setString("Score: " + std::to_string(score));
  this->_score.setPosition((this->windowsize_x / 2) - 48, 24 + (this->windowsize_y / 13));
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
  else if (color == Color::WHITE)
    this->rectangle.setFillColor(sf::Color(255, 255, 255));
  this->rectangle.setPosition((x * 15) + (this->windowsize_x - (width * 15)) / 2, (y * 15) + (this->windowsize_y / 7));
  this->window.draw(this->rectangle);
  this->window.draw(this->_game);
  this->window.draw(this->_library);
  this->window.draw(this->_score);
}

void  SFMLViewController::refresh()
{
  this->window.display();
  // this->window.clear(sf::Color::Black);
  this->window.draw(this->backgroundSprite);
}

std::string	SFMLViewController::getLibraryName()
{
  return ("SFML");
}

void  SFMLViewController::gameOver(int score)
{
  if (!this->playGameOver)
    {
      this->Lose.play();
      this->playGameOver = true;
    }
    (void)score;
  _score.setPosition(((this->windowsize_x / 2) - ((std::to_string(score).length()) / 2) * 24) - 48, 24 + (this->windowsize_y / 7));
  this->window.draw(this->_game_over);
  this->window.draw(this->_key);
  this->window.draw(this->_score);
}

void SFMLViewController::clear()
{
  this->window.display();
  this->window.clear(sf::Color::Black);
}
