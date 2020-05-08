#include <bits/stdc++.h>

using namespace std;

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {

    std::vector< std::vector<int> >::const_iterator row; 
    std::vector<int>::const_iterator col; 

    int sum_corner = 0;
    int sum_rem = 0;
    int err_corner = 0;
    int err_rem = 0;
    int sum_rep = 0;
    int count_row = 0;
    int count_col = 0;

    for (row = s.begin(); row != s.end(); ++row)
    {   count_col = 0;
         for (col = row->begin(); col != row->end(); ++col)
         { 
             if (count_row == 1 && count_col == 1){
                 sum_rep += abs(5 - *col);
             }
             if (abs(count_row-count_col)%2 == 0 && (count_row!=1 && count_col!=1)){
                 sum_corner = sum_corner + *col;
                 if (*col%2 != 0 || *col == 5 || *col>9 || *col<1){
                     err_corner++;
                 }
             }
             if (abs(count_row-count_col)%2 == 1){
                 sum_rem = sum_rem + *col;
                 if (*col%2 != 1 || *col == 5 || *col>9 || *col<1){
                     err_rem++;
                 }
             }
             ++count_col;
         }
         ++count_row; 
    }
    if (err_corner==0 && sum_corner==20){

    }
    else {
        if (err_corner%2 == 0){
        sum_rep = sum_rep + err_corner;
        sum_rep += abs(20-sum_corner);
        }
        else {
             if (err_corner == 1){
             sum_rep += abs(20-sum_corner);
             }
             else {
                 sum_rep += 2;
                 sum_rep += abs(20-sum_corner);
             }
             }
    }

    if (err_rem == 0 && sum_rem == 20){

    }
    else {
        if (err_rem%2 == 0){
        sum_rep += err_rem;
        sum_rep += abs(20-sum_rem);
        }
        else {
             if (err_rem == 1){
             sum_rep += abs(20-sum_rem);
             }
             else {
                 sum_rep += 2;
                 sum_rep += abs(20-sum_rem);
             }
        } 
    }
    
    return (sum_rep);

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";
cout<<result;
    fout.close();

    return 0;
}

