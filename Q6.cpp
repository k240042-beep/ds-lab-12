#include <iostream>
using namespace std;

int main() {
    const int INF = 1000000000;

    int n = 6;
    char nodes[6] = {'A','B','C','D','E','F'};

    int adj[6][6] = {
        {0,4,0,8,0,0},
        {4,0,9,0,0,0},
        {0,9,0,6,14,0},
        {8,0,6,0,0,4},
        {0,0,14,0,0,3},
        {0,0,0,4,3,0}
    };

    int dist[6];
    bool used[6];
    int parent[6];

    for(int i=0;i<6;i++){
        dist[i]=INF;
        used[i]=false;
        parent[i]=-1;
    }

    int start = 1; 
    int target = 4;

    dist[start]=0;

    for(int i=0;i<6;i++){
        int v=-1;
        for(int j=0;j<6;j++){
            if(!used[j] && (v==-1 || dist[j]<dist[v])) v=j;
        }
        used[v]=true;

        for(int u=0;u<6;u++){
            if(adj[v][u] && dist[v] + adj[v][u] < dist[u]){
                dist[u] = dist[v] + adj[v][u];
                parent[u] = v;
            }
        }
    }

    int path[6], idx=0;
    for(int v=target; v!=-1; v=parent[v]) path[idx++] = v;

    for(int i=idx-1;i>=0;i--) cout << nodes[path[i]] << " ";
    cout << "\nDistance: " << dist[target];
}
