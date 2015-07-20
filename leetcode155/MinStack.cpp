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

class MinStack {
public:
	void push(int x) {
		if (s.empty()) {
			s.push(x); s_min.push(x);
		}
		else {
			s.push(x);
			int m = s_min.top();
			if (x < m) s_min.push(x);
		}
	}

	void pop() {
		int m = s.top();
		s.pop(); if (m == s_min.top()) s_min.pop();
	}

	int top() {
		return s.top();
	}

	int getMin() {
		return s_min.top();
	}
private:
	stack<int> s;
	stack<int> s_min;
};

int main(void) {
	MinStack m;
	m.push(2);
	m.push(1);
	m.push(3);
	cout << m.getMin() << endl;
	return 0;
}