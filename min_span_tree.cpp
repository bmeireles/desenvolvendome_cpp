//Minimum spanning tree - Prim's algorithm
//Source code: https://www.codespeedy.com/minimum-spanning-tree-for-graph-in-cpp/


 #include <iostream>
 #include<bits/stdc++.h>
 #include <cstring>
 using namespace std;
  
 // number of vertices in graph
 #define V 7


 int main () {
   // create a 2d array of size 7x7
 //for adjacency matrix to represent graph
   int G[V][V] = {
   {0,28,0,0,0,10,0},
 {28,0,16,0,0,0,14},
 {0,16,0,12,0,0,0},
 {0,0,12,22,0,18},
 {0,0,0,22,0,25,24},
 {10,0,0,0,25,0,0},
 {0,14,0,18,24,0,0}
 };
  
   int edge;// number of edges
  
   // create an array to check visited vertices
   int visit[V];
   
   //initialise the visit array to false
  for(int i=0;i<V;i++){ //for index i in the array
    visit[i]=false; //the index will receive false
}
  
  // set number of edge to 0
   edge = 0;
  
   // the number of edges in minimum spanning tree will be
   // always less than (V -1), where V is the number of vertices in
   //graph
  
   // choose 0th vertice and make it true
   visit[0] = true;
  
   int x; //row number
   int y; //col number
  
   // print for edge and weight
   cout << "Edge" << " : " << "Weight";
   cout << endl;
   while (edge < V - 1) {//in spanning tree consist the V-1 number of edges
  
   //For every vertice in the set S, find the all adjacent vertices
   // , calculate the distance from the vertice selected.
   // if the vertice is already visited, discard it otherwise
   //choose another vertice nearest to selected vertice.
  
       int min = INT_MAX;
       x = 0; //row
       y = 0; //col
  
       for (int i = 0; i < V; i++) { //for every vertice in the set S
         if (visit[i]) { //if the vertice i is marked true (if it was visited)
             for (int j = 0; j < V; j++) { //start a loop to look for other vertice near vertive i
               if (!visit[j] && G[i][j]) { //if vertice j is not visited, and j is near vertice i
                   if (min > G[i][j]) { //if the minimum edge weight so far is higher than the edge
                   //weight between vertice i and j
                       min = G[i][j]; //mark this edge as the new minimum
                       x = i; //x receives i
                       y = j; //y receives j
                   }
      
               }
           }
         }
       }
       cout << x <<  " ---> " << y << " :  " << G[x][y]; //print x, y and de edge weight
       cout << endl;
       visit[y] = true; //mark vertice j as visited
       edge++; //increment +1 to the edge, for the while loop
     }
  
   return 0;
 }