
#include "Scheduler.h"
#include <thread>
#include <bits/stdc++.h>
#include <chrono>

using namespace std;

bool Scheduler::addJob(int id, int interval, int frequency, function<void()> implementation) {
    Job job(id,interval,frequency,implementation);
    if(jobs.count(id)){                             // make sure the ids are unique
        cout<<"This id is already used"<<endl;
        return false;
    }
    time_t my_time = time(NULL);
    cout<<ctime(&my_time)<<" - Job with id "<<id<<" has been added"<<endl;
    currentJobs.push({time( NULL),id});
    jobs[id] = job;
    return true;
}

struct elem{               // struct for the thread vector elements
    thread th;
    int id;
    clock_t clock;
};

void Scheduler::checkJobs() {
    vector<elem> threads;
    while(!currentJobs.empty() && currentJobs.top().first<=time( NULL)){        // checking if the minimum time in the min-heap is less than the time of the system so this will be executed
        auto current = currentJobs.top();
        currentJobs.pop();
        if(!jobs.count(current.second)) continue;            // in case this job has been deleted
        clock_t t;                                             // save the start time of the current job in order to calculate the execution time later
        t = clock();
        threads.push_back({thread(jobs[current.second].func()),currentJobs.top().second,t});
        current.first = time( NULL)+jobs[current.second].getFrequency();    // add the periodic time of the job to the current system time in order to run it again later
        currentJobs.push(current);
    }
    for(int i = 0 ; i<threads.size() ; i++){               //  iterate through the running threads and join them
        threads[i].th.join();
        clock_t t;
        t = threads[i].clock;
        int id = threads[i].id;
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC;
        time_t my_time = time(NULL);
        cout<<ctime(&my_time)<<" - Job with id "<<id<<" has been executed and took "<< fixed<< time_taken << setprecision(5)<<" seconds"<<endl;
    }
}

bool Scheduler::killJob(int id) {
    if(!jobs.count(id)) return false;
    jobs.erase(id);
    return true;
}

void Scheduler::killAll() {
    jobs.clear();
    while(!currentJobs.empty()) currentJobs.pop();
}
