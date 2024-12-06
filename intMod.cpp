/*
I had a dream
I was still on the island
I wanted to leave
I was rushing desperately, trying to reach the light
When I though i did, I reach a dead end instead
"I want to enter that light", I said to myself
And at the end of it,
I found you.
*/

#include <iostream>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

const int mod = 1e9+7;

class intMod{
    protected :
        int x;

    public :
        void setVal(int val) {
            this->x = val;
        }

        intMod operator + (const intMod &num) {
            intMod result;
            result.x = (x + num.x)%mod;
            return result;
        }

        intMod operator - (const intMod &num) {
            intMod result;
            result.x =  (x - num.x) + ((x < num.x) ? (mod) : 0);
            return result;
        }

        intMod operator * (const intMod &num) {
            intMod result;
            result.x =  (1LL * x*num.x)%mod;
            return result;
        }
        friend intMod Power(const intMod &num, int exp);

        friend intMod operator / (int val,const intMod &div);

        intMod Power2(int exp) {
            if (exp == 1) {
                return *this;
            }
            intMod result = Power2(exp/2);
            result = result * result;
            if (exp&1) {
                result = result * (*this);
            }
            return result;
        }

        int getVal() {
            return this->x;
        }
};

intMod Power(const intMod &num, int exp) {
    if (exp == 1) {
        return num;
    }
    intMod result = Power(num, exp/2);
    result = result * result;
    if (exp&1) {
        result = result * num;
    }
    return result;
}

intMod operator / (int val, const intMod &div) {
    intMod result;
    result.x = (val * Power(div,mod-2).x) % mod;
    return result;
}

void solve() {
    intMod *ptr = new intMod;
    cout<<ptr<<' ';
    ptr->setVal(2);
    cout<<ptr<<' ';
    *ptr = 1/(*ptr);
    cout<<ptr<<'\n';
    cout<<ptr->getVal();
    delete ptr;
}

int main() {
    // Start time
    auto start = high_resolution_clock::now();

    // Code goes here
    solve();
    
    // End time
    auto end = high_resolution_clock::now();

    // Calculate the duration
    duration<double> elapsed = end - start;

    // Print the execution time in seconds
    cerr << "\nExecution time: " <<fixed<<setprecision(5)<< elapsed.count() << " seconds\n";
    return 0;
}

/*
I had a dream
The day I met you
You looked like a lost kitten
But you've found a meaning for my existance
I kept working as the sunshine girl 'cos I was happy to make people smile
I'm really glad I've met you
So, don't cry,
Hodaka.
*/