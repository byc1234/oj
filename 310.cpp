/*
First let's review some statement for tree in graph theory:

(1) A tree is an undirected graph in which any two vertices are connected by exactly one path.
(2) Any connected graph who has n nodes with n-1 edges is a tree.
(3) The degree of a vertex of a graph is the number of edges incident to the vertex.
(4) A leaf is a vertex of degree 1. An internal vertex is a vertex of degree at least 2.
(5) A path graph is a tree with two or more vertices that is not branched at all.
(6) A tree is called a rooted tree if one vertex has been designated the root.
(7) The height of a rooted tree is the number of edges on the longest downward path between root and a leaf.
OK. Let's stop here and look at our problem.

Our problem want us to find the minimum height trees and return their root labels. First we can think about a simple case -- a path graph.

For a path graph of n nodes, find the minimum height trees is trivial. Just designate the middle point(s) as roots.

Despite its triviality, let design a algorithm to find them.

Suppose we don't know n, nor do we have random access of the nodes. We have to traversal. It is very easy to get the idea of two pointers. One from each end and move at the same speed. When they meet or they are one step away, (depends on the parity of n), we have the roots we want.

This gives us a lot of useful ideas to crack our real problem.

For a tree we can do some thing similar. We start from every end, by end we mean vertex of degree 1 (aka leaves). We let the pointers move the same speed. When two pointers meet, we keep only one of them, until the last two pointers meet or one step away we then find the roots.

It is easy to see that the last two pointers are from the two ends of the longest path in the graph.

The actual implementation is similar to the BFS topological sort. Remove the leaves, update the degrees of inner vertexes. Then remove the new leaves. Doing so level by level until there are 2 or 1 nodes left. What's left is our answer!

The time complexity and space complexity are both O(n).

Note that for a tree we always have V = n, E = n-1.

*/

        struct Node
        {
            unordered_set<int> neighbor;
            bool isLeaf()const{return neighbor.size()==1;}
        };

        vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {

            vector<int> buffer1;
            vector<int> buffer2;
            vector<int>* pB1 = &buffer1;
            vector<int>* pB2 = &buffer2;
            if(n==1)
            {
                buffer1.push_back(0);
                return buffer1;
            }
            if(n==2)
            {
                buffer1.push_back(0);
                buffer1.push_back(1);
                return buffer1;
            }

            // build the graph
            vector<Node> nodes(n);
            for(auto p:edges)
            {
                nodes[p.first].neighbor.insert(p.second);
                nodes[p.second].neighbor.insert(p.first);
            }

            // find all leaves
            for(int i=0; i<n; ++i)
            {
                if(nodes[i].isLeaf()) pB1->push_back(i);
            }

            // remove leaves layer-by-layer            
            while(1)
            {
                for(int i : *pB1)
                {
                    for(auto n: nodes[i].neighbor)
                    {
                        nodes[n].neighbor.erase(i);
                        if(nodes[n].isLeaf()) pB2->push_back(n);
                    }
                }
                if(pB2->empty())
                {
                    return *pB1;
                }
                pB1->clear();
                swap(pB1, pB2);
            }

        }

