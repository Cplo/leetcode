#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<map>
using namespace std;
class TrieNode {
public:
	char data;
	TrieNode *m[26];
	int cur_idx;		//��¼�ýڵ㴦�ڵڼ��㣬Ҳ�ǵ��ýڵ�ʱ���ַ��������һ���ַ���������
	bool isExist;		//�������ĸʱ���ַ����Ƿ������board��
	vector<vector<int>> cand;	//��isExist==true��ǰ���´洢��ĿǰΪֹ�ĺ�ѡ����,���isExist==false,��cand����Ϊ��
public:
	// Initialize your data structure here.
	TrieNode() {
		for (int i = 0; i < 26; i++){
			m[i] = NULL;
		}
		cur_idx = 0;
	}
	TrieNode(char d, bool isEx, int idx){
		data = d;
		isExist = isEx;
		for (int i = 0; i < 26; i++){
			m[i] = NULL;
		}
		cur_idx = idx;
	}
};
class Solution {
public:
	Solution() {
		root = new TrieNode();
	}
	TrieNode* startswith(string prefix) {
		TrieNode *p = root;
		int n = prefix.length();
		for (int i = 0; i < n; i++) {
			if (p->m[prefix[i] - 'a'] == NULL)
				return p;
			p = p->m[prefix[i] - 'a'];
			if (p->isExist == false) return NULL;
		}
		return p;
	}
	bool recursion(vector<vector<char>>& board, string word, int i, int j, int cur, int arr[], TrieNode*p, int k) {
		int pos = i * n + j;
		bool flag = false;
		if (word[cur] == board[i][j]) {
			if (p->m[word[cur] - 'a'] == NULL || p->m[word[cur] - 'a']->isExist == false) {
				TrieNode *node = new TrieNode(word[cur], true, cur);
				vector<int> v(p->cand[k].begin(), p->cand[k].end());
				v.push_back(pos);
				node->cand.push_back(v);
				p->m[word[cur] - 'a'] = node;
			}
			else{
				vector<int> v(p->cand[k].begin(), p->cand[k].end());
				v.push_back(pos);
				p->m[word[cur] - 'a']->cand.push_back(v);
			}
			TrieNode *p1 = p->m[word[cur] - 'a'];
			k = p1->cand.size() - 1;
			int n_cur = cur + 1;
			if (n_cur == len) return true;
			arr[i*n + j] = 1;
			if (i + 1 < m && (!arr[(i + 1)*n + j]) && recursion(board, word, i + 1, j, n_cur, arr, p1, k)) flag = true;
			if (i - 1 >= 0 && (!arr[(i - 1)*n + j]) && recursion(board, word, i - 1, j, n_cur, arr, p1, k)) flag = true;
			if (j + 1 < n && (!arr[i*n + j + 1]) && recursion(board, word, i, j + 1, n_cur, arr, p1, k)) flag = true;
			if (j - 1 >= 0 && (!arr[i*n + j - 1]) && recursion(board, word, i, j - 1, n_cur, arr, p1, k)) flag = true;
			arr[i*n + j] = 0;
		}
		if (cur < len && p->m[word[cur] - 'a'] == NULL)
			p->m[word[cur] - 'a'] = new TrieNode(word[cur],false,cur);
		return flag;
	}
	bool exist(vector<vector<char>>& board, string word, TrieNode *p) {
		if (word.empty()) return true;
		if (board.empty()) return false;
		bool flag;
		int *arr = new int[m*n];
		if (p != root) {
			flag = false;
			for (int k = 0; k < p->cand.size();k++) {
				memset(arr, 0, m*n*sizeof(int));
				for (auto it_i : p->cand[k]) arr[it_i] = 1;
				int i = p->cand[k].back() / n;
				int j = p->cand[k].back() % n;
				if (i + 1 < m && (!arr[(i + 1)*n + j]) && recursion(board, word, i + 1, j, p->cur_idx + 1, arr, p, k)) flag = true;
				if (i - 1 >= 0 && (!arr[(i - 1)*n + j]) && recursion(board, word, i - 1, j, p->cur_idx + 1, arr, p, k)) flag = true;
				if (j + 1 < n && (!arr[i*n + j + 1]) && recursion(board, word, i, j + 1, p->cur_idx + 1, arr, p, k)) flag = true;
				if (j - 1 >= 0 && (!arr[i*n + j - 1]) && recursion(board, word, i, j - 1, p->cur_idx + 1, arr, p, k)) flag = true;
			}
			return flag;
		}
	}
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> ans;
		map<string, int> map_words;
		int num = words.size();
		m = board.size();
		n = board[0].size();

		//Ԥ������board�����г��ֵĲ�ͬ��ĸ��Ϊһ�������ĸ��ڵ�
		/*
				root
			a b c d e f ...
		*/
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int pos = i * n + j;
				if (root->m[board[i][j] - 'a'] == NULL) {
					TrieNode *node = new TrieNode(board[i][j], true, 0);
					vector<int> v;
					v.push_back(pos);
					node->cand.push_back(v);
					root->m[board[i][j] - 'a'] = node;
				}
				else{
					vector<int> v;
					v.push_back(pos);
					root->m[board[i][j] - 'a']->cand.push_back(v);
				}
			}
		}

		//��ʼ�����ַ�����words, words�е��ַ�������ھ���Ԥ������ֵ����в��ҽ����Ȼ��root����ΪNULL(����ÿ���ַ�ʱΪfalse),˵�����ַ���һ�������ڣ�
		for (int i = 0; i < num; i++) {
			if (map_words.find(words[i]) != map_words.end()) continue;
			else map_words[words[i]]++;
			len = words[i].length();
			TrieNode *p = startswith(words[i]);
			if (p == NULL || p == root) continue; //�����ڵ�ǰ׺��
			if (p->cur_idx == len - 1) {
				ans.push_back(words[i]); 
			}
			else if (exist(board, words[i], p)) ans.push_back(words[i]); 
		}
		return ans;
	}
private:
	int m, n, len;
	TrieNode* root;
};

int main(void)	{
	Solution so;
	vector<vector<char>> board;
	char ch[][5] = {
		"ab",
		"cd",
		"ihkr",
		"iflv" };// ABCE
	for (int i = 0; i < 2; i++) {
		vector<char> v(ch[i], ch[i] + 2);
		board.push_back(v);
	}
	string s[] = { "ab", "cb", "ad", "bd", "ac", "ca", "da", "bc", "db", "adcb", "dabc", "abb", "acb" };
	vector<string> v(s, s + 13);
	vector<string> ans = so.findWords(board, v);
	for (auto k : ans) cout << k << endl;
	return 0;
}
