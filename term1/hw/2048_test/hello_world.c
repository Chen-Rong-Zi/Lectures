# include <ncurses.h>
# include <string.h>

int initialize(){
    initscr();              // start curses mode
    raw();                  // diable line buffering
//     cbreak();               // no idea how to use this!
    keypad(stdscr, TRUE);   // enable arrow keys and f1, f2, etc.
//     noecho();               // Don't echo when we do getch
}

int take_name(char *string){
    mvwprintw(stdscr, 0, 0, "What's your name? ");
    refresh();
    getstr(string);
    clear();
    return 0;
}

int main()
{
    initialize();
    int row = 0, col = 0;
    char name[20] = {0};

    getmaxyx(stdscr, row, col);
    take_name(name);
    if ( strcmp(name, "rongzi") == 0 )
        printw("your are the correct owner!");
    else
    {
        attron(A_UNDERLINE | A_BOLD);
        mvwprintw(stdscr, row/2 - 10, col/2 - 4, "You didn't pass the exam!");
        attroff(A_UNDERLINE | A_BOLD);
        mvwprintw(stdscr, row/2, 0, "%d, %d", row, col);
    }
    refresh();
    getch();
    endwin();
    return 0;
}
