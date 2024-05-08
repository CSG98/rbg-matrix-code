
#include "led-matrix.h"
#include "graphics.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <vector>
#include <string>
#include <time.h>
#include <cmath>

int xpos = 63;
int ypos = 1;
int correctedY = 0;
int Score1 = 0;
int Score2 = 0;
int Tens1;
int Remainder1;
int Tens2;
int Remainder2;
int NumberofPlayers = 1;
int a = 0;
int b = 0;
int c = 0;
int d = 0;
int e = 0;
int f = 0;
int g = 0;
int RealYValues [40] = {0,1,2,3,8,9,10,11,16,17,4,5,6,7,12,13,14,15,20,21,18,19,24,25,26,27,32,33,34,35,22,23,28,29,30,31,36,37,38,39};
int start_timer = 120;
int start_score = 0;
int Timer;
int minutes;
int seconds1;
int seconds2;

uint32_t inputs = 0;

//uint8_t Number1[14] = {0B00000110,0B00001110,0B00011110,0B00111110,0B11111110,0B11100110,0B00000110,0B00000110,0B00000110,0B00000110,0B00000110,0B00000110,0B00000110,0B00000000};
//uint8_t Number2[14] = {0B01111100,0B11111110,0B11000110,0B11000110,0B00000110,0B00000110,0B00001110,0B00011100,0B00111000,0B01110000,0B11100000,0B11111111,0B11111111,0B00000000};
//uint8_t Number3[14] = {0B01111100,0B11111110,0B11000110,0B00000110,0B00000110,0B00001110,0B00011100,0B00001110,0B00000110,0B11000110,0B11000110,0B11111110,0B01111100,0B00000000};
//uint8_t Number4[14] = {0B00000010,0B00000110,0B00001110,0B00011110,0B00111110,0B01110110,0B11100110,0B11000110,0B11111110,0B11111110,0B00000110,0B00000110,0B00000110,0B00000000};
//uint8_t Number5[14] = {0B11111110,0B11111110,0B11000000,0B11000000,0B11000000,0B11111100,0B11111110,0B00000110,0B00000110,0B11000110,0B11000110,0B11111110,0B01111100,0B00000000};
//uint8_t Number6[14] = {0B01111100,0B11111110,0B11000110,0B11000110,0B11000000,0B11111110,0B11111110,0B11000110,0B11000110,0B11000110,0B11000110,0B11111110,0B01111100,0B00000000};
//uint8_t Number7[14] = {0B11111110,0B11111100,0B00001100,0B00001100,0B00011000,0B00011000,0B00110000,0B00110000,0B01100000,0B01100000,0B00110000,0B00110000,0B00110000,0B00000000};
//uint8_t Number8[14] = {0B01111100,0B11111110,0B11000110,0B11000110,0B11000110,0B11111110,0B01111100,0B01111100,0B11000110,0B11000110,0B11000110,0B11111110,0B01111100,0B00000000};
//uint8_t Number9[14] = {0B01111100,0B11111110,0B11000110,0B11000110,0B11000110,0B11000110,0B11000110,0B11111110,0B01111110,0B00000110,0B11000110,0B11111110,0B01111100,0B00000000};
//uint8_t Number0[14] = {0B01111100,0B11111110,0B11000110,0B11000110,0B11000110,0B11000110,0B11000110,0B11000110,0B11000110,0B11000110,0B11000110,0B11111110,0B01111100,0B00000000};

uint8_t Numbers[140] ={0B00111110,0B01111111,0B01100011,0B01100011,0B01100011,0B01100011,0B01100011,0B01100011,0B01100011,0B01100011,0B01100011,0B01111111,0B00111110,0B00000000
                      ,0B01100000,0B01110000,0B01111000,0B01111100,0B01111111,0B01100111,0B01100000,0B01100000,0B01100000,0B01100000,0B01100000,0B01100000,0B01100000,0B00000000
                      ,0B00111110,0B01111111,0B01100011,0B01100011,0B01100000,0B01100000,0B01110000,0B00111000,0B00011100,0B00001110,0B00000111,0B01111111,0B01111111,0B00000000
                      ,0B00111110,0B01111111,0B01100011,0B01100000,0B01100000,0B01110000,0B00111000,0B01110000,0B01100000,0B01100011,0B01100011,0B01111111,0B00111110,0B00000000
                      ,0B01000000,0B01100000,0B01110000,0B01111000,0B01111100,0B01110110,0B01100111,0B01100011,0B01111111,0B01111111,0B01100000,0B01100000,0B01100000,0B00000000
                      ,0B01111111,0B01111111,0B00000011,0B00000011,0B00000011,0B00111111,0B01111111,0B01100000,0B01100000,0B01100011,0B01100011,0B01111111,0B00111110,0B00000000
                      ,0B00111110,0B01111111,0B01100011,0B01100011,0B00000011,0B01111111,0B01111111,0B01100011,0B01100011,0B01100011,0B01100011,0B01111111,0B00111110,0B00000000
                      ,0B01111111,0B01111111,0B01100000,0B01100000,0B01100000,0B01100000,0B00110000,0B00110000,0B00011000,0B00011000,0B00011000,0B00011000,0B00011000,0B00000000
                      ,0B00111110,0B01111111,0B01100011,0B01100011,0B01100011,0B01111111,0B00111110,0B00111110,0B01100011,0B01100011,0B01100011,0B01111111,0B00111110,0B00000000
                      ,0B00111110,0B01111111,0B01100011,0B01100011,0B01100011,0B01100011,0B01100011,0B01111111,0B01111110,0B01100000,0B01100011,0B01111111,0B00111110,0B00000000};



