#include <stdio.h>
#include <ctype.h> 
#include <string.h>
#include<stdlib.h>


/*********************************************************/
/*            Declaraciones de las funciones             */
/*********************************************************/

/* Funciones de test */
void testVolverMayuscula(void);
void testEsLetra(void);
void testStringToMayuscula(void);
void runProgram(void);

/* Funciones del programa */
int esLetra(char ch);
void volverMayuscula(char *ch);
void stringToMayuscula(char *s);


/*********************************************************/
/*                     Funcion main                      */
/*********************************************************/


int main(void) {

  runProgram();
  //testVolverMayuscula();
  //testEsLetra();
  //testStringToMayuscula();
  return 0;
}

/*********************************************************/
/*            Declaraciones de las funciones             */
/*********************************************************/

/* Funciones de test */

void runProgram(){
  char s[256];
  printf("%s", "Ingrese entrada: ");
  scanf("%s",s);
  stringToMayuscula(s);
  printf("%s \n",s);
}

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
    if ( ((ch>=0x41)&&(ch<=0x5A)) ||  //mayuscula
        ((ch>=0x61)&&(ch<=0x7A))) { //minuscula
     
            return 1;
    }else{
        return 0;
    }
            
}

/**  
 *   @brief  Convierte un caracter en mayuscula
 *  
 *   @param  ch es el caracter ingresado
 *   @return void
 */
void volverMayuscula(char *ch) {
  // Coloque el codigo solucion a continuacion...
    //printf("%c",ch);
    *ch = *ch - 32;
    printf("%c%s\n",*ch, " probando");
   
}


/**  
 *   @brief  Convierte en mayusculas la cadena de caracteres ingresada.
 *  
 *   @param  s es una cadena de caracteres ingresada y la cual despues del proceso en la función tendra los caracteres en mayuscula.
 *   @return void
 */

void stringToMayuscula(char *s) {

  for (int i = 0; s[i]!='\0'; i++)
  {
    char car = *(s+i);
   
    int isLetter = esLetra(car);
    if (isLetter == 1){
      volverMayuscula(&car);
    }  

  }


}