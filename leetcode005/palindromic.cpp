#include<iostream>
using namespace std;
#include<string>
class Solution {
public:
	string longestPalindrome(string s) {
		string s1;
		string ans;
		for (int i = 0; i < s.length(); i++)
		{
			s1 += "#";
			s1 += s[i];
		}
		s1 += "#";										//#a#b#c#b#a#d#c#
		int mx=0, id=0;
		int p[2005];
		int j,k;
		for (int i = 0; i < s1.length(); i++)
		{
			if (i < mx){
				j = 2 * id - i;
				if (j - p[j] > id - p[id]) p[i] = p[j];
				else {
					p[i] = p[j];
					while (i-p[i]>=0&&i+p[i]<s1.length()&&(s1[i+p[i]]==s1[i-p[i]]))
					{
						p[i]++;
					}
					if (p[i] > p[id]){
						id = i; mx = i + p[i] - 1;
					}
				}
			}
			else{
				p[i] = 1;
				while (i - p[i] >= 0 && i + p[i]<s1.length() && (s1[i + p[i]] == s1[i - p[i]]))
				{
					p[i]++;
				}
				if (p[i] > p[id]){
					id = i; mx = i + p[i] - 1;
				}
			}
		}
		for (int i = id - p[id] + 1; i < id + p[id]; i++)
			if (s1[i] != '#')
				ans += s1[i];

		return ans;
	}
};
int main()
{
	Solution so;
	cout << so.longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth") << endl;
	return 0;
}