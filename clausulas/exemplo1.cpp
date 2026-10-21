// Comando para compilar o programa com o OpenMP: g++ (ou "gcc") -fopenmp <nome-arquivo>.cpp -o <local-e-nome-arquivo>
# include <windows.h>
# include <assert.h>
# include <stdio.h>
# include <omp.h>

int  main(int argc, char *argv[]){
    // Aqui, a variável num é criada
    int num = 0;

    printf("Serial %d \n", num);

    omp_set_num_threads(4);

    // A cláusula private define que a variável "num" é privada, ou seja,
    // que cada uma das 4 threads terá uma variável "num" não compartilhada.
    #pragma omp parallel private(num)
    {
        // Na região paralela, é criada uma cópia local da variável privada para cada thread.
        // Como estas cópias começam com valores indefinidos, é necessário definir a variável "num"
        // como 0 novamente para evitar erro de indefinição
        num = 0;

        int id = omp_get_thread_num();
        num = num + id;
        
        printf("Paralela - Thread id = %d e (num + id) = %d \n", id, num);
    }

    printf("Serial %d \n", num);

    return 0;
}