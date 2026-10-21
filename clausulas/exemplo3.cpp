# include <windows.h>
# include <assert.h>
# include <stdio.h>
# include <omp.h>

int main(int argc, char *argv[]){
    int num = 0;

    printf("Serial %d \n", num);

    omp_set_num_threads(8);

    // Define que a variável num será compartilhada entre todas as threads na região paralela
    #pragma omp parallel shared(num)
    {
        int id = omp_get_thread_num();

        // Caso o programa não funcionasse, deveria ser adicionado nesta linha a diretiva "#pragma omp atomic"
        // A diretiva "pragma omp atomic" reforça que uma ou mais intruções devem ser feitas por uma thread por vez
        num = num + 1;
        
        printf("Paralela - Thread id = %d e (num + 1) = %d \n", id, num);
    }

    printf("Serial %d \n", num);

    return 0;
}