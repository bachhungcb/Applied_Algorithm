#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    map<string,int> Student_List;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int choice;
        string name;
        int grade;
        cin >> choice;
        if(choice == 1){
            cin >> name >> grade;
            int currentGrade = Student_List[name];
            Student_List[name] = currentGrade + grade;
        }if(choice == 2){
            cin >> name;
             Student_List[name] = 0;
        }if(choice == 3){
            cin >> name;
            int currentGrade = Student_List[name];
            if(currentGrade){
                cout << currentGrade << endl;
            }else{
                cout << "0" << endl;
            }
        }
    }
    return 0;
}
