//
// NcursesEncap.cpp for arcade in /home/prost_m/Rendu/Semestre_4/cpp_arcade/lib-sources/Ncurses/
//
// Made by Matthias Prost
// Login   <matthias.prost@epitech.eu@epitech.eu>
//
// Started on  Mon Mar 20 10:25:11 2017 Matthias Prost
// Last update Fri Mar 24 08:42:25 2017 Yassir Jabbari
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

void  NcursesEncap::n_mvwprintw(WINDOW *win, int y, int x, const char *fmt)
{
  mvwprintw(win, y, x, fmt);
}

int   NcursesEncap::n_wrefresh(WINDOW * windows)
{
  return (wrefresh(windows));
}

int   NcursesEncap::n_getch()
{
  return (getch());
}

void  NcursesEncap::n_curs_set()
{
  curs_set(0);
}

void  NcursesEncap::n_noecho()
{
  noecho();
}

void  NcursesEncap::n_nodelay()
{
  nodelay(stdscr, TRUE);
}

void NcursesEncap::n_keypad()
{
  keypad(stdscr, TRUE);
}

void NcursesEncap::n_start_color()
{
  start_color();
}

void  NcursesEncap::n_init_pair(short a, short b, short c)
{
  init_pair(a, b, c);
}

int   NcursesEncap::n_attron(int attrs)
{
  return (attron(attrs));
}

int   NcursesEncap::n_attroff(int attrs)
{
    return (attroff(attrs));
}

void  NcursesEncap::n_getmaxyx(WINDOW *win, int *y, int *x)
{
  getmaxyx(win, *y, *x);
  (void)y;
}

void NcursesEncap::n_clear()
{
  clear();
}

int NcursesEncap::n_init_color(short color, short r, short g, short b)
{
  return (init_color(color, r, g, b));
}