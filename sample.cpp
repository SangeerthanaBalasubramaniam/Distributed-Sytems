#include <stdio.h>
#include "mpi.h"
#include <iostream>

int main(int argc, char** argv) {

    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    // Print off a hello world message
    printf("Hello World");

    // Finalize the MPI environment.
    MPI_Finalize();
}