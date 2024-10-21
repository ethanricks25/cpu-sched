#ifndef TASK_H
#define TASK_H

#include <string>

using namespace std;

class Task {
	public:
		string name;
		int priority;
		int burst;

		Task(string taskName, int taskPriority, int taskBurst){
			name = taskName;
			priority = taskPriority;
			burst = taskBurst;
		}

};

#endif
