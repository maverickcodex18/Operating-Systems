
#include"sjf.cpp"

void roundRobin(int timeSlice) {
    // Initialize variables
    int currentTime = ganttChart::gantt[0].getarrivalTime();
    rrQueue.push(ganttChart::gantt[0]);  // Push the first process to the queue

    while (!rrQueue.empty()) {
        process currentProcess = rrQueue.front();
        rrQueue.pop();

        // Execute the process for the time slice or until it's finished
        int executionTime = min(timeSlice, currentProcess.getburstTime());
        currentTime += executionTime;

        // Update the remaining time and completed time
        currentProcess.setremainingTime(executionTime);
        currentProcess.setcompletedTime(currentTime);

        // Update turn around time and waiting time
        currentProcess.setturnAroundTime(currentProcess.getcompletedTime() - currentProcess.getarrivalTime());
        currentProcess.setwaitingTime(currentProcess.getturnAroundTime() - currentProcess.getburstTime());

        // Add the process back to the queue if it's not finished
        if (!currentProcess.isFinished()) {
            currentProcess.setfutureArrivalTime(currentTime);
            rrQueue.push(currentProcess);
        }
    }
}
// Rest of the code for "process.cpp" (setTimeGantt, showGantt, showGanttChart, etc.) remains the same


int main() {
    // Call your functions here
    enterProcess();
    roundRobin(1)   ;
    setTimeGantt();
    showGanttChart();
    return 0;
}
