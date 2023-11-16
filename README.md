# <p style="text-align: center;">Spinning Cube in C++</p>

Este código escrito en C++ se basa en el repositorio de [Servet Gulnaroglu](https://github.com/servetgulnaroglu) de [cube.c](https://github.com/servetgulnaroglu/cube.c) desarrollado en C.

## Fundamentos

El fundamento matemático detrás de este proceso es el concepto de [matriz de rotación](https://en.wikipedia.org/wiki/Rotation_matrix) en un espacio euclídeo.

Las siguientes matrices de rotación realizan rotaciones de vectores alrededor de los ejes x, y, o z, en el espacio de tres dimensiones:

$$
Rx(θ) = \left(\begin{array}{cc}
1 & 0 & 0\\
0 & cos(θ) & -sin(θ)\\
0 & sin(θ) & cos(θ)
\end{array}\right)
$$

$$
Ry(θ) = \left(\begin{array}{cc}
cos(θ) & 0 & sin(θ)\\
0 & 1 & 0\\
-sin(θ) & 0 & cos(θ)
\end{array}\right)
$$

$$
Rz(θ) = \left(\begin{array}{cc}
cos(θ) & -sin(θ) & 0\\
sin(θ) & cos(θ) & 0\\
0 & 0 & 1
\end{array}\right)
$$

Teniendo en cuenta un operador

$$
\left(\begin{array}{cc}
i & j & k
\end{array}\right)
$$

es posible calcular los vectores para cada eje utilizando la multiplicación de matrices:

$$
x = j * sin(A) * sin(B) * cos(C) - k * cos(A) * sin(B) * cos(C) + \\
j * cos(A) * sin(C) + k * sin(A) * sin(C) + i * cos(B) * cos(C)
$$

$$
y = j * cos(A) * cos(C) + k * sin(A) * cos(C) - \\ j * sin(A) * sin(B) * sin(C) + \\ k * cos(A) * sin(B) * sin(C) - \\ i * cos(B) * sin(C)
$$

$$
z = k * cos(A) * cos(B) - j * sin(A) * cos(B) + i * sin(B)
$$

### Buffer

Un buffer es simplemente un área de memoria que almacena datos temporales. En este contexto, se utiliza para almacenar la representación visual de la escena que se va a mostrar en la pantalla.

Aquí, `buffer` es un array que representa la pantalla. Cada elemento de este array contiene un carácter que se imprimirá en la pantalla. Durante el proceso de renderización, este buffer se llena con los caracteres que representan la escena 3D antes de imprimirse en la pantalla.

### Z-buffer (depth buffer)

El z-buffer es un concepto relacionado y se utiliza para manejar la ocultación de superficies. En entornos 3D, varios objetos pueden estar en la misma posición en la pantalla, pero en diferentes profundidades. El z-buffer almacena la distancia (o profundidad) de cada píxel en el espacio tridimensional.

En este repositorio, `z_buffer` es un array que almacena los valores de profundidad para cada posición en el buffer. Antes de dibujar un punto en la pantalla, se verifica el valor de ooz (inverso de z) y se compara con el valor existente en el z-buffer para determinar si el punto es visible en función de su distancia a la cámara.

### OOZ (One over Z)

Esta variable representa el inverso de la coordenada Z (1/z). Se utiliza para calcular la posición en la pantalla de un punto en el espacio tridimensional con base en la perspectiva. Al multiplicar las coordenadas `x` e `y` por `ooz`, se ajusta la posición del punto en función de su distancia desde la cámara. Su propósito principal es ajustar las coordenadas proyectadas en la pantalla teniendo en cuenta la perspectiva.

## memset() - C Library Function

#### `void *memset ( void *s, int c, size_t n);`

La función memset copia el valor de c (convertido a un unsigned char) a cada uno de los primeros n caracteres en el objeto al cual señala s. La función memset devuelve el valor de s.

`memset(buffer, background_ASCII_code, WIDTH * HEIGHT);`

Links: https://www.geeksforgeeks.org/memset-in-cpp/

## TODO:

1. Replacing memset() with std::fill();
