#if !defined(CUBE_H)
#define CUBE_H

float A, B, C;  // Ángulos de rotación en los ejes x(A), y(B), z(Z).
float x, y, z;  // Vector tridimensional para cada eje.
float ooz;      // Inverso de la coordenada z para perspectiva.
int xp, yp;     // Coordenadas en la pantalla donde se dibuja cada punto proyectado. Están determinadas por la posición del punto en el espacio tridimensional, la inversa de la coordenada z (ooz), y el factor de escala K1.
int idx_buffer; // Índice para el buffer y z-buffer que corresponde a la posición en la pantalla donde se va a dibujar un punto. Se calcula a partir de las coordenadas xp y yp.

// Constants
const int WIDTH = 75, HEIGHT = 30;      // Dimensiones de la pantalla.
const int AREA = WIDTH * HEIGHT;        // Área de la pantalla.
const int SLEEP_TIME = 1000;            // Velocidad de visualización.
const int DISTANCE_FROM_CAM = 50;       // Distancia desde la cámara al cubo.
const float CUBE_WIDTH = 5;             // Ancho del cubo.
const float INCREMENT_SPEED = 0.5;      // Incremento en las coordenadas del cubo.
const float INCREMENT_ANGLE = 0.005;    // Incremento en el ángulo.
const float K1 = 40;                    // Factor de escala para ajustar la posición en pantalla de los puntos en función de su coordenada z. Modificar este valor afectará la escala y la posición de los puntos proyectados en la pantalla.
const char BACKGROUND_ASCII_CODE = ' '; // Caracter para el fondo de la pantalla.

// Buffers
char buffer[AREA];    // Representación de la pantalla en caracteres.
float z_buffer[AREA]; // Z-buffering (depth buffer). Valores de profundidad para cada posición en el buffer.

float calculateZ(int i, int j, int k);
float calculateX(int i, int j, int k);
float calculateY(int i, int j, int k);

/// @brief Realiza el cálculo de las coordenadas proyectadas de un punto en el cubo, considerando la rotación y la perspectiva. Luego, actualiza un z-buffer y un buffer de caracteres para representar gráficamente el punto en la pantalla. Estos cálculos y actualizaciones son fundamentales para la generación de la animación tridimensional del cubo.
void calculateForSurface(float cube_x, float cube_y, float cube_z, int ch);

#endif // CUBE_H
