#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

typedef struct {
  int v;
  int h;
} Position;

void buffer_cleanup(bool **buffer, int rows);
bool **new_buffer(Position dimentions);

int main(int argc, char **argv) {

  // TERM SETUP
  printf("\x1b[?25l"); // cursor invisible

  struct termios normal_mode;
  tcgetattr(STDIN_FILENO, &normal_mode);

  struct termios raw;
  tcgetattr(STDIN_FILENO, &raw);
  raw.c_lflag &= ~(ECHO | ICANON);
  raw.c_cc[VMIN] = 0;
  raw.c_cc[VTIME] = 1;
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);

  // WINDOW
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  Position win_size = {w.ws_row, w.ws_col};

  // BUFFERS
  bool **curr_buffer = new_buffer(win_size);
  bool **next_buffer = new_buffer(win_size);

  // sample starting point
  Position halfpoint = {win_size.v / 2, win_size.h / 2};

  //..x..
  //.xx..
  //..x..
  //..xx

  curr_buffer[halfpoint.v][halfpoint.h] = 1;
  curr_buffer[halfpoint.v][halfpoint.h + 1] = 1;
  curr_buffer[halfpoint.v + 1][halfpoint.h] = 1;
  curr_buffer[halfpoint.v - 1][halfpoint.h] = 1;
  curr_buffer[halfpoint.v + 2][halfpoint.h + 1] = 1;

  int sum_n = 0;
  int gen_count = 0;
  char input = ' ';

  while (input != 'q') {

    while (read(STDIN_FILENO, &input, 1)) {
    }

    // if (gen_count == 1)
    //   sleep(2);

    // LIFE
    for (int i = 1; i < win_size.v - 1; i++) {
      for (int j = 1; j < win_size.h - 1; j++) {

        // NEIGHBOURS
        sum_n = (curr_buffer[i + 1][j - 1]) + (curr_buffer[i + 1][j]) +
                (curr_buffer[i + 1][j + 1]) + (curr_buffer[i][j - 1]) +
                (curr_buffer[i][j + 1]) + (curr_buffer[i - 1][j + 1]) +
                (curr_buffer[i - 1][j - 1]) + (curr_buffer[i - 1][j]);

        // LOGIC / RULES

        //   if (sum_n == 1 || sum_n > 3)
        //     next_buffer[i][j] = 0;
        //   if ((sum_n == 2) || (sum_n == 3))
        //     next_buffer[i][j] = 1;

        if (curr_buffer[i][j])
          next_buffer[i][j] =
              !(sum_n == 1 || sum_n > 3) || ((sum_n == 2) || (sum_n == 3));
        else
          next_buffer[i][j] = !(sum_n - 3);
      }
    }

    // DRAW
    // printf("\x1b[2J"); // clear screen // niepotrzebne raczej
    printf("\x1b[H");

    for (int i = 0; i < win_size.v; i++) {
      for (int j = 0; j < win_size.h; j++) {
        if (i == 0 || i == w.ws_row - 1 || j == 0 || j == w.ws_col - 1)
          printf("#");
        else {
          printf("%c", (next_buffer[i][j]) ? '0' : ' ');
        }
      }
      printf("\x1b[1E");
    }

    // FRAME
    for (int i = 0; i < win_size.v; i++) {
      for (int j = 0; j < win_size.h; j++) {
        if (i == 0 || i == w.ws_row - 1 || j == 0 || j == w.ws_col - 1)
          printf("\x1b[1d#");
      }
    }

    // counting info
    printf("\x1b[2;2H"); // go 0, 0
    printf("Generation: %i", gen_count++);
    printf("\x1b[%i;%iH", win_size.v - 1, 2); // go 0, 0
    printf("Nasisnij 'q' zeby wyjść");

    // SWAP BUFFERS
    bool **temp = curr_buffer;
    curr_buffer = next_buffer;
    next_buffer = temp;

    // ROUTINE
    fflush(stdout);
    usleep(200 * 1000);
  }

  // out of the while here jkbc
  buffer_cleanup(curr_buffer, win_size.v);
  buffer_cleanup(next_buffer, win_size.v);

  printf("\x1b[?25h\x1b[2J\x1b[H"); // cursor visible // clear scr // go 00
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &normal_mode);

  return 0;
}

void buffer_cleanup(bool **buffer, int rows) {

  for (int i = 0; i < rows; i++)
    free(buffer[i]);
  free(buffer);
}

bool **new_buffer(Position dimentions) {

  bool **buffer = (bool**)malloc(sizeof(bool *) * dimentions.v);
  if (buffer == NULL)
    return NULL; // NOOOOOOOOOO

  for (int i = 0; i < dimentions.v; i++) {
    buffer[i] = (bool*)malloc(sizeof(bool) * dimentions.h); // check later please

    // zero them
    for (int j = 0; j < dimentions.h; j++) {
      buffer[i][j] = 0;
    }
  }
  return buffer;
}
