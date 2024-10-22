#include <iostream>
#include <list>
#include "rr.h"
#include "task.h"
#include "CPU.h"

void calculateAverages(list<Task> processInfo);
const int QUANTUM = 2;

void schedule(list<Task> &taskList){
	cout << "SCHEDULING TASK FOR RR" << endl;
	list<Task> completedTaskInfo;
	int currentTime = 0;
	list<Task>::iterator i = taskList.begin();
	while(!taskList.empty()) {
		if (!i->hasStarted){
			i->responseTime = currentTime;
			i->hasStarted = true;
		}
		if (i == taskList.end())
			i = taskList.begin();
		run(*i, min(QUANTUM, i->burst));
		currentTime += min(QUANTUM, i->burst); 
		i->burst -= min(QUANTUM, i->burst);
		for (list<Task>::iterator it = taskList.begin(); it != taskList.end(); ++it) {
        // If the iterator is not pointing to the currentTask
        if (it != i) {
            it->waitingTime += min(QUANTUM, i->burst); // Increment the waiting time
			}
		}
		if (i->burst <= 0){
			i->completionTime = currentTime - 0;
			completedTaskInfo.push_back(*i);
			i = taskList.erase(i);
		}
		else
			++i;
	}
	calculateAverages(completedTaskInfo);

}
void calculateAverages(list<Task> processInfo){
	int totalWT = 0, totalTAT = 0, totalRT = 0;
	
	for (Task process : processInfo){
		totalWT += process.waitingTime;
		totalTAT += process.completionTime;
		totalRT += process.responseTime;
	}

	cout << "Average Waiting Time: " << (float)totalWT / processInfo.size() <<  "milliseconds" << endl;
    cout << "Average Turnaround Time: " << (float)totalTAT / processInfo.size() <<  "milliseconds" << endl;
    cout << "Average Response Time: " << (float)totalRT / processInfo.size() <<  "milliseconds" << endl;
}


