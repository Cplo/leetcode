//运行时间：526ms
#include<cstdio>
#include<string>
#include<map>
#include<vector>
#include<string.h>
using namespace std;
#define N 100005
class Query
{
public:
	Query(int s, int id) {
		couple = s;
		ID = id;
	}
public:
	int couple;
	int ID;
};
class People
{
public:
	int color;
	int index;
	string name;
	int parent;
	vector<People* > childs;
	vector<Query* > query;
public:
	People(string n,int idx){
		name = n;
		color = 0;
		index = idx;
	}
};
//定义name到编号的映射
map<string, int> m;
int size=0;
People* persons[N];
//遍历时记录当前状态下每个节点的最近灰色祖先（req[no]==no）
int req[N];
//答案集合
//string ans[N];
int ans[N];
//cur表示当前已经找到答案的查询数
int n,m1,cur;

class Tree
{
public:
	void insert(string father, string son);
	void insert1(string s1, string s2, int i);
	int find(int);//找最近的灰色祖先（req[no]==no）
	void DFS(int);
};
void Tree::insert(string father, string son) {
	People *f, *s;
	int no_f, no_s;
	if (!size) {
		f = new People(father,size);
		persons[size] = f;
		m[father] = size;
		no_f = size;
		size++;
		s = new People(son,size);
		persons[size] = s;
		m[son] = size;
		no_s = size;
		size++;
		req[no_f] = no_f;
		req[no_s] = no_s;
	}
	else {
		if (m.find(father) == m.end()) {
			f = new People(father,size);
			m[father] = size;
			persons[size] = f;
			no_f = size;
			size++;
			req[no_f] = no_f;
		}
		else {
			no_f = m[father];
			f = persons[no_f];
		}
		if (m.find(son) == m.end()) {
			s = new People(son,size);
			persons[size] = s;
			m[son] = size;
			no_s = size;
			req[no_s] = no_s;
			size++;
		}
		else{
			no_s = m[son];
			s = persons[no_s];
		}
	}
	f->childs.push_back(s);
	s->parent = f->index;
}
void Tree::insert1(string s1, string s2, int i) {
	int idx1 = m[s1];
	int idx2 = m[s2];
	Query *q1 = new Query(idx2, i);
	Query *q2 = new Query(idx1, i);
	persons[idx1]->query.push_back(q1);
	persons[idx2]->query.push_back(q2);
}
int Tree::find(int no) {
	if (no == req[no])
		return no;
	else{
		req[no] = find(req[no]);
		return req[no];
	}
}
//深度优先遍历多叉树
void Tree::DFS(int idx) {
	People *p = persons[idx];
	People *p1;
	p->color = 1;
	for (auto que : p->query) {
		if (ans[que->ID] >= 0) continue;		//已经找到答案
		int no = que->couple;
		p1 = persons[no];
		//白色
		if (p1->color == 0) {
			continue;
		}
		//灰色
		else if(p1->color == 1) {
			ans[que->ID] = no;
			cur++;
		}
		//黑色
		else
		{
			ans[que->ID] = find(no);
			cur++;
		}
	}
	if (cur == m1) return;
	for (auto chi : p->childs) {
		DFS(chi->index);
	}
	p->color = 2;
	if (idx){
		req[p->index] = p->parent;
	}
}
int main(void) {
	//cin >> n;
	scanf("%d", &n);
	memset(req, -1, (n + 1)*sizeof(int));
	
	Tree tree;
	char ch1[50], ch2[50];
	for (int i = 0; i < n; i++){
		//string son, father;
		//cin >> father >> son;
		scanf("%s%s", ch1, ch2);
		string father(ch1), son(ch2);
		tree.insert(father, son);
	}
	//cin >> m1;
	scanf("%d", &m1);
	cur = 0;
	memset(ans, -1, (m1 + 1)*sizeof(int));
	for (int i = 0; i < m1; i++){
		scanf("%s%s", ch1, ch2);
		string s1(ch1), s2(ch2);
		if (s1 == s2){
			ans[i] = m[s1];
			cur++;
			continue;
		}
		tree.insert1(s1, s2 , i);
	}
	
	if (cur!=m1)
		tree.DFS(0);
	for (int i = 0; i < m1; i++) {
		//cout << persons[ans[i]]->name << endl;
		printf("%s\n", &(persons[ans[i]]->name[0]));
	}
	return 0;
}
