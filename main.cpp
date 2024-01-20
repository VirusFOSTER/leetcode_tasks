/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include "tasks/task_329.hpp"

int main()
{
    Solution sol_;
    vector<vector<int>> matrix =
    {
        {17,4,6,11,4,0,17,12,19,12,12,0},
        {0,6,4,4,5,9,15,1,11,13,18,0},
        {4,2,13,1,2,7,15,5,14,6,8,6}
    };
    int res_ = sol_.longestIncreasingPath(matrix);
    cout << res_ << "\n";

    for (auto &r_ : sol_.paths_) {
        for (auto &c_ : r_) {
            cout << c_ << "\t";
        }
        cout << "\n";
    }

    return 0;
}
