/*
Unique Word Abbreviation
An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:

a) it                      --> it    (no abbreviation)

     1
b) d|o|g                   --> d1g

              1    1  1
     1---5----0----5--8
c) i|nternationalizatio|n  --> i18n

              1
     1---5----0
d) l|ocalizatio|n          --> l10n
Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

Example: 
Given dictionary = [ "deer", "door", "cake", "card" ]

isUnique("dear") -> false
isUnique("cart") -> true
isUnique("cane") -> false
isUnique("make") -> true
*/

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
