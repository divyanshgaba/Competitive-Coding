#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

bool found[10];
ifstream fin("input.in");
ofstream fout("output.out");
int main() {
  int t; fin>>t;
  for (int tc = 1; tc <= t; tc++) {
    int n; fin>>n;

    int last = 0;
    if(n != 0) {
      memset(found, 0, sizeof(found));

      bool foundAll = false;
      while(!foundAll) {
        int next = last = last + n;
        while(next != 0) { found[next % 10] = true; next /= 10; }

        foundAll = true;
        for(int j = 0; j < 10; j++) {
          if(!found[j]) { foundAll = false; break; }
        }
      }
    }

    if(last == 0) fout<<"Case #"<<tc<<": INSOMNIA"<<endl;
    else fout<<"Case #"<<tc<<": "<<last<<endl;
  }
  return 0;
}
