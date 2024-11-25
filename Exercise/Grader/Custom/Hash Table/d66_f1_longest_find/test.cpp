#include <iostream>

int main() {
    int n, m, res1 = 1, res2 = 1;
    std::cin >> n >> m;

    int hashTable[n] = {};
    int mark[n] = {};

    for(int i=1, a, b; i<=m; i++) {
        std::cin >> a >> b;
        if(a == 1) {
            int j = 0;
            while(mark[(b + j*j)%n] == 2) {
                if(hashTable[(b + j*j)%n] == b) break;
                ++j;
            }
            hashTable[(b + j*j)%n] = b;
            mark[(b + j*j)%n] = 2;
        }
        else {
            int j = 0;
            while((mark[(b + j*j)%n] == 2 || mark[(b + j*j)%n] == 1)) {
                if(hashTable[(b + j*j)%n] == b) break;
                ++j;
            }
            if(hashTable[(b + j*j)%n] == b) {
                hashTable[(b + j*j)%n] = 0;
                mark[(b + j*j)%n] = 1;
            }
        }
    }

    for(int i=0; i<n; i++) {
        int j = 0;
        while(mark[(i + j*j)%n] == 2) {
            ++j;
            res1 = std::max(res1, j + 1);
        }

        j = 0;
        while(mark[(i + j*j)%n] == 2 || mark[(i + j*j)%n] == 1) {
            ++j;
            res2 = std::max(res2, j + 1);
        }
    }

    std::cout << res1 << ' ' << res2;
}