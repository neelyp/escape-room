// Atharva and Neel
// 1/7/25
// Escape Room
#include <iostream>
#include <cmath>
#include <ctime>
#include <cctype>
#include <string>
using namespace std;

bool mathPuzzleCheck(int userStar, int userMoon, int userQuestion) {
    if (pow(userStar, 2) + userMoon == userQuestion) {
        return true;
    } else return false;
}

bool caesarCheck(string ans) {
    string res = "";
    for (char ch : ans) {
        res += tolower(ch);
    }

    return true ? res == "egypt" : false;
}

int main() {
    cout << "You wake up after going to a museum. It's 3 am and you want to go home lets find out way out of this jonathan!" << endl;
    cout << "You start walking around you discover a tablet with ancient symbols. Each symbol represents a number" << endl;
    cout << "⭐️ + 🌙 = 11" << endl;
    cout << "⭐️ - (🌙✖️ -4) = 26" << endl;
    cout << "⭐️² + 🌙 = ❓" << endl;
    cout << "Enter numbers seperated by spaces for the values of the star, moon, and question mark: " << endl;
    int star, moon, question;
    cin >> star >> moon >> question; 
    if (mathPuzzleCheck(star, moon, question)) {
        cout << "You got it right!";
    } else {
        cout << "die";
        return -1;
    }
    cout<<"You actually solved it somepeople cannnot think that highly (RRRRRRAJNESH)" << endl;
    cout<<"You keep walking and find a famous quote known by all but its a Caesar Chiper with shift that is equal to the value of the star" << endl;
    cout << "find the meaning of this encrypted word: kmezv: " << endl;
    string caesarAns;
    cin >> caesarAns;
    if (caesarCheck(caesarAns)) {
        cout << "You got it right!";
    } else {
        cout << "die";
        return -1;
    }
    
    return 0;
}