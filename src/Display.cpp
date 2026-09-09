#include "Display.h"

Display::Display(Dim plansza) {
  displayDim = plansza;
  displayDimentions = plansza.x * plansza.y;
  hIn = GetStdHandle(STD_INPUT_HANDLE);
  hOut = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Display::draw() {

  // 0,0
  COORD pos = {0, 0};
  SetConsoleCursorPosition(hOut, pos);

  DWORD bufSize = (displayDim.x + 1) * displayDim.y; // bo newline
  char *displayBuffer = new char[bufSize];

  int index = 0;
  int out = 0;
  for (int i = 0; i < displayDim.y; i++) {
    for (int j = 0; j < displayDim.x; j++) {
      index = i * displayDim.x + j;
      displayBuffer[out++] = board[index] ? '|' : '.';
    }
    displayBuffer[out++] = '\n';
  }

  DWORD written; // windows stuff
  WriteConsoleA(hOut, displayBuffer, out, &written, nullptr);

  delete[] displayBuffer;
}

void Display::update() { draw(); }

void Display::clearScreen() {
  HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO info;
  DWORD cells, written;
  COORD origin = {0, 0};

  // rozmiar
  GetConsoleScreenBufferInfo(out, &info);
  cells = info.dwSize.X * info.dwSize.Y;

  // wypełnij po windowsowemu
  FillConsoleOutputCharacter(out, ' ', cells, origin, &written);

  // optionale, nie jestem pewien
  FillConsoleOutputAttribute(out, info.wAttributes, cells, origin, &written);

  // WAŻNE, 0,0
  SetConsoleCursorPosition(out, origin);
}

void Display::hideCursor() {
  CONSOLE_CURSOR_INFO cursorInfo;
  GetConsoleCursorInfo(hOut, &cursorInfo);
  cursorInfo.bVisible = FALSE;
  SetConsoleCursorInfo(hOut, &cursorInfo);
}

void Display::showCursor() {
  CONSOLE_CURSOR_INFO cursorInfo;
  GetConsoleCursorInfo(hOut, &cursorInfo);
  cursorInfo.bVisible = TRUE;
  SetConsoleCursorInfo(hOut, &cursorInfo);
}
