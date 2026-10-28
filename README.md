# Printer Job Management System Using Queue.

## Objective
To simulate printer job management using a queue data structure that follows First In, First Out (FIFO).

## Features
- scan the number of print jobs
- Add a print job with a file name and page count
- Process the next pending print job
- Display all pending jobs
- Show the number of pending jobs
- Detect full and empty queue conditions
- Reuse freed positions through a circular queue

## Data structure
This program uses an array-based circular queue with a maximum capacity of five print jobs.

- **Enqueue:** add a job at the rear
- **Dequeue:** process and remove the job at the front
- **FIFO:** the first job added is the first job processed

## Compile and run
With GCC installed, run:

```bash
gcc -std=c11 -Wall -Wextra -pedantic prtrjob.exe-o prtrjob.exe
./prtrjob.exe
```

On Windows, run the generated executable as `prtrjob.exe`.

## Note
This is a simulation. It records print jobs as completed; it does not send documents to a physical printer.
