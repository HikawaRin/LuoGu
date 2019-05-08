#include<cstdio>

using namespace std;

#define Max 12

int Matrix[Max][Max];

void trace_back(int& sum, int x, int y, int n){
  if (x == n && y == n){
    return ;
  }
  // move right
  
}

int main(){
  #ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
  int N;
  scanf("%d", &N);
  int row = 0, colum = 0, value = 1;
  while (1){
    scanf("%d%d%d", &row, &colum, &value);
    if (row == 0 && colum == 0 && value == 0){
      break;
    }else{
      Matrix[row][colum] = value;
    }
  }


  return 0;
}