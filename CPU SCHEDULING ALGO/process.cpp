#define cpp
#ifdef cpp
//cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>

#include<cmath>
using namespace std;


class process;
class ganttChart{
    public:
    static vector<process> gantt;
};

vector<process> ganttChart::gantt;
queue<process> rrQueue;  // Add a queue for Round Robin



class process{
    private:
        int processID;
        int arrivalTime;
        int burstTime;
        int completedTime;
        int turnAroundTime;
        int waitingTime;
        int futureArrivalTime;
        int remainingTime;


    public:
        process(int processID,int arrivalTime,int burstTime):processID(processID),arrivalTime(arrivalTime),burstTime(burstTime){
            //cout<<"Process Created\n";

            //ganttChart::gantt.push_back(*this);
        }
        process(const process & p):process(p.processID,p.arrivalTime,p.burstTime){}
        int getPID()const{
            return this->processID;
        }
        int getarrivalTime()const{
            return this->arrivalTime;
        }
        int getburstTime()const{
            return this->burstTime;
        }
        int getcompletedTime()const{
            return this->completedTime;
        }
        int getturnAroundTime()const{
            return this->turnAroundTime;
        }
        int getwaitingTime()const{
            return this->waitingTime;
        }
        int getfutureArrivalTime()const{
            return this->futureArrivalTime;
        }
        void setfutureArrivalTime(int time){
            this->futureArrivalTime=time;
        }
        void setcompletedTime(int time){
            this->completedTime=time;
        }
        void setturnAroundTime(int time){
            this->turnAroundTime=time;
        }
        void setwaitingTime(int time){
            this->waitingTime=time;
        }
        int getremainingTime() const {
        return this->remainingTime;
    }

    void setremainingTime(int time) {
        this->remainingTime -= time;
    }
        bool isFinished() const {
        return remainingTime == 0;
    }
        };

void enterProcess(){
        bool runInput=true;
        while(runInput){
            int option;
            cout<<"Wanna Enter the process...then Enter 1 :  ";
            cin>>option;
            switch(option){
                case 1:
                    int pid,at,bt;
                    cout<<"PID: ";
                    cin>>pid;
                    cout<<"Arrival Time: ";
                    cin>>at;
                    cout<<"Burst Time: ";
                    cin>>bt;
                    ganttChart::gantt.push_back(process(pid,at,bt));
                    break;
                default:
                    runInput=false;

            }
        }
    }


void setTimeGantt(){
    int currentTime=ganttChart::gantt[0].getarrivalTime();
    for (auto &i : ganttChart::gantt)
    {
        if (currentTime<i.getarrivalTime()) currentTime=i.getarrivalTime();
        i.setfutureArrivalTime(currentTime);
        currentTime+=i.getburstTime();
        i.setcompletedTime(currentTime);
        i.setturnAroundTime(i.getcompletedTime()-i.getarrivalTime());
        i.setwaitingTime(i.getturnAroundTime()-i.getburstTime());

    }

}

// void setAllLeftBurstTime(int timeQuanta=0){
//     for (auto &i : ganttChart::gantt)
//         {
//             if(i.getleftBurstTime()==-1) i.setleftBurstTime(i.getburstTime());
//             else  i.setleftBurstTime(i.getleftBurstTime()-timeQuanta);
//         }
// }

// void showPreemptGantt(int index,int timeQuanta){
//     ganttChart::gantt[index].setleftBurstTime(timeQuanta);
//     cout<<ganttChart::gantt[index].getfutureArrivalTime()<<" p"<<ganttChart::gantt[index].getPID()<<" ";
//     ganttChart::gantt[index].setfutureArrivalTime(ganttChart::gantt[index].getfutureArrivalTime()+timeQuanta);
//     cout<<ganttChart::gantt[index].getfutureArrivalTime()<<";";
//     if (ganttChart::gantt[index].getleftBurstTime()==0) ganttChart::gantt[index].setcompletedTime(ganttChart::gantt[index].getfutureArrivalTime());
// }


void showGantt(){
        for (auto &i : ganttChart::gantt)
        {
            cout<<i.getfutureArrivalTime()<<" p"<<i.getPID()<<" "<<i.getcompletedTime()<<";";
        }
        cout<<endl;
    }

void showGanttChart(){
    int length=ganttChart::gantt.size();
    double avgTAT=0,avgWT=0;
    cout<<"ProcessID  Arrival Time  Burst Time  Completed Time  TurnAround Time  Waiting Time\n";
    for (auto &i : ganttChart::gantt)
    {
        avgTAT+=i.getturnAroundTime();
        avgWT+=i.getwaitingTime();
        cout<<i.getPID()<<"\t\t"<<i.getarrivalTime()<<"\t\t"<<i.getburstTime()<<"\t\t"<<i.getcompletedTime()<<"\t\t"<<i.getturnAroundTime()<<"\t\t"<<i.getwaitingTime()<<"\n";
    }
    cout<<"Average TurnAround Time: "<<(avgTAT/length)<<endl;
    cout<<"Average Waiting Time: "<<(avgWT/length)<<endl;

}

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
