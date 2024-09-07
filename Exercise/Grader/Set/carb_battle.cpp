#include <iostream>
#include <vector>
#include <map>
using namespace std;

int gameLoop(map<int,int> &playerCard, vector<vector<int>> &enemy){
    int i = 0;
    while (i < enemy.size()){
        while(!enemy[i].empty()){
            int eCard = enemy[i][0];
            auto pCard = playerCard.upper_bound(eCard);
            if(pCard == playerCard.end()){
                return i + 1;
            }else{
                enemy[i].erase(enemy[i].begin());
                playerCard[(*(pCard)).first]--;
                if(playerCard[(*(pCard)).first] == 0){
                    playerCard.erase((*pCard).first);
                }
            }
        }
        i++;
    }
    return enemy.size() + 1;
}

int main(){
    int n, m, num, card_pow;
    map<int,int> playerCard; // Key: Card power, Value : Card amount
    cin >> n >> m;
    vector<vector<int>> enemy(m);
    for(int _ = 0; _ < n; _ ++){
        cin >> num;
        playerCard[num]++;
    }
    for(auto &e:enemy){
        cin >> num;
        for(int _ = 0; _ < num; _++){
            cin >> card_pow;
            e.push_back(card_pow);
        }
    }
    cout << gameLoop(playerCard, enemy) << endl;

    return 0;
}