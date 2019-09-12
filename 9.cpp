/*
9.  Design a DFA for accepting L = {w1abw2 : w1 belongs to {a,b}^* , w2 belongs to {a,b}^*}

*/
#include<iostream>
using namespace std;

typedef struct Node{
        string name;
        bool isFinal = 0;
        struct Node *aInput  = NULL;
        struct Node *bInput = NULL;
    } State;

class FA {

    State q1,q2,q3; 
    public:
    FA(){
        q1.name = "q1";
        q2.name = "q2";
        q3.name = "q3";
       
      

        q3.isFinal = 1;
        
        //q1 state
        q1.aInput = &q2;
        q1.bInput = &q1;
       
        //q2 state
        q2.aInput = &q2;
        q2.bInput = &q3;
        //q3 state
        q3.aInput = &q3;
        q3.bInput = &q3;
        

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
    FA fsm;
    string ip; cout<<"Enter String: "; cin>>ip;
    bool accepted = fsm.determine(ip);
    if(accepted) cout<<"accepted";
    else cout<<"Not accepted";
    return 0;
}