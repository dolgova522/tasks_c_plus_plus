#include <iostream>
#include <vector>
#include <cassert>

std::string to_roman(unsigned int value)
{
  std::vector<std::pair<unsigned int, char const*>> roman {
   { 1000, "M" },{ 900, "CM" }, { 500, "D" },{ 400, "CD" },
   { 100, "C" },{ 90, "XC" }, { 50, "L" },{ 40, "XL" },
   { 10, "X" },{ 9, "IX" }, { 5, "V" },{ 4, "IV" },{ 1, "I" }};
  std::string result;
  for (auto const & kvp : roman) {
    while (value >= kvp.first) {
      result += kvp.second;
      value -= kvp.first;
    }
  }
  return result;
}

void tests() {
  assert(to_roman(4561) == "MMMMDLXI");
  assert(to_roman(522) == "DXXII");
  assert(to_roman(1) == "I");
  assert(to_roman(12) == "XII");
  assert(to_roman(56707) == "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMDCCVII");
}

int main() {
  tests();
}
