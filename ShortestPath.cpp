#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void BFS(vector<vector<int>>& graph,int s,vector<int>& par,
vector<int>& dist){
    queue<int> q;
    dist[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int node= q.front();
        q.pop();
        for(auto neighbour:graph[node])
        {
            if(dist[neighbour]==1e9){
            dist[neighbour]= dist[node]+1;
            par[neighbour]=node;
            q.push(neighbour);
            }           
        }
    }
}

void printShortestDistance(vector<vector<int>>& graph,
int s,int d,int v)
{
    vector<int>par(v,-1);
    vector<int>dist(v,1e9);
    BFS(graph,s,par,dist);
    vector<int>path;
    path.push_back(d);
    int currentNode=d;
    while(par[currentNode]!=-1)
    {
        path.push_back(par[currentNode]);
        currentNode= par[currentNode];
    }
    cout<<"\nThe path is shown below: \n";
    for(int i= path.size()-1;i>=0;i--)
    {   
         cout<<path[i]<<" ";        
    }
}
int main()
{
    cout<<"Enter number of vertices and edges\n";
    int V,E; cin>>V>>E;
    cout<<"Enter source and destination\n";
    int S,D; cin>>S>>D;
    vector<vector<int>> graph(V);
    cout<<"Enter "<<E<<" edges\n";
    for(int i=0;i<E;i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    printShortestDistance(graph,S,D,V);
}