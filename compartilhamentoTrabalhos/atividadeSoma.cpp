# include <windows.h>
# include <assert.h>
# include <stdio.h>
# include <omp.h>
# include <time.h>

int main(int argc, char *argv[]){
    float A[2048];
    float B[2048];
    float C[2048];

    srand(time(NULL));

    #pragma omp parallel for // "for" pode ser unificado à diretiva parallel, o que provê uma melhora no desempenho (pois não precisa iniciar outro constutor)
    {
        for(int x = 0; x < 2048; x++){
            A[x] = rand() % 5000;
            B[x] = rand() % 5000;
            
            C[x] = A[x] + B[x];
        
            printf("Thread %d -> C[%d] = %f \n", omp_get_thread_num(), x, C[x]);
        }
    }
}