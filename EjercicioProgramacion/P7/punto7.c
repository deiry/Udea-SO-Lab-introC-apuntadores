/**Se trata de resolver el siguiente problema escolar.
 *  Dadas las notas de los alumnos de un colegio en el primer curso de bachillerato,
 *  en las diferentes asignaturas (5, por comodidad), se trata de calcular la media 
 * de cada alumno, la media de cada asignatura, la media total de la clase y ordenar 
 * los alumnos por orden decreciente de notas medias individuales.
 * Nota: utilizar como algoritmo de ordenación el método Shell.*/

#include <stdio.h>
void metodoShell(double *notasE, int tamano);
double calcularPromedio(double *vector, int longitud);

int main(){
    int nEstudiantes;
    double mediaEstudiante, mediaAsignatura, mediaClase, notaE, *apuntador;
    printf("Ingrese el numero de estudiantes \n");
    scanf("%d", &nEstudiantes);
    double notasEstudiantesPorAsignatura[nEstudiantes][5]; 
    double mediasMaterias[5], mediasClase[5], notaEstudiante[5], notasEstudiantes[nEstudiantes];
    for(int i = 0; i < 5; i++){
        printf("MATERIA %d : \n", (i + 1));
        for(int j = 0; j < nEstudiantes; j++){
            double notaEstudiante;
            printf("Ingrese la nota del estudiante %d de la materia %d \n", (j + 1), (i + 1));
            scanf("%lf", &notaEstudiante);
            apuntador = &notasEstudiantesPorAsignatura[j][i];
            *apuntador = notaEstudiante;
        }   
    }
    //Promedio por estudiante
     for(int k = 0; k < nEstudiantes; k++){
        for(int l = 0; l < 5; l++){
            apuntador = &notasEstudiantesPorAsignatura[k][l];
            notaE = *apuntador;
            *(notaEstudiante + l) = notaE; 
        }
        mediaEstudiante = calcularPromedio(notaEstudiante, 5);
        *(notasEstudiantes + k) = mediaEstudiante;
        printf("El promedio del estudiante %d es: %lf \n \n", (k+1), mediaEstudiante);
    }  
    //Promedio por materia
    for(int k = 0; k < 5; k++){
        for(int l = 0; l < nEstudiantes; l++){
            apuntador = &notasEstudiantesPorAsignatura[l][k];
            notaE = *apuntador;
            *(mediasMaterias + l) = notaE; 
        }
        mediaAsignatura = calcularPromedio(mediasMaterias, nEstudiantes);
        *(mediasClase + k) = mediaAsignatura;
        printf("El promedio de la materia %d es: %lf \n \n", (k+1), mediaAsignatura);
    }
    //Promedio clase
    mediaClase = calcularPromedio(mediasClase, 5);
    printf("El promedio de la clase es: %lf \n \n", mediaClase);
    metodoShell(notasEstudiantes, nEstudiantes);
    printf("Las notas ordenadas son: \n");
    //Notas ordenadas
    int aux = nEstudiantes;
    while(aux > 0){
        printf("%lf \n", *(notasEstudiantes + (aux-1)));
        aux--;
    }
    return 0;
}

void metodoShell(double *notasEstudiante, int tamano){
    int intervalo; 
    intervalo = tamano/2;
    while(intervalo > 0){
        for(int i = intervalo; i < tamano; i++){
            int j = i - intervalo;
            while(j >= 0){
                int k = j + intervalo;
                if(*(notasEstudiante + j) <= *(notasEstudiante +k)){
                    j = -1;
                }
                else{
                    double aux;
                    aux = *(notasEstudiante + j);
                    *(notasEstudiante + j) = *(notasEstudiante + k);
                    *(notasEstudiante + k) = aux;
                    j -= intervalo;
                }
            }
        }
        intervalo = intervalo / 2;
    }
}

double calcularPromedio(double *vector, int longitud){
    double promedio = 0;
    for(int i = 0; i < longitud; i++){
        promedio = promedio + *(vector + i);
    }
    promedio = promedio / longitud;
    return promedio;
}

