/*
Design a DFA for accepting L = {ab^(n)a^(m) : n >= 2 , m >= 3}
*/
#include<iostream>
using namespace std;

typedef struct Node{
        string name;
        bool isFinal = 0;
        struct Node *aInput  = NULL;
        struct Node *bInput = NULL;
    } State;

class evenaOddb {

    State q1,q2,q3,q4,q5,q6,q7,q8; 
    //q8 is trap state
    //inital state is q1
    //final state is q7
    public:
    evenaOddb(){
        q1.name = "q1";
        q2.name = "q2";
        q3.name = "q3";
        q4.name = "q4";
        q5.name = "q5";
        q6.name = "q6";
        q7.name = "q7";
        q8.name = "q8";

      

        q7.isFinal = 1;
        
        //q1 state
        q1.aInput = &q2;
        q1.bInput = &q8;
       
        //q2 state
        q2.aInput = &q8;
        q2.bInput = &q3;
        //q3 state
        q3.aInput = &q8;
        q3.bInput = &q4;
        //q4 state
        q4.aInput = &q5;
        q4.bInput = &q4;
        //q5 state
        q5.aInput = &q6;
        q5.bInput = &q8;
        
        //q6 state
        q6.aInput = &q7;
        q6.bInput = &q8;
        //q7 state
        q7.aInput = &q7;
        q7.bInput = &q8;
        //q8 state
        q8.aInput = &q8;
        q8.bInput = &q8;
   

    }
    //returns whether the string is in final state
    //Along with that it prints the transitions
    bool determine(string inputString) {
        State *presentState = &q1;
        cout<<presentState->name;
        for(char c:inputString){
            if(c == 'a'){
                presentState = presentState->aInput;
                cout<<"-->"<<presentState->name;
            }else{
                presentState = presentState->bInput;
                cout<<"-->"<<presentState->name;
            }
        }
        cout<<'\n';
        return presentState->isFinal;
    }

};


int main(){
    evenaOddb fsm;
    string ip; cout<<"Enter String: "; cin>>ip;
    bool accepted = fsm.determine(ip);
    if(accepted) cout<<"accepted";
    else cout<<"Not accepted";
    return 0;
}