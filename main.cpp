#include <iostream>
#include <queue>
#include <utility> //queue 쓰일때는 상관 없음
using namespace std;

int main(){
  int T;
  cin >> T;
  for(int i=0;i<T;i++){
    queue<pair<int,int>> a;
    int map[52][52]={0,};
    int M,N,K;
    cin>>M>>N>>K;

    int x,y;
    for(int j=0;j<K;j++){
      cin>>x>>y;
      map[x+1][y+1]=1;
    }

    for(int j=1;j<=M;j++){
      for(int k=1;k<=N;k++){
        if(map[j][k]==1){
          map[j][k]=2;
          a.push(pair<int,int>(j,k));

          while(!a.empty()){
            if(a.front().first>M || a.front().first<0 || a.front().second>N || a.front().second<0)
            {
              a.pop();
            }
            if(map[a.front().first-1][a.front().second]==1){
              map[a.front().first-1][a.front().second]=0;
              a.push(pair<int,int>(a.front().first-1,a.front().second));
            }if(map[a.front().first+1][a.front().second]==1){
              map[a.front().first+1][a.front().second]=0;
              a.push(pair<int,int>(a.front().first+1,a.front().second));
            }if(map[a.front().first][a.front().second-1]==1){
              map[a.front().first][a.front().second-1]=0;
              a.push(pair<int,int>(a.front().first,a.front().second-1));
            }if(map[a.front().first][a.front().second+1]==1){
              map[a.front().first][a.front().second+1]=0;
              a.push(pair<int,int>(a.front().first,a.front().second+1));
            }
            a.pop();
          }
        }

      }
    }
    int ans=0;
    for(int j=1;j<=M;j++){
      for(int k=1;k<=N;k++){
        if(map[j][k]==2) ans++;
      }
    }
    cout<<ans;
  }
  return 0;
}
