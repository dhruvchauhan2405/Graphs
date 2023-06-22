#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
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
        void bfs(int src,unordered_map<int,bool>&visited){
            queue<int>q;
            q.push(src);
            visited[src] = true;
            while(!q.empty()){
                // Front node
                int frontNode = q.front();
                q.pop();
                cout<<frontNode;
                // Insert neighbours
                for(auto neighbours : adjList[frontNode]){
                    // If not visited then insert
                    if(!visited[neighbours]){
                        q.push(neighbours);
                        visited[neighbours] = true;
                    }
                }
            }
        }

        void topoSortBfs(int n,vector<int>& ans){
            queue<int>q;
            unordered_map<int,int> indegree;

            // indegree calculate
            for(auto i:adjList){
                int src=i.first;
                for(auto nbr:i.second){
                    indegree[nbr]++;
                }
            }

            // put all nodes inside queue, which has indegree-0
            for(int i=0;i<7;i++){
                if(indegree[i]==0){
                    q.push(i);
                }
            }

            while(!q.empty()){
                int fNode = q.front();
                q.pop();

                ans.push_back(fNode);

                for(auto nbr:adjList[fNode]){
                    indegree[nbr]--;
                    // check for zero again
                    if(indegree[nbr]==0){
                        q.push(nbr);
                    }
                }
            }
        }
};
int main(){
    Graph<int> g;
    g.addEdge(2,5,1);
    g.addEdge(2,4,1);
    g.addEdge(5,3,1);
    g.addEdge(3,7,1);
    g.addEdge(4,6,1);
    g.addEdge(6,7,1);
    g.addEdge(7,0,1);
    g.addEdge(7,1,1);
    // unordered_map<int,bool>visited;
    vector<int> ans;
    // connected 
    // for(int i=0;i<7;i++){
    g.topoSortBfs(7,ans);
    // }

    for(auto i:ans){
        cout<<i<<",";
    }cout<<endl;


    // for(int i = 0;i<7;i++){
    //     if(!visited[i])
    //         g.bfs(i,visited);
    // }
    return 0;
} 