#include <iostream>
#include "map_bst_lite.h"
#include "student.h"
#include <fstream>

template<typename CompareT = std::less<int>>
void solve(int n, int m, CompareT comp = CompareT()) {
    CP::map_bst<int, int, CompareT> data_map(comp);

    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        data_map[x] = i;
    }

    for (int i = 0; i < m; ++i) {
        int l, r;
        std::cin >> l >> r;

        auto result = data_map.value_in_key_range(l, r);
        
        for (auto &i : result) {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::ofstream out("output.txt");
    std::streambuf* originalCoutBuffer = std::cout.rdbuf(); // Save original buffer 
    std::cout.rdbuf(out.rdbuf()); // Redirect cout to the file 
    int n, m, greater;
    std::cin >> n >> m >> greater;

    if (greater) solve<std::greater<int>>(n, m);
    else solve<std::less<int>>(n, m);

    out.close(); // Close the file stream
    return 0;
}