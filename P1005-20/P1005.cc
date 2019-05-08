#include<cstdio>
using namespace std;

#define Max 82

int Matrix[82][82];

long long SumOfRow(int rowIndex, int m){
  int left = 0, right = m - 1;
  long long sum = 0, i = 2;
  while (left <= right){
    if (Matrix[rowIndex][left] < Matrix[rowIndex][right]){
      sum += (Matrix[rowIndex][left] * i);
      left++;
    }else{
      sum += (Matrix[rowIndex][right] * i);
      right--;
    }
    i *= 2;
  }
  return sum;
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      scanf("%d", &Matrix[i][j]);
    }
  }

  long long sum = 0;
  for (int i = 0; i < n; i++){
    sum += SumOfRow(i, m);
  }

  printf("%lld", sum);

  return 0;
}