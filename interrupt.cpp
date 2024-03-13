#define cpp
#ifdef cpp
//cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<cmath>
#include<utility>   //pair
using namespace std;

class formInterrupt{
    
    //interrupt vector
    //2d vector
    private:
    //use pair
        vector<pair<int*,string>> interrupt;  //int*=memory address of interrupt , string= state of processor

    public:
        formInterrupt(){
            //creating NON MASKABLE INTERRUPTS
            //EXAMPLE: INTEL PROCESSOR
            //use make_pair
            //replace nullptr with ADDRESS OF ERRORS
            interrupt.push_back(std::make_pair(nullptr, "divide error"));
            interrupt.push_back(std::make_pair(nullptr, "debug exception"));
            interrupt.push_back(std::make_pair(nullptr, "null interrupt"));
            interrupt.push_back(std::make_pair(nullptr, "breakpoint"));
            interrupt.push_back(std::make_pair(nullptr, "INTO-detected overflow"));
            interrupt.push_back(std::make_pair(nullptr, "bound range exception"));
            interrupt.push_back(std::make_pair(nullptr, "invalid opcode"));
            interrupt.push_back(std::make_pair(nullptr, "device not available"));
            interrupt.push_back(std::make_pair(nullptr, "double fault"));
            interrupt.push_back(std::make_pair(nullptr, "coprocessor segment overrun (reserved)"));
            interrupt.push_back(std::make_pair(nullptr, "invalid task state segment"));
            interrupt.push_back(std::make_pair(nullptr, "segment not present"));
            interrupt.push_back(std::make_pair(nullptr, "stack fault"));
            interrupt.push_back(std::make_pair(nullptr, "general protection"));
            interrupt.push_back(std::make_pair(nullptr, "page fault"));
            interrupt.push_back(std::make_pair(nullptr, "(Intel reserved, do not use)"));
            interrupt.push_back(std::make_pair(nullptr, "floating-point error"));
            interrupt.push_back(std::make_pair(nullptr, "alignment check"));
            interrupt.push_back(std::make_pair(nullptr, "machine check"));
        }

        void addInterupt(int *addressOfInterruptHeader,string stateOfProcessor){

            //MASKABLE INTERRUPT
            //CAN BE TURNED OFF WHEN CPU EXECUTING CRITICAL PROGRAMS
            interrupt.push_back(std::make_pair(addressOfInterruptHeader, stateOfProcessor));
        }

        void turnOffMaskableInterrupt(){
            //code to turn off MASKABLE INTERRUPT WHEN CPU IS EXECUTING CRITICAL PROGRAMS
            //maskable interrupt starts from INDEX 32
        }
};

int main() {
    
    formInterrupt interrupt();
    return 0;
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