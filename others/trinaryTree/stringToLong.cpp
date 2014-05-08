/* 
Yan Hong
yhong5@uci.edu

Question 1:
Given a string, write a routine that converts the string to a long, without 
using the built in functions that would do this. 

Assumptions:
1. Testing on 32bit machines, LONG_MAX = 2^31 - 1, LONG_MIN = - 2^31
2. Discard whitespace characters at the beginning of the string
3. Discard invaild characters after vaild number
4. Float number will be changed into long, according to assumption #3
5. If there is no valid conversion, return zero
6. If result is out of the range of INT_MAX (2147483647) or INT_MIN (-2147483648), INT_MAX / INT_MIN is returned

Describe what (if any) limitations the code has:
1. There is no valid conversion, zero is returned. So we cannot distinguish the input is zero or invaild characters.
*/

#include <iostream>
#include <sstream>
#include <cassert>

// assume 32bit, redefine LONG_MAX = 2^31 - 1, LONG_MIN = - 2^31
# define LONG_MAX 2147483647
# define LONG_MIN -2147483648

using namespace std;

long stringToLong(const char* str){
    long n = 0;     // result
    long sign = 1;  // sign = 1 : positive number; sign = -1 : negative number
    int i = 0; 

    while (str[i] == ' ') i++; // ignore spaces
    if (str[i] == '-'){
        i++;
        sign=-1;    // negative number
    }else if(str[i] == '+'){
        i++;    // positive number
    }
    for (; str[i] != '\0'; ++i){
        if (str[i] < '0' || str[i] > '9') 
            break;    // invaild characters, break and return vaild number before invaild characters 
        else {
            if(LONG_MAX/10 < n || (LONG_MAX/10 == n && LONG_MAX%10 < str[i] - '0')){
                return sign == 1 ? LONG_MAX : LONG_MIN;
            }
            n = n * 10 + str[i] - '0';
        }
    }
    return sign * n;
}

int test(){
    long n = 0;
    // functional testing
    n = stringToLong("0");  // zero
    assert(n == 0);
    n = stringToLong("1");  // integer
    assert(n == 1);
    n = stringToLong("12");
    assert(n == 12);
    n = stringToLong("123");
    assert(n == 123);
    n = stringToLong("32767");  // long
    assert(n == 32767);
    n = stringToLong("-32768");
    assert(n == -32768);
    n = stringToLong("+1"); // postive number
    assert(n == 1);
    n = stringToLong("+12");
    assert(n == 12);
    n = stringToLong("+123");
    assert(n == 123);
    n = stringToLong("-1"); // negative number
    assert(n == -1);
    n = stringToLong("-12");
    assert(n == -12);
    n = stringToLong("-123");
    assert(n == -123);
    // sould add more random cases
    // edge cases
    n = stringToLong("2147483646");
    assert(n == LONG_MAX-1);
    n = stringToLong("2147483647");
    assert(n == LONG_MAX);
    n = stringToLong("2147483648");
    assert(n == LONG_MAX);
    n = stringToLong("-2147483647");
    assert(n == LONG_MIN+1);
    n = stringToLong("-2147483648");
    assert(n == LONG_MIN);
    n = stringToLong("-2147483649");
    assert(n == LONG_MIN);
    // spaces-at-first cases
    n = stringToLong(" 0");
    assert(n == 0);
    n = stringToLong("  0");
    assert(n == 0);
    // invaild number
    n = stringToLong("abc");    // if there is no valid conversion, return zero
    assert(n == 0);
    n = stringToLong("1abc");
    assert(n == 1);
    n = stringToLong("1.3");    // float number
    assert(n == 1);
    // extreme long string
    char *ptrExtremeLongString=new char[32768 + 1];
    memset(ptrExtremeLongString, '1', 32768 + 1);
    n = stringToLong(ptrExtremeLongString);
    assert(n == LONG_MAX);
    // corner cases
    n = stringToLong("  0abc"); // spaces-at-first + invaild number
    assert(n == 0);
    n = stringToLong("  +1abc"); // spaces-at-first + positive number + invaild number
    assert(n == 1);
    n = stringToLong("  -1abc"); // spaces-at-first + negative number + invaild number
    assert(n == -1);
    n = stringToLong("  2147483647"); // spaces-at-first + LONG_MAX
    assert(n == LONG_MAX);
    n = stringToLong("  +2147483647"); // spaces-at-first + positive number + LONG_MAX
    assert(n == LONG_MAX);
    n = stringToLong("  +2147483648abc"); // spaces-at-first + positive number + LONG_MAX + invaild number
    assert(n == LONG_MAX);
    return 0;
} 

int main(int argc, char const *argv[]){
    int rc = test();
    assert(rc == 0);
    cout << "pass tests" << endl;
    return 0;
}