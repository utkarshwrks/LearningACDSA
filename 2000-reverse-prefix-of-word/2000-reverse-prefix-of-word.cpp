class Solution {
public:
    string reversePrefix(string word, char ch) {
          size_t pos = word.find(ch);

          reverse(word.begin(), word.begin() + pos + 1);
          return word;
    }
};