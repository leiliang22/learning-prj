/****************************************************************************
* Filename : SetMatrixZero.cpp
* 
* Author : lei.liang
****************************************************************************/
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class Solution{
  public:
    Solution(int row, int column);
    ~Solution();
    void PrintMatrix();
    void HandleMatrix();

  private:
    void InitMatrix();
    vector<vector<int> > v_;
    int row_;
    int column_;
};

Solution::Solution(int row, int column):row_(row), column_(column) {
    InitMatrix();
}

Solution::~Solution(){
}

void Solution::InitMatrix() {
    srand((unsigned)time(NULL));
    for (int i=0; i<row_; ++i) {
		vector<int> tmp;
		v_.push_back(tmp);
        for (int j=0; j<column_; ++j) {
            v_[i].push_back(rand()%3);
        }
    }
}

void Solution::PrintMatrix() {
    vector<vector<int> >::iterator iter_row;
    vector<int>::iterator iter_column;
    for (iter_row=v_.begin(); iter_row!=v_.end(); ++iter_row) {
        for (iter_column=(*iter_row).begin(); iter_column!=(*iter_row).end();
                ++iter_column) {
            cout << *iter_column << " ";
        } 
        cout << endl;
    }
    cout << "-----------" << endl;
}

void Solution::HandleMatrix() {
    int zero_in_first_row = 0;    
    int zero_in_first_column = 0;    
    for (int i=0; i<column_; ++i) {
        if (v_[0][i] == 0) {
            zero_in_first_row = 1;
            break;
        }
    }
    for (int i=0; i<row_; ++i) {
        if (v_[i][0] == 0) {
            zero_in_first_column = 1;
            break;
        }
    }
    for (int i=1; i<row_; ++i) {
        for (int j=1; j<column_; ++j) {
            if (v_[i][j] == 0) {
                v_[0][j] = 0;
                v_[i][0] = 0;
            }
        }
    }
    for (int j=1; j<column_; ++j) {
        if (v_[0][j] == 0) {
            for (int i=0; i<row_; ++i)
                v_[i][j] = 0;
        }
    }
    for (int i=1; i<row_; ++i) {
        if (v_[i][0] == 0) {
            for (int j=0; j<column_; ++j)
                v_[i][j] = 0;
        }
    }
    if (zero_in_first_row) {
        for (int j=0; j<column_; ++j)
            v_[0][j] = 0;
    }
    if (zero_in_first_column) {
        for (int i=0; i<row_; ++i)
            v_[i][0] = 0;
    }
}

int main() {
    Solution s(5,5);
    s.PrintMatrix();
    s.HandleMatrix();
    s.PrintMatrix();
    return 0;
}
