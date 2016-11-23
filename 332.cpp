#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

    vector<string> findItinerary(vector<pair<string, string> > tickets) {
        unordered_map<string, set<string> > graph;
        for (pair<string, string> p : tickets) {
            graph[p.first].insert(p.second);
        }

        vector<string> paths;
        stack<string> dfs;
        dfs.push("JFK");
        while (!dfs.empty()) {
           string airPort = dfs.top();
           if (graph[airport].empty()) {
	      paths.push_back(airport);
              dfs.pop();
           } else {
              dfs.push(*graph[airport].begin());
              graph[airport].erase(graph[airport].begin());
           }
        }
        reverse(paths.begin(), paths.end());
        return paths;
    }

int main() {
   vector<pair<string, string> > tickets;
   tickets.push_back(make_pair<string,string>("MUC","LHR"));
   tickets.push_back(make_pair<string,string>("JFK","MUC"));
   tickets.push_back(make_pair<string,string>("SFO","SJC"));
   tickets.push_back(make_pair<string,string>("LHR","SFO"));

   for (string s : findItinerary(tickets)) {
      cout << s << endl;
   }
}
