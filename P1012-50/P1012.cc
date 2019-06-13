#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int main(){
  #ifdef LOCAL
    freopen("data.in", "r", stdin);
  #endif
  int n = 0;
  vector<int> nums;
  map<int, vector<int> > numCache;
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    int val = 0;
    scanf("%d", &val);
    nums.push_back(val);
    vector<int> s;
    while (val > 10){
      int n = val % 10;
      val /= 10;
      s.push_back(n);
    }
    s.push_back(val);
    numCache[nums[nums.size() - 1]] = s;
  }
  sort(nums.begin(), nums.end(), [&numCache](int a, int b) -> bool { 
    auto apoint = numCache[a].end() - 1;
    auto bpoint = numCache[b].end() - 1;
    while (apoint != numCache[a].begin() && bpoint != numCache[b].begin()){
      if (*apoint > *bpoint) return true;
      else if (*apoint < *bpoint) return false;
      else{
        apoint--; bpoint--;
      }  
    }
    if (apoint == numCache[a].begin()){
      if (bpoint != numCache[b].begin()){
        return true;
      }else{
        return *apoint > *bpoint;
      }
    }
    return false; 
    });
  long long result = 0;
  for (int i = 0; i < nums.size(); i++){
    printf("%d, ", nums[i]);
    int pow = 10;
    for (int j = 1; j < numCache[nums[i]].size(); j++){
      pow *= 10;
    }
    result = result * pow + nums[i];
  }
  printf("\n");
  printf("%lld\n", result);

  return 0;
}