#include <iostream>
using namespace std;
#include <limits.h>

#define V 6

int minTime(int TimeList[], bool sptSet[]){
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
	if (sptSet[v] == false && TimeList[v] <= min)
	min = TimeList[v], min_index = v;
	
	return min_index;
}

void printDijkstra(int TimeList[])
{
	int sum=0;
	cout << "Vertex \t\t\t Time from Source" << endl;
	for (int i = 0; i < V; i++){
		cout << i << "      -------->     " << TimeList[i] << endl;
		sum+=TimeList[i];
	}
	cout<<"Average Time="<<float(sum)/5<<endl;
	cout<<endl;
}


void dijkstra(int graph[V][V], int src)
{
	int TimeList[V];
	
	bool sptSet[V];
	for (int i = 0; i < V; i++)
	TimeList[i] = INT_MAX, sptSet[i] = false;
	TimeList[src] = 0;
	
	for (int count = 0; count < V - 1; count++) {
		int u = minTime(TimeList, sptSet);
		sptSet[u] = true;
		for (int v = 0; v < V; v++)
		if (!sptSet[v] && graph[u][v]
		&& TimeList[u] != INT_MAX
		&& TimeList[u] + graph[u][v] < TimeList[v])
		TimeList[v] = TimeList[u] + graph[u][v];
	}
	
	printDijkstra(TimeList);
}

int main()
{
	int graph[V][V] = { { 0, 10, 0, 0, 15, 5 },
	{ 10, 0, 10, 30, 0, 0 },
	{ 0, 10, 0, 12, 5, 0 },
	{ 0, 30, 12, 0, 0, 20 },
	{ 15, 0, 5, 0, 0, 0 },
	{ 5, 0, 0, 20, 0,0 } };
	
	dijkstra(graph, 0);
	dijkstra(graph, 1);
	dijkstra(graph, 2);
	dijkstra(graph, 3);
	dijkstra(graph, 4);
	dijkstra(graph, 5);
	
	return 0;
}