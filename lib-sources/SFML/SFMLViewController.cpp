//
// SFML.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/SFML.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:07:20 2017 Loïc Lopez
// Last update Wed Apr  5 23:12:17 2017 Matthias Prost
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

void	SFMLViewController::drawMenu(size_t &currentGame,
					 std::vector<std::string> const &games,
					 bool &exit)
{
  sf::Font     	font;
  sf::Event 	event;
  std::vector<sf::Text> menu;
  bool		isSecondPart = false;
  int 		gamePosition;
  int 		selectedItemIndex = 0;
  std::vector<sf::Text> Items;
  const	char 	*ItemStrings[] =
   {
    "Snake",
    "SolarFox",
    "Exit"
   };
  const	char	*texts[] =
   {
    "Move the cursor menu to select a game.",
    "Press enter to choose a game.",
    "In Game :",
   "Key 2 : move to previous graphical library.",
   "Key 3 : move to next graphical library.",
   "Key 4 : move to previous game.",
   "Key 5 : move to next game.",
   "Key 8 : restart the game.",
   "Key 9 : display this menu.",
   "Key Escape : quit the game or menu.",
   "Move character with arrows."
   };
  sf::Text	mainText;
  sf::Text	arrow;
  size_t	index;
  sf::Texture texture;
  sf::Sprite sprite;

  if (!texture.loadFromFile("assets/BorneArcade.png"))
    std::cerr << "ERROR: cannot found BorneArcade in assets/ make sure it exist" << std::endl;
  if (!font.loadFromFile("lib-sources/SFML/Fonts/Roboto-Condensed.ttf"))
    std::cerr << "ERROR: cannot found Roboto-Condensed.ttf in lib-sources/SFML/Fonts/ make sure it exist" << std::endl;
  texture.setSmooth(true);
  sprite.setTexture(texture);
  sprite.setPosition(sf::Vector2f((this->windowsize_x / 2.0f) * 1.15 - (texture.getSize().x),
				  (this->windowsize_y / 2.0f) * 1.1 - (texture.getSize().y)));
  sprite.scale(sf::Vector2f(1.5f, 1.5f));
  mainText.setFont(font);
  mainText.setString("Game Arcade Menu");
  sf::FloatRect textRect = mainText.getLocalBounds();

  mainText.setOrigin(textRect.width / 2, textRect.height / 2);
  mainText.setPosition((sf::Vector2f((this->windowsize_x / 2.0f), sizeof("Game Arcade Menu"))));
  mainText.setCharacterSize(45);
  mainText.setFillColor(sf::Color::Red);
  arrow.setFont(font);
  arrow.setString("->");
  arrow.setCharacterSize(24);
  arrow.setFillColor(sf::Color::Red);
  arrow.setPosition(((this->windowsize_x) / 2) -
		     (sizeof(ItemStrings[selectedItemIndex]) *
		      sizeof(ItemStrings[selectedItemIndex])) -
		     (sizeof("->") * sizeof("->")) * 3 , (this->windowsize_y / 3) +
		    (((selectedItemIndex * sizeof(ItemStrings[selectedItemIndex]))) * 5));
  for (size_t j = 0; j < (sizeof(texts) / sizeof(texts[0])); ++j)
    {
      sf::Text	Text;
      std::string string = texts[j];
      Text.setFont(font);
      Text.setString(string);
      Text.setCharacterSize(24);
      Text.setFillColor(sf::Color::White);
      if (isSecondPart)
	  Text.setPosition((this->windowsize_x) / 12, (gamePosition + j * 25) - 20);
      else if (string == "In Game :")
	{
	  isSecondPart = true;
	  gamePosition = (24 * (j * 2)) + (this->windowsize_y / 3);
	  Text.setPosition((this->windowsize_x) / 12, gamePosition);
	}
      else
	Text.setPosition((this->windowsize_x) / 12, 24 * j + (this->windowsize_y / 3));
      menu.push_back(Text);
    }

  for (size_t i = 0; i < (sizeof(ItemStrings) / sizeof(ItemStrings[0])); ++i)
    {
      sf::Text	Text;
      Text.setFont(font);
      Text.setString(ItemStrings[i]);
      Text.setCharacterSize(35);
      Text.setFillColor(sf::Color::White);
      Text.setPosition(((this->windowsize_x) / 2) - (sizeof(ItemStrings[i]) * sizeof(ItemStrings[i])),
		       (this->windowsize_y / 3) + (((i * sizeof(ItemStrings[i]))) * 5));
      Items.push_back(Text);
    }

  Items[selectedItemIndex].setFillColor(sf::Color::Cyan);
  this->initScreen("Arcade Game Menu");
  while (this->window.isOpen())
    {
      while (this->window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    goto exit;
	  if (event.type == sf::Event::KeyPressed)
	    {
	      if (event.key.code == sf::Keyboard::Escape)
		goto exit;
	      else if (event.key.code == sf::Keyboard::Up)
		{
		  if (selectedItemIndex - 1 >= 0)
		    {
		      Items[selectedItemIndex].setFillColor(sf::Color::White);
		      selectedItemIndex--;
		      Items[selectedItemIndex].setFillColor(sf::Color::Cyan);
		    }
		}
	      else if (event.key.code == sf::Keyboard::Down)
		{
		  if (selectedItemIndex + 1 < static_cast<int>(Items.size()))
		    {
		      Items[selectedItemIndex].setFillColor(sf::Color::White);
		      selectedItemIndex++;
		      Items[selectedItemIndex].setFillColor(sf::Color::Cyan);
		    }
		}
	      else if (event.key.code == sf::Keyboard::Return)
		{
		  std::string 	currentText = Items[selectedItemIndex].getString();
		  std::transform(currentText.begin(), currentText.end(),
				 currentText.begin(), ::tolower);
		  if (currentText == "exit")
		      goto exit;
		  for (index = 0; index < games.size(); ++index)
		    {
		      if (games.at(index).find(currentText) != std::string::npos)
			  goto find;
		    }
		  if (index == games.size())
		      goto exit;
		}
	    }
	}
      for (size_t i = 0; i < menu.size(); ++i)
	  this->window.draw(menu[i]);
      for (size_t j = 0; j < Items.size(); ++j)
	this->window.draw(Items[j]);
      this->window.draw(mainText);
      arrow.setPosition(((this->windowsize_x) / 2) -
			 (sizeof(ItemStrings[selectedItemIndex]) *
			  sizeof(ItemStrings[selectedItemIndex])) -
			(sizeof("->") * sizeof("->")) * 3 ,
			(this->windowsize_y / 3) +
			 (((selectedItemIndex * sizeof(ItemStrings[selectedItemIndex]))) * 5));
      this->window.draw(sprite);
      this->window.draw(arrow);
      this->refresh();
    }
  exit:
    exit = true;
  find:
    currentGame = index;
  this->endScreen();
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
      std::cerr << "ERROR: cannot found Roboto-Regular.ttf in lib-sources/SFML/Fonts/ make sure it exist" << std::endl;

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
      std::cerr << "ERROR: cannot found Roboto-Regular.ttf in lib-sources/SFML/Fonts/ make sure it exist" << std::endl;

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
