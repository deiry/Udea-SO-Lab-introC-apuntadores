# Laboratorio de vectores y apuntadores

> **Objetivos**
> * Introducir el concepto de apuntador, su uso e importancia en la realizacion de programas en C.
> * Comprender la relación que se establece entre apuntadores, variables y memoria.
> * Entender el uso de vectores en C.
> * Relacionar y aplicar los conceptos: vectores, apuntadores y funciones para el desarrollo de problemas de programacion.

## 5. Ejercicios de programación.

Para cada uno de los ejercicio de programacion propuestos a continuacion, realice la respectiva funcion de test para probar el correcto funcionamiento de lo que se pide en el ejercicio.

P1. **Problema de programación**: Hacer que barra una cadena de caracteres en busca de un caracter especifico. La funcion deberá retornar el numero de veces que aparece este caracter o -1 en caso de que no este. La forma de la funcion se muestra a continuación:

```C
/**
 *   @brief  Cuenta las veces que aparece un caracter determinado dentro de una cadena.
 *
 *   @param  array cadena de caracteres a ingresar
 *   @param  ch es el caracter a averiguar
 *   @return el numero de veces que aparece ch en array o -1 si no aparece.
 */
int contarCaracter(char *array, char ch) {
  // Coloque su codigo aqui...
}
```

P2. **Problema de programación**: Hacer una funcion que permita que un usuario obtenga el subindice asociado a la primera aparicion de un caracter en un array. Si el caracter no esta la función debera retornar -1. Haga uso de la funcion del punto 1 para validar la presencia del caracter. A continuacion se muestra la forma de la función:

```C
/**
 *   @brief  Obtiene el indice de la primera aparicion de un caracter en un array
 *
 *   @param  array cadena de caracteres a ingresar
 *   @param  ch es el caracter a ingresa
 *   @return el indice del primer ch en la cadena array
 */
int obtenerIndice(char *array, char ch) {
  // Coloque su codigo aqui...
}
```

Para clarificar un poco la cosa, si por ejemplo la cadena es **hola: que mas** y el caracter a buscar es **:** la funcion debera retornar **4**. Por otro lado, si el caracter a buscar es la **a**, la funcion retornara **3**. Finalmente, si el caracter ingresado es **z** la funcion retornara **-1**.

P3. **Problema de programación**: Obtener la subcadena de una cadena dada a partir de un subindice siguiendo la siguiente funcion.

```C
/**
 *   @brief  Obtiene una subcadena a tomada a partir de un subindice asociado a una subcadena
 *
 *   @param  array cadena de caracteres a ingresar
 *   @param  index indice
 *   @return un apuntador a la posicion inicial de la subcadena o NULL si el tamaño de index supera a la longitud de la cadena
 */
char *obtenerSubcadena(char *array, int index) {
  // Coloque su codigo aqui...
}
```
Para averiguar la longitud de la cadena puede emplar la funcion **strlen** de la libreria **string.h**. Por ejemplo, para el caso, si la cadena es **hola que tal** y el indice ingresado por el usuario es **4**, la funcion debera retornar un apuntador que apunte a la posicion **5** de la cadena, de modo que cuando se imprima la cadena en cuestion a partir de este apuntado se muestre la siguiente salida **que tal**. En el siguiente ejemplo se aterriza lo anterior suponiendo que ya se codifico la funcion subcadena.

```C
char *p1 = "Hola que tal";
char *p2;
p2 = obtenerSubcadena(p1, 5);
printf("%s\n",p1);    // Imprime: Hola que tal
printf("%s\n",p2);    // Imprime: que tal
```

