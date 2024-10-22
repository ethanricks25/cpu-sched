#ifndef TASK_H
#define TASK_H

#include <string>

using namespace std;

class Task {
	public:
		string name;
		int priority;
		int tid;
		int burst;
		bool hasStarted;

		int completionTime;
		int waitingTime;      // Waiting time
		int turnaroundTime;   // Turnaround time
		int responseTime;

		Task(string taskName, int taskPriority, int taskBurst, int newTid){
			name = taskName;
			priority = taskPriority;
			burst = taskBurst;
			hasStarted = false;
			tid = newTid;
		}

};

#endif
