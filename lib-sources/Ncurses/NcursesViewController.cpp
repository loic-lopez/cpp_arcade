//
// NcursesController.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/NcursesController.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:05:35 2017 Loïc Lopez
// Last update Wed Mar 22 13:36:35 2017 Matthias Prost
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

void NcursesViewController::drawMenu()
{
}

void	NcursesViewController::drawCharacter(std::array<int, 2> &position)
{
  (void)position;
}

void	NcursesViewController::drawMap(std::map<int, int> &map)
{
  (void)map;
}

#include <iostream>

bool  NcursesViewController::getEscapeKey(int &key, bool &exit)
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
  NcursesEncap::n_newterm();
  NcursesEncap::n_curs_set();
  NcursesEncap::n_noecho();
  NcursesEncap::n_nodelay();
  NcursesEncap::n_keypad();
}

void	NcursesViewController::displayText(std::string const &msg)
{
    NcursesEncap::n_mvprintw(1, 1, msg.c_str());
    NcursesEncap::n_refresh();
}

void  NcursesViewController::endScreen()
{
    NcursesEncap::n_endwin();
}
