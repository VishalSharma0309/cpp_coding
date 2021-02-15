/*
Reference variable declaration requires initialization
* WRONG *
int &j;
j = i;

* CORRECT *
int &j = i;

Declaring a dynamic array
int * p = new int [50];

Declaring a 2D array
int ** p = new int *[10];
p[0] = new int [12];
p[1] = new int [14];
* accessing data -> p[4][5];

Deallocating 
for (int i=0 ; i<m ; ++i){
    delete [] p;
}
delete [] p;


Incline functions
inline int max (a, b){
    return (a>b) ? a:b;
}

*/