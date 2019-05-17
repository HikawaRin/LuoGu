#include<cstdio>

using namespace std;

int main(){
  int N;
  scanf("%d", &N);

  int count = 0, level = 0;
  while (count < N){
    level++;
    count += level;
  }
  count -= N;
  int up = 1, down = 1;
  if (level % 2){
    up += count;
    down = level - count;
    printf("%d/%d\n", up, down);
  }else{
    up = level - count;
    down += count;
    printf("%d/%d\n", up, down);
  }

  return 0;
}