<img width="1920" height="1080" alt="Screenshot (148)" src="https://github.com/user-attachments/assets/7ba56d76-aa4a-4340-9a6d-5ee92ffc9b86" />CPU Scheduling is the process by which an operating system decides which process should be given the CPU when multiple processes are ready for execution.
The main purpose of CPU scheduling is to use the CPU efficiently while ensuring that all processes get a fair chance to execute. By properly scheduling processes, the system can reduce waiting time, improve response time, and increase overall performance.
CPU scheduling can be preemptive, where a running process can be interrupted, or non-preemptive, where a process runs until it completes. Common CPU scheduling algorithms include FCFS, SJF, Priority Scheduling, and Round Robin.<img width="1920" height="1080" alt="Screenshot (149)" src="https://github.com/user-attachments/assets/79cf1729-048d-4463-8e25-c8890f563015" />


In simple terms, CPU scheduling acts like a traffic controller, deciding which process moves forward and when, so the system runs smoothly and efficiently.
Why CPU Scheduling is Needed?
>Only one process can use the CPU at a time
>Many processes may be in the ready state
>Scheduling helps
>Improve CPU utilization
>Reduce waiting time
>Increase system efficiency
>Objectives of CPU Scheduling
>Maximize CPU utilization
>Minimize waiting time
>Minimize turnaround time
>Provide fairness to all processes
>Improve system responsiveness
>Types of CPU Scheduling
>Non-Preemptive Scheduling
Once a process gets the CPU, it runs until completion
Examples:
>>FCFS (First Come First Serve)
>>SJF (Shortest Job First)
>>Priority (Non-preemptive)
>>Preemptive Scheduling
>>CPU can be taken away from a running process
Examples:
>>Round Robin
>>Preemptive Priority
>>Shortest Remaining Time First (SRTF)
>>Common CPU Scheduling Algorithms
FCFS – Processes execute in arrival order
SJF – Process with shortest burst time executes first
Priority – Highest priority process executes first
Round Robin – Each process gets CPU for a fixed time quantum
Scheduling Criteria
CPU Utilization
Throughput
Waiting Time
Turnaround Time
Response Time




CPU scheduling plays a vital role in operating systems by ensuring that CPU time is shared efficiently and fairly among all processes, leading to better system performance.![Uploading Screenshot (149).png…]()

