
#include<iostream>

using namespace std;

class Process{
  private:
   int pn;
   int at;
   int bt;
   int ct;
   int wt;
   int tat;
   int fat;

  public:
   Process(){

   }

   Process(int pn, int at, int bt){
     this->pn = pn;
     this->at = at;
     this->bt = bt;
   }

   int get_pn(){
     return pn;
   }

   int get_at(){
      return at;
   }

   int get_bt(){
      return bt;
   }

   void set_fat(int t){
       fat = t;
   }

   int get_fat(){
      return fat;
   }

   int get_ct(){
      return ct;
   }

   void set_ct(int t){
       ct = t;
   }

   void set_tat(int t){
       tat = t;
   }

   int get_tat(){
      return tat;
   }

   void set_wt(int t){
     wt = t;
   }

   int get_wt(){
     return wt;
   }

};

void sort_processes_by_at(Process *p, int size);
void schedule_process(Process *p,int size);
void gantt_chart(Process *p, int size);
void display(Process *p, int size);
void average(Process *p, int size);

int main(){
  int n;
  cout<<"Enter number of process : ";
  cin>>n;

  Process *p = new Process[n];

  for(int i=0; i<n; i++){
    int pn, at, bt;
    cout<<"enter process number : ";
    cin>>pn;

    cout<<"enter arrival time : ";
    cin>>at;

    cout<<"enter cpu burst time : ";
    cin>>bt;

    p[i]= Process(pn, at, bt);
  }

  sort_processes_by_at(p, n);

  schedule_process(p,n);

  gantt_chart(p,n);

  display(p,n);

  average(p,n);

  delete []p;

  return 0;
}

void sort_processes_by_at(Process *p, int size){
 int i,j;
 for( i=0; i<size; i++){
    for(j= i+1; j<size; j++){
        if(p[i].get_at() > p[j].get_at()){
            Process temp = p[i];
            p[i] = p[j];
            p[j] = temp;
        }
    }
 }
}

void schedule_process(Process *p,int size){
    int i=0;
    p[0].set_fat( p[0].get_at());

    for(i=0; i<size; i++){
       p[i].set_ct( p[i].get_fat() + p[i].get_bt() ) ;

       p[i+1].set_fat( p[i].get_ct() );

       if( p[i+1].get_fat() < p[i+1].get_at()){
           p[i+1].set_fat( p[i+1].get_at());
       }

       p[i].set_tat( p[i].get_ct() - p[i].get_at());
       p[i].set_wt( p[i].get_tat() - p[i].get_bt() );
    }

}

void gantt_chart(Process *p, int size){
   cout<<endl;
   cout<<p[0].get_at()<<" ";

   for(int i=0; i<size; i++){
     cout<<"p"<<p[i].get_pn()<<" ";
     cout<<p[i].get_ct()<<" ";
   }

   cout<<endl;
}

void display(Process *p, int size){

    cout<<endl;

    cout<<"Process  "<<"Arrival Time  "<<"Burst Time  "<<"Completion Time  "<<" Turn Around Time  " <<"Waiting Time"<<endl;

    for(int i= 0; i<size; i++){
        cout<<p[i].get_pn()<<"\t\t";
        cout<<p[i].get_at()<<"\t\t";
        cout<<p[i].get_bt()<<"\t\t";
        cout<<p[i].get_ct()<<"\t\t";
        cout<<p[i].get_tat()<<"\t\t";
        cout<<p[i].get_wt();
        cout<<endl;
    }

    cout<<endl;
}

void average(Process *p, int size){
 int twt=0, ttat=0;
 float awt, atat;

 for(int i =0; i<size; i++){
    twt = twt + p[i].get_wt();
    ttat = ttat + p[i].get_tat();

 }

 awt = (twt*1.0)/size;
 atat = (ttat * 1.0)/size;

 cout<<endl<<"Average waiting time = "<<awt<<endl;
 cout<<endl<<"Average Turn Around Time = " <<atat<<endl;
}
