#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> data, string text=""){
    cout << text << "\n";

    cout << "Total Row: " << data.size() << "\n";
    for (vector<int> row:data){
        cout << "\t[" << row.size() << "] -> ";
        for (int column:row)
            cout << column << " ";
        cout << "\n";
    }
    cout << "\n";
}

int main()
{
    /// create
//    vector <vector<int>> data;
//    print(data);

//    vector <vector<int>> data(3);
//    print(data);

//    vector <vector<int>> data(3, vector<int>(4));
//    print(data);

//    vector <vector<int>> data(3, vector<int>(4, 5));
//    print(data);

//    vector <vector<int>> data( { {2, 3}, {7, 5, 4, 9}, {3, 1, 2}} );
//    print(data);

//    vector <vector<int>> data = { {2, 3}, {7, 5, 4, 9}, {3, 1, 2}} ;
//    print(data);

    /// add
//    vector <vector<int>> data(3, vector<int>(4));
//    data[0][0] = 2;
//    data[0][1] = 3;
//    print(data);

//    vector<vector<int>> data;
//
//    vector<int> row;
//    row.push_back(2);
//    row.push_back(3);
//    data.push_back(row);
//    print(data);

//    vector <vector<int>> data(3, vector<int>(4));
//
//    for (int i=0; i<3; i++){
//        for (int j=0; j<4; j++){
//            data[i][j] = i*j;
//        }
//    }
//
//    print(data);


    vector<vector<int>> data;
    for(int i=0; i<3; i++){
        vector<int> row;
        for (int j=0; j<4; j++){
            row.push_back(i*j);
        }
        data.push_back(row);
    }
    print(data);

    return 0;
}
