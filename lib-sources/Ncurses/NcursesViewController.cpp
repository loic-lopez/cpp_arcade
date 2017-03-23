//
// NcursesController.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/NcursesController.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:05:35 2017 Loïc Lopez
// Last update Thu Mar 23 11:00:20 2017 Matthias Prost
//

#include "NcursesViewController.hpp"

extern "C" ILibraryViewController	*loadLibrary()
{
  return (new NcursesViewController());
}

NcursesViewController::NcursesViewController()
{

}

NcursesViewController::~NcursesViewController()
{

}

void NcursesViewController::drawMap(int mapsize_x, int mapsize_y)
{
  int x, y = -1;

  this->mapsize_x = mapsize_x;
  this->mapsize_y = mapsize_y;
  while (++y != mapsize_y)
    {
      while (++x != mapsize_x)
      {
        NcursesEncap::n_attron(COLOR_PAIR(1));
        NcursesEncap::n_mvprintw(y, x, "*");
        NcursesEncap::n_attroff(COLOR_PAIR(1));
      }
      x = -1;
    }
}

void	NcursesViewController::drawCharacter(std::array<int, 2> &position)
{
  (void)position;
}

bool  NcursesViewController::getKey(int &key, bool &exit)
{
  key = NcursesEncap::n_getch();
  if (key == 27)
    {
      exit = true;
      return (false);
    }
  if (key == '3')
    key = 1;
  if (key == '2')
    key = 2;
  return (true);
}

void  NcursesViewController::initScreen()
{
  int height, width;

  height = width = 0;
  NcursesEncap::n_newterm();
  NcursesEncap::n_curs_set();
  NcursesEncap::n_noecho();
  NcursesEncap::n_nodelay();
  NcursesEncap::n_keypad();
  NcursesEncap::n_start_color();
  NcursesEncap::n_getmaxyx(stdscr, &height, &width);
  this->h_size = height;
  this->v_size = width;
  NcursesEncap::n_init_pair(1, COLOR_BLUE, COLOR_BLUE);
}

void	NcursesViewController::displayText(std::string const &msg)
{
    NcursesEncap::n_mvprintw(2, 2, msg.c_str());
    NcursesEncap::n_refresh();
}

void  NcursesViewController::endScreen()
{
    NcursesEncap::n_endwin();
}
