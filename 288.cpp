class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (int i = 0; i < dictionary.size(); i++) {
            string tmp = dictionary[i];
            int n = tmp.size();
            string key = tmp[0] + to_string(n) + tmp[n - 1];
            ht[key].push_back(tmp);
        }
    }

    bool isUnique(string word) {
        int n = word.size();
        string key = word[0] + to_string(n) + word[n - 1];
        if (ht.find(key) != ht.end()) {
            for (int i = 0; i < ht[key].size(); i++) {
                if (ht[key][i] != word) return false;
            }
        }
        return true;
    }
private:
    unordered_map<string, vector<string>> ht;
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
