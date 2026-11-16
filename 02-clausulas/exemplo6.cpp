# include <windows.h>
# include <assert.h>
# include <stdio.h>
# include <omp.h>

int main(int argc, char *argv[]){
    int num = 3;

    printf("Serial %d \n", num);

    omp_set_num_threads(4);

    // Define que será feito uma soma com o valor de "num" de cada thread ao final da execução da região paralela
    #pragma omp parallel reduction(+:num)
    {
        int id = omp_get_thread_num();
        num = num + id;
        printf("Paralela - Thread Id = %d e (num + id) = %d \n", id, num);
    }

    printf("Serial %d \n", num);

    return 0;
}