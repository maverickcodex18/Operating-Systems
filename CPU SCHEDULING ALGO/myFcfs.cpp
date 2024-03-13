#define cpp
#ifdef cpp
//cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<cmath>
#include"process.cpp"
using namespace std;


void fcfs(){
    int lengthOfGantt=ganttChart::gantt.size();
    for (int i = 0; i < lengthOfGantt; i++)
    {
        int smallIndex=i;
        for (int j= i+1; j < lengthOfGantt; j++)
        {
            if(ganttChart::gantt[i].getarrivalTime()>ganttChart::gantt[j].getarrivalTime()) smallIndex=j;
            break;
        }
        swap(ganttChart::gantt[i],ganttChart::gantt[smallIndex]);

    }

}


// void setTimeGantt(){
//     int currentTime=ganttChart::gantt[0].getarrivalTime();
//     for (auto &i : ganttChart::gantt)
//     {
//         i.setfutureArrivalTime(currentTime);
//         currentTime+=i.getburstTime();
//         i.setcompletedTime(currentTime);
//         i.setturnAroundTime(i.getcompletedTime()-i.getarrivalTime());
//         i.setwaitingTime(i.getturnAroundTime()-i.getburstTime());

//     }

// }


// int main(){
//     enterProcess();
//     fcfs();
//     setTimeGantt();
//     showGantt();
//     showGanttChart();
//     return 0;
// }

#else
//c

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main() {

    return 0;
}
#endif
