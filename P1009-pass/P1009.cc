#include<cstdio>

using namespace std;

#define Max 100

char sum[Max];
char scopy[Max];

int Len(char *s){
  int i = 0;
  while (*s++) i++;
  return i;
}

void Add(char* a, char* b){
  int n = (Len(a) > Len(b))? Len(a): Len(b);
  for (int i = 0; i < n; i++){
    if (a[i] < '0' || a[i] > '9') a[i] = '0';
    if (!b[i]) break;
    a[i] += b[i] - '0';
    if (a[i] > '9'){
      a[i] -= 10;
      if (i == n - 1){
        a[i + 1] = '1';
      }else{
        a[i + 1] = a[i + 1] + 1;
        if (a[i + 1] > '9'){
          int count = i + 1;
          while (a[count] > '9'){
            a[count] -= 10;
            count++;
            a[count] = (count < n)? a[count] + 1: '1';
          }
        }
      }
    }
    // printf("ai:%c bi:%c a:%s\n", a[i], b[i],a);
  }
}

void StrCopy(char* s, char* copy){
  int n = Len(s);
  for (int i = 0; i < n; i++){
    copy[i] = s[i];
  }
}

void Mul(char* s, int n){
  StrCopy(s, scopy);
  for (int i = 1; i < n; i++){
    Add(s, scopy);
    // printf("s:%s\n", s);
  }
}

void Sum(char* sum, int n){
  if (n == 1){
    char one[] = "1";
    Add(sum, one);
    return ;
  }else{
    Mul(sum, n);
    char nc[4] = {0};
    nc[1] = n / 10 + '0';
    nc[0] = n % 10 + '0';
    // printf("nc:%s mnc:%s\n", nc, sum);
    Add(sum, nc);
    // printf("sum:%s\n", sum);
    Sum(sum, n - 1);
  }
}

int main(){
  sum[0] = '0';
  // sum[1] = '9';
  int n = 0;
  scanf("%d", &n);
  Sum(sum, n);

  for (int i = Len(sum) - 1; i >= 0; i--){
    printf("%c", sum[i]);
  }
  printf("\n");
  return 0;
}