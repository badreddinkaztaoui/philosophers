# Dining Philosophers Problem

The Dining Philosophers Problem is a famous problem in computer science used to illustrate common issues in concurrent programming. This project is coded in C, following the 42 Norm. It simulates a scenario where a number of philosophers are sitting at a round table doing one of three things: eating, thinking, or sleeping.

## Rules

- Philosophers can be in one of three states: eating, thinking, or sleeping.
- Philosophers must eat with two forks, one for each hand.
- Philosophers must never be starving, and every philosopher needs to eat.
- Philosophers don't speak with each other and don't know when another philosopher is about to die.
- The simulation stops when a philosopher dies.

## Program Options

Each program should have the following options:

- `number_of_philosophers`: Number of philosophers and also the number of forks.
- `time_to_die`: Time in milliseconds. If a philosopher doesn't start eating within 'time_to_die' milliseconds after starting his last meal or the beginning of the simulation, they die.
- `time_to_eat`: Time in milliseconds. The time it takes for a philosopher to eat.
- `time_to_sleep`: Time in milliseconds. The time the philosopher will spend sleeping.
- `[number_of_times_each_philosopher_must_eat]` (optional): If specified, the simulation will stop after all philosophers have eaten at least this many times. If not specified, the simulation will stop only at the death of a philosopher.

## Folder Structure

- `include/`: Contains the header file `philo.h`.
- `src/`: Contains the main source file `main.c`.
- `utils/`: Contains utility files:
  - `check_args.c`: Code for checking command line arguments.
  - `check_end_simulation.c`: Code for checking the end conditions of the simulation.
  - `create_threads.c`: Code for initialize the philos data and creating the threads.
  - `ft_atoi.c`: Custom implementation of the `atoi` function.
  - `ft_error.c`: Error handling functions.
  - `ft_state.c`: Function that print the state of the philosophers.
  - `moment.c`: Functions related to time management.
  - `save_args.c`: Code for saving command line arguments.
  - `simulation.c`: Code for simulating the dining philosophers scenario.
- `Makefile`: Build automation file.

## Usage

To run the program, use the following command:

```bash
./philosophers number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
