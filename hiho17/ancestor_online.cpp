//运行时间：111ms
#include<cstdio>
#include<string>
#include<map>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;
#define N 100005

class People
{
public:
	int index;
	string name;
	int height;
	vector<People* > childs;
public:
	People(string n, int idx){
		name = n;
		index = idx;
	}
};
//定义name到编号的映射
map<string, int> m;
int arr[N][20];
int arr_n;
//多叉树中结点索引和数组arr中最后出现的位置的映射
map<int, int> map_node;
int size = 0;
People* persons[N];
int n, m1;

class Tree
{
public:
	void insert(string father, string son);
	void DFS(int,int);
};
void Tree::insert(string father, string son) {
	People *f, *s;
	int no_f, no_s;
	if (!size) {
		f = new People(father, size);
		persons[size] = f;
		m[father] = size;
		no_f = size;
		size++;
		s = new People(son, size);
		persons[size] = s;
		m[son] = size;
		no_s = size;
		size++;
	}
	else {
		if (m.find(father) == m.end()) {
			f = new People(father, size);
			m[father] = size;
			persons[size] = f;
			no_f = size;
			size++;
		}
		else {
			no_f = m[father];
			f = persons[no_f];
		}
		if (m.find(son) == m.end()) {
			s = new People(son, size);
			persons[size] = s;
			m[son] = size;
			no_s = size;
			size++;
		}
		else{
			no_s = m[son];
			s = persons[no_s];
		}
	}
	f->childs.push_back(s);
}
//深度优先遍历多叉树
void Tree::DFS(int idx,int height) {
	People *p = persons[idx];
	p->height = height;
	int childs_n = p->childs.size();
	if (!childs_n) {
		arr[arr_n++][0] = idx;
	}
	else{
		for (auto chi : p->childs) {
			DFS(chi->index, height + 1);
			arr[arr_n++][0] = idx;
		}
	}
	map_node[idx] = arr_n - 1;
}

//重载min，实现返回height更小的index
int min(int a, int b) {
	return persons[a]->height < persons[b]->height ? a : b;
}

void RMQ_init(void){
	int index = floor(log(arr_n) / log(2));
	for (int j = 1; j <= index; j++) {
		for (int i = 0; i + (1 << j) - 1 < arr_n; i++){
			arr[i][j] = min(arr[i][j - 1], arr[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int main(void) {
	//cin >> n;
	scanf("%d", &n);
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
	int l, r;
	arr_n = 0;
	tree.DFS(0, 1);
	RMQ_init();
	for (int i = 0; i < m1; i++){
		scanf("%s%s", ch1, ch2);
		string s1(ch1), s2(ch2);
		l = map_node[m[s1]];
		r = map_node[m[s2]];
		if (r < l) swap(l, r);
		int j = floor(log(r - l + 1) / log(2));
		int rr = r - (1 << j) + 1;
		printf("%s\n", &persons[min(arr[l][j], arr[rr][j])]->name[0]);
	}
	return 0;
}
