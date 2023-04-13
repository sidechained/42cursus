The delta time between eats for each philo should be 400ms, because:
one philo eats, releases forks, then must wait for another philo to eat to get back the forks so they can eat again
200 + 200 = 400
so a death time of 310 should mean the philo dies
but in my case the death_time never raises over 300ms, why?

4 310 200 100
a philo should die

we set time_last_eaten at start and when the philo begins eating
death check always happens at start of loop

// cc -Wall -Werror -Wextra philo.c -o philo && ./philo 4 999 500 500 15
// without optional arg:
// cc -Wall -Werror -Wextra philo.c -o philo && ./philo 4 999 500 500

// TODO
// pthread detach?! need to exit()?
// fix issue identified on slack
// return 1 if threads aren't created properly or mutexes don't init properly
// A message announcing a philosopher died should be displayed no more than 10 ms after the actual death of the philosopher.

// fork state - taken

// Q: do we need to wait an initial amount of time until all philos live?
// A: no, they can begin picking up forks

// p1 attempts to picks up f1, then f2 (success, not blocked)
// p1 eats for 200ms - during which time forks are blocked then puts down f1, then f2
// p2 attempts to pick up f1, then f2 (fail, blocked)
// p2 picks up f1, then f2

// SINGLE PHILOSOPHER
// should always die because they can only ever pick up one fork and can therefore never eat
// shouldn't mutex because there is no one else to pick up from the blocked 

// ONE PHILOSOPHER

// philosopher is created
// philosopher is thinking
// philosopher attempts to pick up fork to right
// if available he picks it up, preventing anyone else from doing so
// philosopher attempts to pick up fork to left
// if available he picks it up, preventing anyone else from doing so
// philosopher is eating (until EATING_TIME elapsed)
// when eating time is over
// - philosopher puts down fork to left
// - philosopher puts down fork to right
// - philosopher is sleeping (until SLEEP_TIME elapsed)
// once sleeping time is over
// - philosopher is thinking

// TWO PHILOSOPHERS
// put down last fork they picked up
//

// philosopher 1 is created
// philosopher 1 is thinking
// philosopher 2 is created
// philosopher 2 is thinking
// philosopher 1 picks up fork to left (because odd)
// philosopher 2 attempts to pick up fork to right (because even), but philosopher 1 already has it (continuously)
// philosopher 1 picks up fork to right
// philosopher 1 is eating
// philosopher 1 puts down fork to right
// philosopher 2 picks up fork to right (successfully now) 
// philosopher 1 puts down fork to left
// philosopher 1 is sleeping
// philosopher 2 picks up fork to left
// philosopher 2 is eating
// philosopher 2 puts down fork to left
// philosopher 2 puts down fork to right
// philosopher 2 is sleeping
// philosopher 1 is thinking (woke up)
// philosopher 1 picks up fork to left (because odd)
// philosopher 1 picks up fork to right
// and so on


# Functions

memset
printf
malloc
free
write
usleep - suspends execution of the calling thread for (at least) usec microseconds. 
gettimeofday - takes a time_values (tv) and/or time_zone (tz) struct as specified in #include <sys/time.h>
pthread_create - starts a new thread in the calling process
pthread_detach - marks a thread as detached. When a detached thread terminates, its resources are automatically released back to the system without the need for another thread to join with the terminated thread.
pthread_join - waits for a specified thread to terminate
pthread_mutex_init - destroy and initialize a mutex
pthread_mutex_destroy - destroy the mutex object. A destroyed mutex object can be reinitialized using pthread_mutex_init();
pthread_mutex_lock - complex - see https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3p.html
pthread_mutex_unlock - release the mutex object

https://www.geeksforgeeks.org/multithreading-in-c/
https://github.com/MichelleJiam/LazyPhilosophersTester
https://docs.oracle.com/cd/E19455-01/806-5257/sync-12/index.html
https://www.delftstack.com/howto/c/mutex-in-c/

pthread_create allows you to separate certain parallelizeable tasks into separate threads. Threads can then exploit the parallelism in hardware (such as multicore processors), that is, they can run simultaneously.

pthread_join is used when one thread waits for another one to finish. The two threads work in parallel, then they must combine the results they obtained. One of them calls join and waits for the other one to exit, so it can collect its result (which may actually be a number*, or perhaps some dynamically allocated larger object**)

When should pthread_join be used?