//
// NcursesController.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/NcursesController.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:05:35 2017 Loïc Lopez
// Last update Fri Apr  7 16:03:44 2017 Matthias Prost
//

#include "NcursesViewController.hpp"

int max_Y_sighandler;
int max_X_sighandler;

static void	resizeHandler(int sig)
{
  (void)sig;
  NcursesEncap::n_getmaxyx(stdscr, &max_Y_sighandler, &max_X_sighandler);
  clear();
  resizeterm(LINES, COLS);
  refresh();
}

extern "C" ILibraryViewController	*loadLibrary()
{
  return (new NcursesViewController());
}

NcursesViewController::NcursesViewController()
{
  std::system("paplay assets/Sound_Theme.ogg & > /dev/null 2>&1");
  this->playGameOver = false;
  this->functionCaller = "OTHER";
}

NcursesViewController::~NcursesViewController()
{
  std::system("killall paplay");
}

void	NcursesViewController::drawSquare(int width, int x, int y, Color const &color)
{
  (void) width;
  NcursesEncap::n_attron(COLOR_PAIR((int)color));
  NcursesEncap::n_mvprintw(y + this->windowsize_y / 20,
			   (int) (x + this->windowsize_x / 2.5), " ");
  NcursesEncap::n_attroff(COLOR_PAIR((int)color));
}

bool  NcursesViewController::getKey(arcade::CommandType *commandType, ChangeCommandType &action, bool &exit)
{
  int key;

  key = NcursesEncap::n_getch();
  if (key == _KEY_ESC)
    {
      exit = true;
      return (false);
    }
  if (key == '3')
    action = ChangeCommandType::NEXT_LIBRARY;
  else if (key == '2')
    action = ChangeCommandType::PREV_LIBRARY;
  else if (key == '4')
    action = ChangeCommandType::PREV_GAME;
  else if (key == '5')
    action = ChangeCommandType::NEXT_GAME;
  else if (key == KEY_UP)
    *commandType = arcade::CommandType::GO_UP;
  else if (key == KEY_DOWN)
    *commandType = arcade::CommandType::GO_DOWN;
  else if (key == KEY_LEFT)
    *commandType = arcade::CommandType::GO_LEFT;
  else if (key == KEY_RIGHT)
    *commandType = arcade::CommandType::GO_RIGHT;
  else if (key == 10) //10 = Enter
    *commandType = arcade::CommandType::SHOOT;
  else if (key == '8')
    {
      *commandType = arcade::CommandType::RESTART;
      std::system("paplay assets/Mercy.ogg & > /dev/null 2>&1");
      this->playGameOver = false;
    }
  else if (key == '9')
    {
      action = ChangeCommandType::DISPLAY_MENU;
      this->playGameOver = false;
    }
  return (true);
}

void  NcursesViewController::initScreen(std::string const &name)
{
  std::string	changeTerminalName = "echo -n \"\033]0;" + name + " \007\"";

  if (this->functionCaller == "OTHER")
      std::system("paplay assets/Death_comes.ogg & > /dev/null 2>&1");
  std::system(changeTerminalName.c_str());
  NcursesEncap::n_clear();
  NcursesEncap::n_newterm();
  NcursesEncap::n_curs_set();
  NcursesEncap::n_noecho();
  NcursesEncap::n_nodelay();
  NcursesEncap::n_keypad();
  NcursesEncap::n_cbreak();
  NcursesEncap::n_start_color();
  NcursesEncap::n_getmaxyx(stdscr, &this->windowsize_y, &this->windowsize_x);
  max_X_sighandler = this->windowsize_x;
  max_Y_sighandler = this->windowsize_y;
  NcursesEncap::n_init_color(0, 0, 0, 0);
  NcursesEncap::n_init_pair(1, COLOR_RED, COLOR_RED);
  NcursesEncap::n_init_pair(2, COLOR_GREEN, COLOR_GREEN);
  NcursesEncap::n_init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
  NcursesEncap::n_init_pair(4, COLOR_BLUE, COLOR_BLUE);
  NcursesEncap::n_init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
  NcursesEncap::n_init_pair(6, COLOR_CYAN, COLOR_CYAN);
  NcursesEncap::n_init_pair(7, COLOR_WHITE, COLOR_WHITE);
  NcursesEncap::n_init_pair(8, COLOR_CYAN, COLOR_BLACK);
  srand(time(NULL));
}

void  NcursesViewController::refresh()
{
  signal(SIGWINCH, resizeHandler);
  this->windowsize_y = max_Y_sighandler;
  this->windowsize_x = max_X_sighandler;
  NcursesEncap::n_wrefresh(stdscr);
  NcursesEncap::n_refresh();
}

void  NcursesViewController::clear()
{
  NcursesEncap::n_clear();
}

void  NcursesViewController::gameOver(int score)
{
  if (!this->playGameOver)
    {
      std::system("paplay assets/Die_Die_Die.ogg & > /dev/null 2>&1");
      this->playGameOver = true;
    }
  NcursesEncap::n_mvprintw(this->windowsize_y / 20 + 10,
			   this->windowsize_x/ 2 - 4, "GameOver");
  NcursesEncap::n_mvprintw(this->windowsize_y / 20 + 12,
   			 this->windowsize_x/ 2 - 4, "Score: ");
  NcursesEncap::n_mvprintw(this->windowsize_y / 20 + 12,
  		   this->windowsize_x / 2 + 4, std::to_string(score).c_str());
  NcursesEncap::n_mvprintw(this->windowsize_y / 20 + 16,
  		   this->windowsize_x/ 2 - 11, "Press 8 to restart");
}

void	NcursesViewController::displayScore(int width, std::string const &Game, std::string const &libraryName, int score)
{
  NcursesEncap::n_mvprintw(this->windowsize_y / 20 + 4,
			   this->windowsize_x / 2 + width / 1.5, Game.c_str());
  NcursesEncap::n_mvprintw(this->windowsize_y / 20 + 2,
			   this->windowsize_x / 2 + width / 1.5, libraryName.c_str());
  NcursesEncap::n_mvprintw(this->windowsize_y / 20,
			   this->windowsize_x / 2 + width / 1.5, "Score: ");
  NcursesEncap::n_mvprintw(this->windowsize_y / 20,
			   this->windowsize_x / 2 + width / 1.5 + 9, std::to_string(score).c_str());
}

void  NcursesViewController::endScreen()
{
  NcursesEncap::n_nocbreak();
  NcursesEncap::n_endwin();
}

std::string	NcursesViewController::getLibraryName()
{
  return ("Ncurses");
}
