#include "Menu.hpp"
#include <cstdlib>
#include <raylib.h>
#include <iostream>

Menu::Menu() {
  logo_txtr = LoadTexture("../Assets/Logo.png");
  logo_dimensions = {(float)logo_txtr.width, (float)logo_txtr.height};
  start_txtr = LoadTexture("../Assets/start.png");
  exit_txtr = LoadTexture("../Assets/exit.png");
  option_dimensions = {start_txtr.width/2.f, (float)start_txtr.height};
}
void Menu::reset_menu() {
  exitflag = false;
  startflag = false;
}

void Menu::check_options() {
  if (GetMouseX() >= screenWidth / 2 - option_dimensions.x && GetMouseX() <= screenWidth / 2 + option_dimensions.x)
  {
    if (GetMouseY() >= screenHeight * 0.45f && GetMouseY() <= screenHeight * 0.45f + option_dimensions.y * 2)
      selected = START;
    else if (GetMouseY() >= screenHeight * 0.6f && GetMouseY() <= screenHeight * 0.6f + option_dimensions.y * 2)
      selected = EXIT;
    else
      selected = UNSELECTED;
  }
  else selected = UNSELECTED;
}

void Menu::draw_options() {
    DrawTextureEx(logo_txtr, { screenWidth / 2 - logo_dimensions.x * 2 + 30, screenHeight * 0.1f }, 0, 4, WHITE);

  Rectangle start_source = {
    0,
    0,
    option_dimensions.x,
    option_dimensions.y
  };

  Rectangle exit_source = {
    0,
    0,
    option_dimensions.x,
    option_dimensions.y
  };

  Rectangle start_dest = {
    screenWidth / 2 - option_dimensions.x,
    screenHeight* 0.45f,
    option_dimensions.x * 2,
    option_dimensions.y * 2
  };

  Rectangle exit_dest = {
    screenWidth / 2 - option_dimensions.x,
    screenHeight * 0.6f,
    option_dimensions.x * 2,
    option_dimensions.y * 2
  };

  switch (selected) {
    case START:
      start_source.x = option_dimensions.x;
      exit_source.x = 0;
      break;
    case EXIT:
      start_source.x = 0;
      exit_source.x = option_dimensions.x;
      break;
    case UNSELECTED:
      start_source.x = 0;
      exit_source.x = 0;
      break;
  }
  DrawTexturePro(start_txtr, start_source, start_dest, {0, 0}, 0, WHITE);
  DrawTexturePro(exit_txtr, exit_source, exit_dest, {0, 0}, 0, WHITE);
  
  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    if (selected == START) startflag = true;
    else if (selected == EXIT) exitflag = true;
  }
}

