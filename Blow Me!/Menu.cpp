//#include <raylib.h>
//
//int main() {
//  Texture logo = LoadTexture("../Assets/Logo.png");
//  
//  InitWindow(1200, 800, "Blow Me!");
//  InitAudioDevice();
//  Music music = LoadMusicStream("../Assets/music/muzyka1.mp3");
//  PlayMusicStream(music);
//
//  Texture start = LoadTexture("../Assets/start.png");
//  Texture exit = LoadTexture("../Assets/exit.png");
//  Texture background = LoadTexture("../Assets/background/Ocean_2/5.png");
//  
//  while (!WindowShouldClose()) {
//    UpdateMusicStream(music);
//    BeginDrawing(); 
//    {
//      ClearBackground(WHITE);
//      DrawTexturePro(background, {0, 0, (float)background.width, (float)background.height}, {0, 0, 1200, 800}, {0, 0}, 0, WHITE);
//      DrawTextureEx(logo, {600 - logo.width * 2.f, 20}, 0, 4, WHITE);
//      // start hovered
//      if (GetMouseX() >= 600 - start.width/2.f && GetMouseX() <= 600 + start.width/2.f) {
//        if (GetMouseY() >= 300 && GetMouseY() <= 300 + start.height * 2.0f) {
//          DrawTexturePro(start, {start.width/2.f, 0, start.width/2.f, (float)start.height}, {600 - start.width/2.f, 300, (float)start.width, start.height * 2.f}, {0, 0}, 0, WHITE);
//          DrawTexturePro(exit, {0, 0, start.width/2.f, (float)start.height}, {600 - start.width/2.f, 450, (float)start.width, start.height * 2.f}, {0, 0}, 0, WHITE);
//        }
//        // exit hovered
//        else if (GetMouseY() >= 450 && GetMouseY() <= 450 + start.height * 2.0f) {
//          DrawTexturePro(start, {0, 0, start.width/2.f, (float)start.height}, {600 - start.width/2.f, 300, (float)start.width, start.height * 2.f}, {0, 0}, 0, WHITE);
//          DrawTexturePro(exit, {start.width/2.f, 0, start.width/2.f, (float)start.height}, {600 - start.width/2.f, 450, (float)start.width, start.height * 2.f}, {0, 0}, 0, WHITE);
//          if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
//            return 0;
//          }
//        }
//        else {
//          DrawTexturePro(start, {0, 0, start.width/2.f, (float)start.height}, {600 - start.width/2.f, 300, (float)start.width, start.height * 2.f}, {0, 0}, 0, WHITE);
//          DrawTexturePro(exit, {0, 0, start.width/2.f, (float)start.height}, {600 - start.width/2.f, 450, (float)start.width, start.height * 2.f}, {0, 0}, 0, WHITE);
//        }
//      }
//      else {
//        DrawTexturePro(start, {0, 0, start.width/2.f, (float)start.height}, {600 - start.width/2.f, 300, (float)start.width, start.height * 2.f}, {0, 0}, 0, WHITE);
//        DrawTexturePro(exit, {0, 0, start.width/2.f, (float)start.height}, {600 - start.width/2.f, 450, (float)start.width, start.height * 2.f}, {0, 0}, 0, WHITE);
//      }
//      // DrawTextureEx(start, {600.f - start.width, 300}, 0, 2, WHITE);
//    }
//    EndDrawing();
//  }
//  return 0;
//}
