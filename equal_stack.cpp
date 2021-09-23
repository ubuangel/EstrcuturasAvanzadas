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
	
	vector<int> h1;
	vector<int>h2;
	vector<int>h3;
	int tam1,tam2,tam3,i=0;
	cin>>tam1>>tam2>>tam3;
	int suma1=0,suma2=0,suma3=0;
	int a,b,c;
	
	while (i<tam1)
	{
		cin>>a;
		h1.push_back(a);
		suma1=suma1+a;
		i++;
	}
	
	i=0;
	while (i<tam2)
		{
			cin>>b;
			h2.push_back(b);
			suma2=suma2+b;
			i++;
		}
		
	i=0;
		while (i<tam3)
	{
		
		cin>>c;
			h3.push_back(c);
		
		suma3=suma3+c;
		i++;
	}
	
	
	if (suma1==suma2 && suma2==suma3)
	{
		
		cout<<suma1;	
	}else{
		
		
		if(suma1 < suma2 && suma1 < suma3){
 			
 			  h1.pop_back();
 			  suma1=suma1-h1[tam1-2];
 			  if(suma1==suma2 && suma2==suma3)
 			  	cout<<suma1<<" ";//return 
   		 }else{
      		  if(suma2 < suma1 && suma2 < suma3){
      		  	h2.pop_back();
      		  	suma2=suma2-h2[tam2-2];
 			  if(suma1==suma2 && suma2==suma3)
 			  	cout<<suma2<<" ";
       			 
       		 }else{
        		h3.pop_back();
      		  	suma3=suma3-h3[tam3-2];
 			  if(suma1==suma2 && suma2==suma3)
 			  	cout<<suma3<<" ";
        }
    }
//		escogemos el menor suma y sacamos un cilindro comparamos luego 
//		
//		sino escogemos el segundo y sacamos el cilindro y comparamos sino el tercero sacamos el cilindro y comparamos 
		
		//luego se repite todos con un cilindro menos 
	}
	
	
}
