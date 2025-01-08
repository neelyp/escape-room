// Atharva and Neel
// 1/7/25
// Escape Room
#include <iostream>
#include <cmath>
#include <ctime>
#include <cctype>
#include <string>
using namespace std;

// math func
bool mathPuzzleCheck(int userStar, int userMoon, int userQuestion) {
    if (pow(userStar, 2) + userMoon == userQuestion) {
        return true;
    } else return false;
}
// char func
bool caesarCheck(string ans) {
    string res = "";
    for (char ch : ans) {
        res += tolower(ch);
    }

    return true ? res == "egypt" : false;
};
// random number
int paintingNumber(){
    srand(time(0));
    return (rand() % 9 + 1 + 1) + 1;
}
// tme func

int main() {
    // first question 
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
    // second question 
    cout<<"You actually solved it somepeople cannnot think that highly (RRRRRRAJNESH)" << endl;
    cout<<"You keep walking and find a famous quote known by all (hint: star)" << endl;
    cout << "find the meaning of this encrypted word: kmezv: " << endl;
    string caesarAns;
    cin >> caesarAns;
    if (caesarCheck(caesarAns)) {
        cout << "You got it right!";
    } else {
        cout << "die";
        return -1;
    }
      // question 3  
    cout << "The quotes so happened to be under a picture of the pyramids" << endl;
    cout << "The moon light shines onto the painting in a certain spot you can see a faint number it seems to be single digit" << endl;
    
    int tries = 3;
    int paintingNum;
    bool solved = false;
    int ansPaint = paintingNumber();
    
    while (tries > 0 && !solved) {
        cout << "What do you think it is? (Tries remaining: " << tries << "): ";
        cin >> paintingNum;
        
        if (paintingNum == ansPaint) {
            cout << "Wow you got it" << endl; 
            solved = true;
        }
        else if (paintingNum > ansPaint) cout << "Too high try again" << endl;
        else cout << "Too low try again" << endl;
        tries--;
    }

    if (!solved) cout << "Out of tries The number was " << ansPaint << endl;

    // question 4
    cout << "This painting also happened to be painting";
    return 0;
}
