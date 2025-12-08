#include<bits/stdc++.h>
using namespace std;


bool validAnagram(string s, string t){
    if(s.size()!= t.size()) return false;
    unordered_map<char,int>freq;    
    for(int i = 0;i<s.size(); i++){
        if(freq.count(s[i])){
            freq[s[i]]++;
        }else{
            freq[s[i]] =1;
        }
    }


    for(int i = 0; i<t.size(); i++){
        if(freq.count(t[i])){
            freq[t[i]]--;
            if(freq[t[i]] == 0)
            freq.erase(freq[t[i]]);
        }else{
            return false;
        }
    }

    return freq.size()==0;
}
int main(){
       string s = "liquid";
       string t = "lipid";
       cout<<validAnagram(s, t);
}