#include<iostream>
using namespace std;

int score = 0;

class QuizGame {
public:
    string name, roll, level;
    int levelChoice;

    void welcome() {
        cout<<"========================================\n";
        cout<<"     << Welcome to Quiz Game >>\n";
        cout<<"========================================\n";
        cout<<"Enter your name: ";
        cin>>name;
        cout<<"Enter your roll number: ";
        cin>>roll;
        cout<<"\nSelect difficulty level:\n";
        cout<<"1. Intermediate\n";
        cout<<"2. University\n";
        cout<<"Enter your choice (1 or 2): ";
        cin>>levelChoice;
        if(levelChoice==1)
            level="Intermediate";
        else
            level="University";
        cout<<"\nWelcome, "<<name<<" (Roll No: "<<roll<<")!\n";
        cout<<"You've selected the "<<level<<" level.\n";
        cout<<"Let's begin your quiz journey!\n";
        cout<<"----------------------------------------\n";
    }

    void askQuestion(string q, string a, string b, string c, string d, char correct) {
        char ans;
        cout<<q<<"\n";
        cout<<"a. "<<a<<"\n";
        cout<<"b. "<<b<<"\n";
        cout<<"c. "<<c<<"\n";
        cout<<"d. "<<d<<"\n";
        cout<<"Your answer: ";
        cin>>ans;
        if(ans==correct || ans==toupper(correct)) {
            score+=10;
            cout<<" Correct! Your score: "<<score<<"\n";
        } else {
            cout<<" Wrong! Correct answer was: "<<correct<<"\n";
        }
        cout<<"----------------------------------------\n";
    }

    void result() {
        cout<<"\n========================================\n";
        cout<<"   FINAL RESULT\n";
        cout<<"========================================\n";
        cout<<"Name      : "<<name<<"\n";
        cout<<"Roll No   : "<<roll<<"\n";
        cout<<"Level     : "<<level<<"\n";
        cout<<"Score     : "<<score<<"\n";
        if(score==30)
            cout<<" Genius alert! You nailed it like a boss!\n";
        else if(score>=20)
            cout<<" Good job! You're quiz-worthy!\n";
        else if(score>=10)
            cout<<" Hmm... Not bad but could be better!\n";
        else
            cout<<" Yikes! Did you close your eyes while answering?\n";
        cout<<"Thanks for playing!\n";
        cout<<"========================================\n";
    }
};

class EnglishQuiz:public QuizGame {
public:
    void start() {
        cout<<"\n Starting English Quiz ("<<level<<" Level)\n";
        cout<<"----------------------------------------\n";
        if(level=="Intermediate") {
            askQuestion("1. Choose the correct spelling:", "Definitely", "Definitely", "Definetly", "Definatly", 'b');
            askQuestion("2. What is a synonym of 'Happy'?", "Sad", "Angry", "Joyful", "Lazy", 'c');
            askQuestion("3. Fill in the blank: She ____ a new dress.", "buy", "bought", "buys", "buyed", 'b');
            askQuestion("4. Choose the correct article: ___ apple a day...", "a", "an", "the", "none", 'b');
            askQuestion("5. Past tense of 'go' is:", "went", "goes", "gone", "going", 'a');
        } else {
            askQuestion("1. Choose the correct passive voice: 'She wrote a letter.'",
                        "A letter is written by her.", "A letter has been written by her.",
                        "A letter was written by her.", "A letter was being written by her.", 'c');
            askQuestion("2. What is an antonym of 'Obscure'?",
                        "Clear", "Dark", "Hidden", "Dull", 'a');
            askQuestion("3. Identify the noun: 'The teacher gave a lecture.'",
                        "gave", "teacher", "a", "lecture", 'b');
            askQuestion("4. Antonym of 'begin' is:", "end", "start", "open", "create", 'a');
            askQuestion("5. Choose the correct preposition: She is good ___ math.", "at", "on", "in", "for", 'a');
        }
    }
};

