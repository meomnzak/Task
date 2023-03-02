#include <bits/stdc++.h>
#include "Job.h"
#include "Scheduler.h"
#include <time.h>

using namespace std;

int main() {
    Scheduler scheduler;

    time_t my_time = time(NULL);
    cout<<ctime(&my_time)<<" - The Scheduler has started"<<endl;

    scheduler.addJob(1, 10, 5, [&]() { sleep(1); }); // examples of using the scheduler
    scheduler.addJob(2, 10, 9, [&]() { vector<int> vec; for(int i = 0 ; i<2e8 ; i++){ vec.push_back(i); vec.pop_back(); }});
    scheduler.addJob(3, 10, 16, [&]() { vector<int> vec; for(int i = 0 ; i<3e7 ; i++){ vec.push_back(i); vec.pop_back(); }});

    while (true) {
        scheduler.checkJobs();
    }

    return 0;
}
