#include <cstring>
#include <iostream>
using namespace std;

#define INF 9999999

#define V 6     // number of vertices in graph

//Graph in 2D array
int G[V][V] = {
	{0, 3, 0, 0, 0, 1},
	{3, 0, 2, 1, 10, 0},
	{0, 2, 0, 3, 0, 5},
	{0, 1, 3, 0, 5, 0},
	{0, 10, 0, 5, 0, 4},
	{1, 0, 5, 0, 4, 0}};

	int main() {
		int edge;  // number of edge

		int selected[V];
		memset(selected, false, sizeof(selected));   // set selected false initially

		edge = 0;  // set number of edge to 0

		selected[0] = true;   // choose 0th vertex and make it true

		int x;  //  row number
		int y;  //  col number

		// print for edge and weight
		cout << "Edge"<< " : "<< "Weight";
		cout << endl;
		while (edge < V - 1) {
			int min = INF;
			x = 0;
			y = 0;

			for (int i = 0; i < V; i++) {
				if (selected[i]) {
					for (int j = 0; j < V; j++) {
						if (!selected[j] && G[i][j]) {
							if (min > G[i][j]) {
								min = G[i][j];
								x = i;
								y = j;
							}
						}
					}
				}
			}
			cout << x << " - " << y << " :  " << G[x][y];
			cout << endl;
			selected[y] = true; //choose y th vertex and make it true
			edge++;
		}

		return 0;
	}