class MathQuiz:public QuizGame {
public:
    void start() {
        cout<<"\n Starting Math Quiz ("<<level<<" Level)\n";
        cout<<"----------------------------------------\n";
        if(level=="Intermediate") {
            askQuestion("1. What is 5 + 3?", "6", "7", "8", "9", 'c');
            askQuestion("2. 12 / 4 = ?", "3", "2", "4", "6", 'a');
            askQuestion("3. What is 9 * 9?", "81", "72", "99", "90", 'a');
            askQuestion("4. 10 - 4 = ?", "5", "6", "7", "8", 'b');
            askQuestion("5. 6 * 2 = ?", "8", "10", "12", "14", 'c');
        } else {
            askQuestion("1. Derivative of x^2?", "2x", "x", "x^2", "1", 'a');
            askQuestion("2. Integration of 1/x dx?", "x", "ln(x)", "1", "x^2/2", 'b');
            askQuestion("3. Value of sin(90)?", "1", "0", "0.5", "undefined", 'a');
            askQuestion("4. Value of 2^3?", "6", "8", "9", "12", 'b');
            askQuestion("5. 15 / 3 = ?", "4", "5", "6", "3", 'b');
        }
    }
};

class PhysicsQuiz:public QuizGame {
public:
    void start() {
        cout<<"\n Starting Physics Quiz ("<<level<<" Level)\n";
        cout<<"----------------------------------------\n";
        if(level=="Intermediate") {
            askQuestion("1. Unit of force?", "Joule", "Newton", "Watt", "Pascal", 'b');
            askQuestion("2. Speed = ?", "Distance/Time", "Time x Distance", "Velocity x Time", "Mass/Volume", 'a');
            askQuestion("3. Gravity on Earth?", "8.9 m/s^2", "10 m/s^2", "9.8 m/s^2", "9.2 m/s^2", 'c');
            askQuestion("4. SI unit of time is:", "second", "minute", "hour", "day", 'a');
            askQuestion("5. SI unit of distance is:", "meter", "second", "kilogram", "ampere", 'a');
        } else {
            askQuestion("1. Formula of kinetic energy?", "1/2mv^2", "mv", "ma", "v^2", 'a');
            askQuestion("2. SI unit of Power?", "Watt", "Newton", "Joule", "Ampere", 'a');
            askQuestion("3. Light year is a unit of?", "Time", "Speed", "Distance", "Weight", 'c');
            askQuestion("4. Unit of acceleration is:", "m/s", "m/s^2", "N", "J", 'b');
     askQuestion("5. Approx speed of light is:", "3×10^8 m/s", "3×10^6 m/s", "3×10^3 m/s", "3×10^5 m/s", 'a');
        }
    }
};

int main() {
    QuizGame game;
    game.welcome();

    int engDone=0, mathDone=0, phyDone=0;
    int choice;

    do {
        cout<<"\nWhich subject would you like to take the quiz of?\n";
        if(engDone==0) cout<<"1. English\n";
        if(mathDone==0) cout<<"2. Math\n";
        if(phyDone==0) cout<<"3. Physics\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        if(choice==1 && engDone==0) {
            EnglishQuiz e;
            e.level=game.level;
            e.start();
            engDone=1;
        }
        else if(choice==2 && mathDone==0) {
            MathQuiz m;
            m.level=game.level;
            m.start();
            mathDone=1;
        }
        else if(choice==3 && phyDone==0) {
            PhysicsQuiz p;
            p.level=game.level;
            p.start();
            phyDone=1;
        }
        else {
            cout<<"You already took that quiz or entered an invalid choice.\n";
        }

        if((engDone+mathDone+phyDone)<3) {
            cout<<"\nDo you want to take another quiz? (1 = Yes / 0 = No): ";
            cin>>choice;
        } else {
            break;
        }
    } while(choice==1);

    game.result();
    return 0;
}

