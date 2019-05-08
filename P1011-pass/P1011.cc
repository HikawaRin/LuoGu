/* 以下描述下标从1开始
传递函数up[n] = up[n - 1] + up[n - 2] 
            = Fibonacci(n - 2) * up[1] + Fibbonacci(n - 3) * up[2]
      car[n] = car[n - 1] + up[n - 2]
            = car[2] + Sum(up[1:n-2])
            = car[2] + Sum(Fibbonacci(1):Fibbonacci(n - 3)) * up[2] + Fibbonacci(n - 2) * up[1]
*/  
#include<cstdio>

using namespace std;

#define MAX 22
long long fb[MAX], sumfb[MAX];

int main(){
  int a, n, m, x;
  scanf("%d%d%d%d", &a, &n, &m, &x);
  
  if (x == 1 || x == 2){
    printf("%d\n", a);
  }else{
    fb[1] = 1;
    fb[2] = 1;
    sumfb[0] = 0;
    sumfb[1] = 1;
    sumfb[2] = 2;
    for (int i = 3; i < MAX; i++){
      fb[i] = fb[i - 1] + fb[i -2];
      sumfb[i] = fb[i] + sumfb[i - 1];
    }

    n--;
    long long up1 = 0, up2 = 0, carx = 0;
    up1 = a;
    up2 = (m - a - fb[n - 2] * a) / sumfb[n - 3];
    carx = a + fb[x - 2] * a + sumfb[x - 3] * up2;
    printf("%lld\n", carx);
  }

  return 0;
}