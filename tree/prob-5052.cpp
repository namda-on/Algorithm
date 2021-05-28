#include<bits/stdc++.h>

using namespace std;

struct node {
    bool valid;
    int child[10];
    node() {
        valid = 0;
        memset(child, -1, sizeof(child));
    }
};

vector<node> trie;

int init(){
    node x;
    trie.push_back(x);
    return (int)trie.size() - 1;
}

void add(int n, string &s, int i){
    if(i == s.length()){
        trie[n].valid = true;
        return;
    } 

    int c = s[i] - '0';
    if(trie[n].child[c] == -1){
        int next = init();
        trie[n].child[c] = next;
    }

    add(trie[n].child[c], s, i + 1);
}

bool find(int n, string &s, int i){
    if(i == s.length()) return false; 
    if(trie[n].valid) return true;


    int c = s[i] - '0';
    if(trie[n].child[c] == - 1)  return false;

    return find(trie[n].child[c], s, i+1);
}




int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    while(n--){
        init();
        int t;
        cin >> t;
        vector<string> v;
        for(int i=0; i<t; i++){
            string s;
            cin >> s;
            v.push_back(s);
            add(0, s, 0);
        }
        bool result = true;
        for(int i=0; i<v.size(); i++){
            if(find(0, v[i], 0)) {
                result = false; 
                break;
            }
        }
        cout << (result ? "YES" : "NO") << "\n"; 
        trie.clear();
    }

}