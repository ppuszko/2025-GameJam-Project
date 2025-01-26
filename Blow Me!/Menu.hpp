#ifndef MENU_HPP
#define MENU_HPP
#include <raylib.h>

#define UNSELECTED 0
#define START 1
#define EXIT 2

class Menu {
    private:
        Texture logo_txtr;
        Texture start_txtr;
        Texture exit_txtr;
        bool exitflag = false;
        bool startflag = false;
        int selected = 0;
        Vector2 logo_dimensions;
        Vector2 option_dimensions;
    public:
        bool get_exitflag() { return exitflag; }
        bool get_startflag() { return startflag; }    
        Menu();
        void reset_menu();
        void draw_options();
        void check_options();
};

#endif
