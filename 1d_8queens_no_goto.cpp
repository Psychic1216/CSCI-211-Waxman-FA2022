//Ng, Timothy / Ibrahim, Md
//CS 211 21A
//Homework #4
//Redo the 8 queens 1 dimensional array program with backtracking WITHOUT gotos.

#include <iostream>
#include <cmath>

using namespace std;

bool ok(int b[], int c){    // checks if queen placement is ok, just like 1D Queens with goto
    for(int i = 0; i < c; i++){
        if(b[i] == b[c] || (c - i) == abs(b[c] - b[i])){ 
          return false; 
          }
    }
    return true;
}

void backtrack(int & c){
  c--;
  if(c==-1){
    exit(1);
  }
}

void print(int b[]){      // Prints all of the solutions to the Queen problems
    static int count = 1;      //Stops the variable from re-initializing itself over and over
    cout<< endl << "Solution count: " << count++ << endl << endl;
    
    for(int i=0; i<8; i++){
          for(int j=0; j<8; j++){
                if(i == b[j]){
                    cout <<"1 ";
                }else{
                    cout <<"0 ";
                }
        }
        cout << endl;
    } 
}

int main(){
  int b[8] = {};      // Initialize the array and column to be 0.
  int c = 0; 
  b[c] = 0;

  while (c >= 0){
    c++;      // Move to the next column.
    if (c == 8){
      print(b);      // If end of column is passed backtrack to c--;
      c--; 
    }
    else b[c] = -1;      // Else, move one before the first row.

    while (c >= 0){
      b[c]++;      // Goes to the next row.
      if (b[c] == 8) c--;      // If the row went outside of the board, backtrack to previous column.
      else if (ok(b, c)) 
        break;      // Else check with the "ok" function to see if the sequence is okay. If the sequence is valid, leave the inner loop and continue with the outer loop.
    }
  }
  return 0;
}