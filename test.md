# Philosophers — Test Suite

## 1. Invalid Arguments

```bash
# No arguments — should print error, exit 1
./philo

# Zero or negative philosophers — should print error, exit 2
./philo 0 800 200 200
./philo -1 800 200 200

# Non-numeric values — should print error, exit 2
./philo 4 abc 200 200
./philo 4 800 2o0 200
./philo 4 800 200 2o0

# Wrong argument count — should print error, exit 1
./philo 4 800 200          # missing time_to_sleep
./philo 4 800 200 200 200 2  # extra argument

# Zero or negative time values — should still run (subject doesn't forbid)
./philo 4 0 200 200
```

## 2. Single Philosopher

Should take one fork, wait `time_to_die` ms, die.

```bash
# Dies at ~800ms
./philo 1 800 200 200

# Dies at ~400ms (fast)
./philo 1 400 200 200
```

Expected output (timestamps approximate):
```
0 1 has taken a fork
800 1 died
```

## 3. Basic Death Detection

```bash
# Tight timing — one philosopher should starve quickly
# time_to_die=310, time_to_eat=200, time_to_sleep=100
# Total cycle = 300ms, only 10ms margin to grab forks again
./philo 4 310 200 100
```
Expected: death within 1-2s, at most one "died" line.

```bash
# Generous timing — no death (runs forever until you ^C)
./philo 4 800 200 200
```
If it exits on its own, something is wrong.

## 4. must_eat Clean Exit

```bash
# 2 philos, 2 meals each — should stop cleanly, no death
./philo 2 1000 200 200 2

# 5 philos, 7 meals each — should stop cleanly
./philo 5 800 200 200 7

# 200 philos, 3 meals — should stop cleanly (may take a while)
./philo 200 800 200 200 3
```
Expected: no "died" in output. Last lines show eating/sleeping. Exit code 0.

## 5. Many Philosophers

```bash
# 200 philos, no must_eat, short die time — mass starvation
./philo 200 400 200 200

# 100 philos, sustainable timing — should run indefinitely
./philo 100 800 200 200
```

## 6. Edge Cases

```bash
# Minimum valid arguments
./philo 2 100 50 50

# Large numbers — no overflow or crashes
./philo 4 2147483647 100 100

# 2 philosophers (classic deadlock test — should survive)
./philo 2 410 200 100
```

## 7. Death Timing Precision

Death message should appear within 10ms of actual death.

```bash
# Philo 2 starts with no fork, should die at ~time_to_die
./philo 2 400 200 200
```
Check that `died` timestamp is ≤ `time_to_die + 10`.

## 8. No Data Races / Sanitizer (if available)

```bash
make re
clang -fsanitize=thread -g *.c libft/libft.a -o philo_tsan
./philo_tsan 4 800 200 200 3
```

## 9. Memory Leaks (valgrind on eval machine)

```bash
valgrind --leak-check=full --show-leak-kinds=all \
  ./philo 2 1000 200 200 2
```

## 10. Norminette

```bash
norminette *.c *.h libft/
```

## Expected Behavior Summary

| Scenario | Expected Result |
|----------|----------------|
| Invalid args | Error message, non-zero exit |
| Single philo | Fork taken, dies after `time_to_die` |
| 4 philos, tight timing | Death within reasonable time |
| must_eat=N (all eat N) | Clean exit, no death, exit 0 |
| 200 philos | No crashes, deadlocks, or segfaults |
| Death timing | "died" within 10ms of actual death |
| No must_eat + sustainable | Runs forever |
| No data races | Thread sanitizer clean |
| Memory | No leaks |
| Norminette | All OK |
