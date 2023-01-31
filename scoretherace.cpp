#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include <bits/stdc++.h>
using namespace std;

string order(string str){      // Orders the string given alphabetically
    char c;
    int n = str.length();
    string result;
    
    for(int x = 65; x <= 90; x++){
        c = x;      // Converts ASCII integer values into characters starting from 'A' to 'Z'
        
        for(int y = 0; y < n; y++){
            char convert[n];
            convert[y] = str[y];
            if(str[y] == c){ result += convert[y]; }
        }
    }
    
    return result;
}

int uniqueNumChar(string str){
    unordered_set<char> s;
    int n = str.size();
    
    for(int i = 0; i < n; i++){ s.insert(str[i]); }
    
    return s.size();
}

bool vaild(string outcome){      // This function was worked on together with group member
    std::string s = outcome;
    std::string::difference_type A = std::count(s.begin(), s.end(), 'A');
    std::string::difference_type B = std::count(s.begin(), s.end(), 'B');
    std::string::difference_type C = std::count(s.begin(), s.end(), 'C');
    std::string::difference_type D = std::count(s.begin(), s.end(), 'D');
    std::string::difference_type E = std::count(s.begin(), s.end(), 'E');
    std::string::difference_type F = std::count(s.begin(), s.end(), 'F');
    std::string::difference_type G = std::count(s.begin(), s.end(), 'G');
    std::string::difference_type H = std::count(s.begin(), s.end(), 'H');
    std::string::difference_type I = std::count(s.begin(), s.end(), 'I');
    std::string::difference_type J = std::count(s.begin(), s.end(), 'J');
    std::string::difference_type K = std::count(s.begin(), s.end(), 'K');
    std::string::difference_type L = std::count(s.begin(), s.end(), 'L');
    std::string::difference_type M = std::count(s.begin(), s.end(), 'M');
    std::string::difference_type N = std::count(s.begin(), s.end(), 'N');
    std::string::difference_type O = std::count(s.begin(), s.end(), 'O');
    std::string::difference_type P = std::count(s.begin(), s.end(), 'P');
    std::string::difference_type Q = std::count(s.begin(), s.end(), 'Q');
    std::string::difference_type R = std::count(s.begin(), s.end(), 'R');
    std::string::difference_type S = std::count(s.begin(), s.end(), 'S');
    std::string::difference_type T = std::count(s.begin(), s.end(), 'T');
    std::string::difference_type U = std::count(s.begin(), s.end(), 'U');
    std::string::difference_type V = std::count(s.begin(), s.end(), 'V');
    std::string::difference_type W = std::count(s.begin(), s.end(), 'W');
    std::string::difference_type X = std::count(s.begin(), s.end(), 'X');
    std::string::difference_type Y = std::count(s.begin(), s.end(), 'Y');
    std::string::difference_type Z = std::count(s.begin(), s.end(), 'Z');
    
    int teams = 0;
    int last = 0;
    long int members[26] = {A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z};

    for(int i = 0; i < 26; i++){
        if(members[i] != 0){ 
            teams++;
            last = members[i];
        }
    }
    
    for(int i = 0; i < 26; i++){
        if(members[i] != 0 && last != members[i]){ return false; }
        else{ return true; }
    }
    
    return false;
}

double score(string outcome, string teams, char c){
    int n1 = teams.length();
    int n2 = outcome.length();
    double result;
    double sum = 0;
    int pos[n1][n2 / n1 + 1];
    size_t found;
    
    for(int x = 0; x < n1; x++){
        pos[x][0] = teams[x];
        found = outcome.find(pos[x][0]);

        for(int y = 1; y < n2/n1 + 1; y++){
            for(int z = 0; z < n2; z++){
                if(outcome[z] == pos[x][0] && pos[x][0] == teams[x]){
                    pos[x][y] = found;
                    found = outcome.find(pos[x][0], found + 1);
                }
            }            
        }
    }
    
    for(int x = 0; x < n1; x++){
        for(int y = 1; y < n2/n1 + 1; y++){
            if(pos[x][0] == c){
                sum+= pos[x][y] + 1;
                result = sum / (n2/n1);
            }
        }
    }
    
    return result;
}

int main(){
    loop:string outcome, outcome_ordered, teams;      // goto loops back to the very beginning of main() to easily reinitialize everything so there's no left over values from previous runs to mess up the next run.
    int runners = 0, numTeams = 0;
    
    cout<< "Please enter the outcome of the race: ";
    cin>> outcome;
    cout<< endl;
    
    if(outcome == "done"){      // If user types "done", the code ends running here
        return 0;
    }
  
    outcome_ordered = order(outcome);
  
    if(vaild(outcome_ordered) == false){      // If the vaild() functions returns 0 (false), then the code will loop back to the beginnning of main() till 1 (true) is returned
        cout<< "Error: Teams do not have the same number of runners" << endl;
        goto loop;
    }
  
    numTeams = uniqueNumChar(outcome_ordered);
    runners = outcome.length()/numTeams;
    
    cout<< "There are " << numTeams << " teams" << endl;
    cout<< "Each team has " << runners << " runners"<< endl;
    cout<< endl << "Team: \tScore:" << endl;
    
    for(int i = 0; i < outcome_ordered.length(); i+= runners){      // This is to have 'teams' store the names of every team in the race
        teams+= outcome_ordered[i];
    }
    
    double s;
    double min_s = score(outcome, teams, outcome[0]);      // I can't find the ACTUAL minimum score because I need a some sort of consistent baseline value (no for loops), so I chose the score of whatever team's runner that finished 1st
    
    for(char c:teams){
        s = score(outcome, teams, c);
        cout<< c << '\t' << s << endl;
    }

    for(char c:teams){      // Made a whole new loop inorder to format the output correctly so I don't get too much headache messing with the previous for loop
        s = score(outcome, teams, c);
        
        if(s < min_s){      // Because 'min_s' previous comment about its problem, I had to come up with a solution with if statements to find the real winning team of the race
            cout<< endl << "The winning team is " << c << " with the score " << s << endl;
            break;      // This is here so the for loop doesn't keep repeating the if statements where it would output every team being a winner
        } else if(s == min_s){       // Because there's a possible condition where the winning team has the same score as 'min_s', I had to create this if statement
            cout<< endl << "The winning team is " << c << " with the score " << s << endl; 
        }
    }
    
    cout<< endl;
    
    goto loop;      // Loops back to the very beginning where the first line of main() is tagged 'loop'
                    // goto is what I've learned in Prof. Waxman lectures
    return 0;
}









