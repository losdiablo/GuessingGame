
#include<iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
	string playerName;
	int balance,bettingAmount;
	int guess,dice;
	char choice;
void welcome();
void rules();
void inputBet();	
void guessGame();
int main()
	{
	welcome();	
	return 0;
	}
void welcome()
	{
	cout<<"\n\t\t=====Welcome to casiono=====\n\n";
	cout<<"enter your name: ";
	getline(cin,playerName);
	cout<<"\n\nEnter the starting balace to play the game:	";
	cin>>balance;
	rules();
	}
void rules()
	{
	cout<<"\t\t=====CASINO  NUMBER GUESSING RULES!=====\n";
	cout<<"\t1. Choose a number between 1 to 10\n";	
	cout<<"\t2. Winner gets 10x of his /her bet amount\n";	
	cout<<"\t3. If your guess is incorrect, then you lose the entire bet amount\n";	
	inputBet();	
	}
void inputBet()
	{
	cout<<"\nyour current balance is:	"<<balance<<"\n";
	cout<<"Hey "<<playerName<<"enter the bet amount:	";
	cin>>bettingAmount;
	if (bettingAmount>balance)
		{
		cout<<"betting amount can't be more than current balance !\n"
			<<"\nre-enter balance ";
		inputBet();	
		}
	else	
		{
		guessGame();	
		}
	}
void guessGame()	
	{
	cout<<"Guess any number between 1 & 10: ";
	cin>>guess;
	if (guess<=1||guess>10)
	do
		{
		cout<<"\nNumber shoulde be between 1&10 !\n"
			<<"\nre-enter number ";
		} while (guess<=0||guess>10);
	srand(time(0));
	dice =rand()%10+1;
	if (dice==guess)
		{
		cout<<"Congratulations, You have won "<<bettingAmount*10;
		balance+=bettingAmount*10;
		}		
	else
		{
		cout<<"Oops! You lost "<<bettingAmount<<endl;	
		balance-=bettingAmount;
		}		
	cout<<"\nThe winning number was: "<<dice<<"\n";
	cout<<"\n"<<playerName<<", You have balace of "<<balance<<"\n";
	if(balance==0)
		{
		cout<<"You have no balace to play"<<"\n";
		cout<<"Thanks for playing the game\n";
		return ;
		}	
	cout<<"\n --Do you  want to play again (y/n)\n";
	cin>>choice;
	if((choice=='Y'||choice=='y'))
		{
		inputBet();	
		}
	else
		{
		cout<<"Thanks for playing the game.Your balance is"<<balance<<"\n"; 
		}	
	}
