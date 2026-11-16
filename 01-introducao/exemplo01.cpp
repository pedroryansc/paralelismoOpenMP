// Imports para o Windows
#include <windows.h>
#include <assert.h>
#include <stdio.h>
#include <omp.h>

// Comando para compilar o programa com o OpenMP: g++ (ou "gcc") -fopenmp <nome-arquivo>.cpp -o <local-e-nome-arquivo>
int main(int argc, char *argv[]){
    printf("\nOla 1 - Regiao Serial... \n");
    
    #pragma omp parallel
    {
        printf("\nOla 2 - Regiao Paralela... \n");
    }

    printf("\nOla 3 - Regiao Serial... \n");

    // return 0; // No main, não é necessário adicionar o retorno explícito, pois o compilador o adiciona se não houver
}