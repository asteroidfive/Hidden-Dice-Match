//Created by SKY BROOKS

#include <iostream>
#include <cstdlib> 
#include <ctime> 
using namespace std;

void decision(char a);
void diceRoll(int i);
void prompt();

int money = 100;

void prompt() {
  cout << "Your current balance is $" << money << endl;
  cout << "Would you like to roll dice?" << endl << "Type Y for 'yes' or N for 'no'" << endl;
  char dec;
  cin >> dec;
  decision(dec);
}

void decision (char dec) {
  dec = toupper(dec);
  if (dec == 'Y') {
    int bet;
    cout << endl << "How much money would you like to bet?" << endl << '$';
    cin >> bet;

    if (bet > money) {
      cout << "Invalid amount, please do not bet more money than you have" << endl;
      decision(dec);
    }

    else {diceRoll(bet);}
    }
  else if (dec == 'N') {
  cout << "Exiting program";
  exit(0);
  }
  else {
  cout << "Invalid response" << endl;
  prompt();
  } 
}

void diceRoll(int bet) {
  int die1 = (rand() % 6) + 1;
  int die2 = (rand() % 6) + 1;
  int totalRoll = die1 + die2;
  char dec;
  int die3 = (rand() % 6) + 1;
  int die4 = (rand() % 6) + 1;
  int totalHidden = die3 + die4;

  cout << "You rolled a " << die1 << " and a " << die2 << endl;

  cout << "Total Roll: " << totalRoll << endl;
  
  cout << "The hidden numbers were " << die3 << " and " << die4 << endl;

  cout << "Total Hidden: " << totalHidden << endl;

  if ((die1 == die3 && die2 == die4) || (die1 == die4 && die2 == die3)) {
    money = money + (bet * 10);
  }
  else if (totalRoll == totalHidden) {
    money = money + bet;
  }
  else if ((die1 == die3 || die2 == die3) || (die1 == die4 || die2 == die4)) {
    money = money + (bet / 2);
  }
  else {
    money = money - bet;
  }
  
  cout << "Your current balance is $" << money << endl;
  if (money == 0) {
    cout << "You've run out of money, exiting game";
    exit(0);
  }
  cout << endl << "Would you like to roll again?" << endl;
  cin >> dec;
  decision(dec);
}

int main() {
  srand((unsigned) time(0));
  prompt();
}
