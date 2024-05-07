#include <bits/stdc++.h>

using namespace std;

vector<int> prefix(string s){
    vector<int> p(s.length());
    for(int i =1;i<s.length();i++){
        int j = p[i-1];
        while(j>0 && s[i]!=s[j]) j = p[i-1];
        if(s[i]==s[j]) j++;
        p[i]=j;
    }
    return p;
}

int KMP(string t,string f){
    int ans=-1;
    string concat = f+'#'+t;
    vector<int> p =prefix(concat);
    for(int i = f.size()+1;i<concat.size();i++){
        if(p[i]==f.size()){
            ans = i-2*f.size();
        }
    }
    return ans;
}
int main() {
	string s;
    cin >> s;
	s[0] += 32;
    int n;
    cin >> n;
	vector<string> cities;
	vector<int> num;
    while(n--){
        string t;
        cin >> t;
		t[0] += 32;
		cities.push_back(t);
    }
	int max = -1;
	for(int i = 0; i < cities.size(); i++){
		string ss = cities[i] + s;
		vector<int> v = prefix(ss);
		int k = v.back();
		if(max < k){
			max = k;
		}
		num.push_back(k);
	}
	vector<string> ans;
	for(int i = 0; i < num.size(); i++){
		if(num[i] == max && num[i] > 0){
			cities[i][0] -= 32;
			ans.push_back(cities[i]);
		}
	}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << endl;
	}
	return 0;
}