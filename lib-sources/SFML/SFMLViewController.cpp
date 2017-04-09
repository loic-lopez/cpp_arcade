//
// SFML.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/SFML.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:07:20 2017 Loïc Lopez
// Last update Sun Apr  9 17:49:56 2017 Matthias Prost
//

#include "SFMLViewController.hpp"

extern "C" ILibraryViewController	*loadLibrary()
{
  return (new SFMLViewController());
}

SFMLViewController::~SFMLViewController()
{
  this->SoundTrack.stop();
}

SFMLViewController::SFMLViewController()
{
  this->windowsize_x = sf::VideoMode::getDesktopMode().width;
  this->windowsize_y = sf::VideoMode::getDesktopMode().height;
  this->playGameOver = false;
  if (!this->bufferLose.loadFromFile("assets/Die_Die_Die.ogg"))
    std::cerr << "ERROR: cannot found Die_Die_Die.ogg in assets/ make sure it exist" << std::endl;
  if (!this->bufferMercy.loadFromFile("assets/Mercy.ogg"))
    std::cerr << "ERROR: cannot found Sound_Theme.ogg in assets/ make sure it exist" << std::endl;
  if (!this->bufferSoundTrack.loadFromFile("assets/Sound_Theme.ogg"))
    std::cerr << "ERROR: cannot found Sound_Theme.ogg in assets/ make sure it exist" << std::endl;
  if (!regular.loadFromFile("lib-sources/SFML/Fonts/Roboto-Regular.ttf"))
    std::cerr << "ERROR: cannot found Roboto-Regular.ttf in lib-sources/SFML/Fonts/ make sure it exist" << std::endl;
  if (!deathComes.openFromFile("assets/Death_comes.ogg"))
    std::cerr << "ERROR: cannot found Death_comes.ogg in assets/ make sure it exist" << std::endl;
  if (!backgroundTexture.loadFromFile("assets/BackgroundArcade.jpg"))
    std::cerr << "ERROR: cannot found BackgroundArcadejpg in assets/ make sure it exist" << std::endl;
  this->Lose.setBuffer(this->bufferLose);
  this->Restart.setBuffer(this->bufferMercy);
  this->SoundTrack.setBuffer(this->bufferSoundTrack);
  this->_game.setFont(this->regular);
  this->_game.setCharacterSize(24);
  this->_game.setFillColor(sf::Color::White);
  this->_library.setFont(this->regular);
  this->_library.setCharacterSize(24);
  this->_library.setFillColor(sf::Color::White);
  this->_score.setFont(this->regular);
  this->_score.setCharacterSize(24);
  this->_score.setFillColor(sf::Color::White);
  this->_win.setString("You win !");
  this->_win.setFillColor(sf::Color::Green);
  this->_win.setCharacterSize(24);
  this->_win.setFont(regular);
  this->_win.setPosition((this->windowsize_x / 2) - (3 * 24) + 8, 24 + (this->windowsize_y / 9));
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
  Fill_textures(&this->Textures);
  this->SoundTrack.setLoop(true);
  this->SoundTrack.setVolume(70);
  this->keySave = arcade::CommandType::GO_LEFT;
  this->lastKey = arcade::CommandType::GO_LEFT;
}

