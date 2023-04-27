CC=gcc-12
CFLAGS=-fopenmp

game_of_life: game_of_life.c
	$(CC) $(CFLAGS) -o game_of_life game_of_life.c

run: game_of_life
	@echo "Running game_of_life"
	@time -p ./game_of_life

run_parallel: game_of_life
	@echo "Running game_of_life on 4 threads"
	@export OMP_NUM_THREADS=4 && time -p ./game_of_life

run_all: run run_parallel

clean:
	rm -f game_of_life

