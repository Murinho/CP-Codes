#include <bits/stdc++.h>
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
using namespace std;

static int next_id=0;

struct aho{
  unordered_map<int,aho*> succ;
  aho *fail=nullptr;
  int hits=0;
  int id;

  aho(){
    id=next_id++;
  }

  ~aho(){
    for (auto const &i: succ) delete i.second;
  }

  struct corasick{
    aho *root;

    corasick(vector<vector<int>> dict){
      next_id=0;
      root=new aho();
      root->fail=root;
      for (int i=dict.size(),j; j=0,i--;)
        for (aho *on=root; j!=dict[i].size() or (++on->hits,false); on=on->succ[dict[i][j++]])
          if (not on->succ[dict[i][j]])
            on->succ[dict[i][j]]=new aho();
      queue<aho*> bfs;
      queue<int> bft;
      for (bfs.push(root), bft.push(-1); not bfs.empty(); bfs.pop(),bft.pop()){
        while (bfs.front()->fail!=root   and not bfs.front()->fail->succ[bft.front()]) bfs.front()->fail = bfs.front()->fail->fail;
        if (bfs.front() != bfs.front()->fail and bfs.front()->fail->succ[bft.front()] and bfs.front()->fail->succ[bft.front()]!=bfs.front())
          bfs.front()->fail = bfs.front()->fail->succ[bft.front()];
        bfs.front()->hits+=bfs.front()->fail->hits;
        for (auto &i: bfs.front()->succ)
          if (i.second and not i.second->fail)
            i.second->fail=bfs.front()->fail,
            bfs.push(i.second),
            bft.push(i.first);
      }
    }

    ~corasick(){
      delete root;
    }

    aho *advance(aho *state, int const c) const{
      while (state!=root and not state->succ[c]) state=state->fail;
      if (state->succ[c]) state=state->succ[c];
      return state;
    }
  };
};

int main(){
	fast;
  int a,b; cin>>a>>b;
  vector<vector<int>> needle(a);
  for (auto &i: needle){
    string s; cin>>s;
    for (auto &j: s) i.push_back(j-'a');
  }

  int n,m; cin>>n>>m;
  vector<vector<int>> grid(n);
  for (auto &i: grid){
    string s; cin>>s;
    for (auto &j: s) i.push_back(j-'a');
  }

  aho::corasick row_matcher(needle);
  vector<int> col_needle;
  for (int i=0; i<a; i++){
    aho *state=row_matcher.root;
    for (int j=0; j<b; j++){
      state=row_matcher.advance(state,needle[i][j]);
    }
    col_needle.push_back(state->id);
  }
  aho::corasick col_matcher({col_needle});

  vector<vector<int>> row_results(n,vector<int>(m));
  for (int i=0; i<n; i++){
    aho *state=row_matcher.root;
    for (int j=0; j<m; j++){
      state=row_matcher.advance(state,grid[i][j]);
      row_results[i][j]=state->id;
    }
  }
  vector<vector<int>> col_results(n,vector<int>(m));
  for (int i=0; i<m; i++){
    aho *state=col_matcher.root;
    for (int j=0; j<n; j++){
      state=col_matcher.advance(state,row_results[j][i]);
      if (state->hits){
        ++col_results[j][i];
        if (j>=a and i>=b) ++col_results[j-a][i-b];
        if (j>=a) --col_results[j-a][i];
        if (i>=b) --col_results[j][i-b];
      }
    }
  }
  for (int i=n; i--;)
    for (int j=m; j--;)
      col_results[i][j]+=
          (i+1<n?col_results[i+1][j]:0)+
          (j+1<m?col_results[i][j+1]:0)+
          (i+1<n and j+1<m?-col_results[i+1][j+1]:0);

  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++)
      cout<<(col_results[i][j]?(char)('a'+grid[i][j]):'.');
    cout<<endl;
  }
}
