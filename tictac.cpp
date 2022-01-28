#include <iostream>
#include <stdlib.h>
using namespace std;
class tictactoe4;
class tictactoe{
	int sq[10];
	int p=1,choice;
	string player[3];
	public:
	tictactoe(){
	 for(int i=1;i<10;i++)
		 sq[i]=0;
	}
	int win=-1;
	 int res();
	 void move();
	 void display();
	void turn();
	void winner(int);
	 void input(int);
	 void turncomp();
	 void first();
	friend class tictactoe4;
	friend void display4(tictactoe&);
	friend void turn4comp(tictactoe&,tictactoe4&);
	friend void move4(tictactoe4&,tictactoe&);
	
	void reset(){
		system("cls");
		 for(int i=1;i<10;i++)
		 sq[i]=0;
	}
	
	int checkhor(int z){
		if(sq[1] == z && sq[2] == z && sq[3] == z || sq[4] == z && sq[5] == z && sq[6] == z ||
		sq[7] == z && sq[8] == z && sq[9] == z)
	return 1;
		return 0;
	}

	int checkdia(int z){
		if(sq[1] == z && sq[5] == z && sq[9] == z || sq[3] == z && sq[5] == z && sq[7] == z )
	return 1;
		return 0;
	}
	int checkvert(int z){
		if (sq[1] == z && sq[4] == z && sq[7] == z ||
		sq[2] == z && sq[5] == z && sq[8] == z || sq[3] == z && sq[6] == z && sq[9] == z)
	return 1;
		return 0;		
	}
};

class tictactoe4{
	int sq[17];
	public:
	tictactoe4(){
		for(int i=0;i<17;i++)
		sq[i]=0;
	}
	void display4(tictactoe&);
	friend void turn4comp(tictactoe&,tictactoe4&);
	friend void move4(tictactoe4&,tictactoe&);
	 int res4();
void reset(){
		system("cls");
		 for(int i=1;i<17;i++)
		 sq[i]=0;
	}

	int check4hori(int z){
		if(sq[1] == z && sq[2] == z && sq[3] == z && sq[4] == z || sq[5] == z && sq[6] == z && sq[7] == z && 
		sq[8] == z || sq[9] == z && sq[10] == z && sq[11] == z && sq[12] == z || sq[13] == z && sq[14]== z&&
		sq[15]==z && sq[16]==z )
		return 1;

			return 0;
	}

	int check4vert(int z){
		if(sq[1] == z && sq[5] == z && sq[9] == z && sq[13] == z || sq[2] == z && sq[6] == z && 
		sq[10] == z && sq[14] == z || sq[3] == z && sq[7] == z && sq[11] == z && sq[15] == z 
		|| sq[4] == z && sq[8] == z && sq[12] == z && sq[16] == z )
		return 1;

			return 0;
	}

	int check4dia(int z){
		if(sq[1] == z && sq[6] == z && sq[11] == z && sq[16] == z || 
		sq[4] == z && sq[7] == z && sq[10] == z && sq[13] == z )
		return 1;

			return 0;
	}
	
};

void tictactoe4 :: display4(tictactoe& t){

		cout << t.player[1] << "'s Symbol -> 1  & " << t.player[2] <<"'s Symbol -> 2" << endl;
		cout << endl;
    	cout << "  \t\t      |     |     |" << endl;
		cout << "  \t\t   " << sq[1] << "  |  " << sq[2] << "  |  " << sq[3] << "  |  " << sq[4] << endl;
		cout << "  \t\t _____|_____|_____|_____" << endl;
		cout << "  \t\t      |     |     |     " << endl;
		cout << "  \t\t   " << sq[5] << "  |  " << sq[6] << "  |  " << sq[7] << "  |  " << sq[8] << endl;
		cout << "  \t\t _____|_____|_____|_____" << endl;
		cout << "  \t\t      |     |     |     " << endl;
		cout << "  \t\t   " << sq[9] << "  |  " << sq[10] << "  |  " << sq[11] << "  |  " << sq[12] << endl;
		cout << "  \t\t _____|_____|_____|_____" << endl;
		cout << "  \t\t      |     |     |     " << endl ;
		cout << "  \t\t   " << sq[13] << "  |  " << sq[14] << "  |  " << sq[15] << "  |  " << sq[16] << endl;
		cout << "  \t\t      |     |     |     " << endl << endl;

}


