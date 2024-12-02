#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> hashTable(n, -1);
    vector<int> deletePos(n, 0);
    for (int i = 0; i < m; i++) {
        int a, x;
        cin >> a >> x;
        int homePos = x % n;
        if (a == 1) {
            int probe = 0;
            int curr_pos = homePos;
            while (hashTable[curr_pos] != -1 && !deletePos[curr_pos]) { // FIXED
                probe++;
                curr_pos = (homePos + probe*probe) % n;
            }
            hashTable[curr_pos] = x;
            deletePos[curr_pos] = 0;
        }
        if (a == 2) {
            int probe = 0;
            int curr_pos = homePos;
            while (hashTable[curr_pos] != x && hashTable[curr_pos] != -1) {
                probe++;
                curr_pos = (homePos + probe*probe) % n;
            }
            if (hashTable[curr_pos] == x && deletePos[curr_pos] != 1) {
                deletePos[curr_pos] = 1;
                hashTable[curr_pos] = -2;
            }
        }
    }
    int maxProbeForInsert = 0;
    int maxProbeForFind = 0;
    int maxFindPos = 0;
    for (int i = 0; i < n; i++) {
        int homePos = i;
        int probe = 0;
        int curr_pos = homePos;
        bool flag = false;
        while (hashTable[curr_pos] != -1) {
            if (deletePos[curr_pos] == 1 && !flag) {
                maxProbeForInsert = max(probe+1, maxProbeForInsert);
                flag = true;
            }
            probe++;
            curr_pos = (homePos + probe*probe) % n;
        }
        if (probe+1 > maxProbeForFind){
            maxProbeForFind = probe+1;
            maxFindPos = i;
        }
        if (!flag) {
            maxProbeForInsert = max(maxProbeForInsert, probe+1);
        }
        
    }
    for (auto & x : hashTable) {
        cout << x  << " ";
    }
    cout << endl;
    for (auto & x : deletePos) {
        cout << x << " ";
    }
    cout << endl;
    cout << maxProbeForInsert << " " << maxProbeForFind << endl;
}