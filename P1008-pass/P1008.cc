#include<cstdio>
#include<set>
using namespace std;

std::set<int> UsedNumber;
int num1, num2, num3;

bool check(){
  num1 = num2 / 2;
  num3 = num1 * 3;
  if (num1 < 100 || num3 > 999){
    UsedNumber.clear();
    return false;
  }
  int n1 = num1, n3 = num3;
  for (int i = 0; i < 3; i++){
    int one = n1 % 10;
    int three = n3 % 10;
    if (one < 1 || one > 9 || three < 1 || three > 9) {
      UsedNumber.clear();
      return false;
    }
    if (one == three){
      UsedNumber.clear();
      return false;
    }
    if (UsedNumber.count(one) || UsedNumber.count(three)) {
      UsedNumber.clear();
      return false;
    }
    UsedNumber.insert(one); 
    UsedNumber.insert(three);
    n1 /= 10; n3 /= 10; 
  }
  UsedNumber.clear();
  return true;
}

int main(){
  #ifdef LOCAL
    freopen("data.out", "w", stdout);
  #endif
  UsedNumber.clear();
  for (int f = 1; f < 10; f++){
    for (int t = 1; t < 10; t++){
      if (t == f) continue;
      for (int s = 1; s < 10; s++){
        if (s == f || s == t) continue;
        num1 = 0; num2 = 0; num3 = 0;
        num2 = f * 100 + s * 10 + t;
        UsedNumber.insert(f);
        UsedNumber.insert(s);
        UsedNumber.insert(t);
        if (check()) printf("%d %d %d\n", num1, num2, num3);
      }
    }
  }

  return 0;
}
