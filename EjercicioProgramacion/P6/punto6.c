/**Dado un vector x de n elementos reales, donde n es impar, diseñar una función que calcule 
 * y devuelva la mediana de ese vector. La mediana es el valor tal que la mitad de los números 
 * son mayores que el valor y la otra mitad son menores. Escribir un programa que compruebe la función.*/

#include <stdio.h>

double calcularMediana(double *array, int tamano);
void burbuja(double *vectorAOrdenar, int tamano);

int main(){
    int tamano;
    double mediana;
    printf("Ingrese un número impar par el tamaño del vector: \n");
    scanf("%d", &tamano);
    while(tamano % 2 == 0){
        printf("Ingrese un número impar par el tamaño del vector: \n");
        scanf("%d", &tamano);
    } 
    double vector[tamano];
    for(int i = 0; i < tamano; i++){
        double auxiliar;
        printf("Ingrese el numero de la posicion %d del vector: \n", (i+1));
        scanf("%lf", &auxiliar);
        *(vector + i) = auxiliar;
    }
    burbuja(vector, tamano);
    mediana = calcularMediana(vector, tamano);
    printf("La mediana del vector es %lf \n", mediana);
    return 0;
}

double calcularMediana(double *array, int tamano){
    int mitad = (tamano)/2;
    double mediana = *(array + mitad);
    return mediana;
}

void swap(double *vector, int o, int d)
{
    double auxiliar;
    auxiliar = *(vector + d);
    *(vector + d) = *(vector + o);
    *(vector + o) = auxiliar;
}

void burbuja(double *vectorAOrdenar, int tamano)
{
    int i, j;
    for (j=0; j<tamano; j++){
        for (i=0; i<tamano-1; i++){
            if(*(vectorAOrdenar + i) > *(vectorAOrdenar + i + 1)){
                swap(vectorAOrdenar, i, i+1);
            }
                 
        }
            
    }
        
}