void   Fill_textures(std::vector<sf::Texture> *Textures)
{
  sf::Texture buffer;
  size_t i = 0;
  std::string path;

  std::string	name[] =
   {
    "ship",
    "wall",
    "ennemy",
    "coin",
    "laser",
    "ennemy_laser",
    "snake_body",
    "snake_head",
    "apple"
   };
   while (i < (sizeof(name) / sizeof(name[0])))
     {
	path = "assets/" + name[i] + ".png";
	if (!buffer.loadFromFile(path))
	  std::cerr << "ERROR: cannot found " << path << " in assets/ make sure it exist" << std::endl;
	Textures->push_back(buffer);
	i++;
     }
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
          {
            this->SoundTrack.stop();
            action = ChangeCommandType::NEXT_LIBRARY;
          }
          else if (event.key.code == sf::Keyboard::Num2)
          {
            this->SoundTrack.stop();
            action = ChangeCommandType::PREV_LIBRARY;
          }
          else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
            action = ChangeCommandType::PREV_GAME;
          else if (event.key.code == sf::Keyboard::Num5)
            action = ChangeCommandType::NEXT_GAME;
          else if (event.key.code == sf::Keyboard::Up)
          {
            *commandType = arcade::CommandType::GO_UP;
            keySave = arcade::CommandType::GO_UP;
          }
          else if (event.key.code == sf::Keyboard::Down)
          {
            *commandType = arcade::CommandType::GO_DOWN;
            keySave = arcade::CommandType::GO_DOWN;
          }
          else if (event.key.code == sf::Keyboard::Left)
          {
            *commandType = arcade::CommandType::GO_LEFT;
            keySave = arcade::CommandType::GO_LEFT;
          }
          else if (event.key.code == sf::Keyboard::Right)
          {
            *commandType = arcade::CommandType::GO_RIGHT;
            keySave = arcade::CommandType::GO_RIGHT;
          }
          else if (event.key.code == sf::Keyboard::Space)
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

void	SFMLViewController::initScreen(std::string const &name, std::string const &playername)
{
  this->SoundTrack.play();
  this->window.create(sf::VideoMode::getDesktopMode(), name.c_str());
  if (this->functionCaller == "OTHER")
    this->deathComes.play();
  this->playerName.setFont(this->regular);
  this->playerName.setString("Player Name: " + playername);
  this->playerName.setCharacterSize(24);
  this->playerName.setPosition((this->windowsize_x / 2) - 62
			       - this->playerName.getString().getSize() , 24 + (this->windowsize_y / 13));
}

void	SFMLViewController::displayScore(int width, std::string const &Game, std::string const &libraryName, int score)
{
  (void) width;
  this->_game.setString(Game);
  this->_game.setPosition((this->windowsize_x / 2) - 48 * 2, 24 + 10);

  this->_library.setString(libraryName);
  this->_library.setPosition((this->windowsize_x / 2) + 48 , 24 + 10);

  this->_score.setString("Score: " + std::to_string(score));
  this->_score.setPosition((this->windowsize_x / 2) - 48, 24 + (this->windowsize_y / 25));
}

void  SFMLViewController::endScreen()
{
  this->SoundTrack.stop();
  this->window.close();
}

void	SFMLViewController::drawSquare(int width, int x, int y, Color const &color)
{
  sf::RectangleShape rectangle;

  rectangle.setSize(sf::Vector2f(16, 16));
  rectangle.setOrigin(8, 8);
  if (color == Color::BLUE)
  {
    rectangle.setFillColor(sf::Color(33, 150, 243));
    rectangle.setTexture(NULL);
  }
  else if (color == Color::SHIP)
  {
    rectangle.setTexture(&this->Textures.at(0));
    if (lastKey == arcade::CommandType::GO_LEFT)
      rectangle.setRotation(270);
    else if (lastKey == arcade::CommandType::GO_RIGHT)
      rectangle.setRotation(90);
    else if (lastKey == arcade::CommandType::GO_DOWN)
      rectangle.setRotation(180);
    else if (lastKey == arcade::CommandType::GO_UP)
      rectangle.setRotation(0);
    if (this->keySave == arcade::CommandType::GO_LEFT
    && this->lastKey != arcade::CommandType::GO_RIGHT)
    {
      rectangle.setRotation(270);
      this->lastKey = arcade::CommandType::GO_LEFT;
    }
    else if (this->keySave == arcade::CommandType::GO_RIGHT
    && this->lastKey != arcade::CommandType::GO_LEFT)
    {
      rectangle.setRotation(90);
      this->lastKey = arcade::CommandType::GO_RIGHT;
    }
    else if (this->keySave == arcade::CommandType::GO_DOWN
    && this->lastKey != arcade::CommandType::GO_UP)
    {
      rectangle.setRotation(180);
      this->lastKey = arcade::CommandType::GO_DOWN;
    }
    else if (this->keySave == arcade::CommandType::GO_UP
    && this->lastKey != arcade::CommandType::GO_DOWN)
    {
      rectangle.setRotation(0);
      this->lastKey = arcade::CommandType::GO_UP;
    }
  }
  else if (color == Color::CYAN)
  {
    rectangle.setTexture(&this->Textures.at(1));
  }
  else if (color == Color::BLACK)
  {
    rectangle.setFillColor(sf::Color(0, 0, 0));
    rectangle.setTexture(NULL);
  }
  else if (color == Color::ENNEMY_LASER)
  {
    rectangle.setTexture(&this->Textures.at(5));
    rectangle.setRotation(90);
  }
  else if (color == Color::ENNEMY)
  {
    rectangle.setTexture(&this->Textures.at(2));
    rectangle.setRotation(90);
  }
  else if (color == Color::APPLE)
  {
    rectangle.setTexture(&this->Textures.at(8));
  }
  else if (color == Color::LASER)
  {
    rectangle.setTexture(&this->Textures.at(4));
    if (this->keySave == arcade::CommandType::GO_LEFT)
      rectangle.setRotation(270);
    if (this->keySave == arcade::CommandType::GO_RIGHT)
      rectangle.setRotation(90);
  }
  else if (color == Color::SNAKE_BODY)
  {
    rectangle.setTexture(&this->Textures.at(6));
  }
  else if (color == Color::SNAKE_HEAD)
  {
    rectangle.setTexture(&this->Textures.at(7));
    if (lastKey == arcade::CommandType::GO_LEFT)
      rectangle.setRotation(270);
    else if (lastKey == arcade::CommandType::GO_RIGHT)
      rectangle.setRotation(90);
    else if (lastKey == arcade::CommandType::GO_DOWN)
      rectangle.setRotation(180);
    else if (lastKey == arcade::CommandType::GO_UP)
      rectangle.setRotation(0);
    if (this->keySave == arcade::CommandType::GO_LEFT
    && this->lastKey != arcade::CommandType::GO_RIGHT)
    {
      rectangle.setRotation(270);
      this->lastKey = arcade::CommandType::GO_LEFT;
    }
    else if (this->keySave == arcade::CommandType::GO_RIGHT
    && this->lastKey != arcade::CommandType::GO_LEFT)
    {
      rectangle.setRotation(90);
      this->lastKey = arcade::CommandType::GO_RIGHT;
    }
    else if (this->keySave == arcade::CommandType::GO_DOWN
    && this->lastKey != arcade::CommandType::GO_UP)
    {
      rectangle.setRotation(180);
      this->lastKey = arcade::CommandType::GO_DOWN;
    }
    else if (this->keySave == arcade::CommandType::GO_UP
    && this->lastKey != arcade::CommandType::GO_DOWN)
    {
      rectangle.setRotation(0);
      this->lastKey = arcade::CommandType::GO_UP;
    }
  }
  else if (color == Color::YELLOW)
  {
    rectangle.setTexture(&this->Textures.at(3));
  }
  else if (color == Color::WHITE)
  {
    rectangle.setFillColor(sf::Color(255, 255, 255));
    rectangle.setTexture(NULL);
  }
  rectangle.setPosition((x * 15) + (this->windowsize_x - (width * 15)) / 2, (y * 15) + (this->windowsize_y / 7));
  this->window.draw(rectangle);
  this->window.draw(this->_game);
  this->window.draw(this->_library);
  this->window.draw(this->_score);
}

void  SFMLViewController::refresh()
{
  this->window.display();
  this->window.draw(this->backgroundSprite);
}

std::string	SFMLViewController::getLibraryName() const
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
  _score.setPosition(((this->windowsize_x / 2) - ((std::to_string(score).length()) / 2) * 24) - 48, 24 + (this->windowsize_y / 7));
  this->window.draw(this->_game_over);
  this->window.draw(this->_key);
  this->window.draw(this->_score);
}

void  SFMLViewController::win(int score)
{
  if (!this->playGameOver)
    {
      this->Lose.play();
      this->playGameOver = true;
    }
  _score.setPosition(((this->windowsize_x / 2) - ((std::to_string(score).length()) / 2) * 24) - 48, 24 + (this->windowsize_y / 7));
  this->window.draw(this->_win);
  this->window.draw(this->_key);
  this->window.draw(this->_score);
}

void SFMLViewController::clear()
{
  this->window.clear(sf::Color::Black);
}

void	SFMLViewController::displayPlayerName()
{
  this->window.draw(static_cast<sf::Text>(this->playerName));
}
