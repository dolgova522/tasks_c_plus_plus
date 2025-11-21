#include <iostream>
#include <string>
#include <cassert>

unsigned int gray_encode(unsigned int const num) {
  return num ^ (num >> 1);
}
unsigned int gray_decode(unsigned int gray) {
  for (unsigned int bit = 1 << 31; bit > 1; bit >>= 1) {
    if (gray & bit) gray ^= bit >> 1;
  }
  return gray;
}
std::string to_binary(unsigned int value, int const digits)
{
  return std::bitset<32>(value).to_string().substr(32-digits, digits);
}

void tests() {
  assert(gray_encode(2) == 3);
  assert(gray_encode(1) == 1);
  assert(gray_decode(1) == 1);
  assert(gray_decode(3) == 2);
  assert(gray_encode(2) == gray_encode(gray_decode(3)));

}

int main()
{
  tests();
}
