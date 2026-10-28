# include <windows.h>
# include <assert.h>
# include <stdio.h>
# include <omp.h>

int main(int argc, char *argv[]){
    printf("Quantidade máxima de threads neste computador: %d \n", omp_get_max_threads());

    #pragma omp parallel
    {
        #pragma omp for
        for(int i = 0; i < 10; i++){
            printf("Thread %d - i = %d \n", omp_get_thread_num(), i);
        }
    }
}