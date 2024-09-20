#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main() {
    int n;
    cin >> n;
    set<int>s;
    for(int i = 0; i < n; i++){
        int choice;
        cin >> choice;
        int temp;
        if(choice == 1){
            cin >> temp;
            s.insert(temp);
        }
        if(choice == 2){
            cin >> temp;
            s.erase((temp));
        }if(choice == 3){
            cin >> temp;
            if(s.find(temp) != s.end()){
                cout << "Yes" << endl;
            }else{
                cout << "No"<< endl;
            }
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
