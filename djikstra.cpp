#include <iostream>
#include <stack>
#include <set>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;


int Minimum_Distance(int distance[], bool Tset[])
{
    int minimum = INT_MAX,ind;

    for(int k=0;k<6;k++)
    {
        if(Tset[k]==0 and distance[k]<=minimum)
        {
            minimum = distance[k];
            ind = k;
        }
    }
    return ind;
}


void Dijkstra_Algorithm(int graph[6][6], int src) // adjancy matrix
{
    int distance[6]; // array to calc the min distance for each node
    bool Tset[6]; // Boolean array to mark vistied and unvisited for each node



    for(int k=0;k<6;k++)
    {
        distance[k] = INT_MAX;
        Tset[k] = false;
    }

    distance[src] = 0; //Source Vertex is set to 0

    for(int k=0;k<6;k++)
    {
        int m = Minimum_Distance(distance,Tset);
        Tset[m] = true;
        for(int k=0;k<6;k++)
        {
            //Update the distance for neighbor vertex
            if(!Tset[k] && graph[m][k] && distance[m]!=INT_MAX && distance[m]+graph[m][k]<distance[k])
            {
                distance[k]=distance[m]+graph[m][k];
            }

        }

        cout<<"Vertex\t\tDistance from source vertex"<<endl;
        for(int k=0;k<6;k++)
        {
            char str = 65+k;
            cout<<str<<"\t\t\t"<<distance[k]<<endl;
        }
    }



}





int main()
{
    int graph[6][6]={
        {0, 1, 2, 0, 0, 0},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 0, 2, 1, 0}};
    Dijkstra_Algorithm(graph,0);
}
