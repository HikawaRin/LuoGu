#include<cstdio>
#include<map>
#include<vector>
using namespace std;

#define Max 100
char result[Max];
int rpoint = 0;
std::map<int, int> fmap;

int FindFac(int n){
  if (n == 1) return 0;
  if (n == 2) return 1;
  int i = 2;
  while (fmap[i] <= n){
    i++;
  }
  return i - 1;
}

void Make(int n);

void Write(int num){
  result[rpoint++] = '2';
  result[rpoint++] = '(';

  if (num == 0){
    result[rpoint++] = '0';
    result[rpoint++] = ')';
  }else if (num == 1){
    rpoint--;
  }else{
    Make(num);
    result[rpoint++] = ')';
  }

  result[rpoint++] = '+';
}

void Make(int n){
  std::vector<int> sub;
  while (n != 0){
    int f = FindFac(n);
    sub.push_back(f);
    n -= fmap[f];
  }

  for (int i = 0; i < sub.size(); i++){
    Write(sub[i]);
    if (i == sub.size() - 1) result[--rpoint] = 0;
  }
}

int main(){
  int n = 0;
  scanf("%d", &n);
  int fac = 1;
  int i = 0;
  for (; fac < n; i++){
    fmap[i] = fac;
    fac = fac * 2;
  }
  fmap[i] = fac;
  
  Make(n);
  printf("%s\n", result);
  
  return 0;
}