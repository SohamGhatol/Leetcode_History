class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for(char c:s){
            freq[c]++;
        }

        int n=s.size();
        vector<vector<char>> bucket(n+1);

        for(auto p:freq){
            bucket[p.second].push_back(p.first);
        }

        string answer="";

        for(int f=n;f>=1;f--){
            for (char c:bucket[f]){
                answer.append(f,c);
            }
        }

        return answer;
    }
};