#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c){
   for (int i = 0; i < c; i++){
        if (q[i] == q[c] || (c-i) == abs(q[c]-q[i])){
            return false;
        }
   }
    
    return true; 
}


int nqueens(int n){
    int* q = new int[n];
    q[0] = 0;
    int col = 0;
    int count = 0;
   
    while( col >= 0){
        if(col > n-1){
            count++;
            col--;
            q[col]++;
        }

        if(q[col] > n-1){
            q[col] = 0;
            col--;
            if(col != -1){ q[col]++; }
        }
        else if(ok(q, col)){
            col++;
        } 
        else{
            q[col]++;
        }
    }
    
    delete[] q;
    
    return count;
}

int main(){
   int n = 8;
   for (int i = 1; i <= n; ++i)
      cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";
   return 0;
}