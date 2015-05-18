#include<iostream>
#include<string>
#include<map>
using namespace std;
#define N 100005
map<string, string> rep;
string find(string x)
{
	if (x == rep[x])
		return x;
	else
	{
		rep[x] = find(rep[x]);
		return rep[x];
	}
}
void join(string x, string y)
{
	string fx = find(x);
	string fy = find(y);
	if (fx != fy)
		rep[fx] = fy;
}
int main()
{
	int n;
	int op;
	cin >> n;
	string s1, s2;
	for (int i = 0; i < n; i++)
	{
		cin >> op >> s1 >> s2;
		if (rep.find(s1) == rep.end()) rep[s1] = s1;
		if (rep.find(s2) == rep.end()) rep[s2] = s2;
		if (!op){
			join(s1, s2);
		}
		else{
			cout << (find(s1) == find(s2) ? "yes" : "no") << endl;
		}
	}
	return 0;
}