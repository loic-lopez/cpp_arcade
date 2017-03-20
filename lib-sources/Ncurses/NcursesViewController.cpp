//
// NcursesController.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/NcursesController.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:05:35 2017 Loïc Lopez
// Last update Mon Mar 20 14:43:47 2017 Matthias Prost
//

#include "NcursesViewController.hpp"

extern "C" ILibraryViewController	*loadLibrary()
{
  return (new NcursesViewController());
}

NcursesViewController::~NcursesViewController()
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

void	NcursesViewController::loadScreen()
{
  WINDOW  *window;

	NcursesEncap::n_newterm();
  window = NcursesEncap::n_subwin(stdscr, 10, 45, 1, 94);
  while(1)
  {
    NcursesEncap::n_refresh();
    NcursesEncap::n_box(window, ACS_VLINE, ACS_HLINE);
    NcursesEncap::n_mvprintw(5, 5, "Test");
  }
	NcursesEncap::n_endwin();
}
