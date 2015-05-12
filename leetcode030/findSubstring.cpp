#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>
#include<map>
class Solution {
public:
	vector<int> findSubstring(string S, vector<string>& L) {
		vector<int> ans;
		int n = S.length(), cnt = L.size();
		if (!n || !cnt) return ans;
		map<string, int> dict;
		map<string, int> tdict;
		for (int i = 0; i < cnt; ++i) dict[L[i]]++;
		int wl = L[0].size();
		int count;
		map<string, int> mdict;
		map<string, int>::iterator it;
		int loc;
		for (it = dict.begin(); it != dict.end(); it++){
			loc = 0;
			while (loc<n)
			{
				loc = S.find(it->first, loc);
				if (loc != string::npos){
					mdict[it->first]++;
					loc++;
				}
				else{
					break;
				}
			}
		}
		int idx = -1;
		for (int i = 0; i < cnt; ++i){
			if (mdict[L[i]] < dict[L[i]]) return ans;
			if (mdict[L[i]] == 1) idx = S.find(L[i]) % wl;
		}
		if (idx != -1){
			count = 0;
			tdict.clear();
			while (idx + wl <= n){
				string s = S.substr(idx, wl);
				if (dict.find(s) != dict.end()) {
					if (tdict[s]<dict[s]){
						tdict[s]++;
						count++;
					}
					else{
						int k = idx - wl * count;
						while (S.substr(k, wl) != s){
							tdict[S.substr(k, wl)]--;
							count--;
							k += wl;
						}
					}
					if (count == cnt){
						ans.push_back(idx - wl * (cnt - 1));
						tdict[S.substr(idx - wl * (cnt - 1), wl)]--;
						count--;
					}
				}
				else{
					tdict.clear();
					count = 0;
				}
				idx += wl;
			}
			return ans;
		}
		for (int i = 0; i < wl; ++i) {
			idx = i;
			count = 0;
			tdict.clear();
			while (idx + wl <= n){
				string s = S.substr(idx, wl);
				if (dict.find(s) != dict.end()) {
					if (tdict[s]<dict[s]){
						tdict[s]++;
						count++;
					}
					else{
						int k = idx - wl * count;
						while (S.substr(k, wl) != s){
							tdict[S.substr(k, wl)]--;
							count--;
							k += wl;
						}
					}
					if (count == cnt){
						ans.push_back(idx - wl * (cnt - 1));
						tdict[S.substr(idx - wl * (cnt - 1), wl)]--;
						count--;
					}
				}
				else{
					tdict.clear();
					count = 0;
				}
				idx += wl;
			}
		}
		return ans;
	}
};


int main(){
	Solution so;
	vector<string> L;
	//L.push_back("a");
	//L.push_back("a");
	L.push_back("a");
	L.push_back("b");
	L.push_back("a");/*
	L.push_back("wing");
	L.push_back("ding");
	L.push_back("wing");*/
	//L.push_back("the");
	vector<int> ans = so.findSubstring("abababab", L);
	vector<int>::iterator it;
	for (it = ans.begin(); it != ans.end(); it++){
		cout << *it << endl;
	}
	return 0;
}