
/*https://github.com/BlakeBrown/HackerRank-Solutions/blob/master/Algorithms/Implementation/Equal%20Stacks.cpp*/
#include "bits/stdc++.h"
using namespace std;


int main(){
	
    int n1;
    int n2;
    int n3;
    cin >> n1 >> n2 >> n3;
    int h1 = 0, h2 = 0, h3 = 0; // alturas de las 3 pilas
    vector<int> torre1(n1);
    for(int i = 0; i < n1; i++){
       cin>>torre1[i];
       h1 += torre1[i];
    }
    vector<int> torre2(n2);
    for(int i = 0; i < n2; i++){
       cin>>torre2[i];
       h2 += torre2[i];
    }
    vector<int> torre3(n3);
    for(int i = 0; i < n3; i++){
       cin>>torre3[i];
       h3 += torre3[i];
    }
    //Usa un enfoque codicioso, siempre retire los cilindros de la torre más alta hasta que todas las torres
    //tener la misma altura.
    bool mismaAltura = false;
    if(h1 == h2 && h2 == h3) {
        mismaAltura = true;
    }
    int r1 = 0, r2 = 0, r3 = 0; // Almacene los índices de qué cilindro quitar
    while(!mismaAltura) {
        if(h1 >= h2 && h1 >= h3) {
            h1 -= torre1[r1];
            r1++;
        } else if(h2 >= h1 && h2 >= h3) {
            h2 -= torre2[r2];
            r2++;
        } else if(h3 >= h1 && h3 >= h2) {
            h3 -= torre3[r3];
            r3++;
        }
        if((h1 == h2 && h2 == h3) || (h1 == 0 && h2 == 0 && h3 == 0)) {
            mismaAltura = true;
        }
    }
    cout<<h1;
    return 0;
}
