//
// NcursesEncap.hpp for arcade in /home/prost_m/Rendu/Semestre_4/cpp_arcade/lib-include/Ncurses/
//
// Made by Matthias Prost
// Login   <matthias.prost@epitech.eu@epitech.eu>
//
// Started on  Mon Mar 20 10:24:02 2017 Matthias Prost
// Last update Mon Mar 20 14:41:00 2017 Matthias Prost
//

#ifndef _NcursesEncap_H__
#define _NcursesEncap_H__

#include <curses.h>

class   NcursesEncap
{
public:
  static void n_newterm(void);
  static int n_endwin(void);
  static int n_refresh(void);
  static void n_mvprintw(int, int, const char *);
  static int  n_box(WINDOW *win, chtype verch, chtype horch);
  static WINDOW *n_subwin(WINDOW *orig, int nlines, int ncols, int begin_y, int begin_x);
};

#endif
