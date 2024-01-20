#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    unordered_map<int, int> map_pathes_ = {};

    int search_path(vector<vector<int>>& matrix, size_t i, size_t j) {
        auto itr_ = map_pathes_.find(i * matrix.size() + j);
        if (itr_ != map_pathes_.end()) {
            return itr_->second;
        }

        int length_path_ = 1;

        if (i >= 0 && j >= 0 && i < matrix.size() && j < matrix[i].size()) {
            int down_length_ = (i >= 1) ?
                        (matrix[i - 1][j] > matrix[i][j]) ?
                        this->search_path(matrix, i - 1, j) : 0 :
                        0;
            int up_length_ =
                    (i + 1 < matrix.size() && matrix[i + 1][j] > matrix[i][j])
                    ? this->search_path(matrix, i + 1, j)
                    : 0;
            int right_length_ =
                    (j + 1 < matrix[i].size() && matrix[i][j + 1] > matrix[i][j])
                    ? this->search_path(matrix, i, j + 1)
                    : 0;
            int left_length_ = (j >= 1 && matrix[i][j - 1] > matrix[i][j])
                    ? this->search_path(matrix, i, j - 1)
                    : 0;
            length_path_ += max(max(down_length_, up_length_),
                                max(right_length_, left_length_));
        }

        map_pathes_.insert(make_pair(i * matrix.size() + j, length_path_));

        return length_path_;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int max_path_ = 0;

        for (size_t i = 0; i < matrix.size(); ++i) {
            vector<int> row_paths_ = {};
            for (size_t j = 0; j < matrix[i].size(); ++j) {
                int cur_length_ = this->search_path(matrix, i, j);
                row_paths_.push_back(cur_length_);
                max_path_ = (max_path_ < cur_length_) ? cur_length_ : max_path_;
            }
            paths_.push_back(row_paths_);
        }

        return max_path_;
    }

    vector<vector<int>> paths_ = {};
};
