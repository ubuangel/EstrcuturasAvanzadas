//determinar el número máximo de subgrafos conectados de un gráfico dado.


#include <iostream>
#include <string.h>
#include <vector>
#include <cstring>
#include "stdio.h"
using namespace std;
#define MAX 30 

vector <int> grafo[MAX];
bool visitado[MAX];

void dfs(int u)
{
	visitado[u] = true;
	for(int v=0; v < grafo[u].size(); v++){
		if(visitado[grafo[u][v]] == false)
			dfs(grafo[u][v]);
	}
}

void dfs_visitar(int V)
{
	int num = 0;

	for(int i=1; i <= V; i++){
		if(visitado[i] == false){
			num++;
			dfs(i);
		}
	}

	//printf("%d\n", num);
	cout<<num<<"\n";
}

int main()
{
	int i, V;
	char c, a, b;
	char input[10];
		
	//scanf("%d", &i);	
	cin>>i;
	while(i--)
	{
		memset(visitado, false, sizeof(visitado));
		cin >> c;
		V = c - '0' - 16;
		while(getchar() != '\n');
		
		
		while(gets(input) && sscanf(input, "%c%c", &a, &b) == 2)
		{
			int u, v;
			u = a - '0' - 16;
			v = b - '0' - 16;			
			grafo[u].push_back(v);
			grafo[v].push_back(u);
		}
		dfs_visitar(V);
		if(i)	
			//printf("\n");
			cout<<"\n";
		for(int i=0; i<MAX; i++)
			grafo[i].clear();
	}

	return 0;
}
