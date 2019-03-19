#include <queue>
#include <fstream>
#include <iostream>
#include <map>
#include <utility>

using namespace std;

const int MAX_TIME = 500,
      AT_ONCE = 5,
      QUEUE_SIZE = 20,
      ARRAY_SIZE = 10,
      HOW_OFTEN = 25;

struct process 
{
    string ProcessName;
    pair <char, int> History[10];
    int Priority,
        ProcessID,
        ArrivalTime,
        Sub,
        CPUTimer,
        IOTimer,
        CPUTotal,
        ITotal,
        OTotal,
        CPUCount,
        ICount,
        OCount;
};
struct processPQ {process *p;};

int main()
{
    queue<process> entry;
     priority_queue<process> ready,
        input,
        output;
    process processes[20];
    process tempP;
    process *Active,
            *IActive,
            *OActive;

    string name;
    int i = 0,
        j = 0;
    pair <char, int> history;
    int timer = 0;

    // read the input file

    ifstream data ("data4.txt");

    // create processes and store in Entry queue

    while (!data.eof())
    {
        data >> tempP.ProcessName >> tempP.Priority >> tempP.ArrivalTime;

        for (i = 0; i < 10; i++)
        {
            data >> history.first >> history.second;
            tempP.History[i] = history;
        }
        
        processes[j] = tempP;

        entry.push(processes[j]);

        j++;
    }

    

    // initialize
    
    // while timer < MAX_TIME or there are no processes left
    //                                  (all queues empty)
    while (timer < MAX_TIME || (entry.empty() && ready.empty()
                && input.empty() && output.empty()
                && !Active && !IActive && !OActive))
    {
        //      if number of processes < AT_ONCE
        if (entry.size() + ready.size() + input.size() + output.size() < AT_ONCE)
        {
            //          look in Entry if arrival time is reached
            if (entry.front().ArrivalTime <= timer)
            {
                ready.push(entry.front());
                entry.pop();
            }
        }

        //      if no Active process
        if (!Active)
        {
            //          look in Ready queue
            Active = ready.top();
        }

        //          if still no Active process
        if (!Active)
            continue;

        //      if Active process
        if (Active)
        {
            //          look in History for I/O burst
            //          move to Input/Output queue
            //          look in History for terminator
            //          find ("N" 0)
        }

        //      if no IActive process
        if (!IActive)
        {
            //          look in Input queue
            if (!input.empty())
            {
                IActive = input.top();
            }
        } 
           
        //      if IActive
        if (IActive)
        {
            //          look for end of burst
            //          move to ready queue
        }

        //      if no OActive process
        if (!OActive)
        {
            //          look in Output queue
            if(!output.empty())
            {
                OActive = output.top();
            }
        }
    
        //      if OActive process
        if (OActive)
        {
            //          look for end of burst
            //          move to Ready queue
        }

        timer++;
    }

    // print summary data

    return 0;
}
