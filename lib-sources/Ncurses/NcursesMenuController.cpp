/*
** NcursesMenuController.cpp.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/NcursesMenuController.cpp.cpp
**
** Made by Loïc Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  jeu. avr. 06 13:27:47 2017 Loïc Lopez
** Last update Fri Apr  7 20:19:16 2017 Matthias Prost
*/

#include "NcursesViewController.hpp"

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
  NcursesEncap::n_mvwprintw(win, y, x, string);
  wattroff(win, color);
  refresh();
}

static	void	printKeys(int max_y, int max_x)
{
  NcursesEncap::n_mvprintw((max_y / 2) - 9, (max_x / 2) - 18, "Move the cursor menu to select a game.");
  NcursesEncap::n_mvprintw((max_y / 2) - 8, (max_x / 2) - 18, "Press enter to choose a game.");
  NcursesEncap::n_mvprintw((max_y / 2) - 6, (max_x / 2) - 18, "In Game :");
  NcursesEncap::n_mvprintw((max_y / 2) - 5, (max_x / 2) - 18, "Key 2 : move to previous graphical library.");
  NcursesEncap::n_mvprintw((max_y / 2) - 4, (max_x / 2) - 18, "Key 3 : move to next graphical library.");
  NcursesEncap::n_mvprintw((max_y / 2) - 3, (max_x / 2) - 18, "Key 4 : move to previous game.");
  NcursesEncap::n_mvprintw((max_y / 2) - 2, (max_x / 2) - 18, "Key 5 : move to next game.");
  NcursesEncap::n_mvprintw((max_y / 2) - 1, (max_x / 2) - 18, "Key 8 : restart the game.");
  NcursesEncap::n_mvprintw((max_y / 2), (max_x / 2) - 18, "Key 9 : display this menu.");
  NcursesEncap::n_mvprintw((max_y / 2) + 1, (max_x / 2) - 18, "Key Escape : quit the game or menu.");
  NcursesEncap::n_mvprintw((max_y / 2) + 2, (max_x / 2) - 18, "Move character with arrows.");
  NcursesEncap::n_mvprintw((max_y / 2) + 3, (max_x / 2) - 18, "Space to shoot (SolarFox)");
}

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

  this->functionCaller = __FUNCTION__;
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
  set_menu_fore(menu, COLOR_PAIR(0));
  set_menu_mark(menu, " -> ");
  box(menu_win, 0, 0);
  print_in_middle(menu_win, 1, 0, 40, (char *)"Arcade Game Menu", COLOR_PAIR(0));
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
      print_in_middle(menu_win, 1, 0, 40, (char *)"Arcade Game Menu", COLOR_PAIR(0));
      NcursesEncap::n_wrefresh(menu_win);
    }
  if (key == _KEY_ESC)
    exit = true;
  unpost_menu(menu);
  free_menu(menu);
  for(int i = 0; i < n_choices; ++i)
    free_item(my_items[i]);
  this->functionCaller = "OTHER";
  this->endScreen();
}