void gameplay3(tictactoe& t,int q){
	do
	{	
		t.display();
		if(q==1)
		t.turncomp();
		else if(q==2)
		t.turn();
		else{
		cout<<"Invalid Input";
		system("pause");}
		t.move();
		t.win = t.res();
		system("cls");
	}while (t.win == -1);
	t.display();

}

	void gameplay4(tictactoe4& x,tictactoe& t,int q){
		do
		{
			x.display4(t);
			if(q==1)
			turn4comp(t,x);
			else if(q==2)
			t.turn();
			else{
				cout<<"Invalid Input";
				system("pause");
			}
			move4(x,t);
			t.win = x.res4();
			system("cls");
		}while(t.win == -1);
		x.display4(t);
	}



  int tictactoe :: res() {
	if (checkhor(1)||checkhor(2)||checkvert(1)||checkvert(2)||checkdia(1)||checkdia(2))
		return 1;
	else if (sq[1] != 0 && sq[2] != 0 && sq[3] != 0 && sq[4] != 0 && sq[5] != 0 && sq[6] != 0 && sq[7] != 0 && sq[8] != 0 && sq[9] != 0)
		return 0;
	return -1;
}

	
  int tictactoe4 :: res4() {
	if (check4hori(1)||check4hori(2)||check4vert(1)||check4vert(2)||check4dia(1)||check4dia(2))
		return 1;
	else if (sq[1] != 0 && sq[2] != 0 && sq[3] != 0 && sq[4] != 0 && sq[5] != 0 && sq[6] != 0 && sq[7] != 0 
	      && sq[8] != 0 && sq[9] != 0 && sq[10] != 0 && sq[11] != 0 && sq[12] != 0 && sq[13] != 0 && sq[14] != 0 
	      && sq[15] != 0 && sq[16] !=0)
		return 0;
	return -1;
}

void tictactoe :: move(){
	if (p == 1)
		{
			if (sq[choice] == 1 || sq[choice] == 2) {
				cout << "Invalid Move" << endl;
				system("pause");
			}
			else if (choice < 10 && choice>0) {
				sq[choice] = 1;
				p = 2;
			}
			else {
				cout << "Invalid Move" << endl;
				system("pause");
			}
		}
		else
		{
			if (sq[choice] == 1 || sq[choice] == 2) {
				cout << "Invalid Move" << endl;
				system("pause");
			}
			else if (choice < 10 && choice>0) {
				sq[choice] = 2;
				p = 1;
			}
			else {
				cout << "Invalid Move" << endl;
				system("pause");
			}
		}
}


void move4(tictactoe4& x,tictactoe& t){
	if (t.p == 1)
		{
			if (x.sq[t.choice] == 1 || x.sq[t.choice] == 2) {
				cout << "Invalid Move" << endl;
				system("pause");
			}
			else if (t.choice < 17 && t.choice>0) {
				x.sq[t.choice] = 1;
				t.p = 2;
			}
			else {
				cout << "Invalid Move" << endl;
				system("pause");
			}
		}
		else
		{
			if (x.sq[t.choice] == 1 || x.sq[t.choice] == 2) {
				cout << "Invalid Move" << endl;
				system("pause");
			}
			else if (t.choice < 17 && t.choice>0) {
				x.sq[t.choice] = 2;
				t.p = 1;
			}
			else {
				cout << "Invalid Move" << endl;
				system("pause");
			}
		}
}


