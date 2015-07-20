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

class LRUCache{
public:
	LRUCache(int capacity):n(capacity),tail(0),head(0) {
	}

	int get(int key) {
		if (m_lru.find(key) == m_lru.end()) return -1;
		else {
			/*找到，提到前面*/
			int idx = m_key_exist[key];
			q_exist[idx] = 0;
			q_key[tail] = key;
			q_exist[tail] = 1;
			m_key_exist[key] = tail;
			tail++;
			return m_lru[key];
		}
	}
	void set(int key, int value) {
		int num = m_lru.size();
		if (m_lru.find(key) == m_lru.end()) {
			if (num < n) {
				m_lru[key] = value;
				q_key[tail] = key;
				m_key_exist[key] = tail;
				q_exist[tail] = 1;
				tail++;
			}
			else /*没找到，并且cache已经满*/{
				while (!q_exist[head]) head++;
				int del_key = q_key[head];
				head++;
				m_lru.erase(del_key);
				m_lru[key] = value;
				q_exist[tail] = 1;
				q_key[tail] = key;
				m_key_exist[key] = tail;
				tail++;
			}
		}
		else {
			/*找到，提到前面*/
			int idx = m_key_exist[key];
			m_lru[key] = value;
			q_exist[idx] = 0;
			q_key[tail] = key;
			q_exist[tail] = 1;
			m_key_exist[key] = tail;
			tail++;
		}
	}
private:
	map<int, int> m_lru;
	map<int, int> m_key_exist;
	int n;
	int head, tail;
	int q_key[100000];
	int q_exist[100000];
};

int main(void) {
	LRUCache l(2); 
	
	//l.set(2, 1); l.set(2, 2); cout << l.get(2) << endl; l.set(1, 1); l.set(4, 1); cout << l.get(2) << endl;
	//l.set(2, 1); l.set(1, 1); cout << l.get(2) << endl; l.set(4, 1); cout << l.get(1) << endl; cout << l.get(2) << endl;
	//-1 3
/*  l.set(2, 1); 
	l.set(1, 1); 
	l.set(2, 3); 
	l.set(4, 1); */
	//2,[set(2,1),set(1,1),get(2),set(4,1),get(1),get(2)]
	l.set(2, 1);
	l.set(1, 1); 
	cout << l.get(2) << endl; 
	l.set(4, 1); 
	cout << l.get(1) << endl; 
	cout << l.get(2) << endl;
	return 0;
}