
/**Hacer que barra una cadena de caracteres en busca de un caracter especifico. 
*La funcion deberá retornar el numero de veces que aparece este caracter o -1 en caso de que no este. 
*La forma de la funcion se muestra a continuación:*/

#include<stdlib.h>
#include<stdio.h>


int contarCaracter(char *array, char ch);
void test(void);

int main() {
  test();
  return 0;
}
void test(void) {
  char cad[] = "cadena";
  int v = contarCaracter(cad,'a');
  printf("%s : %d\n", cad, v);
 
}

/**
 *   @brief  Cuenta las veces que aparece un caracter determinado dentro de una cadena.
 *   @param  array cadena de caracteres a ingresar
 *   @param  ch es el caracter a averiguar
 *   @return el numero de veces que aparece ch en array o -1 si no aparece.
 */
int contarCaracter(char *array, char ch) {
    int cont = 0;
    while (*array != '\0'){
        if(ch == *array) {
           cont++;
        }
    
        array++;
    }
    if(cont==0){
        cont = -1;
    }

    return cont;
   
}