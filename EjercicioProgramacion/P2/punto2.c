/**Hacer una funcion que permita que un usuario obtenga el subindice asociado
*  a la primera aparicion de un caracter en un array. 
* Si el caracter no esta la función debera retornar -1. 
* Haga uso de la funcion del punto 1 para validar la presencia del caracter. 
* A continuacion se muestra la forma de la función:*/
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int obtenerIndice(char *array, char ch);
void test(void);

int main(){
    test();
    return 0;
}

void test(void){

    char cad[] = "ejemplopunto2";
    char ch = 'n';
    int v = obtenerIndice(cad,ch);
    printf("Obtener indice de %s con el caracter %c: %d\n", cad, ch, v);
}

/**
 *   @brief  Obtiene el indice de la primera aparicion de un caracter en un array
 *
 *   @param  array cadena de caracteres a ingresar
 *   @param  ch es el caracter a ingresa
 *   @return el indice del primer ch en la cadena array
 */
int obtenerIndice(char *array, char ch) {
    int indice = 0;
    int flag = 0;
    while(*array != '\0'){
        if(ch == *array){
            flag = 1;
            break;
        }
        array++;
        indice++;
    } 
    if(flag == 0){
        indice = -1;
    }
    return indice;
      
}

/**
 * Para clarificar un poco la cosa, si por ejemplo la cadena es hola: 
 * que mas y el caracter a buscar es : la funcion debera retornar 4. Por otro lado, 
 * si el caracter a buscar es la a, la funcion retornara 3. 
 * Finalmente, si el caracter ingresado es z la funcion retornara -1.
*/