/*
L = { w : Na(w) mod 3 > Nb(w) mod 3}
#Any number mod 3 = {0,1,2}
There are 9 states. q0,q1,q2,q3,q4,q5,q6,q7,q8
    Na(w)%3     Nb(w)%3
q0  0               0
q1  0               1
q2  0               2
q3  1               0  => final state
q4  1               1
q5  1               2
q6  2               0  =>final state
q7  2               1  =>final state
q8  2               2  

*/
#include<iostream>
using namespace std;

typedef struct Node{
        string name;
        bool isFinal = 0;
        struct Node *aInput  = NULL;
        struct Node *bInput = NULL;
    } State;

class aGreaterThanb {

    State q0,q1,q2,q3,q4,q5,q6,q7,q8;

    public:
    aGreaterThanb(){
        q0.name = "q0";
        q1.name = "q1";
        q2.name = "q2";
        q3.name = "q3";
        q4.name = "q4";
        q5.name = "q5";
        q6.name = "q6";
        q7.name = "q7";
        q8.name = "q8";

        q3.isFinal = 1;
        q6.isFinal = 1;
        q7.isFinal = 1;
        
        //q0 state
        q0.aInput = &q3;
        q0.bInput = &q1;

        //q1 state
        q1.aInput = &q4;
        q1.bInput = &q2;
        //q2 state
        q2.aInput = &q5;
        q2.bInput = &q0;
        //q3 state
        q3.aInput = &q6;
        q3.bInput = &q4;
        //q4 state
        q4.aInput = &q7;
        q4.bInput = &q5;
        //q5 state
        q5.aInput = &q8;
        q5.bInput = &q3;
        
        //q6 state
        q6.aInput = &q0;
        q6.bInput = &q7;
        //q7 state
        q7.aInput = &q1;
        q7.bInput = &q8;
        //q8 state
        q8.aInput = &q2;
        q8.bInput = &q6;
     
    }
    //returns whether the string is in final state
    //Along with that it prints the transitions
    bool determine(string inputString) {
        State *presentState = &q0;
        cout<<presentState->name;
        int numberOfa = 0,numberOfb = 0;
        for(char c:inputString){
            if(c == 'a'){
                presentState = presentState->aInput;
                cout<<"-->"<<presentState->name;
                numberOfa ++;
            }else{
                presentState = presentState->bInput;
                cout<<"-->"<<presentState->name;
                numberOfb ++;
            }
        }
        cout<<'\n';

        numberOfa %= 3;
        numberOfb %= 3;
        cout<<"Na(w) mod 3: "<<numberOfa<<'\n';
        cout<<"Nb(w) mod 3: "<<numberOfb<<'\n';
        return presentState->isFinal;
    }

};


int main(){
    aGreaterThanb fsm;
    string ip; cout<<"Enter input: ";cin>>ip; 
    bool accepted = fsm.determine(ip);
    if(accepted) cout<<"accepted";
    else cout<<"Not accepted";
    return 0;
}