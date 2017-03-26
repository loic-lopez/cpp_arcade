//
// NcursesController.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/NcursesController.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:05:35 2017 Loïc Lopez
// Last update Fri Mar 24 08:42:33 2017 Yassir Jabbari
//

#include "NcursesViewController.hpp"

extern "C" ILibraryViewController	*loadLibrary()
{
  return (new NcursesViewController());
}

NcursesViewController::NcursesViewController()
{
  this->score = 0;
}

NcursesViewController::~NcursesViewController()
{

}

void	NcursesViewController::drawSquare(int x, int y, Color const &color)
{
  NcursesEncap::n_attron(COLOR_PAIR((int)color));
  NcursesEncap::n_mvprintw(y + this->windowsize_y / 20,
			   (int) (x + this->windowsize_x / 2.5), "*");
  NcursesEncap::n_attroff(COLOR_PAIR((int)color));
}

void  NcursesViewController::drawMenu()
{
}

bool  NcursesViewController::getKey(arcade::CommandType *commandType, ChangeCommandType &action, bool &exit)
{
  int key;

  key = NcursesEncap::n_getch();
  if (key == 27)
    {
      exit = true;
      return (false);
    }
  if (key == '3')
    action = ChangeCommandType::NEXT_LIBRARY;
  else if (key == '2')
    action = ChangeCommandType::PREV_LIBRARY;
  else if (key == KEY_UP)
    *commandType = arcade::CommandType::GO_UP;
  else if (key == KEY_DOWN)
    *commandType = arcade::CommandType::GO_DOWN;
  else if (key == KEY_LEFT)
    *commandType = arcade::CommandType::GO_LEFT;
  else if (key == KEY_RIGHT)
    *commandType = arcade::CommandType::GO_RIGHT;
  return (true);
}

void  NcursesViewController::setScore(int score)
{
  this->score = score;
  NcursesEncap::n_mvprintw(this->windowsize_y/20,
    this->windowsize_x/1.5 + 9, std::to_string(this->score).c_str());
}

int  NcursesViewController::getScore()
{
  return (this->score);
}

void  NcursesViewController::initScreen(std::string const &name)
{
  std::string	changeTerminalName = "echo -n \"\033]0;" + name + " \007\"";

  system(changeTerminalName.c_str());
  NcursesEncap::n_clear();
  NcursesEncap::n_newterm();
  NcursesEncap::n_curs_set();
  NcursesEncap::n_noecho();
  NcursesEncap::n_nodelay();
  NcursesEncap::n_keypad();
  NcursesEncap::n_start_color();
  NcursesEncap::n_getmaxyx(stdscr, &this->windowsize_y, &this->windowsize_x);
  NcursesEncap::n_init_pair(1, COLOR_BLUE, COLOR_BLUE);
  NcursesEncap::n_init_pair(2, COLOR_BLACK, COLOR_BLACK);
  NcursesEncap::n_init_pair(3, COLOR_BLUE, COLOR_BLACK);
  NcursesEncap::n_init_pair(4, COLOR_RED, COLOR_RED);
  NcursesEncap::n_init_pair(5, COLOR_BLACK, COLOR_BLUE);
  NcursesEncap::n_refresh();
}

void  NcursesViewController::refresh()
{
  NcursesEncap::n_wrefresh(stdscr);
  NcursesEncap::n_refresh();
}

void	NcursesViewController::displayText(std::string const &Game, std::string const &libraryName) const
{
  NcursesEncap::n_mvprintw(this->windowsize_y /20,
			   this->windowsize_x / 1.5 - 9, Game.c_str());
  NcursesEncap::n_mvprintw(this->windowsize_y /20 + 2,
			   this->windowsize_x/ 1.5 - 9, libraryName.c_str());
  NcursesEncap::n_mvprintw(this->windowsize_y / 20,
			   this->windowsize_x/ 1.5 + 2, "Score: ");
  NcursesEncap::n_mvprintw(this->windowsize_y / 20,
			   this->windowsize_x / 1.5 + 9, std::to_string(this->score).c_str());
}

void  NcursesViewController::setUserXY(int x, int y)
{
  this->user_x = x + 1;
  this->user_y = y;

  NcursesEncap::n_attron(COLOR_PAIR(4));
  NcursesEncap::n_mvprintw(this->user_y + this->windowsize_y/20 + 1,
    this->user_x + this->windowsize_x/1.5 - 50 + 1, "*");
  NcursesEncap::n_mvprintw(this->user_y + this->windowsize_y/20 + 1,
    this->user_x + this->windowsize_x/1.5 - 50 + 2, "*");
  NcursesEncap::n_attroff(COLOR_PAIR(4));
}

int  NcursesViewController::getUserX()
{
  return (this->user_x);
}

int  NcursesViewController::getUserY()
{
  return (this->user_y);
}

void  NcursesViewController::endScreen()
{
    NcursesEncap::n_endwin();
}

std::string	NcursesViewController::getLibraryName()
{
  return ("Ncurses");
}