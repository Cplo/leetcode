#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>
#include<float.h>
#include<stack>
#include<math.h>
#include<queue>
#include<unordered_set>
using namespace std;

//Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (!node) return NULL;
		UndirectedGraphNode *ans = new UndirectedGraphNode(node->label);
		queue<UndirectedGraphNode*> q_graph, q_ans_graph;
		map<int, UndirectedGraphNode *> m_node;
		q_graph.push(node);
		q_ans_graph.push(ans);
		m_node[ans->label] = ans;
		while (!q_graph.empty()) {
			UndirectedGraphNode* u = q_graph.front(); q_graph.pop();
			UndirectedGraphNode* ans_u = q_ans_graph.front(); q_ans_graph.pop();
			for (auto k : u->neighbors) {
				UndirectedGraphNode *node;
				int isnew = 0;
				if (m_node.find(k->label) == m_node.end()) {
					isnew = 1;
					node = new UndirectedGraphNode(k->label); 
					m_node[k->label] = node;
				}
				else node = m_node[k->label];
				ans_u->neighbors.push_back(node);
				if (isnew) {
					q_graph.push(k); q_ans_graph.push(node);
				}
			}
		}
		return ans;
	}
};

int main(void) {
	return 0;
}