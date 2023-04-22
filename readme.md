# Código de Temperaturas
Este repositorio contiene un programa en lenguaje C para cargar y filtrar temperaturas. Se trata de un programa de consola que permite cargar las temperaturas de 90 días y luego mostrarlas según su rango.

## Requerimientos
Para compilar y ejecutar este programa se requiere tener instalado un compilador de C como GCC. O puedes abrir directamente el .exe incluído en la compilación.

## Uso
El programa muestra un menú con diferentes opciones:

- Cargar las temperaturas.
- Filtrar las temperaturas en pilas.
- Mostrar las temperaturas.
- Mostrar las temperaturas menores a una temperatura especificada por el usuario.
- Para seleccionar una opción, ingrese el número correspondiente y presione Enter.

### Opciones
- Opción 1: Cargar las temperaturas
Esta opción permite cargar las temperaturas de 90 días. El usuario debe ingresar una temperatura para cada día. La temperatura debe estar en el rango de -10 a 40 grados Celsius. Si el usuario ingresa una temperatura fuera de ese rango, se le pedirá que ingrese otra temperatura válida.

- Opción 2: Filtrar las temperaturas en pilas
Esta opción filtra las temperaturas cargadas en la opción 1 en tres pilas distintas según su rango de temperatura. Las pilas se clasifican en menores a 10 grados Celsius, entre 10 y 20 grados Celsius y mayores a 20 grados Celsius.

- Opción 3: Mostrar las temperaturas
Esta opción muestra las temperaturas cargadas en la opción 1 según su rango de temperatura. Las temperaturas se muestran en tres columnas, cada una con su rango de temperatura correspondiente.

- Opción 4: Mostrar las temperaturas menores a una temperatura especificada por el usuario
Esta opción muestra las temperaturas cargadas en la opción 1 que son menores a una temperatura especificada por el usuario. El usuario debe ingresar la temperatura límite. Las temperaturas se muestran en orden descendente.

Después de seleccionar una opción, el programa preguntará si desea continuar con el menú. Si el usuario ingresa 's', el menú se mostrará de nuevo. Si el usuario ingresa 'n', el programa terminará.

