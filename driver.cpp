#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <sstream>
#include <pthread.h>
#include <stdio.h>
#include "task.h"
#include "fcfs.h"
#include "rr.h"
#include "sjf.h"
#include "srtf.h"
#define NUM_THREADS 5

using namespace std;

int nextTID = 0;
void readTaskFile(const string filename, list<Task> &taskList);

void *runner(void *param);
	
int main(int argc, char *argv[]) {
	cout << "BEGINNING PROGRAM " << endl;
	int i, scope;

	if (argc != 2) {
		cerr << "Invalid args: " << argv[0] << "<tasks file" << endl;
		return 2;
	}
	list<Task> taskList;

	readTaskFile(argv[1], taskList);
	pthread_t tid[NUM_THREADS];
	pthread_attr_t attr;
	 
	/* get the default attributes */
	pthread_attr_init(&attr);
	 
	/* first inquire on the current scope */
	if (pthread_attr_getscope(&attr, &scope) != 0)
	    fprintf(stderr, "Unable to get scheduling scope\n");
	else {
	    if (scope == PTHREAD_SCOPE_PROCESS)
	     printf("PTHREAD_SCOPE_PROCESS");
	    else if (scope == PTHREAD_SCOPE_SYSTEM)
	     printf("PTHREAD_SCOPE_SYSTEM");
	    else
	     fprintf(stderr, "Illegal scope value.\n");
	}
	/* set the scheduling algorithm to PCS or SCS */
	pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
	 
	/* create the threads */
	for (i = 0; i < NUM_THREADS; i++)
	     pthread_create(&tid[i],&attr,runner,NULL);
	 
	  /* now join on each thread */
	  for (i = 0; i < NUM_THREADS; i++)
	     pthread_join(tid[i], NULL);
	



	return 0;
}

void readTaskFile(const string filename, list<Task> &taskList){
	ifstream file(filename);
	if (!file.is_open()){
		cerr << "Error: Could not open file " << filename << endl;
	exit(1);
	}
	cout << "READING TASKS" << endl;

	string taskName, line;
	int priority, burst;
	char delim = ',';

	while (getline(file, line)) {
		stringstream ss(line);
		
		if (getline(ss, taskName, delim) && 
				ss >> priority >> delim &&
				ss >> burst) {
				int tid = __sync_fetch_and_add(&nextTID, 1);
				Task newTask = Task(taskName, priority, burst, tid);

				cout << "NEW TASK = TASKNAME: " << taskName << ", PRIORITY: " << priority << ", BURST: " << burst << endl;
				taskList.push_back(newTask);
		}
	}

	file.close();
}

void *runner(void *param)
{
	if (param != NULL) {

		list<Task>* taskList = (list<Task>*)param;
		schedule(*taskList);
	} else {
		cout << "A thread is running..." << endl;
	}
  pthread_exit(0);
}

