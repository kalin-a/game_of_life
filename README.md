# game_of_life

This is an implementation of Conway's Game of Life, a cellular automaton that simulates the evolution of a population of cells. 
The program uses OpenMP to parallelize the simulation, allowing it to run faster on multi-core processors.
To build the program, run the following command in your terminal:

make run_all

This will compile the program using gcc-12 and OpenMP, 
`OMP_NUM_THREADS` will environment variable to 4 and run the program with the `time` command, which will display the execution time with and without parallelization.
Then the executable file and object files created during compilation will be removed.