using namespace rgb_matrix;


volatile bool interrupt_received = false;
static void InterruptHandler(int signo) {
  interrupt_received = true;
}

  Color color(255, 255, 255);
  Color green(0,255,0);
  Color bg_color(0, 0, 0);
  Color flood_color(0, 0, 0);
  Color outline_color(0,0,0);

static int usage(const char *progname) {
  fprintf(stderr, "usage: %s [options]\n", progname);
  fprintf(stderr, "Reads text from stdin and displays it. "
          "Empty string: clear screen\n");
  fprintf(stderr, "Options:\n");
  fprintf(stderr,
          "\t-x <x-origin>     : X-Origin of displaying text (Default: 0)\n"
          "\t-y <y-origin>     : Y-Origin of displaying text (Default: 0)\n"
          "\t-C <r,g,b>        : Color. Default 255,255,0\n"
          "\t-F <r,g,b>        : Panel flooding-background color. Default 0,0,0\n"
          "\n"
          );
  rgb_matrix::PrintMatrixFlags(stderr);
  return 1;
}


static bool parseColor(Color *c, const char *str) {
  return sscanf(str, "%hhu,%hhu,%hhu", &c->r, &c->g, &c->b) == 3;
}

static bool FullSaturation(const Color &c) {
  return (c.r == 0 || c.r == 255)
    && (c.g == 0 || c.g == 255)
    && (c.b == 0 || c.b == 255);
}

void CorrectYValues(int y){
  correctedY = RealYValues[y];
}

