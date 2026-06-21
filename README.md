*This project has been created as part of the 42 curriculum by hbani-at.*

---

## Description

**Philosophers** is the classic Dining Philosophers problem implemented in C using POSIX threads (`pthreads`) and mutexes. The simulation models `N` philosophers sitting around a circular table, each alternating between three states: **eating**, **thinking**, and **sleeping**. A shared set of `N` forks — one between each pair of adjacent philosophers — is the limited resource they must acquire to eat.

The goal is to design a concurrent solution that avoids **deadlock** (every philosopher holding one fork and waiting indefinitely for the other) and **data races**, while ensuring no philosopher starves. The simulation ends when a philosopher dies of starvation (i.e., exceeds `time_to_die` ms since their last meal) or, optionally, when all philosophers have eaten at least `must_eat` times.

### Key Features

- **Thread-per-philosopher architecture** — each philosopher runs in its own POSIX thread.
- **Mutex-based fork protection** — each fork is a `pthread_mutex_t` to ensure exclusive access.
- **Even-odd fork acquisition** — even-id philosophers pick up their right fork first, odd-id pick up their left fork first, reducing contention and breaking cyclic wait.
- **Separate monitoring thread** — the main thread continuously checks for death and the "all full" condition.
- **Precise timing** — a spin-loop `better_usleep` avoids the inaccuracies of `usleep()` for sub-millisecond precision.
- **Deadlock-free single-philosopher edge case** — a single philosopher picks up the only fork and waits until death is detected.

---

## Instructions

### Compilation

```sh
make
```

This compiles the `philo` executable and the internal `libft` library. The following targets are available:

| Target    | Action                                |
|-----------|---------------------------------------|
| `all`     | Build the executable                  |
| `clean`   | Remove object files                   |
| `fclean`  | Remove object files and executable    |
| `re`      | Full rebuild (`fclean` + `all`)       |

### Execution

```sh
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

| Argument                               | Description                                                  |
|----------------------------------------|--------------------------------------------------------------|
| `number_of_philosophers`               | Number of philosophers / forks on the table                  |
| `time_to_die` (ms)                     | Max time (ms) a philosopher can go without eating before dying |
| `time_to_eat` (ms)                     | Time (ms) a philosopher spends eating                        |
| `time_to_sleep` (ms)                   | Time (ms) a philosopher spends sleeping                      |
| `number_of_times_each_philosopher_must_eat` (optional) | Simulation stops once every philosopher has eaten this many times |

### Example

```sh
./philo 5 800 200 200
# 5 philosophers, 800 ms to die, 200 ms to eat, 200 ms to sleep
```

```sh
./philo 4 410 200 200 5
# Stops when all 4 philosophers have eaten 5 times each
```

### Output Format

```
timestamp_in_ms philosopher_id action
```

Actions:
- `has taken a fork`
- `is eating`
- `is sleeping`
- `is thinking`
- `died`

---

## Resources

- **Butenhof, D. R. (1997).** *Programming with POSIX® Threads.* Addison-Wesley. — The definitive guide to POSIX threads programming, covering thread management, synchronization, and real-world patterns.

### Online Articles & Tutorials

- [Breaking Down Serialization: How Data Travels Between Worlds](https://medium.com/@muhammadalikhan0003/breaking-down-serialization-how-code-turns-memory-into-meaning-0d8db03863f9)
- [Kernel task_struct](https://alex-xjk.github.io/post/taskstruct/)
- [What Is a Thread in an Operating System?](https://medium.com/@no_man/what-is-a-thread-in-an-operating-system-88f31c92bd91)
- [What is the difference between concurrency and parallelism?](https://stackoverflow.com/questions/1050222/what-is-the-difference-between-concurrency-and-parallelism)

### Manual Pages (man)

#### POSIX Threads (pthreads)
- `man pthread_create` — create a new thread
- `man pthread_join` — join with a terminated thread
- `man pthread_mutex_init` — initialise a mutex
- `man pthread_mutex_lock` — lock a mutex
- `man pthread_mutex_unlock` — unlock a mutex
- `man pthread_mutex_destroy` — destroy a mutex

#### System Calls / Library Functions
- `man gettimeofday` — get the current time of day with microsecond precision
- `man usleep` — suspend execution for microsecond intervals
- `man malloc` — allocate dynamic memory
- `man free` — free allocated memory
- `man printf` — formatted output conversion
- `man write` — write to a file descriptor (used internally by `ft_putstr_fd`)

### AI Usage

AI was used during the development of this project for code review (identifying data-race scenarios and suggesting correct mutex placement) and optimization advice. All logic, architecture decisions, and final implementation remain the original work of the author.

---

## Project Structure

```
philosopher/
├── Makefile          # Build system
├── philo.h           # Header — type definitions and function prototypes
├── main.c            # Entry point, argument validation, simulation bootstrap
├── init.c            # Data initialisation (forks, philosophers, mutexes)
├── routine.c         # Philosopher thread routine (think, eat, sleep cycle)
├── monitoring.c      # Death detection and "all full" condition checker
├── print.c           # Thread-safe state printing
├── time.c            # Timing utilities (get_time_ms, better_usleep)
├── error.c           # Error message printing
├── cleanup.c         # Resource cleanup (join threads, destroy mutexes, free)
└── libft/            # Custom libft C library
    ├── Makefile
    ├── libft.h
    ├── ft_atoi.c
    ├── ft_atol.c
    ├── ft_isdigit.c
    └── ... (other libft functions)
```
