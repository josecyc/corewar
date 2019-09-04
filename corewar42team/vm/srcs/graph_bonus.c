
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include "../includes/vm.h"

WINDOW *create_newwin(int height, int width, int starty, int startx, char *title);
void destroy_win(WINDOW *local_win);

void error_handler_bonuses(int error)
{
	int token;

	endwin();
	if (error == 1)
		ft_putendl("\033[1;32mThis terminal window is too small, please expend it for decent visibility\033[0m");
	if (error == 2)
		ft_putendl("This terminal dont support colors");
	exit(error);	
}

int graph_bonus(t_player *players, t_arena *arena)
{	

	(void)players; (void)arena;
	WINDOW *big_win;
	WINDOW *side_win;
	WINDOW *down_win;
	int startx, starty, height;
	float width;
	int ch;
	int error_code;
	
	initscr();			/* Start curses mode 		*/
	
	
	cbreak();		
	start_color();		
	keypad(stdscr, TRUE);		/* I need that nifty F1 */
	noecho();
	
	if (COLS < 120 || LINES < 80)
		error_handler_bonuses(WINDOW_TO_SMALL);
	else if (has_colors() == FALSE)
		error_handler_bonuses(NO_COLORS);
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	height = LINES - 1;
	width = COLS * 0.6;
	starty = (LINES - LINES + 1);
	startx = (COLS - COLS + 1);	/* of the window		*/
	attron(COLOR_PAIR(1));
	printw("Press Q to exit");
	refresh();
	attroff(COLOR_PAIR(1));
	
//	my_win = create_newwin(height, (int)width, starty, startx);
	big_win = create_newwin(LINES * 0.8, COLS * 0.7, LINES - LINES + 1, COLS - COLS + 1, "ARENA");
	side_win = create_newwin(LINES * 0.8, COLS * 0.3, LINES - LINES + 1, (COLS * 0.7) + 1, "DATA");
	down_win = create_newwin(LINES * 0.2, COLS - 1, LINES - (LINES * 0.2 - 1), (COLS - COLS + 1), "OTHER DATA :-)");
	mvprintw(4,3,"viduvern is a rottweiller");
	refresh();
	mvwprintw(side_win, 2, 2, "viduv le pti chien");
	wrefresh(side_win);
	//	win2 = create_newwin();
	while ((ch = getch()) != 'q');
	endwin();			/* End curses mode		  */
	exit(1);
}

WINDOW *create_newwin(int height, int width, int starty, int startx, char *title)
{	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);		/* 0, 0 gives default characters */
	mvwprintw(local_win, 0,  width / 2 - ft_strlen(title), title);								 
								 
	wrefresh(local_win);		/* Show that box 		*/

	return local_win;
}

void destroy_win(WINDOW *local_win)
{	
	/* box(local_win, ' ', ' '); : This won't produce the desired
	 * result of erasing the window. It will leave it's four corners 
	 * and so an ugly remnant of window. 
	 */
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	/* The parameters taken are 
	 * 1. win: the window on which to operate
	 * 2. ls: character to be used for the left side of the window 
	 * 3. rs: character to be used for the right side of the window 
	 * 4. ts: character to be used for the top side of the window 
	 * 5. bs: character to be used for the bottom side of the window 
	 * 6. tl: character to be used for the top left corner of the window 
	 * 7. tr: character to be used for the top right corner of the window 
	 * 8. bl: character to be used for the bottom left corner of the window 
	 * 9. br: character to be used for the bottom right corner of the window
	 */
	wrefresh(local_win);
	delwin(local_win);
}
