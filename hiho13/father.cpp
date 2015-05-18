#include<iostream>
using namespace std;
#include<string>
#include<map>
int main(void) {
	int N,M;
	cin >> N;
	map<string,string> m;
	string son, father;
	for (int i = 0; i < N; i++){
		//string son, father;
		cin >> father >> son;
		m[son] = father;
	}
	cin >> M;
	string s1, s2, s;
	for (int i = 0; i < M; i++) {
		cin >> s1 >> s2;
		int flag = 0;
		while(1){
			s = s2;
			while (1) {
				if (s1 == s) {
					flag = 1;
					break;
				}
				if (m.find(s) != m.end())
					s = m[s];
				else break;
			}
			if (flag) break;
			if (m.find(s1) != m.end())
				s1 = m[s1];
			else break;
		} 
		if (flag) cout << s << endl;
		else cout << "-1" << endl;
	}
	return 0;
}