#include<iostream>
using namespace std;

#include<string>
//双向链表管理
//12ms
struct node
{
	string dirname;
	node* next;
	node* pre;
	node(string dir){
		dirname = dir;
		pre = next = NULL;
	}
	node(){
		dirname = "";
		pre = next = NULL;
	}
};
class Solution {
public:
	Solution(){
		head = new node();
	}
	node* addnode(node* p,string dir) {
		node* newnode = new node(dir);
		p->next = newnode;
		newnode->pre = p;
		return newnode;
	}
	string simplifyPath(string path) {
		int n = path.length();
		string ans;
		node *p = head;
		for (int i = 0; i < n;) {
			if (path[i] == '/') {
				i++;
				while (i < n && path[i] == '/') i++;
				if (i + 1 < n && (path.substr(i, 2) == "./")){
					i++;
				}
				else if (i<n && path.substr(i) == "."){
					break;
				}
				else if (i+2 < n && (path.substr(i,3) == "../")) {
					if (p != head) {
							p = p->pre; p->next = NULL;
					}
					if (i + 2 < n) i += 2;
					else i += 1;
				}
				else if (i<n && path.substr(i) == "..") {
					if (p != head) {
						p = p->pre; p->next = NULL;
					}
					break;
				}
				else{
					string s;
					while (i<n&&path[i]!='/')
					{
						s += path[i];
						i++;
					}
					if (!s.empty())
						p = addnode(p, s);
				}
			}
		}
		if (head->next == NULL) return "/";
		p = head->next;
		while (p) {
			ans += ("/" + p->dirname);
			p = p->next;
		}
		return ans;
	}
private:
	node *head;
};

int main(void) {
	Solution so;
	cout << so.simplifyPath("/.") << endl;
	return 0;
}