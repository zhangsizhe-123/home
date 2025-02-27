#include<bits/stdc++.h>
using namespace std; 
// 大整数类
class BigInt {
public:
    vector<int> digits;
    bool isNegative;

    BigInt() : isNegative(false) {}
    BigInt(long long num) {
        if (num < 0) {
            isNegative = true;
            num = -num;
        } else {
            isNegative = false;
        }
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
        if (digits.empty()) {
            digits.push_back(0);
        }
    }

    // 大整数加法
    BigInt operator+(const BigInt& other) const {
        if (isNegative != other.isNegative) {
            if (isNegative) {
                BigInt temp = *this;
                temp.isNegative = false;
                return other - temp;
            } else {
                BigInt temp = other;
                temp.isNegative = false;
                return *this - temp;
            }
        }
        BigInt result;
        result.isNegative = isNegative;
        int carry = 0;
        for (int i = 0; i < max(digits.size(), other.digits.size()) || carry; ++i) {
            int sum = carry;
            if (i < digits.size()) sum += digits[i];
            if (i < other.digits.size()) sum += other.digits[i];
            result.digits.push_back(sum % 10);
            carry = sum / 10;
        }
        return result;
    }

    // 大整数减法
    BigInt operator-(const BigInt& other) const {
        if (isNegative != other.isNegative) {
            if (isNegative) {
                BigInt temp = *this;
                temp.isNegative = false;
                return other - temp;
            } else {
                BigInt temp = other;
                temp.isNegative = false;
                return *this + temp;
            }
        }
        if (isNegative) {
            BigInt temp1 = *this;
            temp1.isNegative = false;
            BigInt temp2 = other;
            temp2.isNegative = false;
            return temp2 - temp1;
        }
        if (*this < other) {
            BigInt result = other - *this;
            result.isNegative = true;
            return result;
        }
        BigInt result;
        int borrow = 0;
        for (int i = 0; i < digits.size(); ++i) {
            int diff = digits[i] - borrow;
            if (i < other.digits.size()) diff -= other.digits[i];
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.digits.push_back(diff);
        }
        while (result.digits.size() > 1 && result.digits.back() == 0) {
            result.digits.pop_back();
        }
        return result;
    }

    // 大整数乘法
    BigInt operator*(const BigInt& other) const {
        BigInt result;
        result.digits.resize(digits.size() + other.digits.size());
        for (int i = 0; i < digits.size(); ++i) {
            int carry = 0;
            for (int j = 0; j < other.digits.size() || carry; ++j) {
                long long cur = result.digits[i + j] + digits[i] * (j < other.digits.size() ? other.digits[j] : 0) + carry;
                result.digits[i + j] = cur % 10;
                carry = cur / 10;
            }
        }
        while (result.digits.size() > 1 && result.digits.back() == 0) {
            result.digits.pop_back();
        }
        result.isNegative = isNegative != other.isNegative;
        return result;
    }

    // 大整数取模
    BigInt operator%(const BigInt& other) const {
        BigInt quotient = *this / other;
        BigInt remainder = *this - quotient * other;
        return remainder;
    }

    // 大整数除法
    BigInt operator/(const BigInt& other) const {
        if (other == BigInt(0)) {
            throw runtime_error("Division by zero");
        }
        BigInt result, temp;
        result.digits.resize(digits.size());
        for (int i = digits.size() - 1; i >= 0; --i) {
            temp.digits.insert(temp.digits.begin(), digits[i]);
            while (temp.digits.size() > 1 && temp.digits.back() == 0) {
                temp.digits.pop_back();
            }
            int count = 0;
            while (temp >= other) {
                temp = temp - other;
                ++count;
            }
            result.digits[i] = count;
        }
        while (result.digits.size() > 1 && result.digits.back() == 0) {
            result.digits.pop_back();
        }
        result.isNegative = isNegative != other.isNegative;
        return result;
    }

    // 比较运算符
    bool operator<(const BigInt& other) const {
        if (isNegative != other.isNegative) {
            return isNegative;
        }
        if (digits.size() != other.digits.size()) {
            return (isNegative ? digits.size() > other.digits.size() : digits.size() < other.digits.size());
        }
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] != other.digits[i]) {
                return (isNegative ? digits[i] > other.digits[i] : digits[i] < other.digits[i]);
            }
        }
        return false;
    }

    bool operator>(const BigInt& other) const {
        return other < *this;
    }

    bool operator<=(const BigInt& other) const {
        return !(*this > other);
    }

    bool operator>=(const BigInt& other) const {
        return !(*this < other);
    }

    bool operator==(const BigInt& other) const {
        return isNegative == other.isNegative && digits == other.digits;
    }

    // 左移运算符重载
    BigInt operator<<(int shift) const {
        BigInt result = *this;
        for (int i = 0; i < shift; ++i) {
            result = result * BigInt(2);
        }
        return result;
    }

    // 输出大整数
    friend ostream& operator<<(ostream& os, const BigInt& num) {
        if (num.isNegative) {
            os << '-';
        }
        for (int i = num.digits.size() - 1; i >= 0; --i) {
            os << num.digits[i];
        }
        return os;
    }
};

// 判断素数
bool isPrime(BigInt N) {
    if (N < 4) {
        return N > 1;
    }
    if (N%2==0) {
        return false;
    }
    for (BigInt i = 3; i * i <= N; i =i+2) {
        if (N % i==0) {
            return false;
        }
    }
    return true;
}

// 素性测试
bool primality(BigInt N, const BigInt& M) {
    if (N == 2) {
        return true;
    }
    BigInt s(4);
    for (BigInt i = 0; i < N - 2; i=i+1) {
        s = (s * s - BigInt(2)) % M;
    }
    return s==0;
}

// 查找完全数
void findPerfectNumber() {
    int count = 0;
    auto start = chrono::high_resolution_clock::now();
    int i = 1;
    while (true) {
        i = i + 1;
        if (!isPrime(i)) {
            continue;
        }
        BigInt M = (BigInt(1) << i) - BigInt(1);
        BigInt t = M << (i - 1);
        if (primality(i, M)) {
            count++;
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed = end - start;
            printf("- [%.10lfs(%d)] ",elapsed.count(),count);
            cout<<t<<endl;
        }
    }
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    findPerfectNumber();
    return 0;
}
