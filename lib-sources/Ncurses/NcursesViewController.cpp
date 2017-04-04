//
// NcursesController.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/NcursesController.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:05:35 2017 Loïc Lopez
// Last update Mon Apr  3 17:57:27 2017 Matthias Prost
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

void	NcursesViewController::drawSquare(int width, int x, int y, Color const &color)
{
  (void) width;
  NcursesEncap::n_attron(COLOR_PAIR((int)color));
  NcursesEncap::n_mvprintw(y + this->windowsize_y / 20,
			   (int) (x + this->windowsize_x / 2.5), " ");
  NcursesEncap::n_attroff(COLOR_PAIR((int)color));
}

static int	my_strlen(char *str)
{
  int		i = 0;

  while (str[i])
    i++;
  return (i);
}

static void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color)
{
  int length, x, y;
  float temp;

  if(win == NULL)
    win = stdscr;
  getyx(win, y, x);
  if(startx != 0)
    x = startx;
  if(starty != 0)
    y = starty;
  if(width == 0)
    width = 80;

  length = my_strlen(string);
  temp = (width - length)/ 2;
  x = startx + (int)temp;
  wattron(win, color);
  mvwprintw(win, y, x, "%s", string);
  wattroff(win, color);
  refresh();
}


void  NcursesViewController::drawMenu(size_t &currentGame)
{
  (void)currentGame;
  ITEM **my_items;
  int c;
  MENU *my_menu;
  WINDOW *my_menu_win;
  int n_choices, i;
  char *choices[] = {
   (char *) "Snake",
   (char *) "SolarFox",
   (char *) "Exit",
   (char *) NULL,
  };

  this->initScreen("Arcade Game Menu");
  n_choices = ARRAY_SIZE(choices);
  my_items = (ITEM **)calloc(n_choices, sizeof(ITEM *));
  for(i = 0; i < n_choices; ++i)
    my_items[i] = new_item(choices[i], NULL);

  my_menu = new_menu(my_items);
  my_menu_win = newwin(10, 40, (this->windowsize_y / 2) - 20, (this->windowsize_x / 2) - 20);
  keypad(my_menu_win, TRUE);
  set_menu_win(my_menu, my_menu_win);
  set_menu_sub(my_menu, derwin(my_menu_win, 6, 38, 3, 1));
  set_menu_fore(my_menu, COLOR_PAIR(6));
  set_menu_mark(my_menu, " -> ");
  box(my_menu_win, 0, 0);
  print_in_middle(my_menu_win, 1, 0, 40, (char *)"Arcade Game Menu", COLOR_PAIR(1));
  post_menu(my_menu);
  while((c = wgetch(my_menu_win)) != 27)
    {       switch(c)
    {	case KEY_DOWN:
    menu_driver(my_menu, REQ_DOWN_ITEM);
      break;
      case KEY_UP:
	menu_driver(my_menu, REQ_UP_ITEM);
      break;
    }
      wrefresh(my_menu_win);
    }

  /* Unpost and free all the memory taken up */
  unpost_menu(my_menu);
  free_menu(my_menu);
  for(i = 0; i < n_choices; ++i)
    free_item(my_items[i]);
  endwin();
  exit(0);
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
  else if (key == ' ')
    *commandType = arcade::CommandType::RESTART;
  return (true);
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
  NcursesEncap::n_cbreak();
  NcursesEncap::n_start_color();
  NcursesEncap::n_getmaxyx(stdscr, &this->windowsize_y, &this->windowsize_x);
  NcursesEncap::n_init_color(0, 0, 0, 0);
  NcursesEncap::n_init_pair(1, COLOR_RED, COLOR_BLACK);
  NcursesEncap::n_init_pair(2, COLOR_GREEN, COLOR_BLACK);
  NcursesEncap::n_init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  NcursesEncap::n_init_pair(4, COLOR_BLUE, COLOR_BLACK);
  NcursesEncap::n_init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
  NcursesEncap::n_init_pair(6, COLOR_CYAN, COLOR_BLACK);
  srand(time(NULL));
}

void  NcursesViewController::refresh()
{
  NcursesEncap::n_wrefresh(stdscr);
  NcursesEncap::n_refresh();
}

void  NcursesViewController::clear()
{
  NcursesEncap::n_clear();
}

void  NcursesViewController::gameOver(int score)
{
  NcursesEncap::n_mvprintw(this->windowsize_y / 20 + 10,
			   this->windowsize_x/ 2 - 4, "GameOver");
  NcursesEncap::n_mvprintw(this->windowsize_y / 20 + 12,
   			 this->windowsize_x/ 2 - 4, "Score: ");
  NcursesEncap::n_mvprintw(this->windowsize_y / 20 + 12,
  		   this->windowsize_x / 2 + 4, std::to_string(score).c_str());
  NcursesEncap::n_mvprintw(this->windowsize_y / 20 + 16,
  		   this->windowsize_x/ 2 - 11, "Press SPACE to restart");
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
