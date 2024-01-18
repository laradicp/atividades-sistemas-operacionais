# Operational Systems class projects

This repository contains projects developed for the Operational Systems (OS) class in the Computer Engineering undergraduate course at the Universidade Federal da Paraíba (UFPB).

## Page replacement

This project implements the following page replacement algorithms:

- First in, first out (FIFO);
- Least recently used (LRU);
- Optimal page replacement (OTM).

### Input file format

\<number of page frames\>\
\<1st page reference\>\
...\
\<nth page reference\>

### Output format

\<algorithm\> \<number of page faults\>

## Scheduler

This project implements different scheduling algorithms for managing the execution of jobs in an OS:

- First come, first serve (FCFS);
- Round-robin (RR);
- Shortest job first (SJF).

### Input file format

\<arrival time\> \<duration\>

### Output format
\<algorithm\> \<average completion time\> \<average response time\> \<average waiting time\>
