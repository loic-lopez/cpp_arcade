//
// NcursesEncap.cpp for arcade in /home/prost_m/Rendu/Semestre_4/cpp_arcade/lib-sources/Ncurses/
//
// Made by Matthias Prost
// Login   <matthias.prost@epitech.eu@epitech.eu>
//
// Started on  Mon Mar 20 10:25:11 2017 Matthias Prost
// Last update Mon Mar 20 11:07:41 2017 Matthias Prost
//

#include "NcursesEncap.hpp"

WINDOW *NcursesEncap::n_initscr(void)
{
  return(initscr());
}

int NcursesEncap::n_endwin(void)
{
  return(endwin());
}

int NcursesEncap::n_refresh(void)
{
  return (refresh());
}
