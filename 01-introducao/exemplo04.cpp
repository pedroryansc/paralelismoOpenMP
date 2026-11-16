#include <windows.h>
#include <assert.h>
#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[]){
    printf("\nOla 1 - Fora da Regiao Paralela... \n\n");

    for(int i = 1; i <= 2; i++){
        if(i == 1)
            omp_set_num_threads(4);
        else{
            omp_set_num_threads(8);

            printf("\nOla 2 - Fora da Regiao Paralela... \n\n");
        }
        
        #pragma omp parallel
        {
            int idThread = omp_get_thread_num();
            int quantThreads = omp_get_num_threads();

            printf("Sou a thread %d de um total de %d \n", idThread, quantThreads);
        }
    }

    printf("\nOla 3 - Fora da Regiao Paralela... \n");

    return 0;
}