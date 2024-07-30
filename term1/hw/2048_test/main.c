#include <ncurses.h>

int main() {
    // 初始化curses库
    initscr();

    // 在屏幕上打印一条消息
    printw("Hello, ncurses!");

    // 刷新屏幕
    refresh();

    // 等待用户按键
    getch();

    // 结束curses模式
    endwin();

    return 0;
}

