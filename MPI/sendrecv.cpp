#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    // Find out rank, size
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // We are assuming at least 2 processes for this task
    if (world_size < 2) {
        fprintf(stderr, "World size must be greater than 1 for %s\n", argv[0]);
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
    
    int number;

    if (world_rank == 0) {
        // If we are rank 0, set number to -1 and send it to process 1
        number = -1;
        MPI_Send(
            /* data = */ &number,
            /* count = */ 1,
            /* datatype = */ MPI_INT,
            /* destination = */ 1,
            /* tag = */ 0,
            /* communicator = */ MPI_COMM_WORLD);
        printf("hello from Process 0");
    }
    else if (world_rank == 1) {
        MPI_Recv(
            /* data = */ &number,
            /* count = */ 1,
            /* datatype = */ MPI_INT,
            /* source = */ 0,
            /* tag = */ 0,
            /* communicator = */ MPI_COMM_WORLD,
            /* status = */ MPI_STATUS_IGNORE);
        printf("Process 1 received number %d from process 0\n", number);
    }

    MPI_Finalize();
    return 0;
}