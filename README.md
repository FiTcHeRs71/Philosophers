*This project has been created as part of the 42 curriculum by fitchers.*

# Philosophers

## Description
This project is an implementation of the classic "Dining Philosophers problem", designed to teach the basics of threading a process, synchronization, and the use of mutexes in C. 

The simulation involves a specific number of philosophers sitting at a round table, doing one of three things: eating, thinking, or sleeping. To eat, a philosopher must hold two forks (one on the left, one on the right). The goal is to create a concurrent algorithm where no philosopher starves to death, ensuring proper memory management, avoiding data races, and preventing deadlocks. 

## Instructions

### Compilation
The project comes with a Makefile. To compile the mandatory part of the project, run:
```bash
make
```

## Ressources

https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2

https://github.com/mcombeau/philosophers