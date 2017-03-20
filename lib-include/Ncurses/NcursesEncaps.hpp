//
// NcursesEncap.hpp for arcade in /home/prost_m/Rendu/Semestre_4/cpp_arcade/lib-include/Ncurses/
//
// Made by Matthias Prost
// Login   <matthias.prost@epitech.eu@epitech.eu>
//
// Started on  Mon Mar 20 10:24:02 2017 Matthias Prost
// Last update Mon Mar 20 10:49:17 2017 Matthias Prost
//

#ifndef _NcursesEncap_H__
#define _NcursesEncap_H__

#include <ncurses.h>

class   NcursesEncap
{
public:
  NcursesEncap();
  ~NcursesEncap();
  WINDOW *initscr(void);
  int endwin(void);
};

#endif
