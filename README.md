*This project has been created as partof the 42 curriculum by aphyo-ht.*

# Philosophers

The Philosophers project is an implementation of the classic dining philosophers problem, designed to teach the fundamentals of threading, mutexes, and process synchronization. This project explores the challenges of resource sharing, deadlock prevention, and concurrent programming.

The dining philosophers problem illustrates synchronization issues and techniques for resolving them in concurrent algorithm design. Philosophers sit around a circular table with forks between each pair of adjacent philosophers. Each philosopher must alternately think and eat, but can only eat when holding both forks adjacent to their position.

##  Mandatory

### Description

In the mandatory part, you must solve the dining philosophers problem using threads and mutexes. Each philosopher is represented by a thread, and each fork is protected by a mutex. The simulation must prevent data races and ensure no philosopher starves.

Key requirements:
- Philosophers alternate between eating, sleeping, and thinking
- A philosopher needs two forks (left and right) to eat
- Philosophers cannot communicate with each other
- The simulation stops when a philosopher dies of starvation
- No philosopher should die if the arguments are valid
- Avoid data races at all costs

### Instructions

**Usage:**
```
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

**Arguments:**
- `number_of_philosophers`: The number of philosophers (and forks)
- `time_to_die`: Time in milliseconds - if a philosopher doesn't start eating within this time since their last meal, they die
- `time_to_eat`: Time in milliseconds it takes for a philosopher to eat
- `time_to_sleep`: Time in milliseconds a philosopher spends sleeping
- `number_of_times_each_philosopher_must_eat`: (Optional) If specified, the simulation stops when all philosophers have eaten at least this many times

**Implementation Requirements:**
- Use pthread library for threading
- Use mutex for fork synchronization
- Each philosopher should be a thread
- Protect shared resources with mutexes
- Log all philosopher actions with timestamps
- Ensure no data races occur

**Output Format:**
```
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```

##  BONUS

### Description

The bonus part involves solving the same problem using processes and semaphores instead of threads and mutexes. Each philosopher is represented by a process, and synchronization is achieved through semaphores. This approach demonstrates inter-process communication and semaphore-based synchronization.

Key differences from mandatory:
- Use processes instead of threads
- Use semaphores instead of mutexes for fork management
- Implement proper process communication
- Handle process creation and cleanup
- Ensure proper semaphore initialization and destruction

### Instructions

**Implementation Requirements:**
- Use fork() system call to create child processes
- Use semaphores (sem_open, sem_wait, sem_post, sem_close, sem_unlink)
- Each philosopher runs in its own process
- Use named semaphores for inter-process synchronization
- Implement proper process synchronization
- Handle zombie processes appropriately
- Clean up all semaphores and processes on exit

**Additional Considerations:**
- Process communication through shared memory or signals
- Proper error handling for process creation
- Semaphore naming conventions to avoid conflicts
- Signal handling for graceful termination
- Memory management across process boundaries

## Resources
[Unix Threads in C - Code Valut](https://www.youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)

### Race Conditions

A race condition occurs when two or more threads or processes access shared data concurrently, and the final result depends on the timing or order of execution. This creates unpredictable behavior because the outcome varies based on which thread executes first or how the operating system schedules the threads.

**Common scenarios in the Philosophers problem:**
- Multiple philosophers trying to pick up the same fork simultaneously
- Reading and writing to shared variables (like `meals_eaten` or `last_meal`) without proper mutex protection
- Checking if a philosopher is alive while another thread is updating the status

**Example of a race condition:**
```c
// Thread 1: Philosopher eating
philosopher->meals_eaten++;        // Read, increment, write

// Thread 2: Monitor checking meals
if (philosopher->meals_eaten >= max_meals)  // Read
    stop_simulation();

// Example usage of mutex lock.
void	ft_wait_until_ready(t_table *table)
{
	while (1)
	{
		pthread_mutex_lock(&table->ready_mutex);
		pthread_mutex_lock(&table->alive_mutex);
		if (table->is_ready)
		{
			pthread_mutex_unlock(&table->ready_mutex);
			pthread_mutex_unlock(&table->alive_mutex);
			break ;
		}
		pthread_mutex_unlock(&table->ready_mutex);
		pthread_mutex_unlock(&table->alive_mutex);
		usleep(100);
	}
}
// Actually, there is only one place in code which modify the is_ready variable. However, we've to use the lock as there are many threads racing to get the is_ready value.

```

**Prevention with mutex locks:**
- **Fork mutexes**: Each fork has its own mutex - philosophers must acquire the mutex before picking up a fork
- **Data protection mutexes**: Shared variables like `meals_eaten`, `last_meal`, and `is_alive` are protected by individual mutexes
- **Critical sections**: Use `pthread_mutex_lock()` before accessing shared data and `pthread_mutex_unlock()` after

**In this project:**
Race conditions are prevented by protecting every shared resource with mutex locks. Before a philosopher can pick up a fork or modify shared data, they must first acquire the corresponding mutex lock, ensuring exclusive access to prevent data corruption and undefined behavior.