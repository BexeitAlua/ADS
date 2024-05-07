#include<bits/stdc++.h>

using namespace std;

bool comp(string& s,string & s2){
    return s.size()<=s2.size();
}

vector<string> merge(vector<string>le,vector<string> ri){
    vector<string> res;

    int l =0;
    int r=0;
    while(l<le.size()&& r<ri.size()){
            if(comp(le[l],ri[r])){
                res.push_back(le[l++]);
            }else{
                res.push_back(ri[r++]);
            }
    }

    while(l<le.size()){
        res.push_back(le[l++]);

    }
    while(r<ri.size()){
        res.push_back(ri[r++]);
    }
    return res;
}

vector<string> msort(vector<string> a,int l,int r){
    if(l==r){
        vector<string> res;
        res.push_back(a[l]);
        return res;
    }
    int m = l+(r-1)/2;
    vector<string> le = msort(a,l,m);
    vector<string> ri = msort(a,m+1,r);
    return merge(le,ri);
}

int main(){
  string n;
	getline(cin,n);
	int k = stoi(n);
    for(int j = 0; j < k; j++){
        string s;
        getline(cin,s);
      
        vector<string> v;
	    string t = "";
	    for (int i = 0; i < s.length(); i++) {
		    if (s[i] != ' ') {
			    t += s[i];
		    } else if (s[i] == ' ') { 
			    v.push_back(t);
			    t = "";
		    }
        }
        if(t.size() != 0) v.push_back(t);
        vector<string> ans = msort(v, 0, v.size() - 1);
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;

    
}