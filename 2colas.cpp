//Cola usando dos pilas


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Ingresar numero de consulta  */ 
    stack<int> s1, s2;
    int numero_operaciones;
    cin>>numero_operaciones;
    int Q_operacion, x;
    
    for(int i=0; i<numero_operaciones; i++){
        cin>>Q_operacion;
        if(Q_operacion == 1){
            cin>>x;
            s1.push(x);
        }
        if(Q_operacion == 2){
            if(!s2.empty()){
                s2.pop();
            }
            else{
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
                s2.pop();
            }
        }
        if(Q_operacion == 3){

            if(!s2.empty()){
            cout<<s2.top()<<endl;
            }
            else{
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
                cout<<s2.top()<<endl;
            }
        }
    }
    
    return 0;
}