P4. **Analisis de codigo**: Dado el siguiente codigo fuente tomado del siguiente [enlace](https://en.wikibooks.org/wiki/C_Programming/stdio.h/getchar)

```C
#include <stdio.h>

// Codigo tomado de: https://en.wikibooks.org/wiki/C_Programming/stdio.h/getchar

 int main(void)
 {
   char str[1000];
   int ch, n = 0;
   while ((ch = getchar()) != EOF && n < 1000) {
      str[n] = ch;
      ++n;
   }   
   for (int i = 0; i < n; ++i)
      putchar(str[i]);

   putchar('\n');
   return 0;
 }
```

Guardelo como punto4.c y compilelo como punto4.out:

```
gcc -Wall punto4.c -o punto4.out
```

Luego corralo:

```
./punto4.out
```

**Nota**: Cuando un programa en C corre infinitamente presione la combinacion ```Ctrl + D``` (que envia una notificación de EOF) o la combinacin ```Ctrl + C``` (que permite la terminación del programa que se esta ejecutando actualmente) para culminar su ejecución.

Responda las siguientes preguntas:
1. ¿Que hace el programa anterior?
2. Describa las funciones ```getchar``` y ```putchar```
3. ¿Cuales son las condiciones necesarias para que el primer ciclo deje de ejecutarse?

P5. **Problema de programación**: Codifique un programa que permita convertir en mayuscula una cadena de caracteres ingresada por teclado y solo terminara su ejecución cuando el usuario emplee la combinación de teclas . Por ejemplo si la entrada del programa es:

```
1234abcdABCD!
```

La salida debera ser:

```
1234ABCDABCD!
```

La implementación del programa deberá ser hecha de manera modular, de modo que el objetivo realice las siguientes tareas de manera gradual tal y como se muestra a continuación:

* **Fase 1 - Codificando las funciones**: dado el siguiente código (c1_parte1.c) completelo complete las funciones es que complete la siguiente el inicialmente el siguiente codigo y lo compile. Si todo esta bien, puede continuar con la **fase 2**; sino, corrija los errores hasta que compile.

```C
#include <stdio.h>


/*********************************************************/
/*            Declaraciones de las funciones             */
/*********************************************************/

/* Funciones de test */
void testVolverMayuscula(void);
void testEsLetra(void);
void testStringToMayuscula(void);

/* Funciones del programa */
int esLetra(char ch);
void volverMayuscula(char *ch);
void stringToMayuscula(char s[]);


/*********************************************************/
/*                     Funcion main                      */
/*********************************************************/


int main(void) {
  testVolverMayuscula();
  testEsLetra();
  testStringToMayuscula();
  return 0;
}

/*********************************************************/
/*            Declaraciones de las funciones             */
/*********************************************************/

#include <stdio.h>

/* Funciones del programa */
int esLetra(char ch);
void volverMayuscula(char *ch);
void stringToMayuscula(char s[]);

/*********************************************************/
/*             Definiciones de las funciones             */
/*********************************************************/

/* Funciones del programa */

/**  
 *   @brief  Determina si un caracter alfabetico
 *  
 *   @param  ch es el caracter a verificar
 *   @return 1 si el caracter es una letra del alfabeto y 0 si es otro simbolo.
 */
int esLetra(char ch) {
  // Coloque el codigo solucion a continuacion...

}

/**  
 *   @brief  Convierte un caracter en mayuscula
 *  
 *   @param  ch es el caracter ingresado
 *   @return void
 */
void volverMayuscula(char *ch) {
  // Coloque el codigo solucion a continuacion...

}


/**  
 *   @brief  Convierte en mayusculas la cadena de caracteres ingresada.
 *  
 *   @param  s es una cadena de caracteres ingresada y la cual despues del proceso en la función tendra los caracteres en mayuscula.
 *   @return void
 */

void stringToMayuscula(char s[]) {
  // Coloque el codigo solucion a continuacion...

}
```

* **Fase 2 - Testeando las funciones**: Una vez las funciones estan codificadas, verifique que implementen correctamente la logica. Para ello agregue al codigo anterior las siguientes funciones de test, e invoquelas en el main como se muestra a continuacion:

```C
#include <stdio.h>


/*********************************************************/
/*            Declaraciones de las funciones             */
/*********************************************************/

/* Funciones de test */
void testVolverMayuscula(void);
void testEsLetra(void);
void testStringToMayuscula(void);

/* Funciones del programa */
int esLetra(char ch);
void volverMayuscula(char *ch);
void stringToMayuscula(char s[]);


/*********************************************************/
/*                     Funcion main                      */
/*********************************************************/


int main(void) {
  testVolverMayuscula();
  testEsLetra();
  testStringToMayuscula();
  return 0;
}

/*********************************************************/
/*             Definiciones de las funciones             */
/*********************************************************/

/* Funciones de test */

/**  
 *   @brief  Funcion para testear volverMayuscula
 *  
 *   @param  void
 *   @return void
 */
void testVolverMayuscula(void) {
  char *p_char;
  char l1 = 'a', l2 = 'z';
  p_char = &l2;
  printf("Minusculas -> %c, %c\n", l1, l2);
  volverMayuscula(&l1);
  volverMayuscula(p_char);
  printf("Mayusculas -> %c, %c\n", l1, *p_char);
}

/**  
 *   @brief  Funcion para testear esLetra
 *  
 *   @param  void
 *   @return void
 */
void testEsLetra(void) {
  char c1 = '!', c2 = 's';
  printf("%c -> %d\n", c1, esLetra(c1));
  printf("%c -> %d\n", c2, esLetra(c2));
}

void testStringToMayuscula(void) {
  char s1[] = "hola que mas!!!\n";
  char s2[] = "1234 e_-+!!hay";
  printf("Cadenas en minuscula -> \n");
  printf("cadena 1: %s\n", s1);
  printf("cadena 2: %s\n", s2);
  stringToMayuscula(s1);
  stringToMayuscula(s2);
  printf("\nCadenas en mayuscula -> \n");
  printf("cadena 1: %s\n", s1);
  printf("cadena 2: %s\n", s2);
}

/* Funciones del programa */

/* Codigo ya implementado en la fase 1...*/
```
Compile y ejecute en esta ocación. Si todo esta bien, la salida será como la mostrada a continuación:

```
Minusculas -> a, z
Mayusculas -> A, Z
! -> 0
s -> 1
Cadenas en minuscula ->
cadena 1: hola que mas!!!

cadena 2: 1234 e_-+!!hay

Cadenas en mayuscula ->
cadena 1: HOLA QUE MAS!!!

cadena 2: 1234 E_-+!!HAY
```

* **Fase 3 - Implementacin del código definitivo (el que interactua con el usuario)**: una vez con la certeza de que la funciones trabajan correctamente implemente un programa que permita la interacción con el usuario de modo que cuando este precione la combinación ```Ctrl + D``` o ```Ctrl + C``` el programa se salga. Por ejemplo una salida tipica puede ser como la mostrada a continuacin:

```
Entrada > hola
HOLA
Entrada > nuen
NUEN
Entrada > s
S
Entrada > casi 12345
CASI 12345
Entrada > sisaz
SISAZ
Entrada > ^C
```
P6. **Problema de programación**: Dado un vector x de n elementos reales, donde n es impar, diseñar una función que calcule y devuelva la mediana de ese vector. La mediana es el valor tal que la mitad de los números son mayores que el valor y la otra mitad son menores. Escribir un programa que compruebe la función.

P7. **Problema de programación**: Se trata de resolver el siguiente problema escolar. Dadas las notas de los alumnos de un colegio en el primer curso de bachillerato, en las diferentes asignaturas (5, por comodidad), se trata de calcular la media de cada alumno, la media de cada asignatura, la media total de la clase y ordenar los alumnos por orden decreciente de notas medias individuales.

**Nota**: utilizar como algoritmo de ordenación el método Shell.

**Recomendaciones**:
Para los dos ultimos problemas se sugiere revisar el capitulo de muestra de Algoritmos de ordenacion y busqueda del libro de Joyanes Aguilar el cual puede ser descargado del siguiente [enlace](material_apoyo/joyanes_c_java_y_uml_capitulo_muestra.pdf)

## Enlaces de utilidad
* http://csweb.cs.wfu.edu/~fulp/CSC112/codeStyle.html
* https://overiq.com/c-programming/101/the-malloc-function-in-c/
* https://www.geeksforgeeks.org/void-pointer-c/
