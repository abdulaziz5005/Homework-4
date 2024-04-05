//
// Created by ...
// Date:
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    int i = 5;
    while (i * i <= n) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
        i += 6;
    }
    return true;
}
int countPrimesUntilN(int N) {
    int count = 0;
    for (int i = 2; i <= N; ++i) {
        if (isPrime(i))
            count++;
    }
    return count;
}
int tribonacci ( int num_3 ) {
    if ( num_3 == 0) {
        return 0 ;
    }
    if ( num_3 ==1 || num_3==2) {
        return 1;
    }
    int cur1=0, cur2=1, cur3 =1 ;
    int curent;
    for ( int i=3 ; i <=num_3 ; ++i ) {
        curent=cur1+cur2+cur3 ;
        cur1=cur2;
        cur2=cur3;
        cur3=curent;
    }
    return curent ;
}
bool valid( int x, int y , int z , int num_4) {
    int eq1=4*x-2*y+3*z;
    int eq2=x*y*z;
    int eq3=x*x+y*y+z*z ;
    return (eq1==20 && eq2 < num_4 && eq3 >8) ;
}
char caesar ( char ch, int shift) {
    if (isalpha(ch)) {
        char base = islower(ch) ? 'a' : 'A';
        return (ch - base + shift) % 26 + base;
    }
    return ch;
}
int main() {
    cout << "PROBLEM 1\n";
    int N ;
    cout<< " Enter the number for 'N': " ;
    cin>> N;
    cout << countPrimesUntilN (N) << endl;




    cout << "PROBLEm 2\n";
    int number_2;
    cout << " Enter your number: " ;
    cin >> number_2;
    int x= number_2 ;
    while ( number_2> 0) {
        for ( int i=1 ; i <= number_2 ; i++) {
            cout<<i<<" ";
        }
        for ( int i =0 ; i < ( x-number_2)*2 ; i++) {
            cout << " ";
        }
        for ( int i=1 ; number_2<=i ;i-- ) {
            cout<< i << " " ;
        }
        number_2 -- ;
    }
    cout << "PROBLEM 3\n";
    int N_3 ;
    cout << " Enter the number for 'N_3': ";
    cin >> N_3;
    cout << tribonacci( N_3) << endl;



    cout << "PROBLEM 4\n";
    int N_4 ;
    cout << " Enter the number for 'N_4': " ;
    cin >> N_4;
    vector<vector<int > > solutions;
    for (int x = -10; x <= 10; ++x) {
        for (int y = -3; y <= 3; ++y) {
            for (int z = 2; z <= 6; ++z) {
                if (valid(x, y, z, N_4)) {
                    solutions.push_back( {x, y, z});
                }
            }
        }
    }
    if (solutions.empty()) {
        cout << "No integer solution for this" << endl;
    } else {
        cout << "Integer soultion:" << endl;
        for (const auto& sol : solutions) {
            cout << "x = " << sol[0] << ", y = " << sol[1] << ", z = " << sol[2] <<
                 endl;
        }
    }
    cout << "PROBLEM 5\n";
    char character;
    int shiftfactor , rounds ;
    cout << " Enter the character to be encrypted: " ;
    cin >> character;
    cout << " Enter the Caesar cipher shift factor: " ;
    cin>> shiftfactor ;
    cout << " Enter the number of encyption rounds: " ;
    cin >> rounds ;
    for ( int round=1 ; round <=rounds ; ++round ) {
        cout << "Round "<< round;
        character= caesar(character,shiftfactor);
        cout << character << endl ;
    }
    return 0;
}
