#include<cstdio>

using namespace std;

#define MAX 100
char math[MAX];
char result[MAX];

int Len(char* s){
  int n = 0;
  while (*s++) n++;
  return n;
}

void PutOne(char* s, int& startAt){
  s[startAt++] = ')';
  s[startAt++] = '0';
  s[startAt++] = '(';
  s[startAt++] = '2';
}

int main(){
  int n = 0;
  int rpoint = 0;
  scanf("%d", &n);
  while (n != 1){
    if (n % 2){
      n -= 1;
      math[rpoint++] = '1';
      math[rpoint++] = '+';
    }
    n /= 2;
    math[rpoint++] = '2';
    math[rpoint++] = '*';
  }
  math[rpoint] = '1';

  int _twoCount = 0;
  rpoint = 0;
  for (int i = 0; i < Len(math); i++){
    if (math[i] == '1'){
      PutOne(result, rpoint);
    }else if (math[i] == '+'){
      result[rpoint++] = '+';
    }else if (math[i] == '2'){
      _twoCount++;
      i = i + 1;
      if (math[i + 1] == '1'){
        result[rpoint++] = '2';
        i++;
      }
    }
  }

  printf("%s\n", math);
  for (int i = Len(result); i >= 0; i--){
    printf("%c", result[i]);
  }
  printf("\n");

  return 0;
}