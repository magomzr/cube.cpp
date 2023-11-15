#include <iostream>
#include <cstring>
#include <cmath>
#include <unistd.h>

using namespace std;

// This represents the rotation of the axes θx, θy, θz.
double A, B, C;

// Vectors
double x, y, z;
double ooz;     // ??????????????
double K1 = 40; // ??????????????
int xp, yp;     // ??????????????
int idx;        // ??????????????

// Dimensions
const int WIDTH = 75, HEIGHT = 30;
const double increment_speed = 0.5;
const int distanceFromCam = 50;

// Cube width
double cube_width = 10;

// Z-buffering
double z_buffer[WIDTH * HEIGHT];

// Buffer of characters?
char buffer[WIDTH * HEIGHT];

// Background ASCII code
const char background_ASCII_code = ' ';

// Calculate vectors of rotation matrices for each axis.
double calculateX(int i, int j, int k)
{
  return j * sin(A) * sin(B) * cos(C) - k * cos(A) * sin(B) * cos(C) +
         j * cos(A) * sin(C) + k * sin(A) * sin(C) + i * cos(B) * cos(C);
}

double calculateY(int i, int j, int k)
{
  return j * cos(A) * cos(C) + k * sin(A) * cos(C) -
         j * sin(A) * sin(B) * sin(C) + k * cos(A) * sin(B) * sin(C) -
         i * cos(B) * sin(C);
}

double calculateZ(int i, int j, int k)
{
  return k * cos(A) * cos(B) - j * sin(A) * cos(B) + i * sin(B);
}

void *calculateForSurface(double cube_x, double cube_y, double cube_z, int ch)
{
  x = calculateX(cube_x, cube_y, cube_z);
  y = calculateY(cube_x, cube_y, cube_z);
  z = calculateZ(cube_x, cube_y, cube_z) + distanceFromCam;

  ooz = 1 / z;
  xp = (int)(WIDTH / 2 + K1 * ooz * x * 2);
  yp = (int)(HEIGHT / 2 + K1 * ooz * y);

  idx = xp + yp * WIDTH;
  if (idx >= 0 && idx < WIDTH * HEIGHT)
  {
    if (ooz > z_buffer[idx])
    {
      z_buffer[idx] = ooz;
      buffer[idx] = ch;
    }
  }
}

int main(int argc, char const *argv[])
{
  // Cleaning screen like C
  printf("\x1b[2J");

  // Infinite loop
  while (1)
  {
    // Copying ASCII code into buffer. Size is WIDTH * HEIGHT
    memset(buffer, background_ASCII_code, WIDTH * HEIGHT);

    // [?] What is this? 4 depth levels?
    memset(z_buffer, 0, WIDTH * HEIGHT * 4);

    // Looping through X
    for (double cube_x = -cube_width; cube_x < cube_width; cube_x += increment_speed)
    {
      // Looping through Y
      for (double cube_y = -cube_width; cube_y < cube_width; cube_y += increment_speed)
      {
        calculateForSurface(cube_x, cube_y, -cube_width, '.');
      }
    }
    printf("\x1b[H");
    for (int k = 0; k < WIDTH * HEIGHT; k++)
    {
      cout << ((k % WIDTH) ? buffer[k] : '\n');
      // putchar(k % WIDTH ? buffer[k] : 10);
    }
    A += 0.005;
    B += 0.005;
    usleep(1000);
  }
  return 0;
}
