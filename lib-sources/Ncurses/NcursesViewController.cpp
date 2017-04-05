//
// NcursesController.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/NcursesController.cpp
//
// Made by Loïc Lopez
// Login   <loic.lopez@epitech.eu>
//
// Started on  jeu. mars 16 15:05:35 2017 Loïc Lopez
// Last update Wed Apr  5 16:54:15 2017 Matthias Prost
//

#include "NcursesViewController.hpp"
#include <signal.h>

int max_Y_sighandler;
int max_X_sighandler;

static void	resizeHandler(int sig)
{
  (void)sig;
  NcursesEncap::n_getmaxyx(stdscr, &max_Y_sighandler, &max_X_sighandler);
  clear();
  resizeterm(LINES, COLS);
  refresh();
}

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

static	void	print_in_middle(WINDOW *win, int starty, int startx,
					  int width, char *string, chtype color)
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

static	void	printKeys(int max_y, int max_x)
{
  mvprintw((max_y / 2) - 9, (max_x / 2) - 18, "Move the cursor menu to select a game.");
  mvprintw((max_y / 2) - 8, (max_x / 2) - 18, "Press enter to choose a game.");
  mvprintw((max_y / 2) - 6, (max_x / 2) - 18, "In Game :");
  mvprintw((max_y / 2) - 5, (max_x / 2) - 18, "Key 2 : move to previous graphical library.");
  mvprintw((max_y / 2) - 4, (max_x / 2) - 18, "Key 3 : move to next graphical library.");
  mvprintw((max_y / 2) - 3, (max_x / 2) - 18, "Key 4 : move to previous game.");
  mvprintw((max_y / 2) - 2, (max_x / 2) - 18, "Key 5 : move to next game.");
  mvprintw((max_y / 2) - 1, (max_x / 2) - 18, "Key 8 : restart the game.");
  mvprintw((max_y / 2), (max_x / 2) - 18, "Key 9 : display this menu.");
  mvprintw((max_y / 2) + 1, (max_x / 2) - 18, "Key Escape : quit the game or menu.");
  mvprintw((max_y / 2) + 2, (max_x / 2) - 18, "Move character with arrows.");
}

#include <iostream>

void	NcursesViewController::drawMenu(size_t &currentGame,
					    std::vector<std::string> const &games,
					    bool &exit)
{
  int	key;
  int n_choices;
  const char *choices[] =
   {
    "Snake",
    "SolarFox",
    "Exit",
    NULL,
   };


  this->initScreen("Arcade Game Menu");
  n_choices = ARRAY_SIZE(choices);
  for(int i = 0; i < n_choices; ++i)
    my_items[i] = new_item(choices[i], NULL);

  menu = new_menu(my_items);
  menu_win = newwin(10, 40, (this->windowsize_y / 2) - 20, (this->windowsize_x / 2) - 20);
  printKeys(this->windowsize_y, windowsize_x);
  keypad(menu_win, TRUE);
  set_menu_win(menu, menu_win);
  set_menu_sub(menu, derwin(menu_win, 6, 38, 3, 1));
  set_menu_fore(menu, COLOR_PAIR(8));
  set_menu_mark(menu, " -> ");
  box(menu_win, 0, 0);
  print_in_middle(menu_win, 1, 0, 40, (char *)"Arcade Game Menu", COLOR_PAIR(7));
  post_menu(menu);
  while((key = wgetch(menu_win)) != _KEY_ESC)
    {
      if (key == KEY_DOWN)
	menu_driver(menu, REQ_DOWN_ITEM);
      else if (key == KEY_UP)
    	menu_driver(menu, REQ_UP_ITEM);
      else if (key == _KEY_ENTER)
      	{
	  std::string item = item_name(current_item(menu));
	  if (item == "Exit")
	    {
	      exit = true;
	      break;
	    }
	  else
	    {
	      size_t	index;
	      std::transform(item.begin(), item.end(), item.begin(), ::tolower);
	      for (index = 0; index < games.size(); ++index)
		{
		  if (games.at(index).find(item) != std::string::npos)
		    {
		      currentGame = index;
		      break;
		    }
		}
	      if (index == games.size())
		{
		  exit = true;
		  break;
		}
	       else
		break;
	    }
      	}
      clear();
      printKeys(this->windowsize_y, windowsize_x);
      box(menu_win, 0, 0);
      print_in_middle(menu_win, 1, 0, 40, (char *)"Arcade Game Menu", COLOR_PAIR(7));
      wrefresh(menu_win);
    }
  if (key == _KEY_ESC)
    exit = true;
  unpost_menu(menu);
  free_menu(menu);
  for(int i = 0; i < n_choices; ++i)
    free_item(my_items[i]);
  endwin();
}

bool  NcursesViewController::getKey(arcade::CommandType *commandType, ChangeCommandType &action, bool &exit)
{
  int key;

  key = NcursesEncap::n_getch();
  if (key == _KEY_ESC)
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
  max_X_sighandler = this->windowsize_x;
  max_Y_sighandler = this->windowsize_y;
  NcursesEncap::n_init_color(0, 0, 0, 0);
  NcursesEncap::n_init_pair(1, COLOR_RED, COLOR_RED);
  NcursesEncap::n_init_pair(2, COLOR_GREEN, COLOR_GREEN);
  NcursesEncap::n_init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
  NcursesEncap::n_init_pair(4, COLOR_BLUE, COLOR_BLUE);
  NcursesEncap::n_init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
  NcursesEncap::n_init_pair(6, COLOR_CYAN, COLOR_CYAN);
  NcursesEncap::n_init_pair(7, COLOR_RED, COLOR_BLACK);
  NcursesEncap::n_init_pair(8, COLOR_CYAN, COLOR_BLACK);
  srand(time(NULL));
}

void  NcursesViewController::refresh()
{
  signal(SIGWINCH, resizeHandler);
  this->windowsize_y = max_Y_sighandler;
  this->windowsize_x = max_X_sighandler;
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
