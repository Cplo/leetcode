#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<map>
#include<string.h>
#include<string>
#include<queue>
#include<float.h>

// Definition for an interval.
 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };
bool comp(Interval left, Interval right){
		return left.start < right.start;
	}
class Solution {
public:
	/*
	Given [1,3],[2,6],[8,10],[15,18],
	return [1,6],[8,10],[15,18].
	*/
	
	int search(vector<Interval> &array, int T){
		int low, high, mid;
		low = 0;
		high = array.size() - 1;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (array[mid].start < T)
			{
				low = mid + 1;
			}
			else if (array[mid].start>T)
			{
				high = mid - 1;
			}
			else
			{
				return mid;
			}
		}
		if (T < array[mid].start && mid > 0) mid--;
		return mid;
	}
	vector<Interval> merge(vector<Interval>& intervals) {
		if (intervals.empty()) return intervals;
		//sort(intervals.begin(), intervals.end(), comp); 
		vector<Interval> ans;
		ans.push_back(intervals.front());
		int n = intervals.size();
		for (int i = 1; i < n; i++){
			//深打泣荷恬
			if (intervals[i].start == intervals[i].end){
				int idx_l = search(ans, intervals[i].start);
				if (intervals[i].start < ans[idx_l].start){
					ans.insert(ans.begin() + idx_l, intervals[i]);
				}
				else if (intervals[i].start > ans[idx_l].end){
					ans.insert(ans.begin() + idx_l + 1, intervals[i]);
				}
				continue;
			}
			int idx_l = search(ans, intervals[i].start);
			int idx_r = search(ans, intervals[i].end);
			if (intervals[i].end < ans[idx_l].start) ans.insert(ans.begin() + idx_l, intervals[i]);
			else if (intervals[i].start > ans[idx_l].end) {
				//idx_l+1！！idx_r
				if (ans[idx_r].end < intervals[i].end) {
					if (idx_r == idx_l) { ans.insert(ans.begin() + idx_l + 1, intervals[i]); continue; }
					if (idx_l + 1 < ans.size()) {
						if (ans[idx_l + 1].start > intervals[i].start) ans[idx_l + 1].start = intervals[i].start;
						ans[idx_l + 1].end = intervals[i].end;
						int count = idx_r - idx_l - 1;
						for (int j = 0; j < count; j++){
							ans.erase(ans.begin() + idx_l + 2);
						}
					}
					else
					{
						Interval tt(intervals[i].start, intervals[i].end);
						ans.push_back(tt);
					}
				}
				else{
					if (idx_l + 1 < ans.size()){
						if (ans[idx_l + 1].start > intervals[i].start) ans[idx_l + 1].start = intervals[i].start;
						ans[idx_l + 1].end = ans[idx_r].end;
						int count = idx_r - idx_l - 1;
						for (int j = 0; j < count; j++){
							ans.erase(ans.begin() + idx_l + 2);
						}
					}
					else
					{
						Interval tt(intervals[i].start, ans[idx_r].end);
						ans.push_back(tt);
					}
				}
			}
			else{
				//idx_l！！idx_r
				if (ans[idx_l].start > intervals[i].start) ans[idx_l].start = intervals[i].start;
				if (ans[idx_r].end < intervals[i].end)
					ans[idx_l ].end = intervals[i].end;
				else
					ans[idx_l ].end = ans[idx_r].end;
				int count = idx_r - idx_l;
				for (int j = 0; j < count; j++)
					ans.erase(ans.begin() + idx_l + 1);
			}
		}
		return ans;
	}

	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> ans;
		if (intervals.empty()) { ans.push_back(newInterval); return ans; }
		
		if (newInterval.start <= intervals.front().start&&newInterval.end >= intervals.back().end) { ans.push_back(newInterval); return ans; }
		if (newInterval.start == newInterval.end){
			int idx_l = search(intervals, newInterval.start);
			if (newInterval.start < intervals[idx_l].start){
				intervals.insert(intervals.begin() + idx_l, newInterval);
			}
			else if (newInterval.start > intervals[idx_l].end){
				intervals.insert(intervals.begin() + idx_l + 1, newInterval);
			}
			return intervals;
		}
		int idx_l = search(intervals, newInterval.start);
		int idx_r = search(intervals, newInterval.end);
		if (newInterval.end < intervals[idx_l].start) intervals.insert(intervals.begin() + idx_l, newInterval);
		else if (newInterval.start > intervals[idx_l].end) {
			//idx_l+1！！idx_r
			if (intervals[idx_r].end < newInterval.end) {
				if (idx_r == idx_l) { intervals.insert(intervals.begin() + idx_l + 1, newInterval); return intervals; }
				if (idx_l + 1 < intervals.size()) {
					if (intervals[idx_l + 1].start > newInterval.start) intervals[idx_l + 1].start = newInterval.start;
					intervals[idx_l + 1].end = newInterval.end;
					int count = idx_r - idx_l - 1;
					for (int j = 0; j < count; j++){
						intervals.erase(intervals.begin() + idx_l + 2);
					}
				}
				else
				{
					Interval tt(newInterval.start, newInterval.end);
					intervals.push_back(tt);
				}
			}
			else{
				if (idx_l + 1 < intervals.size()){
					if (intervals[idx_l + 1].start > newInterval.start) intervals[idx_l + 1].start = newInterval.start;
					intervals[idx_l + 1].end = intervals[idx_r].end;
					int count = idx_r - idx_l - 1;
					for (int j = 0; j < count; j++){
						intervals.erase(intervals.begin() + idx_l + 2);
					}
				}
				else
				{
					Interval tt(newInterval.start, intervals[idx_r].end);
					intervals.push_back(tt);
				}
			}
		}
		else{
			//idx_l！！idx_r
			if (intervals[idx_l].start > newInterval.start) intervals[idx_l].start = newInterval.start;
			if (intervals[idx_r].end < newInterval.end)
				intervals[idx_l].end = newInterval.end;
			else
				intervals[idx_l].end = intervals[idx_r].end;
			int count = idx_r - idx_l;
			for (int j = 0; j < count; j++)
				intervals.erase(intervals.begin() + idx_l + 1);
		}
		return intervals;
	}
};

int main(){
	Solution so;
	vector<Interval> v;
	Interval a1(1, 2);
	Interval a2(3, 4);
	Interval a3(5, 6);
	Interval a4(8, 10);
	Interval a5(12, 16);
	Interval a6(5, 7);
	Interval a7(0, 0);
	Interval a8(5, 6);
	Interval a9(0, 7);
	Interval a10(5, 6);
	v.push_back(a1);
	v.push_back(a2);
	v.push_back(a3);
	//v.push_back(a4);
	//v.push_back(a5);
	//v.push_back(a6);
	//v.push_back(a7);
	//v.push_back(a8);
	v.push_back(a9);
	//v.push_back(a10);
	v = so.merge(v);
	so.insert(v, a9);
	/*int array[] = { 1, 3, 5, 8, 13 };
	cout << so.search(array, 5, 7) << endl;*/
	return 0;
}