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
#include<cstdlib>
using namespace std;

//Definition for a point.
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
	int maxPoints(vector<Point>& points) {
		int n = points.size();
		if (n <= 1) return n;
		int ans = 1;
		map<int, int> m_x;
		map<int, int> m_y;
		map<int, map<int, int>> point_num;
		for (int i = 0; i < n; i++) {
			m_x[points[i].x]++; m_y[points[i].y]++;
			ans = max(m_x[points[i].x], ans);
			ans = max(m_y[points[i].y], ans);
			point_num[points[i].x][points[i].y]++;
		}
		vector<Point> p;
		map<int, map<int, int>> m_point;
		for (int i = 0; i < n; i++) {
			if (m_point.find(points[i].x) == m_point.end() || m_point[points[i].x].find(points[i].y) == m_point[points[i].x].end()) {
				p.push_back(points[i]);
				m_point[points[i].x][points[i].y]++;
			}
			else continue;
		}
		n = p.size();
		map<double, map<double, int>> m_edge_num;
		map<double, map<double, int>> m_edge_have;
		for (int i = 1; i < n; i++) {
			m_edge_have.clear();
			for (int j = 0; j < i; j++) {
				int x = p[i].x - p[j].x;
				int y = p[i].y - p[j].y;
				if (!x || !y) continue;
				double k = (double)y / x;
				double b = p[i].y - k * p[i].x;
				char ch[100];
				sprintf(ch, "%lf", k);
				sscanf(ch, "%15lf", &k);
				sprintf(ch, "%lf", b);
				sscanf(ch, "%15lf", &b);
				//k = (int)k + ((int)((k-(int)k) * 100000000000000)) / 100000000000.0;
				//b = (int)b + ((int)((b-(int)b) * 100000000000)) / 100000000000.0;
				//新边，两点个数都加，否则只加i点的个数
				if (m_edge_num.find(k) == m_edge_num.end() || m_edge_num[k].find(b) == m_edge_num[k].end()) {
					m_edge_num[k][b] = point_num[p[i].x][p[i].y] + point_num[p[j].x][p[j].y];
					ans = max(m_edge_num[k][b], ans);
				}
				else {
					if (m_edge_have.find(k) == m_edge_have.end() || m_edge_have[k].find(b) == m_edge_have[k].end()) {
						m_edge_num[k][b] += point_num[p[i].x][p[i].y];
						ans = max(m_edge_num[k][b], ans);
						m_edge_have[k][b] = 1;
					}
				}
			}
		}
		return ans;
	}
};

int main(void) {
	Solution so;
	vector<Point> v;
	//[84,250] [0,-70]  [21, 10]  [42,90]
	//[[84,250],[0,0],[1,0],[0,-70],[0,-70],[1,-1],[21,10],[42,90],[-42,-230]]
	//Point *p = new Point(0, 0);
	//Point *p1 = new Point(1, 1);
	//Point *p2 = new Point(1, -1);
	//Point *p3 = new Point(0, -70);
	//Point *p4 = new Point(0, -70);
	//Point *p5 = new Point(1, -1);
	//Point *p6 = new Point(21, 10);
	//Point *p7 = new Point(42, 90);
	//Point *p8 = new Point(-42, -230);v.push_back(*p);
	/*v.push_back(*p);
	v.push_back(*p1);
	v.push_back(*p2);*/
	//v.push_back(*p4);
	//v.push_back(*p5);
	//v.push_back(*p6);
	//v.push_back(*p7);
	//v.push_back(*p8);
	Point px[] = { 
		Point(0, 9), Point(138, 429), Point(115, 359), Point(115, 359), Point(-30, -102), 
		Point(230, 709), Point(-150, -686), Point(-135, -613), Point(-60, -248), Point(-161, -481), 
		Point(207, 639), Point(23, 79), Point(-230, -691), Point(-115, -341), Point(92, 289), 
		Point(60, 336), Point(-105, -467), Point(135, 701), Point(-90, -394), Point(-184, -551), Point(150, 774) };
	//[[0, 9], [138, 429], [115, 359], [115, 359], [-30, -102], [230, 709], [-150, -686], [-135, -613], [-60, -248], [-161, -481], [207, 639], [23, 79], [-230, -691], [-115, -341], [92, 289], [60, 336], [-105, -467], [135, 701], [-90, -394], [-184, -551], [150, 774]]
	for (int i = 0; i < 21; i++) {
		v.push_back(px[i]);
	}
	cout << so.maxPoints(v) << endl;
	return 0;
}