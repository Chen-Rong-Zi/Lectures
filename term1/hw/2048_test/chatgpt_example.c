#include <ncurses.h>

int main() {
    initscr();  // 初始化ncurses
    start_color();  // 启用颜色

    init_pair(1, COLOR_RED, COLOR_GREEN);  // 创建颜色对，第一个参数是颜色对的编号

    attron(COLOR_PAIR(1));  // 启用颜色对

    mvprintw(10, 10, "Hello, NCurses!");  // 在指定位置打印字符串

    attroff(COLOR_PAIR(1));  // 关闭颜色对

    refresh();  // 刷新屏幕

    getch();  // 等待用户按键

    endwin();  // 结束ncurses

    return 0;
}

