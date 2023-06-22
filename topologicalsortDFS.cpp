#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
using namespace std;
template<typename T>
class Graph{
    public:
        unordered_map<T,list<T>>adjList;
        void addEdge(T u,T v,bool direction){
            // direction = 0 -> undirected
            // direction = 1 -> directed 
            // Create an edge from u to v
            adjList[u].push_back(v);
            // if undirected 
            if(direction == 0)
                adjList[v].push_back(u); // edge created from v to u    
        }
        void printAdjList(){
            for(auto node : adjList){
                cout<<node.first<<"-> ";
                for(auto neighbours : node.second){
                    cout<<neighbours<<", ";
                }
                cout<<endl;
            }
        }
        void toposortDfs(int src,unordered_map<int,bool>&visited,stack<int>& ans){
            // cout<<src<<" ";
            visited[src] = true;
            for(auto neighbour : adjList[src]){
                if(!visited[neighbour]){
                    toposortDfs(neighbour,visited,ans);
                }
            }
            ans.push(src);
        }
};
int main(){
    Graph<int> g;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,5,1);
    g.addEdge(3,4,1);
    g.addEdge(4,6,1);
    g.addEdge(5,6,1);
    g.addEdge(6,7,1);
    int n=7;
    unordered_map<int,bool>visited;
    stack<int> ans;
    for(int i = 0;i<n;i++){
        if(!visited[i]){
            g.toposortDfs(i,visited,ans);
        }
    }
    while(!ans.empty()){
        cout<<ans.top();
        ans.pop();
    }
    return 0;
}