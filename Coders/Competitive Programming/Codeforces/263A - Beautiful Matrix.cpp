#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int matrix[5][5];
    // Variables to store the location of '1'
    int one_i=0, one_j=0;
    
    // Inputting the matrix
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            cin>>matrix[i][j];
            if(matrix[i][j]) {
                one_i = i+1;
                one_j = j+1;
            }
        }
    }
    
    int count = 0;
    count += abs(one_i-3);
    count += abs(one_j-3);
    
    cout<<count;
    
    return 0;
}