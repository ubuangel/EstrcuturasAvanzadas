#include <iostream>
#include<vector> 
#include <algorithm>
#define input freopen("int.txt" ,"r" ,stdin)
#define output freopen("out.txt" ,"w", stdout)
using namespace std;
vector<string>graf(30);

int n;
int filas[]={1,1,0,-1,-1,-1,0,1};
int colum[]={0,1,1,1,0,-1,-1,-1};

int dfs(int f,int c){
	
	if (f<0 ||f>=n || c<0 ||c>=n)
	{
		return 0;
	}
	
	if (graf[f][c]=='0')
	{
		return 0;
	}
	
	graf[f][c]='0';
	
	for (int d = 0; d < 8; d += 1)
	{
		dfs(f+filas[d],c+colum[d]);
	}
	return 1;
	
	
}

int main(){
	
	
	input;
	int casos=0;

	
	while(cin>>n){
		
		for ( int i = 0; i < n; i += 1)
		{
			cin>>graf[i];
		}
		
		int cont=0;
		
		for ( int i = 0; i < n; i += 1)
		{
			for (int j = 0; j < n; j += 1)
			{
				if (graf[i][j]=='1')
				{
					dfs(i,j);
					cont++;
				}
			}
		}
		
		cout<<"Image number "<<++casos<<" contains "<<cont<<" war eagles."<<endl;
	}

	return 0;

}
