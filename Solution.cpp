
#include<bits/stdc++.h>
using namespace std;

class Queue { //Queue:FirstIn-FirsOut (2 ends)  ,  Stack:LastIn,FirstOut(1 end)
    stack<int> input, output; 
    //input          ouput           input          ouput
    /*
  top   ->  2        empty                            0--->dequeued() : FirstIn-FirsOut
            4                                         8
            8                                         4
firstIn ->  0                                         2              
    */
public:

    void enqueue(int x) 
    {
        input.push(x);
    }

    int dequeue() 
    {
        if(input.empty() && output.empty())
            return -1; //error
            
        if(output.empty())
            while(!input.empty()) //push everything from input to output.
            {
                output.push(input.top());
                input.pop();
            }
        
        int val=output.top();
        output.pop();
        return val;
    }
};


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Queue ob;

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            ob.enqueue(a);
        }
        else if(QueryType==2)
        {
            cout<<ob.dequeue()<<" ";
        }
        }
    cout<<endl;
    }
}