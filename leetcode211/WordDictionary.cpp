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

class WordDictionary {
public:
	WordDictionary() {
		root = new TrieNode();
	}
	// Adds a word into the data structure.
	void addWord(string s) {
		int n = s.length();
		if (!n) return;
		TrieNode *p = root;
		for (int i = 0; i < n; i++){
			if (p->m[s[i] - 'a'] == NULL){
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

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool sea(string& word, int cur, int& n, TrieNode *p) {
		if (cur == n - 1) {
			if (word[cur] == '.') {
				for (int i = 0; i < 26; i++){
					if (p->m[i] && p->m[i]->isWord) return true;
				}
				return false;
			}
			else {
				if (p->m[word[cur] - 'a'] && p->m[word[cur] - 'a']->isWord) return true;
				return false;
			}
		}
		if (word[cur] == '.') {
			for (int i = 0; i < 26; i++){
				if (p->m[i] && sea(word, cur + 1, n, p->m[i])) return true;
			}
			return false;
		}
		else {
			if (p->m[word[cur] - 'a'] == NULL) return false;
			return sea(word, cur + 1, n, p->m[word[cur] - 'a']);
		}
	}
	bool search(string key) {
		TrieNode *p = root;
		int n = key.length();
		return sea(key, 0, n, root);
	}
private:
	TrieNode* root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main(void){
	// Your WordDictionary object will be instantiated and called as such:
	WordDictionary wordDictionary;
	wordDictionary.addWord("bad");
	wordDictionary.addWord("dad");
	wordDictionary.addWord("mad");
	cout << wordDictionary.search("pad") << endl;
	cout << wordDictionary.search("bad") << endl;
	cout << wordDictionary.search(".ad") << endl;
	cout << wordDictionary.search("b..") << endl;
	return 0;
}