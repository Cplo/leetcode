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

class Solution {
public:
	int search_idx(int loc, vector<pair<int, int>>& v){
		int n = v.size();
		if (loc >= v.back().first) return n - 1;
		int l = 0, r = n - 1;
		int mid;
		while (l <= r) {
			mid = (l + r) / 2;
			if (loc < v[mid].first) r--;
			else {
				if (loc < v[mid + 1].first) return mid;
				l++;
			}
		}
	}
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		vector<pair<int, int>> v_pair;
		int n = buildings.size();
		if (!n) return v_pair;
		pair<int, int> point(buildings[0][0], buildings[0][2]);
		pair<int, int> point1(buildings[0][1], 0);
		v_pair.push_back(point);
		v_pair.push_back(point1);
		for (int i = 1; i < n; i++) {
			if (buildings[i][0] > v_pair.back().first) {
				point = make_pair(buildings[i][0], buildings[i][2]);
				point1 = make_pair(buildings[i][1], 0);
				v_pair.push_back(point);
				v_pair.push_back(point1);
			}
			else {
				int hei = buildings[i][2];
				int l_idx = search_idx(buildings[i][0], v_pair);
				int r_idx = search_idx(buildings[i][1], v_pair);
				vector<pair<int, int>> v_temp;
				int start = l_idx + 1;
				if (buildings[i][0] == v_pair[l_idx].first) {
					if (l_idx - 1 >=0 && hei == v_pair[l_idx - 1].second) start = l_idx;
					else if(hei > v_pair[l_idx].second) v_pair[l_idx].second = hei;
				}
				else if (buildings[i][0] > v_pair[l_idx].first && hei > v_pair[l_idx].second) {
					point = make_pair(buildings[i][0], hei);
					v_temp.push_back(point);
				}
				for (int k = l_idx+1; k <= r_idx; k++) {
					if (!v_pair[k].second && v_pair[k].first == buildings[i][1]) break;
					if (hei > v_pair[k].second) {
						if (hei < v_pair[k - 1].second) {
							point = make_pair(v_pair[k].first, hei);
							v_temp.push_back(point);
						}
					}
					else {
						v_temp.push_back(v_pair[k]);
					}
				}
				if (buildings[i][1] > v_pair.back().first) {
					point = make_pair(buildings[i][1], 0);
					v_temp.push_back(point);
				}
				else {
					if (hei > v_pair[r_idx].second) {
						point = make_pair(buildings[i][1], v_pair[r_idx].second);
						v_temp.push_back(point);
					}
				}
				int v_pair_size = v_pair.size();
				for (int k = r_idx + 1; k < v_pair_size; k++){
					v_temp.push_back(v_pair[k]);
				}
				int m = 0;
				int v_temp_size = v_temp.size();
				for (int k = start; k < v_pair_size&&m < v_temp_size; k++) {
					v_pair[k].first = v_temp[m].first;
					v_pair[k].second = v_temp[m].second;
					m++;
				}
				if (m == v_temp_size) {
					int del_size = v_pair_size - start - v_temp_size;
					int j = 0;
					while (j < del_size) {
						v_pair.pop_back();
						j++;
					}
				}
				else {
					for (; m < v_temp_size; m++) {
						v_pair.push_back(v_temp[m]);
					}
				}
			}
		}
		return v_pair;
	}
	void rotate(vector<int>& nums, int k) {
		int n = nums.size();
		k =  k % n;
		if (!k) return;
		for (int i = 0; i<(n - k) / 2; i++) {
			swap(nums[i], nums[n - k - i - 1]);
		}
		for (int i = n - k; i<n - k + k / 2; i++) {
			swap(nums[i], nums[n - 1 + n - k - i]);
		}
		for (int i = 0; i<n / 2; i++) {
			swap(nums[i], nums[n - i - 1]);
		}
	}
};

int main(void){
	int a[][3] = { 
		/*2, 9, 10, 3, 7, 15, 5, 12, 12,15 ,20 ,10, 19, 24, 8*/
		0, 2, 3, 2, 5, 3
	};
	vector<vector<int>> v; 
	for (int i = 0; i < 2; i++) {
		vector<int> v1(a[i], a[i] + 3);
		v.push_back(v1);
	}
	Solution so;
	so.getSkyline(v);
	int abc[] = { 1, 2, 3, 4, 5 };
	vector<int> vec(abc,abc+2);
	so.rotate(vec, 3);
	return 0;
}