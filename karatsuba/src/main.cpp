#include <bits/stdc++.h>
#include <string>
using namespace std;

// Base 2 methods
//  Hàm tạo 2 số nhị phân cùng Size với nhau
int makeEqualLength(string &str1, string &str2) {
  // Lấy 2 size của input
  int len1 = str1.size();
  int len2 = str2.size();
  // Nếu như size của input 1 < size của input 2 thì thêm 0 ở trước
  if (len1 < len2) {
    for (int i = 0; i < len2 - len1; i++)
      str1 = '0' + str1;
    return len2;
  } else if (len1 > len2) {
    for (int i = 0; i < len1 - len2; i++)
      str2 = '0' + str2;
  }
  return len1; // Nếu len1 >= len2
}
// Hàm cộng Bits (Base 2)
string addBitString(string first, string second) {
  // Store sum bits
  string result;

  int length = makeEqualLength(first, second); // 2 cái string phải cùng size
  int carry = 0;                               // biến lưu số carry

  for (int i = length - 1; i >= 0; i--) {
    int firstBit = first.at(i) - '0';   // Lấy bit đầu
    int secondBit = second.at(i) - '0'; // Lấy bit 2

    // Tổng 3 bits bằng biểu thức bool
    int sum = (firstBit ^ secondBit ^ carry) + '0';

    result = (char)sum + result;
    carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
  }
  // Nếu như biểu thức overflow thì cộng 1 vào kết quả
  if (carry)
    result = '1' + result;

  return result;
}
// Hàm nhân bit
int multiplyingSingleBit(string a, string b) {
  return (a[0] - '0') * (b[0] - '0');
}

// Hàm nhân 2 bit string X Y và trả về kết quả là số long int
long int multiply(string X, string Y) {
  // Tìm length của X và Y
  int n = makeEqualLength(X, Y);

  // Base case
  if (n == 0)
    return 0;
  if (n == 1)
    return multiplyingSingleBit(X, Y);

  int fh = n / 2;    // First half of string, floor(n/2)
  int sh = (n - fh); // Second half of string, ceil(n/2)

  // Tìm half đầu và half thứ 2 của string đầu
  string Xl = X.substr(0, fh);
  string Xr = X.substr(fh, sh);

  // Tìm half đầu và half sau của string 2
  string Yl = Y.substr(0, fh);
  string Yr = Y.substr(fh, sh);

  // Đệ quy tính toán 3 phép nhân input size n/2
  long int P1 = multiply(Xl, Yl);
  long int P2 = multiply(Xr, Yr);
  long int P3 = multiply(addBitString(Xl, Xr), addBitString(Yl, Yr));

  // Combine 3 products
  return P1 * (1 << (2 * sh)) + (P3 - P1 - P2) * (1 << sh) + P2;
}
void BinaryStringToDecimal(string result) {
  cout << "Binary Result : " << result << endl;
  unsigned long long int val = 0;
  for (int i = result.length() - 1; i >= 0; i--) {
    if (result[i] == '1') {
      val += pow(2, (result.length() - 1) - i);
    }
  }
  cout << "Decimal Result (Not proper for Large Binary Numbers):" << val
       << endl;
}
string DecimalToBinary(long long int number) {
  string result = "";
  if (number <= 0) {
    return "0";
  } else {
    int i = 0;
    while (number > 0) {

      long long int num = number % 2;
      stringstream ss;
      ss << num;
      result = ss.str() + result;
      number = number / 2;
      i++;
    }
    return result;
  }
}
string schoolAddition(string a, string b, int base) {
  int len_a, len_b;

  len_a = a.size();
  len_b = b.size();
  string sum, s;
  s = "";
  sum = "";

  int diff;
  diff = abs(len_a - len_b);
  // Padding 0 in front of the
  // number to make both numbers equal
  for (int i = 1; i <= diff; i++)
    s += "0";
  // Condition to check if the strings
  // have lengths mis-match
  if (len_a < len_b)
    a = s + a;
  else
    b = s + b;
  int curr, carry = 0;
  // Loop to find the find the sum
  // of two integers of base B
  for (int i = max(len_a, len_b) - 1; i > -1; i--) {
    // Current Place value for
    // the resultant sum
    curr = carry + (a[i] - '0') + (b[i] - '0');
    // Update carry
    carry = curr / base;
    // Find current digit
    curr = curr % base;
    // Update sum result
    sum = (char)(curr + '0') + sum;
  }
  if (carry > 0)
    sum = (char)(carry + '0') + sum;
  return sum;
}

int main(int argc, char *argv[]) {
  int a, b, base;
  cout << "I1: ";
  cin >> a;
  cout << "I2: ";
  cin >> b;
  cout << "B: ";
  cin >> base;
  if (base < 2 || base > 10) {
    return 1;
  } else {
    cout << schoolAddition(to_string(a), to_string(b), base) << " "
         << multiply(DecimalToBinary(a), DecimalToBinary(b)) << " "
         << floor(a / b);
  }

  return 0;
}
