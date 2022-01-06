#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {

    int my_id, root_process, ierr, num_procs;
    MPI_Status status;

    /* Create child processes, each of which has its own variables.
     * From this point on, every process exexutes a seperate copy
     * of this program. Each process has a different process ID,
     * ranging from 0 to num_procs minus 1, and COPIES of all
     * variables defined in the program. No variables are shared.
     */

    ierr = MPI_Init(&argc, &argv);

    /* find out MY process ID, and how many processes were started. */

    ierr = MPI_Comm_rank(MPI_COMM_WORLD, &my_id);
    ierr = MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    if (my_id == 0) {
        printf("do some work as process 0 ");
    }

    else {
        printf("do some work as process 1 ");
    }

    /* Stop this process */

    ierr = MPI_Finalize();
    return 0;
}