void tictactoe :: display(){
		

		cout << player[1] << "'s Symbol -> 1  & " << player[2] <<"'s Symbol -> 2" << endl;

		cout << endl;
		cout << "  \t\t      |     |     " << endl;
		cout << "  \t\t   " << sq[1] << "  |  " << sq[2] << "  |  " << sq[3] << endl;
		cout << "  \t\t _____|_____|_____" << endl;
		cout << "  \t\t      |     |     " << endl;
		cout << "  \t\t   " << sq[4] << "  |  " << sq[5] << "  |  " << sq[6] << endl;
		cout << "  \t\t _____|_____|_____" << endl;
		cout << "  \t\t      |     |     " << endl;
		cout << "  \t\t   " << sq[7] << "  |  " << sq[8] << "  |  " << sq[9] << endl;
		cout << "  \t\t      |     |     " << endl << endl;
		
}
void tictactoe :: turn(){
	cout << player[p] << " enter your choice(1-9): ";
	cin >> choice;
}

void tictactoe :: turncomp(){
	int k = 1 + ( std::rand() % ( 9 - 1 + 1 ) );

	if(p==1){
	cout << player[p] << " enter your choice(1-9): ";
	cin >> choice;}
	else{
		while(sq[k] == 1 || sq[k] == 2){
		 k = 1 + ( std::rand() % ( 9 - 1 + 1 ) );
		}
		choice = k;
	}
}


void turn4comp(tictactoe& t,tictactoe4& x){
	int k = 1 + ( std::rand() % ( 16 - 1 + 1 ) );

	if(t.p==1){
	cout << t.player[t.p] << " enter your choice(1-9): ";
	cin >> t.choice;}
	else{
		while(x.sq[k] == 1 || x.sq[k] == 2){
		 k = 1 + ( std::rand() % ( 16 - 1 + 1 ) );
		}
		t.choice = k;
	}
}

void tictactoe ::  winner(int q){
	if (win == 1)
	{
		if (p == 1)
		{
			p = 2;
		}
		else if (p == 2)
		{
			p = 1;
		}
		if(q==1 && p==2){
		cout<<"\t\t\t ---------------------------------------"<<endl;
		cout  << "\t\t\t|\t!!!Better Luck Next Time!!!"<<"\t|" << endl;
		cout<<"\t\t\t ---------------------------------------"<<endl;
		}
		else
		cout<<"\t\t\t ---------------------------------------"<<endl;
		cout  << "\t\t\t|\tCongrats "<< player[p] << " you won" <<"\t|" << endl;
		cout<<"\t\t\t ---------------------------------------"<<endl;
	}
	else
		cout << "\aGame draw" << endl;
}
void tictactoe :: input(int q){
	cout<<endl<<"Enter name of player 1: ";
	cin>>player[1];
	if(q==1)
	player[2]="Computer";
	else{
	cout<<endl<<"Enter name of player 2: ";
	cin>>player[2];}

}
void tictactoe :: first(){
	char e;
		cout<<"Do you want to go first(Y/N): ";
		cin>>e;
		if(e=='y'||e=='Y')
		p=1;
		else if(e=='n'||e=='N')
		p=2;
		else{
		cout<<"Invalid Input";
		system("pause");
		}
	
}
void title(){
	cout << "\t\t\t\t\t-------------------------------------------" << endl;
		cout << "\t\t\t\t\t" <<"|"<<"\tWelcome To Tic Tac Toe Game\t  " << "|" << endl ;
		cout << "\t\t\t\t\t-------------------------------------------" << endl<<endl<<endl;
}
int main()
{	tictactoe t;
   tictactoe4 x;
	char j;
	int q,m;
	system("cls");
	title();
	cout<<"1 - Player or 2 - Player: ";
	cin>>q;
	cout<<endl;
	if(q==1){
	cout<<endl;
	t.first();}
	t.input(q);
	cout<<endl<<endl<<"PLease Select type of Board"<<endl;
	cout<<"Enter 1 for 3x3 \nEnter 2 for 4x4: ";
	cin>>m;
	cout<<endl<<endl<<endl;
	again:
	if(m==1)
	gameplay3(t,q);
	else if(m==2)
	gameplay4(x,t,q);
	else{
		cout<<"Invalid Input";
		system("pause");
	}

	t.winner(q);

	cout<<"Do you want to play(Y/N): ";
	cin>>j;
	if(j=='y'||j=='Y'){
	if(m==1)
	t.reset();
	else
	x.reset();
	goto again;
	}

	return 0;
}