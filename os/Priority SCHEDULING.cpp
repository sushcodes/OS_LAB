/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
using namespace std;
#include <bits/stdc++.h>
class process
{
    public:
    public:
    int at;
    int bt;
    int pid;
    int priority;
    int ct;
    int tat;
    int wt;
    int remainingbt;
    bool used;
    
    void initialize(int pi,int a,int b,int pri)
    {
        at=a;
        bt=b;
        pid=pi;
        priority=pri;
        ct=tat=wt=-1;
        remainingbt=b;
        used=false;
    }
    
    void completed(int c) // when completed
    {
        // call this when you have ct;
        remainingbt=0;
        ct=c;
        tat=c-at; // 37-7
        wt=tat-bt;
        used=true;
        
    }
};

int main()
{
    int n;
    cin>>n;
    process Arr[n];
    // Turn Around Time = Completion Time - Arrival Time   
    //Waiting Time = Turn Around Time - Burst Time   
    for (int i=0;i<n;i++)
    {
        int a,b,pi,pri;
        cin>>pi;
        cin>>pri;
        cin>>a;
        cin>>b;
       
        Arr[i].initialize(pi,a,b,pri);
    }
    
int completed=0;
int currenttime=0;

int optional;
cout<<"PPRESS 1 FOR LOWER THE NUMBER HIGHER THE PRIORITY OTHERWISE PRESS 2"<<endl;
cin>>optional;

cout<<"PRINT 1 FOR PREMPTIVE AND 2 FOR NON PREMPTIVE"<<endl;
int choice;
cin>>choice;
int count10=1000;
// suppose higher the number,higher the priority
   while(completed!=n)
   {
       //cout<<"completed count"<<completed<<endl;
       
       
       
       int index=-1;
       
       int priority=-10;

       if (optional==1)
       priority=10000;

       for (int i=0;i<n;i++)
       {
           if (Arr[i].used==true || Arr[i].at>currenttime || Arr[i].remainingbt<=0 )
           continue;
           
           if (Arr[i].priority>priority && optional!=1)
           {
               index=i;
               priority=Arr[i].priority;
           }
           else if (Arr[i].priority<priority && optional==1)
           {
            index=i;
            priority=Arr[i].priority;
           }
           else if (Arr[i].priority==priority)
           {
               
               if (Arr[i].at<Arr[index].at)
               {
                   index=i;
               }
               else if (Arr[i].at==Arr[index].at)
               {
                   if (Arr[i].pid<Arr[index].pid)
                   index=i;
               }
           }
           
       
       }
       
       if (index==-1)
       {
           cout<<"COULDNT EXECUTE"<<endl;
           currenttime++;
           continue;
       }
       
       
       if (choice==1) //premptive
       {
           Arr[index].remainingbt-=1;
           currenttime++;
           if (Arr[index].remainingbt==0)
           {
               completed++;
               Arr[index].completed(currenttime);
           }
           continue;
       }
       else  // non premptive
       {
          currenttime+=Arr[index].bt;
          Arr[index].completed(currenttime);
          completed++;
          cout<<Arr[index].pid<<" has been executed"<<endl;
       }
       
   }
   
   float totalwt=0;
   float totaltat=0;
   for (int i=0;i<n;i++)
   {
       totaltat+=Arr[i].tat;
       cout<<Arr[i].pid<<" "<<Arr[i].wt<<endl;
       cout<<Arr[i].pid<<" "<<Arr[i].ct<<endl;
       totalwt+=Arr[i].wt;
   }
   cout<<totalwt/n<<" "<<totaltat/n<<endl;

    return 0;
}
