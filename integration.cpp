#include <iostream>
using namespace std;

double line (double x){ //y=x
    return x; 
}

double square (double x){ //y=x^2
    return x*x; 
}

double cube (double x){ //y=x^3
    return x*x*x; 
}
 
typedef double (*FUNC)(double);
double integrate (FUNC f, double x, double b){

double delta= 0.0000001;
double sum= 0;
while (x<b) {
    sum+= f(x)*delta;
    x+= delta;
}
return sum;
}

int main (){
    cout<< "The integral of f(x)=x between 1 and 5 is: " <<integrate(line, 1, 5)<< endl;
    cout<< "The integral of f(x)=x^2 between 1 and 5 is: " <<integrate(square, 1, 5)<< endl;
    cout<< "The integral of f(x)=x^3 between 1 and 5 is: " <<integrate(cube, 1, 5)<< endl;
    return 0;
}

