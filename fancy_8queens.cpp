#include <iostream>
using namespace std;

void print(int q[]);

bool ok(int q[], int c);

int main(){
    int q[8]={0}, c = 0;

    while(c >= 0){
        if(c > 7){
            print(q);
            c--;
            q[c]++;
        }

        if(q[c] > 7){
            q[c] = 0;
            c--;
            if(c != -1) q[c]++;
        }

        else if(ok(q, c)){
            c++;
        } 
        else{
            q[c]++;
        }
    }
    
    return 0;
}

bool ok(int q[], int c) {
    for (int i = 0; i < c; i++){
        if (q[i] == q[c] || (c-i) == abs(q[c]-q[i])){
            return false;
        }
    }

    return true; 
}


void print(int q[]){
    static int count = 0;
    
    count++;
    cout<< "Solution: "<< count << endl;
    
    for(int i=0;i<8;i++){
		cout<< q[i] << " ";
	}
	
	cout<< endl;
    
    int i, j, k, l;
    
    typedef char box[5][7];
    
    box bb, wb, bq, wq, *board[8][8];
    
    // fill in bb(black box), wb(white box), bq(black queen), wq(white queen)
    for(i = 0; i < 5; i++){
        for(j = 0; j < 7; j++){
            wb[i][j] = ' ';
            wq[i][j] = ' ';
            bb[i][j] = '#';
            bq[i][j] = '#';
        }
    }
    
    // white queen
    wq[1][1]='#';
	wq[2][1]='#';
	wq[3][1]='#';
	wq[3][2]='#';
	wq[1][3]='#';
	wq[2][3]='#';
	wq[3][3]='#';
	wq[3][4]='#';
	wq[1][5]='#';
	wq[2][5]='#';
	wq[3][5]='#';
	
	// black queen
	bq[1][1]=' ';
	bq[2][1]=' ';
	bq[3][1]=' ';
	bq[3][2]=' ';
	bq[1][3]=' ';
	bq[2][3]=' ';
	bq[3][3]=' ';
	bq[3][4]=' ';
	bq[1][5]=' ';
	bq[2][5]=' ';
	bq[3][5]=' ';
    
    // fill board with pointers to bb and wb in alternate positions
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            if((i + j) % 2 == 0){
                if(q[i] == j){
					board[i][j] = &wq;
				} else{
                    board[i][j] = &wb;
				}
            } else{
                if(q[i] == j){
					board[i][j] = &bq;
                } else{
                    board[i][j] = &bb;
			    }
            }
        }
    }
    
    // printing the board via pointers in the array board
    
    // printing upper border of the board 
    cout<< "  ";
    
    for(i = 0; i < 7*8; i++){
        cout<< '=';
    }
    
    cout<< endl;
    
    // printing the board
    for(i = 0; i < 8; i++){
        for(k = 0; k < 5; k++){
            cout<< " " << '|';   // printing left border of the board
            
            for(j = 0; j < 8; j++){
                for(l = 0; l < 7; l++){
                    cout<< (*board[i][j])[k][l];
                }
            }
            
            cout<< '|' << endl;
        }
    }
    
    // printing lower border of the board
    cout<< "  ";
    
    for(i = 0; i < 7*8; i++){
        cout<< '=';
    }
    
    cout<< endl << endl;
}


