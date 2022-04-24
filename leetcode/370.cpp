using namespace std;

void print_v(std::vector<int> v) {
    std::cout << "[" ;
    for (auto num : v) {
        std::cout << num << "," ;
    }
    std::cout << "]" << std::endl;
}

vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    vector<int> diff(length+1, 0); // diff[i] = init[i] - init[i-1];
    int start_idx, end_idx, update;
    for (auto iter = updates.begin(); iter != updates.end(); ++iter) {
        start_idx = (*iter)[0]; end_idx = (*iter)[1]; update = (*iter)[2];
        diff[start_idx] += update;
        diff[end_idx+1] -= update;
    }
    
    for (auto iter = diff.begin()+1; iter != diff.end(); ++iter) {
        *iter += *(iter-1);
    }
    diff.pop_back(); // delete last 0
    return diff;
}

int main() {
    int length = 5;
    vector<vector<int>> updates{{1,  3,  2},{2,  4,  3},{0,  2, -2}};
    print_v(getModifiedArray(length, updates));
}