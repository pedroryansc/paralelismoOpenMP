# include <windows.h>
# include <assert.h>
# include <stdio.h>
# include <omp.h>

int main(int argc, char *argv[]){
    printf("Ola 1 - Fora da Regiao Paralela... \n");

    // "t" recebe a quantidade de núcleos do processador
    int t = omp_get_max_threads();
    printf("T = %d \n", t);

    // A região paralela só é executa se a quantidade de núcleos do processador >= 4
    #pragma omp parallel if(t >= 4)
    {
        int id = omp_get_thread_num();
        // Como omp_set_num_threads não foi definido, a quantidade de threads da região paralela é igual ao máximo suportado pelo PC
        int num = omp_get_num_threads();
        printf("Sou a thread %d de um total de %d \n", id, num);
    }

    printf("Ola 2 - Fora da Regiao Paralela... \n");
}