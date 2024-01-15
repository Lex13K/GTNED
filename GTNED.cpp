#include<iostream>
using namespace std;

void findDominatedPlayerOne(float a[100][100][2], int n, int m) {
  bool weakly = false, dominated = true,fist = false;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i == j) continue;
      for(int k = 0; k < m; k++) {
        if(a[i][k][0] == a[j][k][0]) weakly = true;
        else if(a[i][k][0] > a[j][k][0]) {
          dominated = false;
          break;
          }
      }
      if(dominated == true && weakly == false) {
        if(fist == false) {
          cout<<"For player 1, dominated strategies (rows) are:"<<endl;
          fist = true;
        }
        cout<<"Strictly row "<<i + 1<<" by row "<<j + 1<<endl;
      } 
      else if (dominated && weakly) {
        if(fist == false) {
          cout<<"For player 1, dominated strategies (rows) are:"<<endl;
          fist = true;
        }
        cout<<"Weakly row "<<i + 1<<" by row "<<j + 1<<endl;
      }
      dominated = true;
      weakly = false;
    }
  }
}
void findDominatedPlayerTwo(float a[100][100][2], int n, int m) {
  bool weakly = false, dominated = true,fist = false;

  for(int i = 0; i < m; i++) {
    for(int j = 0; j < m; j++) {
      if(i == j) continue;
      for(int k = 0; k < n; k++) {
        if(a[k][i][1] == a[k][j][1]) weakly = true;
        else if(a[k][i][1] > a[k][j][1]) {
          dominated = false;
          break;
          }
      }
      if(dominated == true && weakly == false) {
        if(fist == false) {
          cout<<"For player 2, dominated strategies (columns) are:"<<endl;
          fist = true;
        }
        cout<<"Strictly column "<<i + 1<<" by column "<<j + 1<<endl;
      } 
      else if (dominated && weakly) {
        if(fist == false) {
          cout<<"For player 2, dominated strategies (columns) are:"<<endl;
          fist = true;
        }
        cout<<"Weakly column "<<i + 1<<" by column "<<j + 1<<endl;
      }
      dominated = true;
      weakly = false;
    }
  }
}
void findNashEquilibrium(float a[100][100][2], int n, int m) {
  float mx = 0;
  bool fist = false;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
    mx = a[i][0][1];
      for(int k = 1; k < m; k++) {  
        if(a[i][k][1] > mx) mx = a[i][k][1];
      }
      if(mx == a[i][j][1]) {
        mx = a[0][j][0];
        for(int k = 1; k < n; k++) {
        if(a[k][j][0] > mx) mx = a[k][j][0];
        }
        if(mx == a[i][j][0]) {
          if(fist == false) {
            cout<<"Nash equilibrium points are: "<<endl;
            fist = true;
          }
          cout<<"("<<i+1<<", "<<j+1<<")"<<endl;
        }
      } 
    }
  }
  if(fist == false) cout<<"There are no Nash equilibrium points"<<endl;
}
int main() {

  float a[100][100][2];
  int n,m;


  cout<<"Input dimensions of table (nRows x nColumns) "<<endl;
  cin>>n>>m;

  cout<<"Outcomes for Player 1: "<<endl;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin>>a[i][j][0];
    }
  }

  cout<<"Outcomes for Player 2: "<<endl;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin>>a[i][j][1];
    }
  }

  findDominatedPlayerOne(a, n, m);
  findDominatedPlayerTwo(a, n, m);

  findNashEquilibrium(a, n, m);
  return 0;
}