#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        double a,b,c;
        cin >> a >> b >> c;
        long long int strip_a = static_cast<long long int> (a);
        cout << "0x" << hex << nouppercase << strip_a << endl;
        
        cout << setw(15) << setfill('_') << showpos << fixed << setprecision(2) << b << endl;

        cout<<noshowpos                       
        <<scientific<<uppercase<<setprecision(9)<<c<<endl;
        
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
