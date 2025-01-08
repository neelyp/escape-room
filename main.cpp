// Atharva and Neel
// 1/7/25
// Escape Room
// Extra: Time whole lab
#include <iostream>
#include <cmath>
#include <ctime>
#include <cctype>
#include <string>
#include <iomanip>

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
    return (rand() % 9 + 1) + 1;
}
// tme func
int getTimeDigitSum() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    // Display the current time
    cout << "You find a clock that displays the current time in the room. The clock says: " 
         << (ltm->tm_hour) << ":" << (ltm->tm_min) << endl;


    return (ltm->tm_hour / 10 + ltm->tm_hour % 10) + (ltm->tm_min / 10 + ltm->tm_min % 10);
}
bool checkTimePuzzle(int correctAnswer) {
    cout << "To open the door add the digits of the current hour and minute together. What is the result? ";
    int userAnswer;
    cin >> userAnswer;

    if (userAnswer == correctAnswer) {
        cout << "Correct! The door creaks open." << endl;
        return true;
    } else {
        cout << "Incorrect! The correct sum was " << correctAnswer << "." << endl;
        return false;
    }
}

int main() {
    // first question 
    time_t start, end; 
    time(&start); 
    cout << "You wake up after going to a museum. It's 3 am and you want to go home lets find out way out of this jonathan!" << endl;
    cout << "You start walking around you discover a tablet with ancient symbols. Each symbol represents a number" << endl;
    cout << "⭐️ + 🌙 = 11" << endl;
    cout << "⭐️ - (🌙✖️ -4) = 26" << endl;
    cout << "⭐️² + 🌙 = ❓" << endl;
    cout << "Enter numbers seperated by spaces for the values of the star, moon, and question mark: " << endl;
    int star, moon, question;
    cin >> star >> moon >> question; 
    if (mathPuzzleCheck(star, moon, question)) {
        cout << "You got it right!" << endl;
    } else {
        cout << "die" << endl;
        return -1;
    }
    // second question 
    cout<<"You actually solved it somepeople cannnot think that highly (RRRRRRAJNESH)" << endl;
    cout<<"You keep walking and find a famous quote known by all (hint: star)" << endl;
    cout << "find the meaning of this encrypted word: kmezv: " << endl;
    string caesarAns;
    cin >> caesarAns;
    if (caesarCheck(caesarAns)) {
        cout << "You got it right!" << endl;

    } else {
        cout << "die" << endl;
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
        cout << "What do you think it is? (Tries remaining: " << tries << "): " << endl;
        cin >> paintingNum;
        
        if (paintingNum == ansPaint) {
            cout << "Wow you got it" << endl; 
            solved = true;
        }
        else if (paintingNum > ansPaint) cout << "Too high try again" << endl;
        else cout << "Too low try again" << endl;
        tries--;
    }

    if (!solved) 
    {
        cout << "Out of tries The number was " << ansPaint << endl;
         return -1;
    }
    // question 4
   int correctAnswer = getTimeDigitSum();

    // Check if the user can solve the time puzzle
    if (!checkTimePuzzle(correctAnswer)) {
        return -1; 
    }

    cout<<"There is nothing else left in the room expect the exit door it needs a combo what do you put in(Hint: use the past puzzle answers)"<<endl;

    string onecode = to_string(star+moon+question);
    
    string code = onecode + "5" + to_string(ansPaint) + to_string(correctAnswer);
    cout << "All the puzzles gave you clues for the keycode to escape the museum. You get one try to figure it out: " << endl;
    
    int code_;
    cin >> code_;
    string msg =  code_ == stoi(code) ? "That's correct! You escaped" : "That's wrong. You are stuck forever";
    cout << msg << endl;
    //extra
    time(&end); 
    double time_taken = double(end - start); 
    cout << "Time taken by program is : " << fixed << time_taken<< setprecision(2); 
}
