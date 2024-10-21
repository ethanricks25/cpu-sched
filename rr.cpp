#include <iostream>
#include <list>
#include "rr.h"
#include "task.h"
#include "CPU.h"

const int QUANTUM = 2;

void schedule(list<Task> &taskList){
	cout << "SCHEDULING TASK FOR RR" << endl;
	list<Task>::iterator i = taskList.begin();
	while(!taskList.empty()) {
		if (i == taskList.end())
			i = taskList.begin();
		run(*i, min(QUANTUM, i->burst));
		i->burst -= min(QUANTUM, i->burst);
		if (i->burst <= 0)
			i = taskList.erase(i);
		else
			++i;
	}
}


