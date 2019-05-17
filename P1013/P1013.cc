#include<iostream>
#include<string>
using namespace std;

#define MAX 12
string table[MAX][MAX];

int main(){
  #ifdef LOCAL
    freopen("data.in", "r", stdin);
  #endif
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> table[i][j];
    }
  }

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cout << table[i][j] << ", ";
    }
    printf("\n");
  }
  return 0;
}