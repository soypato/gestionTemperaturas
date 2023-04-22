#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
int ingresarTemperaturas(float arrayTemperaturas[], int validos);
int validarTemperaturas(int temperatura);
void deArrayAPila(float arregloDeTemperaturas[], int validos, Pila *menoresA10, Pila *entre10y20, Pila *mayoresA20);
void mostrarTemperaturasDePila(Pila pila1, Pila pila2, Pila pila3);
void menoresAUnEspecifico(float arrayDeTemperaturas[], int validos, float minimo);
float calcularPorcentaje(float primerValor, float SegundoValor);
void resultadosObtenidosDelPorcentaje(int contador, int i);

int main()
{
    float temperaturasNoventaDias[90];
    int validosTemperaturas;
    int op = 0;
    char decision = 's';
    float minimoPorElUsuario = 0;

    Pila menoresA10, entre10y20, mayoresA20;
    inicpila(&menoresA10);
    inicpila(&entre10y20);
    inicpila(&mayoresA20);
    do
    {
        printf("-------------------\n");
        printf("Menu del sistema:\n");
        printf("-------------------\n");
        printf("1- Cargar las temperaturas\n");
        printf("2- Filtrar en pilas las temperaturas\n");
        printf("3- Mostrar temperaturas\n");
        printf("4- Mostrar menores a una temperatura\n");
        printf("-------------------\n");
        printf("Tu decision: ");
        fflush(stdin);
        scanf("%i", &op);

        switch(op)
        {
        case 1:
            validosTemperaturas = ingresarTemperaturas(temperaturasNoventaDias, 90);
            printf("%i", validosTemperaturas);
            printf("-----------------------\n");
            break;

        case 2:
            deArrayAPila(temperaturasNoventaDias, validosTemperaturas, &menoresA10, &entre10y20, &mayoresA20);
            printf("\nMenores a 10:\n");
            mostrar(&menoresA10);
            printf("\nEntre 10 y 20:\n");
            mostrar(&entre10y20);
            printf("\nMayores a 20:\n");
            mostrar(&mayoresA20);
            break;
        case 3:
            mostrarTemperaturasDePila(menoresA10, entre10y20, mayoresA20);
            break;
        case 4:
            printf("Ingresa el limite de temperaturas a filtrar: (por ej: 25 ira del -10 al 25):  ");
            scanf("%f", &minimoPorElUsuario);
            menoresAUnEspecifico(temperaturasNoventaDias, validosTemperaturas, minimoPorElUsuario);
        }
        printf("\nQuieres seguir ejecutando el menu (s/n)?: ");
        fflush(stdin);
        scanf("%c", &decision);
    }
    while(decision != 'n');
}

int ingresarTemperaturas(float arrayTemperaturas[], int validos)
{
    char continuacion = 's';
    float temperatura;
    int validacionTemperatura = 0;

    int i = 0;
    for(i; i < validos; i++)
    {
        printf("Ingresa la temperatura del dia %i (entre -10 y 40): ", i+1);
        scanf("%f", &temperatura);

        while(validacionTemperatura == 0)
        {
            {
                validacionTemperatura = validarTemperaturas(temperatura);
                if(validacionTemperatura == 0)
                {
                    printf("\n[ERROR] La temperatura debe ser entre -10 y 40\n");
                    printf("Ingresa la temperatura del dia %i (entre -10 y 40): ", i+1);
                    scanf("%f", &temperatura);
                }
            }
        }
        arrayTemperaturas[i] = temperatura;
        temperatura = 0; // para limpiar el dato para la siguiente iteración
        validacionTemperatura = 0; // resetear validación para el siguiente ciclo
    }

    return i; // retornar validos
}

int validarTemperaturas(int temperatura)
{
    int tempValida = 0;
    if(temperatura >= -10 && temperatura <= 40)
    {
        tempValida = 1;
    }
    else
    {
        tempValida = 0;
    }
    return tempValida;
}

void deArrayAPila(float arregloDeTemperaturas[], int validos, Pila *menoresA10, Pila *entre10y20, Pila *mayoresA20)
{
    Pila auxiliar1;
    inicpila(&auxiliar1);
    for(int i = 0; i < validos; i++)
    {
        if(arregloDeTemperaturas[i] >= -10 && arregloDeTemperaturas[i] < 10)
        {
            apilar(menoresA10, arregloDeTemperaturas[i]);

        }
        else if(arregloDeTemperaturas[i] >= 10 && arregloDeTemperaturas[i] <= 20)
        {
            apilar(entre10y20, arregloDeTemperaturas[i]);
        }
        else
        {
            apilar(mayoresA20, arregloDeTemperaturas[i]);
        }
    }
}

void mostrarTemperaturasDePila(Pila pila1, Pila pila2, Pila pila3)
{
    while(!pilavacia(&pila1))
    {
        int topecito = tope(&pila1);
        printf("Temperatura: %i grados celcius\n", topecito);
        desapilar(&pila1);
    }
    while(!pilavacia(&pila2))
    {
        int topecito = tope(&pila2);
        printf("Temperatura: %i grados celcius\n", topecito);
        desapilar(&pila2);
    }
    while(!pilavacia(&pila3))
    {
        int topecito = tope(&pila3);
        printf("Temperatura: %i grados celcius\n", topecito);
        desapilar(&pila3);
    }
}

void menoresAUnEspecifico(float arrayDeTemperaturas[], int validos, float minimo)
{
    int arrayDeMinimos[validos];
    int contador = 0;
    int i = 0;
    for(i; i < validos; i++)
    {
        if(arrayDeTemperaturas[i] < minimo)
        {
            arrayDeMinimos[i] = arrayDeTemperaturas[i];
            printf("Filtrado el %i\n", arrayDeMinimos[i]);
            contador++;
        }
    }
    resultadosObtenidosDelPorcentaje(contador, i);
}

float calcularPorcentaje(float primerValor, float segundoValor)
{
    return primerValor * 100.0 / segundoValor;
}

void resultadosObtenidosDelPorcentaje(int contador, int i)
{
    float porcentaje = 0;
    porcentaje = calcularPorcentaje(contador, i);
    printf("Se han filtrado el %g%% de las temperaturas\n", porcentaje);
}
