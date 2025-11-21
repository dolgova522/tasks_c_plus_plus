#include <iostream>
#include <vector>
#include <string>
#include <cassert>


std::string longest_palindrome(std::string_view str) {
  if (str.empty()) {
    return "";
  }
  size_t const len = str.size();
  size_t longestBegin = 0;
  size_t maxLen = 1;
  std::vector<bool> table(len * len, false);

  for (size_t i = 0; i < len; i++)
    table[i * len + i] = true;

  for (size_t i = 0; i < len - 1; i++) {

    if (str[i] == str[i + 1]) {
      table[i*len + i + 1] = true;

      if (maxLen < 2) {
        longestBegin = i;
        maxLen = 2;
      }
    }
  }

  for (size_t k = 3; k <= len; k++) {

    for (size_t i = 0; i < len - k + 1; i++) {

      size_t j = i + k - 1;
      if (str[i] == str[j] && table[(i + 1)*len + j - 1]) {

        table[i*len +j] = true;
        if (maxLen < k) {

          longestBegin = i;
          maxLen = k;
        }
      }
    }
  }

  return std::string(str.substr(longestBegin, maxLen));
}

void tests() {
  assert(longest_palindrome("sahararahnide") == "hararah");
  assert(longest_palindrome("level") == "level");
  assert(longest_palindrome("s") == "s");
  assert(longest_palindrome("") == "");
  assert(longest_palindrome("abc") == "a");
}

int main()
  {
    tests();
}
