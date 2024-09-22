#include <bits/stdc++.h>
using namespace std;

class SocialNetwork{
    public:
    int mUser;
    map<int,int> mLike,mContent;
    SocialNetwork(int n){
        mUser = n;
    }
    void add_content(int user_id,int content){
        mContent[user_id] += content;
    }
    void add_like(int user_id,int like){
        mLike[user_id] += like;
    }

    vector<pair<int,int>> like_in_range(int min_like,int max_like){
        map<int,vector<int>> temp;
        for(int i = 0;i < mUser;i++){
            temp[mLike[i]].push_back(i);
        }
        vector<pair<int,int>> res;
        auto it_min = temp.lower_bound(min_like);
        auto it_max = temp.upper_bound(max_like);
        for( auto it = it_min;it != it_max;it++){
            int like = it->first;
            vector<int> users = it->second;
            for(int i = 0;i < users.size();i++){
                res.push_back(make_pair(users[i],like));
            }
        }
        return res;
    }
    pair<int, vector<int>> content_below(int threshold){
        map<int,vector<int>> temp;
        for(int i = 0;i < mUser;i++){
            temp[mContent[i]].push_back(i);
        }
        auto it = temp.lower_bound(threshold);
        pair<int, vector<int>> res;
        if( it == temp.begin()){
            return res;
        }
        it--;
        res.first = it->first;
        res.second = it->second;
        return res;
    }
};

int main(){
    SocialNetwork test(50);
    for(int i = 0;i < 50;i++){
        test.add_content(i,i+5);
        test.add_like(i,i+3);
    }
    test.add_content(35,3);
    cout << "Users Like" << endl;
    for(int i = 0;i < 50;i++){
        cout << i << ": " << test.mLike[i] << endl;;
    }
    cout << endl;
    cout << "Users Content" << endl;
    for(int i = 0;i < 50;i++){
        cout << i << ": " << test.mContent[i] << endl;
    }
    cout << endl;
    cout << "like_in_range test" << endl;
    for(auto pair:test.like_in_range(25,50)){
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << "content_below test" << endl;
    pair <int,vector<int>> res = test.content_below(44);
    cout << "Content Amount = " << res.first << endl;;
    cout << "User: ";
    for(auto e:res.second){
        cout << e << " ";
    }
    cout << endl;
    return 0;
}