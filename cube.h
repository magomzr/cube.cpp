#if !defined(CUBE_H)
#define CUBE_H

float A, B, C;  // Rotation angles in the axes x(A), y(B), z(Z).
float x, y, z;  // Three-dimensional vector for each axis.
float ooz;      // Inverse of the z-coordinate for perspective.
int xp, yp;     // Coordinates on the screen where each projected point is drawn. They are determined by the position of the point in three-dimensional space, the inverse of the z-coordinate (ooz), and the scale factor K1.
int idx_buffer; // Index for the buffer and z-buffer corresponding to the position on the screen where a point is to be drawn. It is calculated from the xp and yp coordinates.

// Constants
const int WIDTH = 75, HEIGHT = 30;      // Screen dimensions.
const int AREA = WIDTH * HEIGHT;        // Screen area.
const int SLEEP_TIME = 1000;            // Display speed.
const int DISTANCE_FROM_CAM = 50;       // Distance from the camera to the cube.
const float CUBE_WIDTH = 7;             // Cube width.
const float INCREMENT_SPEED = 0.5;      // Increment in cube coordinates.
const float INCREMENT_ANGLE = 0.005;    // Angle increase.
const float K1 = 40;                    // Scale factor to adjust the screen position of the points according to their z-coordinate. Changing this value will affect the scale and position of the projected points on the screen.
const char BACKGROUND_ASCII_CODE = ' '; // Character for the background of the screen.

// Buffers
char buffer[AREA];    // Representation of the screen in characters.
float z_buffer[AREA]; // Z-buffering (depth buffer). Depth values for each position in the buffer.

float calculateZ(int i, int j, int k);
float calculateX(int i, int j, int k);
float calculateY(int i, int j, int k);

/// @brief Performs the calculation of the projected coordinates of a point on the cube, considering rotation and perspective. It then updates a z-buffer and a character buffer to graphically represent the point on the screen. These calculations and updates are essential for the generation of the three-dimensional animation of the cube.
void calculateForSurface(float cube_x, float cube_y, float cube_z, int ch);

#endif // CUBE_H
