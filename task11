#include <iostream>
using namespace std;

№1
template <int n> 
struct factorial
{ 
    enum{ ret = factorial<n - 1>::ret * n }; 
}; 

template <> 
struct factorial<0>
{ 
    enum { ret = 1 }; 
};

№2
template <int n, int k>
struct binom
{
    enum { ret = factorial<n>::ret / (factorial<n-k>::ret * factorial<k>::ret)};
};

int main()
{
  cout << binom<4, 2>::ret << endl;
}

№3
template <int n> 
struct fibonacci
{ 
    enum{ ret = fibonacci<n-1>::ret + fibonacci<n-2>::ret}; 
}; 

template <> 
struct fibonacci<1>
{ 
    enum { ret = 0 }; 
};

template <> 
struct fibonacci<2>
{ 
    enum { ret = 1 }; 
};

int main()
{
    cout << fibonacci<7>::ret << endl;
}

№4
template <typename T>
constexpr T element(T value, unsigned power)
{
    return power == 0 ? 1 : value * element(value, power-1) / double(power);
}

template <typename T>
constexpr T partial(T x, int n)
{
    return n == 0 ? 1 : partial(x, n-1) + element(x, n);
}

int main()
{
    cout << partial(double(2), 15);
}

constexpr bool isPrimeLoop(int i, int k)
{
    return (k * k > i) ? true : (i % k == 0) ? false: isPrimeLoop(i, k + 1);
}

constexpr bool isPrime(int i)
{
    return isPrimeLoop(i, 2);
}

constexpr int nextPrime(int k)
{
    return isPrime(k) ? k : nextPrime(k + 1);
}

constexpr int getPrimeLoop(int i, int k)
{
    return (i == 0) ? k : getPrimeLoop(i - 1, nextPrime(k + 1));
}

constexpr int getPrime(int i)
{
    return getPrimeLoop(i, 2);
}

int main()
{
    cout << nextPrime(14) << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << getPrime(i) << endl;
    }    
}
