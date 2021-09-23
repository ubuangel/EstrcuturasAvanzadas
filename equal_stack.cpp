#include <vector>
#include <iostream>
#include <algorithm>
//#include<stack>
using namespace std;

//STDIN       Function
//-----       --------
//5 3 4       h1[] size n1 = 5, h2[] size n2 = 3, h3[] size n3 = 4  
//3 2 1 1 1   h1 = [3, 2, 1, 1, 1]
//4 3 2       h2 = [4, 3, 2]
//1 1 4 1     h3 = [1, 1, 4, 1]

//salida 5

int main(){
	
	
	
	int tam1,tam2,tam3;
	cin>>tam1>>tam2>>tam3;
	
	vector<int>h1;
	vector<int>h2;
	vector<int>h3;
	
	int sumaAl1=0,sumaAl2=0,sumaAl3=0;
	
	int a ,b,c;
	
	int i=0;
	while (i<tam1)
		{
		//cin>>h1[i];
		cin>>a;
		h1.push_back(a);
		sumaAl1=sumaAl1+a;
		i++;
		}
	
	i=0;
	while (i<tam2)
		{
			cin>>b;
			//cin>>h2[i];
			h2.push_back(b);
			sumaAl2=sumaAl2+b;
			i++;
		}
		
	i=0;
	while (i<tam3)
		{	
		cin>>c;
		//cin>>h3[i];
		h3.push_back(c);
		
		sumaAl3=sumaAl3+c;
		i++;
	}
	
	
	bool mismaaltura=false;
	
	
	
	if (sumaAl1==sumaAl2 && sumaAl2==sumaAl3)
	{
		
		mismaaltura=true;	
	}
	
	int ci1=0,ci2=0,ci3=0;//indice del cilindro a quitar
		
		while (!mismaaltura)
		{
			if (sumaAl1>=sumaAl2 && sumaAl1>= sumaAl3)
			{
				sumaAl1=sumaAl1-h1[ci1]	;
				ci1++;
			}else if (sumaAl2>=sumaAl1 && sumaAl2>= sumaAl3){
				
				sumaAl2=sumaAl2-h2[ci2];
				ci2++;
			}else if(sumaAl3>=sumaAl1 && sumaAl3>=sumaAl2){
				
				sumaAl3=sumaAl3-h3[ci3];
				ci3++;
			}
				
				if ((sumaAl1==sumaAl2 && sumaAl2==sumaAl3) || (sumaAl2==0 && sumaAl1==0 && sumaAl3==0) )
					{
						mismaaltura=true;
					}
				
			}
		
		
	
		
			cout<<sumaAl1;

}
