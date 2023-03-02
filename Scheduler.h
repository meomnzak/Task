

#ifndef TASK_SCHEDULER_H
#define TASK_SCHEDULER_H
#include "Job.h"
#include <bits/stdc++.h>
#include <chrono>

using namespace std;

class Scheduler {
private:
    map<int,Job> jobs;         // a map from id to the job object
    priority_queue<pair<time_t,int>,vector<pair<time_t,int>>,greater<pair<time_t,int>>> currentJobs;  // min-heap to store the jobs
public:
    bool addJob(int id, int interval, int frequency, function<void()> implementation);
    void checkJobs();
    bool killJob(int id);
    void killAll();
};


#endif
