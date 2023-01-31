#include <iostream>
#include <cmath>
using namespace std;
 
bool okay(int cross[], int box) {
  //Helper array
  static int adj_table[8][5] = { 
   {-1}, //box 0
   {0, -1}, //box 1
   {0, 1, -1}, //box 2
   {0, 2, -1}, //box 3
   {1, 2, -1}, //box 4
   {1, 2, 3, 4, -1}, //box 5
   {2, 3, 5, -1}, //box 6
   {4, 5, 6, -1} //box 7
};

   // Test 1: Similar to  eight-queens style row-check; if the test fails, return false
  for(int i = 0; i < box; i++) {
     if(cross[box] == cross[i])
      return false;
   }
 
   // Test 2: consecutive number check, hence the need for the adjacency table.
    for(int i = 0; adj_table[box][i] != -1; i++) {
      if(abs(cross[box] - cross[adj_table[box][i]]) == 1)
            return false;
    //Moves on to next neighbor box
  }
    return true;
  }

void print(int cross[]) {
   static int solutions = 1;   //Stops the varible from re-initializing itself over and over

   cout << "Solutions #" << solutions << ":" << endl;
   cout << " " << " " << cross[1] << " " << cross[4] << " " << endl;
   cout << cross[0] << " " << cross[2] << " " << cross[5] << " " << cross[7] << " " << endl;
   cout << " " << " " << cross[3] << " " << cross[6] << " " << endl;

   cout << endl;
   solutions++;
}

int main() {
    int b[8] = {};      
    int c = 0; 
    b[c] = 1;
  
    while(c >= 0){
	    if( c > 7 ){
			print(b) ;
			c-- ;
		}
		else{ b[c] = 0 ; }
		
		while(c >= 0 && c < 8){
			b[c]++ ;
			
			if(b[c] > 8) { c-- ; }
			else if( okay( b, c ) ==  true ){
				c++ ;
				break ;
			}
		}
	}
    return 0;
}
