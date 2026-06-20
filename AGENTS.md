# philo — 42 Philosophers (Mandatory)

## Build & Verify

```
make              # build philo binary (links libft)
make clean        # remove .o files
make fclean       # remove .o + binary
make re           # fclean + all
```

No test, lint, or format commands exist. No CI.

## 42 Norminette (agent will miss this without help)

Every `.c`/`.h` file must pass `norminette`. Key constraints differing from defaults:
- **No `for` loops** — use `while`
- **Max 25 lines per function**, 5 functions per file, 4 params per function
- **No variable declarations after statements** — C89 mode only
- **No global variables** — project rule, also a Norm requirement when enforced
- **42 header** required at top of every file (already present)

## Allowed External Functions

Only these. Do not use anything else (no `readline`, `signal`, `time`, `nanosleep`, etc.):
`memset`, `printf`, `malloc`, `free`, `write`, `usleep`, `gettimeofday`,
`pthread_create`, `pthread_detach`, `pthread_join`,
`pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, `pthread_mutex_unlock`

## Current State

| File | Status | Notes |
|------|--------|-------|
| `philo.h` | Partial | Structs defined (`t_data`, `t_philo`, `t_fork`, `t_error`). Missing function prototypes. Includes `<bits/pthreadtypes.h>` (non-standard; `<pthread.h>` also included). |
| `main.c` | Validates args only | `input_validation()` + `is_valid_number()` done. No simulation orchestration yet. |
| `init.c` | **Has bug** | `parse_args()` line 23 writes optional arg to `data->time_to_sleep` instead of `data->must_eat`. No fork/philo init functions exist. |
| `error.c` | Complete | `print_error()` prints error messages to stderr. |
| `Makefile` | Needs update | `SRC` only lists `main.c` and `error.c`. Must add new files. |
| `libft/` | Complete | Has `ft_atoi`, `ft_atol`, `ft_isdigit`, `ft_putstr_fd`, `ft_putnbr_fd`, etc. |

Missing files to create: `routine.c`, `time.c`, `print.c`, `monitor.c`, `cleanup.c`.

## Key Design Constraints (from subject)

- **One thread per philosopher** → `pthread_create` for each
- **One mutex per fork** → `t_fork.fork` protects that fork
- **Print mutex** (`data->print_mutex`) prevents overlapping log lines
- **Death within 10ms** → `usleep` alone is inaccurate; use precise busy-wait (`gettimeofday` loop) for timing
- **Simulation stop** → `data->sim_running` flag protected by `sim_mutex`
- **Optional arg** `number_of_times_each_philosopher_must_eat`: if all philos meet it, simulation stops cleanly (no death)
- **Single philosopher** edge case: picks up one fork, can't eat second, dies after `time_to_die`
- **No data races** → all shared state protected by mutexes

## Architecture (file responsibilities)

| File | Contains |
|------|----------|
| `main.c` | Input validation, simulation orchestration (init → threads → monitor → join → cleanup) |
| `init.c` | `parse_args()`, `init_data()`, `init_forks()`, `init_philos()` |
| `time.c` | `get_time_ms()`, `timestamp()`, `precise_usleep()` |
| `print.c` | `print_state()` — thread-safe logging with print mutex |
| `routine.c` | `philo_routine()` — eat/sleep/think loop with fork acquisition |
| `monitor.c` | Death detection loop (runs in main thread after thread creation) |
| `cleanup.c` | Mutex destruction, free, thread join |

## Deadlock Prevention

Even-id philos lock right fork first, odd-id lock left fork first:
```c
// philo_routine()
if (philo->id % 2 == 0)
    pthread_mutex_lock(philo->right_fork->fork);
else
    pthread_mutex_lock(philo->left_fork->fork);
// then lock the other fork
```
This breaks the circular-wait condition. Single-philosopher case skips the second lock (one fork only).

Even philos should also `usleep(1000)` at routine start to stagger odd/even startup and prevent initial deadlock.

## Portability Note

`philo.h` includes `<bits/pthreadtypes.h>` (a glibc internal header). This is non-standard and may fail on non-glibc systems. The `<pthread.h>` include is already present and sufficient.
