#include <stdio.h>
#include "main.h"

#define N 10

long buffer[N];
int inicio = 0;
int fin = 0;

void interrupcion(int scancode)
{
    int siguiente = (fin + 1) % N;
    if (siguiente != inicio)
    {
        buffer[fin] = scancode;
        fin = siguiente;
    }
    else
    {
        printf("La cola está llena.\n");
    }
}

char getCaracter(int code)
{
    // Lógica para convertir el código en el carácter correspondiente
    // Aquí se debe implementar la lógica real que mapea el scancode a un carácter
    // En este ejemplo, se utilizará un mapeo simple para los códigos 33, 44, 4B y 1C
    if (code == 33)
        return 'h';
    else if (code == 44)
        return 'o';
    else if (code == 0x4B)
        return 'l';
    else if (code == 0x1C)
        return 'a';
    else
        return ' ';
}

void procesamiento()
{
    while (inicio != fin)
    {
        int code = buffer[inicio];
        char caracter = getCaracter(code);
        printf("%c", caracter);
        inicio = (inicio + 1) % N;
    }
}

int main()
{
    interrupcion(33);
    interrupcion(44);
    interrupcion(0x4B);
    interrupcion(0x1C);

    procesamiento();

    return 0;
}
