//
// NcursesEncap.cpp for arcade in /home/prost_m/Rendu/Semestre_4/cpp_arcade/lib-sources/Ncurses/
//
// Made by Matthias Prost
// Login   <matthias.prost@epitech.eu@epitech.eu>
//
// Started on  Mon Mar 20 10:25:11 2017 Matthias Prost
// Last update Mon Mar 20 14:43:01 2017 Matthias Prost
//

#include "NcursesEncap.hpp"

void NcursesEncap::n_newterm(void)
{
  newterm(NULL, stderr, stdin);
}

int NcursesEncap::n_endwin(void)
{
  return(endwin());
}

int NcursesEncap::n_refresh(void)
{
  return (refresh());
}

void NcursesEncap::n_mvprintw(int x, int y, const char *str)
{
  mvprintw(x, y, str);
}

int NcursesEncap::n_box(WINDOW *win, chtype verch, chtype horch)
{
  return box(win, verch, horch);
}

WINDOW *NcursesEncap::n_subwin(WINDOW *orig, int nlines, int ncols, int begin_y, int begin_x)
{
  return subwin(orig, nlines, ncols, begin_y, begin_x);
}
