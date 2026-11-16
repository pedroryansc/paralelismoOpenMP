#include <windows.h>
#include <assert.h>
#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[]){
    printf("\nOla 1 - Fora da Regiao Paralela... \n\n");

    #pragma omp parallel
    {
        int idThread = omp_get_thread_num();
        int quantThreads = omp_get_num_threads();

        printf("Sou a thread %d de um total de %d threads. \n", idThread, quantThreads);
    }

    printf("\nOla 2 - Fora da Regiao Paralela... \n");

    return 0;
}