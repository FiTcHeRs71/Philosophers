*This project has been created as part of the 42 curriculum by fitchers.*

# Philosophers

## Description

### Mandatory Part
The mandatory part of the project uses **threads** (one thread per philosopher) and **mutexes** (to represent the forks placed between each philosopher and to protect shared variables).

### Bonus Part
The bonus part approaches the problem with a different system architecture:
* All philosophers are separate **processes** (created using `fork()`).
* The forks are placed in the middle of the table, managed by a set of **semaphores** instead of independent mutexes.
* Semaphores are also utilized to synchronize the printing of states and to monitor the death of a philosopher across different processes.

## Instructions

### Compilation
The project comes with a Makefile. To compile the mandatory part of the project, run:
```bash
cd philo
make
```

### Compilation bonus

```bash
cd philo_bonus
make
```
## Ressources

https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2

https://github.com/mcombeau/philosophers