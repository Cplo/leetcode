#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<map>
#include<string.h>
#include<string>
#include<queue>
#include<float.h>
class TrieNode {
public:
	char data;
	int count;
	//map<char, TrieNode*> m;
	TrieNode *m[26];
	bool isWord;
public:
	// Initialize your data structure here.
	TrieNode() {
		for (int i = 0; i < 26; i++){
			m[i] = NULL;
		}
	}
	TrieNode(char d){
		data = d;
		count = 1;
		isWord = false;
		for (int i = 0; i < 26; i++){
			m[i] = NULL;
		}
	}
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}
	// Inserts a word into the trie.
	void insert(string s) {
		int n = s.length();
		if (!n) return;
		TrieNode *p = root;
		for (int i = 0; i < n; i++){
			if (p->m[s[i]-'a'] == NULL){
				TrieNode *node = new TrieNode(s[i]);
				//root->m.insert(make_pair(s[i],node));
				p->m[s[i] - 'a'] = node;
				p = node;
			}
			else{
				p->m[s[i] - 'a']->count++;
				p = p->m[s[i] - 'a'];
			}
		}
		p->isWord = true;
	}

	// Returns if the word is in the trie.
	bool search(string key) {
		int n = key.length();
		if (!n) return false;
		TrieNode *p = root;
		for (int i = 0; i < n; i++) {
			if (p->m[key[i] - 'a'] == NULL)
				return false;
			p = p->m[key[i] - 'a'];
		}
		return p->isWord;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	int startsWith(string prefix) {
		int n = prefix.length();
		if (!n) return false;
		TrieNode *p = root;
		for (int i = 0; i < n; i++) {
			if (p->m[prefix[i] - 'a'] == NULL)
				return 0;
			p = p->m[prefix[i] - 'a'];
		}
		return p->count;
	}

private:
	TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main()
{
	Trie t;
	int n, m;
	cin >> n;// scanf("%d", &n);
	string s;
	for (int i = 0; i < n; i++){
		//scanf("%s", s);
		cin >> s;
		t.insert(s);
	}
	//scanf("%d", &m);
	cin >> m;
	for (int i = 0; i < m; i++){
		cin >> s;
		//scanf("%s", s);
		//printf("%s\n", s);
		//cout << s << endl;
		cout << t.startsWith(s) << endl;
		//printf("%d\n", ans);
	}
	return 0;
}