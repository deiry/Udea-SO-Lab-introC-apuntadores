#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char *obtenerSubcadena(char *array, int index);
void test(void);

int main(){
  test();
  return 0;
}

void test(void){
  char *p1 = "Hola,¿qué tal? ¿cómo estás?";
  char *p2;
  p2 = obtenerSubcadena(p1, 5);
  printf("%s\n",p1);    // Imprime: Hola que tal
  printf("%s\n",p2);    // Imprime: que tal

}

/**Obtener la subcadena de una cadena dada a partir 
 * de un subindice siguiendo la siguiente funcion*/
/**
 *   @brief  Obtiene una subcadena a tomada a partir de un subindice asociado a una subcadena
 *
 *   @param  array cadena de caracteres a ingresar
 *   @param  index indice
 *   @return un apuntador a la posicion inicial de la subcadena o NULL si el tamaño de index supera a la longitud de la cadena
 */
char *obtenerSubcadena(char *array, int index) {

    int cont = 0;
    if(index < strlen(array)){
      while (*array != '\0'){
      if(cont == index){
        return array;
      }
      cont++;
      array++;
    }
    }
    
    return array;
    
}