# Task

Implementation of an in-process cron scheduler that accepts a job and executes it periodically.

## Getting Started

### Usage

* You have to include the scheduler header file in your project
 ```
#include "scheduler.h"
 ```
* You can use the functions provided for adding and deleting jobs where the parameters of the add job function are:
  * id: unique job identifier.
  * interval: single run expected interval in seconds.
  * frequency: scheduling frequency in seconds, e.g. 100 for a job that should run every 100 seconds.
  * implementation: job implementation, e.g. a function.
 ```
bool Scheduler::addJob(int id, int interval, int frequency, function<void()> implementation)
bool Scheduler::killJob(int id)
 ```
* There are already three tests.

## Description

The cron schedular takes the job information from you then associates the next time that this job must run and push it in a min-heap. The scheduler constantly checks the current system time with the top of the heap when the system time is bigger a new thread is made with the user function and the time is updated.

## Logs example
 ```
Thu Mar  2 07:38:55 2023 - The Scheduler has started
Thu Mar  2 07:38:55 2023 - Job with id 1 has been added
Thu Mar  2 07:38:55 2023 - Job with id 2 has been added
Thu Mar  2 07:38:55 2023 - Job with id 3 has been added
Thu Mar  2 07:38:56 2023 - Job with id 2 has been executed and took 1.000000 seconds
Thu Mar  2 07:38:59 2023 - Job with id 3 has been executed and took 4.00000 seconds
Thu Mar  2 07:38:59 2023 - Job with id 1 has been executed and took 4.00000 seconds
Thu Mar  2 07:39:01 2023 - Job with id 2 has been executed and took 1.00000 seconds
Thu Mar  2 07:39:07 2023 - Job with id 1 has been executed and took 3.00000 seconds
Thu Mar  2 07:39:08 2023 - Job with id 3 has been executed and took 1.00000 seconds
 ```
 
 ## Technical decisions and Trade-offs
 * I used C/C++ as they are considered the fastest.
 * I decided to go with making the project as a library that other developers can use. A different approach would make the project executable and ask the user to provide a path to the script file and use a function like exec() but this will mean making the project multiprocessing other than multithreading so I decided to go with the latter cause it is faster.

## Possible future improvements
* Store the jobs logs in a database.
* I decided to go for providing the seconds for frequency for simplicity but a future feature will be supporting the cronjob format provided by linux: 
  * Day of the Week(0-6) - Month of the Year(1-12) - Day of the Month(1-31) - Hour(0-23) - Min(0-59)
* One of the things I was thinking about was making an actual low-level schedular that can take a decision to interrupt certain threads and resume it or take decisions based on the expected time as it is provided by the user.
## References

* [OPERATING SYSTEMS THREE EASY PIECES](https://techiefood4u.files.wordpress.com/2020/02/operating_systems_three_easy_pieces.pdf)
