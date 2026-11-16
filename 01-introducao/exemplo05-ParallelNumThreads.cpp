#include <windows.h>
#include <assert.h>
#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[]){
    printf("\nOla 1 - Fora da Regiao Paralela... \n\n");
    
    // Define que todas as regiões paralelas, a princípio, serão executadas em 8 threads
    omp_set_num_threads(8);

    // Define que esta região paralela específica será executada em 4 threads, sobrescrevendo a quantidade definida antes apenas para este caso
    #pragma omp parallel num_threads(4)
    {
        int idThread = omp_get_thread_num();
        int quantThreads = omp_get_num_threads();

        printf("Sou a thread %d de um total de %d \n", idThread, quantThreads);
    }

    printf("\nOla 2 - Fora da Regiao Paralela... \n\n");

    // Esta região paralela seguirá a quantidade de threads definida para todos anteriormente (8)
    #pragma omp parallel
    {
        int idThread = omp_get_thread_num();
        int quantThreads = omp_get_num_threads();

        printf("Sou a thread %d de um total de %d \n", idThread, quantThreads);
    }

    printf("\nOla 3 - Fora da Regiao Paralela...");
}