int main(int argc, char *argv[]) {
  RGBMatrix::Options matrix_options;
  matrix_options.multiplexing = 13;
  matrix_options.rows = 40;
  matrix_options.cols = 80;
  matrix_options.brightness = 30;
  matrix_options.chain_length = 1;
  rgb_matrix::RuntimeOptions runtime_opt;
  if (!rgb_matrix::ParseOptionsFromFlags(&argc, &argv,
                                         &matrix_options, &runtime_opt)) {
    return usage(argv[0]);
  }
  runtime_opt.gpio_slowdown = 3;
  runtime_opt.drop_privileges = 1;
  
  int x_orig = 0;
  int y_orig = 1;
  int y_clock = 20;

  int opt;
  while ((opt = getopt(argc, argv, "x:y:C:B:F:")) != -1) {
    switch (opt) {
    case 'x': x_orig = atoi(optarg); break;
    case 'y': y_orig = atoi(optarg); break;
    case 'C':
      if (!parseColor(&color, optarg)) {
        fprintf(stderr, "Invalid color spec: %s\n", optarg);
        return usage(argv[0]);
      }
      break;
    case 'B':
      if (!parseColor(&bg_color, optarg)) {
        fprintf(stderr, "Invalid background color spec: %s\n", optarg);
        return usage(argv[0]);
      }
      break;
    case 'F':
      if (!parseColor(&flood_color, optarg)) {
        fprintf(stderr, "Invalid background color spec: %s\n", optarg);
        return usage(argv[0]);
      }
      break;
    default:
      return usage(argv[0]);
    }
  }



  RGBMatrix *canvas = RGBMatrix::CreateFromOptions(matrix_options, runtime_opt);
  if (canvas == NULL)
    return 1;

  const bool all_extreme_colors = (matrix_options.brightness == 100)
    && FullSaturation(color)
    && FullSaturation(bg_color)
    && FullSaturation(outline_color);
  if (all_extreme_colors)
    canvas->SetPWMBits(1);

  canvas->Fill(flood_color.r, flood_color.g, flood_color.b);
  char line[1024];
  while (fgets(line, sizeof(line), stdin)) {
    const size_t last = strlen(line);
    if (last > 0) line[last - 1] = '\0';  // remove newline.
    bool line_empty = strlen(line) == 0;

    if (line_empty)
      continue;
  }
  
  FrameCanvas *offscreen = canvas->CreateFrameCanvas();
  canvas->Fill(bg_color.r, bg_color.g, bg_color.b);
  
  

  struct timespec next_time;
  next_time.tv_sec = time(NULL);
  next_time.tv_nsec = 0;
  struct tm tm;

  signal(SIGTERM, InterruptHandler);
  signal(SIGINT, InterruptHandler);
  Timer = start_timer;
  
  while (!interrupt_received) {
    //S for score
  rgb_matrix::DrawLine(canvas, 2, 1, 4, 1, color);
  rgb_matrix::DrawLine(canvas, 1, 2, 5, 2, color);
  rgb_matrix::DrawLine(canvas, 0, 3, 1, 3, color);
  rgb_matrix::DrawLine(canvas, 5, 3, 6, 3, color);
  rgb_matrix::DrawLine(canvas, 0, 8, 1, 8, color);
  rgb_matrix::DrawLine(canvas, 5, 8, 6, 8, color);
  rgb_matrix::DrawLine(canvas, 0, 9, 3, 9, color);
  rgb_matrix::DrawLine(canvas, 1, 10, 4, 10, color);
  rgb_matrix::DrawLine(canvas, 3, 11, 5, 11, color);
  rgb_matrix::DrawLine(canvas, 3, 16, 6, 16, color);
  rgb_matrix::DrawLine(canvas, 0, 17, 1, 17, color);
  rgb_matrix::DrawLine(canvas, 5, 17, 6, 17, color);
  rgb_matrix::DrawLine(canvas, 0, 4, 1, 4, color);
  rgb_matrix::DrawLine(canvas, 5, 4, 6, 4, color);
  rgb_matrix::DrawLine(canvas, 5, 5, 6, 5, color);
  rgb_matrix::DrawLine(canvas, 0, 5, 1, 5, color);
  rgb_matrix::DrawLine(canvas, 1, 6, 5, 6, color);
  rgb_matrix::DrawLine(canvas, 2, 7, 4, 7, color);

//c 8
  rgb_matrix::DrawLine(canvas, 10, 1, 13, 1, color);
  rgb_matrix::DrawLine(canvas, 9, 2, 14, 2, color);
  rgb_matrix::DrawLine(canvas, 8, 3, 10, 3, color);
  rgb_matrix::DrawLine(canvas, 12, 3, 14, 3, color);
  rgb_matrix::DrawLine(canvas, 8, 8, 9, 8, color);
  rgb_matrix::DrawLine(canvas, 12, 8, 14, 8, color);
  rgb_matrix::DrawLine(canvas, 8, 9, 9, 9, color);
  rgb_matrix::DrawLine(canvas, 8, 10, 9, 10, color);
  rgb_matrix::DrawLine(canvas, 8, 11, 9, 11, color);
  rgb_matrix::DrawLine(canvas, 8, 16, 9, 16, color);
  rgb_matrix::DrawLine(canvas, 8, 17, 9, 17, color);
  rgb_matrix::DrawLine(canvas, 12, 17, 14, 17, color);
  rgb_matrix::DrawLine(canvas, 8, 4, 9, 4, color);
  rgb_matrix::DrawLine(canvas, 12, 4, 14, 4, color);
  rgb_matrix::DrawLine(canvas, 8, 5, 13, 5, color);
  rgb_matrix::DrawLine(canvas, 9, 6, 13, 6, color);
  rgb_matrix::DrawLine(canvas, 10, 7, 12, 7, color);

//o  16
  rgb_matrix::DrawLine(canvas, 18, 1, 20, 1, color);
  rgb_matrix::DrawLine(canvas, 17, 2, 21, 2, color);
  rgb_matrix::DrawLine(canvas, 16, 3, 18, 3, color);
  rgb_matrix::DrawLine(canvas, 20, 3, 22, 3, color);
  rgb_matrix::DrawLine(canvas, 16, 8, 17, 8, color);
  rgb_matrix::DrawLine(canvas, 21, 8, 22, 8, color);
  rgb_matrix::DrawLine(canvas, 16, 9, 17, 9, color);
  rgb_matrix::DrawLine(canvas, 21, 9, 22, 9, color);
  rgb_matrix::DrawLine(canvas, 16, 10, 17, 10, color);
  rgb_matrix::DrawLine(canvas, 21, 10, 22, 10, color);
  rgb_matrix::DrawLine(canvas, 16, 11, 17, 11, color);
  rgb_matrix::DrawLine(canvas, 21, 11, 22, 11, color);
  rgb_matrix::DrawLine(canvas, 16, 16, 17, 16, color);
  rgb_matrix::DrawLine(canvas, 21, 16, 22, 16, color);
  rgb_matrix::DrawLine(canvas, 16, 17, 17, 17, color);
  rgb_matrix::DrawLine(canvas, 21, 17, 22, 17, color);
  rgb_matrix::DrawLine(canvas, 16, 4, 17, 4, color);
  rgb_matrix::DrawLine(canvas, 21, 4, 22, 4, color);
  rgb_matrix::DrawLine(canvas, 16, 5, 18, 5, color);
  rgb_matrix::DrawLine(canvas, 20, 5, 22, 5, color);
  rgb_matrix::DrawLine(canvas, 17, 6, 21, 6, color);
  rgb_matrix::DrawLine(canvas, 18, 7, 20, 7, color);
 

//r 24
  rgb_matrix::DrawLine(canvas, 24, 1, 29, 1, color);
  rgb_matrix::DrawLine(canvas, 24, 2, 30, 2, color);
  rgb_matrix::DrawLine(canvas, 24, 3, 25, 3, color);
  rgb_matrix::DrawLine(canvas, 29, 3, 30, 3, color);
  rgb_matrix::DrawLine(canvas, 24, 8, 25, 8, color);
  rgb_matrix::DrawLine(canvas, 29, 8, 30, 8, color);
  rgb_matrix::DrawLine(canvas, 24, 9, 25, 9, color);
  rgb_matrix::DrawLine(canvas, 29, 9, 30, 9, color);
  rgb_matrix::DrawLine(canvas, 24, 10, 30, 10, color);
  rgb_matrix::DrawLine(canvas, 24, 11, 29, 11, color);
  rgb_matrix::DrawLine(canvas, 24, 16, 25, 16, color);
  rgb_matrix::DrawLine(canvas, 27, 16, 28, 16, color);
  rgb_matrix::DrawLine(canvas, 24, 17, 25, 17, color);
  rgb_matrix::DrawLine(canvas, 27, 17, 28, 17, color);
  rgb_matrix::DrawLine(canvas, 24, 4, 25, 4, color);
  rgb_matrix::DrawLine(canvas, 28, 4, 29, 4, color);
  rgb_matrix::DrawLine(canvas, 24, 5, 25, 5, color);
  rgb_matrix::DrawLine(canvas, 28, 5, 29, 5, color);
  rgb_matrix::DrawLine(canvas, 24, 6, 25, 6, color);
  rgb_matrix::DrawLine(canvas, 29, 6, 30, 6, color);
  rgb_matrix::DrawLine(canvas, 24, 7, 25, 7, color);
  rgb_matrix::DrawLine(canvas, 29, 7, 30, 7, color);
 
//e 32

  rgb_matrix::DrawLine(canvas, 32, 1, 38, 1, color);
  rgb_matrix::DrawLine(canvas, 32, 2, 38, 2, color);
  rgb_matrix::DrawLine(canvas, 32, 3, 38, 3, color);
  rgb_matrix::DrawLine(canvas, 32, 8, 33, 8, color);
  rgb_matrix::DrawLine(canvas, 32, 9, 33, 9, color);
  rgb_matrix::DrawLine(canvas, 32, 10, 38, 10, color);
  rgb_matrix::DrawLine(canvas, 32, 11, 38, 11, color);
  rgb_matrix::DrawLine(canvas, 32, 16, 38, 16, color);
  rgb_matrix::DrawLine(canvas, 32, 17, 33, 17, color);
  rgb_matrix::DrawLine(canvas, 32, 4, 33, 4, color);
  rgb_matrix::DrawLine(canvas, 32, 5, 33, 5, color);
  rgb_matrix::DrawLine(canvas, 32, 6, 38, 6, color);
  rgb_matrix::DrawLine(canvas, 32, 7, 38, 7, color);
  
//T
  CorrectYValues(y_clock);
  rgb_matrix::DrawLine(canvas, x_orig, correctedY, x_orig+6, correctedY, color);
  CorrectYValues(y_clock+1);
  rgb_matrix::DrawLine(canvas, x_orig, correctedY, x_orig+6, correctedY, color);
  CorrectYValues(y_clock+2);
  rgb_matrix::DrawLine(canvas, x_orig, correctedY, x_orig+6, correctedY, color);
  CorrectYValues(y_clock+3);
  rgb_matrix::DrawLine(canvas, x_orig+2, correctedY, x_orig+4, correctedY, color);
  CorrectYValues(y_clock+4);
  rgb_matrix::DrawLine(canvas, x_orig+2, correctedY, x_orig+4, correctedY, color);
  CorrectYValues(y_clock+5);
  rgb_matrix::DrawLine(canvas, x_orig+2, correctedY, x_orig+4, correctedY, color);
  CorrectYValues(y_clock+6);
  rgb_matrix::DrawLine(canvas, x_orig+2, correctedY, x_orig+4, correctedY, color);
  CorrectYValues(y_clock+7);
  rgb_matrix::DrawLine(canvas, x_orig+2, correctedY, x_orig+4, correctedY, color);
  CorrectYValues(y_clock+8);
  rgb_matrix::DrawLine(canvas, x_orig+2, correctedY, x_orig+4, correctedY, color);
  CorrectYValues(y_clock+9);
  rgb_matrix::DrawLine(canvas, x_orig+2, correctedY, x_orig+4, correctedY, color);
  CorrectYValues(y_clock+10);
  rgb_matrix::DrawLine(canvas, x_orig+2, correctedY, x_orig+4, correctedY, color);
  CorrectYValues(y_clock+11);
  rgb_matrix::DrawLine(canvas, x_orig+2, correctedY, x_orig+4, correctedY, color);
  CorrectYValues(y_clock+12);
  rgb_matrix::DrawLine(canvas, x_orig+2, correctedY, x_orig+4, correctedY, color);
  
//I
  CorrectYValues(y_clock);
  rgb_matrix::DrawLine(canvas, x_orig+10, correctedY, x_orig+12, correctedY, color);
  CorrectYValues(y_clock+1);
  rgb_matrix::DrawLine(canvas, x_orig+10, correctedY, x_orig+12, correctedY, color);
  CorrectYValues(y_clock+2);
  rgb_matrix::DrawLine(canvas, x_orig+10, correctedY, x_orig+12, correctedY, color);
  CorrectYValues(y_clock+3);
  rgb_matrix::DrawLine(canvas, x_orig+10, correctedY, x_orig+12, correctedY, color);
  CorrectYValues(y_clock+4);
  rgb_matrix::DrawLine(canvas, x_orig+10, correctedY, x_orig+12, correctedY, color);
  CorrectYValues(y_clock+5);
  rgb_matrix::DrawLine(canvas, x_orig+10, correctedY, x_orig+12, correctedY, color);
  CorrectYValues(y_clock+6);
  rgb_matrix::DrawLine(canvas, x_orig+10, correctedY, x_orig+12, correctedY, color);
  CorrectYValues(y_clock+7);
  rgb_matrix::DrawLine(canvas, x_orig+10, correctedY, x_orig+12, correctedY, color);
  CorrectYValues(y_clock+8);
  rgb_matrix::DrawLine(canvas, x_orig+10, correctedY, x_orig+12, correctedY, color);
  CorrectYValues(y_clock+9);
  rgb_matrix::DrawLine(canvas, x_orig+10, correctedY, x_orig+12, correctedY, color);
  CorrectYValues(y_clock+10);
  rgb_matrix::DrawLine(canvas, x_orig+10, correctedY, x_orig+12, correctedY, color);
  CorrectYValues(y_clock+11);
  rgb_matrix::DrawLine(canvas, x_orig+10, correctedY, x_orig+12, correctedY, color);
  CorrectYValues(y_clock+12);
  rgb_matrix::DrawLine(canvas, x_orig+10, correctedY, x_orig+12, correctedY, color);
//M
  CorrectYValues(y_clock);
  rgb_matrix::DrawLine(canvas, x_orig+16, correctedY, x_orig+17, correctedY, color);
  rgb_matrix::DrawLine(canvas, x_orig+21, correctedY, x_orig+22, correctedY, color);
  CorrectYValues(y_clock+1);
  rgb_matrix::DrawLine(canvas, x_orig+20, correctedY, x_orig+22, correctedY, color);
  rgb_matrix::DrawLine(canvas, x_orig+16, correctedY, x_orig+18, correctedY, color);
  CorrectYValues(y_clock+2);
  rgb_matrix::DrawLine(canvas, x_orig+16, correctedY, x_orig+18, correctedY, color);
  rgb_matrix::DrawLine(canvas, x_orig+20, correctedY, x_orig+22, correctedY, color);
  CorrectYValues(y_clock+3);
  rgb_matrix::DrawLine(canvas, x_orig+16, correctedY, x_orig+17, correctedY, color);
  canvas->SetPixel(x_orig+19, correctedY, 255, 255, 255);
  rgb_matrix::DrawLine(canvas, x_orig+21, correctedY, x_orig+22, correctedY, color);
  CorrectYValues(y_clock+4);
  rgb_matrix::DrawLine(canvas, x_orig+16, correctedY, x_orig+17, correctedY, color);
  canvas->SetPixel(x_orig+19, correctedY, 255, 255, 255);
  rgb_matrix::DrawLine(canvas, x_orig+21, correctedY, x_orig+22, correctedY, color);
  CorrectYValues(y_clock+5);
  rgb_matrix::DrawLine(canvas, x_orig+16, correctedY, x_orig+17, correctedY, color);
  rgb_matrix::DrawLine(canvas, x_orig+21, correctedY, x_orig+22, correctedY, color);
  CorrectYValues(y_clock+6);
  rgb_matrix::DrawLine(canvas, x_orig+16, correctedY, x_orig+17, correctedY, color);
  rgb_matrix::DrawLine(canvas, x_orig+21, correctedY, x_orig+22, correctedY, color);
  CorrectYValues(y_clock+7);
  rgb_matrix::DrawLine(canvas, x_orig+16, correctedY, x_orig+17, correctedY, color);
  rgb_matrix::DrawLine(canvas, x_orig+21, correctedY, x_orig+22, correctedY, color);
  CorrectYValues(y_clock+8);
  rgb_matrix::DrawLine(canvas, x_orig+16, correctedY, x_orig+17, correctedY, color);
  rgb_matrix::DrawLine(canvas, x_orig+21, correctedY, x_orig+22, correctedY, color);
  CorrectYValues(y_clock+9);
  rgb_matrix::DrawLine(canvas, x_orig+16, correctedY, x_orig+17, correctedY, color);
  rgb_matrix::DrawLine(canvas, x_orig+21, correctedY, x_orig+22, correctedY, color);
  CorrectYValues(y_clock+10);
  rgb_matrix::DrawLine(canvas, x_orig+16, correctedY, x_orig+17, correctedY, color);
  rgb_matrix::DrawLine(canvas, x_orig+21, correctedY, x_orig+22, correctedY, color);
  CorrectYValues(y_clock+11);
  rgb_matrix::DrawLine(canvas, x_orig+16, correctedY, x_orig+17, correctedY, color);
  rgb_matrix::DrawLine(canvas, x_orig+21, correctedY, x_orig+22, correctedY, color);
  CorrectYValues(y_clock+12);
  rgb_matrix::DrawLine(canvas, x_orig+16, correctedY, x_orig+17, correctedY, color);
  rgb_matrix::DrawLine(canvas, x_orig+21, correctedY, x_orig+22, correctedY, color);
//E  
  CorrectYValues(y_clock);
  rgb_matrix::DrawLine(canvas, x_orig+24, correctedY, x_orig+31, correctedY, color);
  CorrectYValues(y_clock+1);
  rgb_matrix::DrawLine(canvas, x_orig+24, correctedY, x_orig+31, correctedY, color);
  CorrectYValues(y_clock+2);
  rgb_matrix::DrawLine(canvas, x_orig+24, correctedY, x_orig+31, correctedY, color);
  CorrectYValues(y_clock+3);
  rgb_matrix::DrawLine(canvas, x_orig+24, correctedY, x_orig+25, correctedY, color);
  CorrectYValues(y_clock+4);
  rgb_matrix::DrawLine(canvas, x_orig+24, correctedY, x_orig+25, correctedY, color);
  CorrectYValues(y_clock+5);
  rgb_matrix::DrawLine(canvas, x_orig+24, correctedY, x_orig+31, correctedY, color);
  CorrectYValues(y_clock+6);
  rgb_matrix::DrawLine(canvas, x_orig+24, correctedY, x_orig+31, correctedY, color);
  CorrectYValues(y_clock+7);
  rgb_matrix::DrawLine(canvas, x_orig+24, correctedY, x_orig+31, correctedY, color);
  CorrectYValues(y_clock+8);
  rgb_matrix::DrawLine(canvas, x_orig+24, correctedY, x_orig+25, correctedY, color);
  CorrectYValues(y_clock+9);
  rgb_matrix::DrawLine(canvas, x_orig+24, correctedY, x_orig+25, correctedY, color);
  CorrectYValues(y_clock+10);
  rgb_matrix::DrawLine(canvas, x_orig+24, correctedY, x_orig+25, correctedY, color);
  CorrectYValues(y_clock+11);
  rgb_matrix::DrawLine(canvas, x_orig+24, correctedY, x_orig+31, correctedY, color);
  CorrectYValues(y_clock+12);
  rgb_matrix::DrawLine(canvas, x_orig+24, correctedY, x_orig+31, correctedY, color);
    
    ypos = y_clock;
    xpos = 51;
    
    CorrectYValues(ypos);
          rgb_matrix::DrawLine(offscreen, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+1);
          rgb_matrix::DrawLine(offscreen, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+2);
          rgb_matrix::DrawLine(offscreen, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+3);
          rgb_matrix::DrawLine(offscreen, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+4);
          rgb_matrix::DrawLine(offscreen, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+5);
          rgb_matrix::DrawLine(offscreen, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+6);
          rgb_matrix::DrawLine(offscreen, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+7);
          rgb_matrix::DrawLine(offscreen, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+8);
          rgb_matrix::DrawLine(offscreen, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+9);
          rgb_matrix::DrawLine(offscreen, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+10);
          rgb_matrix::DrawLine(offscreen, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+11);
          rgb_matrix::DrawLine(offscreen, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+12);
          rgb_matrix::DrawLine(offscreen, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+13);
          rgb_matrix::DrawLine(offscreen, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+14);
          rgb_matrix::DrawLine(offscreen, 43, correctedY, 79, correctedY, bg_color);
    
    localtime_r(&next_time.tv_sec, &tm);
    
      if(Timer >= 0){
        minutes = std::floor(Timer/60);
        seconds1 = std::floor((Timer-(minutes*60))/10);
        seconds2 = Timer - ((minutes*60)+(seconds1*10));
  }
  if(Timer > 20){
  if(minutes !=0){
  int ArrayStart5;
  int ArrayEnd5;
  ArrayEnd5 = ((minutes*14) + 14);
    for(ArrayStart5 = minutes*14; ArrayStart5 < ArrayEnd5; ArrayStart5++){
      for(e=0; e < 8; e++){
      CorrectYValues(ypos);
        if(Numbers[ArrayStart5] & (1 << e)){
          CorrectYValues(ypos);
          offscreen->SetPixel(xpos+e, correctedY, 255, 165, 0);
          }
        }
      ypos++;
    }
    ypos = y_clock;
  }
    if(Timer >= 60){
    CorrectYValues(ypos+2);
    offscreen->SetPixel(xpos+8, correctedY, 255, 165, 0);
    offscreen->SetPixel(xpos+9, correctedY, 255, 165, 0);
    CorrectYValues(ypos+3);
    offscreen->SetPixel(xpos+8, correctedY, 255, 165, 0);
    offscreen->SetPixel(xpos+9, correctedY, 255, 165, 0);
    CorrectYValues(ypos+11);
    offscreen->SetPixel(xpos+8, correctedY, 255, 165, 0);
    offscreen->SetPixel(xpos+9, correctedY, 255, 165, 0);
    CorrectYValues(ypos+10);
    offscreen->SetPixel(xpos+8, correctedY, 255, 165, 0);
    offscreen->SetPixel(xpos+9, correctedY, 255, 165, 0);
  }
  
  int ArrayStart6;
  int ArrayEnd6;
  ArrayEnd6 = ((seconds1*14)+14);
    for(ArrayStart6 = seconds1*14; ArrayStart6 < ArrayEnd6; ArrayStart6++){
      for(f=0; f < 8; f++){
        int xmod6 = f+11;
        if(Numbers[ArrayStart6] & (1 << f)){
          CorrectYValues(ypos);
          offscreen->SetPixel((xpos+xmod6), correctedY, 255, 165, 0);
          }
      }   
    ypos++;
  }
  
  ypos = y_clock;
  
    int ArrayStart7;
    int ArrayEnd7;
    ArrayEnd7 = ((seconds2*14) + 14);
    for(ArrayStart7 = seconds2*14; ArrayStart7 < ArrayEnd7; ArrayStart7++){
      for(g=0; g < 8; g++){
      int xmod7 = g+19;
        if(Numbers[ArrayStart7] & (1 << g)){
          CorrectYValues(ypos);
          offscreen->SetPixel(xpos+xmod7, correctedY, 255, 165, 0);
          }
        }
      ypos++;
    }
    ypos = y_clock;
  
  
      // Wait until we're ready to show it.
      clock_nanosleep(CLOCK_REALTIME, TIMER_ABSTIME, &next_time, NULL);
      offscreen = canvas->SwapOnVSync(offscreen);
      next_time.tv_sec += 1;
      Timer --;
    } else if(Timer <= 20){
    if(minutes !=0){
    int ArrayStart5;
    int ArrayEnd5;
    ArrayEnd5 = ((minutes*14) + 14);
    for(ArrayStart5 = minutes*14; ArrayStart5 < ArrayEnd5; ArrayStart5++){
      for(e=0; e < 8; e++){
      CorrectYValues(ypos);
        if(Numbers[ArrayStart5] & (1 << e)){
          CorrectYValues(ypos);
          offscreen->SetPixel(xpos+e, correctedY, 255, 0, 0);
          }
        }
      ypos++;
    }
    ypos = y_clock;
  }
  
  int ArrayStart6;
  int ArrayEnd6;
  ArrayEnd6 = ((seconds1*14)+14);
    for(ArrayStart6 = seconds1*14; ArrayStart6 < ArrayEnd6; ArrayStart6++){
      for(f=0; f < 8; f++){
        int xmod6 = f+11;
        if(Numbers[ArrayStart6] & (1 << f)){
          CorrectYValues(ypos);
          offscreen->SetPixel((xpos+xmod6), correctedY, 255, 0, 0);
          }
      }   
    ypos++;
  }
  
  ypos = y_clock;
  
    int ArrayStart7;
    int ArrayEnd7;
    ArrayEnd7 = ((seconds2*14) + 14);
    for(ArrayStart7 = seconds2*14; ArrayStart7 < ArrayEnd7; ArrayStart7++){
      for(g=0; g < 8; g++){
      int xmod7 = g+19;
        if(Numbers[ArrayStart7] & (1 << g)){
          CorrectYValues(ypos);
          offscreen->SetPixel(xpos+xmod7, correctedY, 255, 0, 0);
          }
        }
      ypos++;
    }
    ypos = y_clock;
    // Wait until we're ready to show it.
      clock_nanosleep(CLOCK_REALTIME, TIMER_ABSTIME, &next_time, NULL);
      offscreen = canvas->SwapOnVSync(offscreen);
      next_time.tv_sec += 1;
      Timer --;
    }
    canvas->RequestInputs((1<<19)|(1<<13)|(1<<16)|(1<<20)|(1<<21)|(1<<26));
    if(canvas->AwaitInputChange(0) == (1<<21)){
        Score1 = start_score;
        Score2 = start_score;
        Timer = start_timer;
      }else if (Timer <= 0){
      }else if(canvas->AwaitInputChange(50) == (1<<26)){
      Score1++;
      }else if(canvas->AwaitInputChange(0) == (1<<19)){
        Score1 += 2;
      }else if(canvas->AwaitInputChange(0) == (1<<16)){
        Score1 += 3;
      }else if(canvas->AwaitInputChange(0) == (1<<13)){
        Score1 += 4;
      }else if(canvas->AwaitInputChange(0) == (1<<20)){
        Score1 += 5;
      }
  
        ////score starts col 47
        if(NumberofPlayers == 2){
          ypos= y_orig;
          CorrectYValues(ypos);
          rgb_matrix::DrawLine(canvas, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+1);
          rgb_matrix::DrawLine(canvas, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+2);
          rgb_matrix::DrawLine(canvas, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+3);
          rgb_matrix::DrawLine(canvas, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+4);
          rgb_matrix::DrawLine(canvas, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+5);
          rgb_matrix::DrawLine(canvas, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+6);
          rgb_matrix::DrawLine(canvas, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+7);
          rgb_matrix::DrawLine(canvas, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+8);
          rgb_matrix::DrawLine(canvas, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+9);
          rgb_matrix::DrawLine(canvas, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+10);
          rgb_matrix::DrawLine(canvas, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+11);
          rgb_matrix::DrawLine(canvas, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+12);
          rgb_matrix::DrawLine(canvas, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+13);
          rgb_matrix::DrawLine(canvas, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+14);
          rgb_matrix::DrawLine(canvas, 43, correctedY, 79, correctedY, bg_color);
                
        xpos = 43;
        ypos = y_orig;
        
        if(Score1 >= 0){
         Tens1 = std::floor(Score1/10);
         Remainder1 = Score1 - (Tens1*10);
        }
        
        if(Score2 >= 0){
         Tens2 = std::floor(Score2/10);
         Remainder2 = (Score2 - (Tens2*10));
        }
        
        if(Tens1 !=0){
          int ArrayStart1;
          int ArrayEnd1;
          ArrayEnd1 = ((Tens1*14) + 14);
          for(ArrayStart1 = Tens1*14; ArrayStart1 < ArrayEnd1; ArrayStart1++){
            for(a=0; a < 8; a++){
            CorrectYValues(ypos);
              if(Numbers[ArrayStart1] & (1 << a)){
                CorrectYValues(ypos);
                canvas->SetPixel(xpos+a, correctedY, 0, 255, 0);
                }
              }
            ypos++;
          }
          ypos = y_orig;
        }
        
        
        int ArrayStart2;
        int ArrayEnd2;
        ArrayEnd2 = ((Remainder1*14)+14);
          for(ArrayStart2 = Remainder1*14; ArrayStart2 < ArrayEnd2; ArrayStart2++){
            for(b=0; b < 8; b++){
              int xmod2 = b+8;
              if(Numbers[ArrayStart2] & (1 << b)){
                CorrectYValues(ypos);
                canvas->SetPixel((xpos+xmod2), correctedY, 0, 255, 0);
                }
            }   
          ypos++;
        }
        
        ypos = y_orig;
        
        CorrectYValues(ypos+2);
        canvas->SetPixel(xpos+16, correctedY, 0, 255, 0);
        canvas->SetPixel(xpos+17, correctedY, 0, 255, 0);
        CorrectYValues(ypos+3);
        canvas->SetPixel(xpos+16, correctedY, 0, 255, 0);
        canvas->SetPixel(xpos+17, correctedY, 0, 255, 0);
        CorrectYValues(ypos+11);
        canvas->SetPixel(xpos+16, (correctedY), 0, 255, 0);
        canvas->SetPixel(xpos+17, correctedY, 0, 255, 0);
        CorrectYValues(ypos+10);
        canvas->SetPixel(xpos+16, (correctedY), 0, 255, 0);
        canvas->SetPixel(xpos+17, correctedY, 0, 255, 0);
        
        if(Tens2 !=0){
          int ArrayStart3;
          int ArrayEnd3;
          ArrayEnd3 = ((Tens2*14) + 14);
          for(ArrayStart3 = Tens2*14; ArrayStart3 < ArrayEnd3; ArrayStart3++){
            for(c=0; c < 8; c++){
            int xmod3 = c+19;
              if(Numbers[ArrayStart3] & (1 << c)){
                CorrectYValues(ypos);
                canvas->SetPixel(xpos+xmod3, correctedY, 0, 255, 0);
                }
              }
            ypos++;
          }
          ypos = y_orig;
        }
        
        
        int ArrayStart4;
        int ArrayEnd4;
        ArrayEnd4 = ((Remainder2*14)+14);
          for(ArrayStart4 = Remainder2*14; ArrayStart4 < ArrayEnd4; ArrayStart4++){
            for(d=0; d < 8; d++){
              int xmod4 = d+27;
              if(Numbers[ArrayStart4] & (1 << d)){
                CorrectYValues(ypos);
                canvas->SetPixel((xpos+xmod4), correctedY, 0, 255, 0);
                }
            }   
          ypos++;
        }
        ypos = y_orig;
        
        }
        
        
        if(NumberofPlayers == 1){
          ypos= y_orig;
          CorrectYValues(ypos);
          rgb_matrix::DrawLine(canvas, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+1);
          rgb_matrix::DrawLine(canvas, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+2);
          rgb_matrix::DrawLine(canvas, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+3);
          rgb_matrix::DrawLine(canvas, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+4);
          rgb_matrix::DrawLine(canvas, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+5);
          rgb_matrix::DrawLine(canvas, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+6);
          rgb_matrix::DrawLine(canvas, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+7);
          rgb_matrix::DrawLine(canvas, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+8);
          rgb_matrix::DrawLine(canvas, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+9);
          rgb_matrix::DrawLine(canvas, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+10);
          rgb_matrix::DrawLine(canvas, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+11);
          rgb_matrix::DrawLine(canvas, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+12);
          rgb_matrix::DrawLine(canvas, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+13);
          rgb_matrix::DrawLine(canvas, 43, correctedY, 79, correctedY, bg_color);
          CorrectYValues(ypos+14);
          rgb_matrix::DrawLine(canvas, 43, correctedY, 79, correctedY, bg_color);
                
          xpos = 62;
          ypos = y_orig;
          
          if(Score1 >= 0){
            Tens1 = std::floor(Score1/10);
            Remainder1 = Score1 - (Tens1*10);
          }
        
          if(Tens1 !=0){
            int ArrayStart1;
            int ArrayEnd1;
            ArrayEnd1 = ((Tens1*14) + 14);
           
          for(ArrayStart1 = Tens1*14; ArrayStart1 < ArrayEnd1; ArrayStart1++){
            for(a=0; a < 8; a++){
              CorrectYValues(ypos);
                if(Numbers[ArrayStart1] & (1 << a)){
                  CorrectYValues(ypos);
                  canvas->SetPixel(xpos+a, correctedY, 0, 255, 0);
                }
              }
            ypos++;
          }
          ypos = y_orig;
        }
        
        
        int ArrayStart2;
        int ArrayEnd2;
        ArrayEnd2 = ((Remainder1*14)+14);
          for(ArrayStart2 = Remainder1*14; ArrayStart2 < ArrayEnd2; ArrayStart2++){
            for(b=0; b < 8; b++){
              int xmod2 = b+8;
        
              if(Numbers[ArrayStart2] & (1 << b)){
                CorrectYValues(ypos);
                canvas->SetPixel((xpos+xmod2), correctedY, 0, 255, 0);
                }
            }   
          ypos++;
        }
        ypos = y_orig;
        }

  
      
  }
  
  // Finished. Shut down the RGB matrix.

  delete canvas;


  return 0;
}

  

