#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
using namespace	std;
struct bodypart
{
	int x;
	int y;
};
class character
{
	private:
		int x;
		int y;
		struct bodypart left;
		struct bodypart right;
		int speed;
	public:
		character(int coordx,int coordy)
		{
			setX(coordx);
			setY(coordy);
			setBody();
		}
//		virtual void changeX() = 0;
//		virtual void changeY() = 0;
		void setX(int a)
		{
			this->x = a;
		}
		void setY(int a)
		{
			this->y = a;
		}
		int getX()
		{
			return this->x;
		}
		int getY()
		{
			return this->y;
		}
		void setBody()
		{
			this->left.x = this->x - 1;
			this->left.y = this->y;
			this->right.x = this->x+1;
			this->right.y = this->y;
		}
		int getLeftX()
		{
			return this->left.x;
		}
		int getLeftY()
		{
			return this->left.y;
		}
		int getRightX()
		{
			return this->right.x;
		}
		int getRightY()
		{
			return this->right.y;
		}
};

class pacman:public character
{
	private:
		char bodyPartMid;
		char bodyPartLeft;
		char bodyPartRight;
	public:
		pacman(int startx,int starty):character(startx,starty)
		{
			bodyPartMid = '<';
			bodyPartLeft ='(';
			bodyPartRight = ')';
			
		}
		void changeX(char a)//moving left
		{
			int b = getX();
			b--;
			setX(b);
			setBody();
		}
		void changeX(int a)//moving right
		{
			int b= getX();
			b++;
			setX(b);
			setBody();
		}
		void changeY(char a)//moving up
		{
			int b = getY();
			b--;
			setY(b);
			setBody();
		}
		void changeY(int a)//moving down
		{
			
			int b = getY();
			b++;
			setY(b);
			setBody();
		}	
		void setBodyPartMid(char a)
		{
			this->bodyPartMid = a;
		}
		void setBodyPartLeft(char a)
		{
			this->bodyPartLeft = a;
		}
		void setBodyPartRight(char a)
		{
			this->bodyPartRight = a;
		}
		char getBodyPartMid()
		{
			return this->bodyPartMid;
		}
		char getBodyPartLeft()
		{
			return this->bodyPartLeft;
		}
		char getBodyPartRight()
		{
			return this->bodyPartRight;
		}
};
class ghost: public character
{
	private:
		char bodyPartMid;
		char bodyPartLeft;
		char bodyPartRight;
	public:
		ghost(int startx,int starty):character(startx,starty)
		{
			bodyPartMid = '_';
			bodyPartLeft ='O';
			bodyPartRight = 'O';
			
		}
		void changeX(char a)//moving left
		{
			int b = getX();
			b--;
			setX(b);
			setBody();
		}
		void changeX(int a)//moving right
		{
			int b= getX();
			b++;
			setX(b);
			setBody();
		}
		void changeY(char a)//moving up
		{
			int b = getY();
			b--;
			setY(b);
			setBody();
		}
		void changeY(int a)//moving down
		{
			
			int b = getY();
			b++;
			setY(b);
			setBody();
		}	
		void setBodyPartMid(char a)
		{
			this->bodyPartMid = a;
		}
		void setBodyPartLeft(char a)
		{
			this->bodyPartLeft = a;
		}
		void setBodyPartRight(char a)
		{
			this->bodyPartRight = a;
		}
		char getBodyPartMid()
		{
			return this->bodyPartMid;
		}
		char getBodyPartLeft()
		{
			return this->bodyPartLeft;
		}
		char getBodyPartRight()
		{
			return this->bodyPartRight;
		}
		
};
class map
{
	private:
		char m[21][66];
	public:
		map()
		{
			freshdraw();
		}
		void freshdraw()
		{
			char a[21][66]={ 
"#################################################################",
"# * * * * * * * * * * * * * * * # * * * * * * * * * * * * * * * #",
"# * ########### * ########### * # * ########### * ########### * #",
"# * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * #",
"# * ########### * # * ################### # * # * ########### * #",
"# * * * * * * * * # * * * * * * # * * * * * * # * * * * * * * * #",
"############### * ########### * # * ########### * ###############",
"              # * # * * * * * * * * * * * * * # * #              ",
"############### * # * #####           ##### * # * ###############",
"* * * * * * * * * * * #                   # * * * * * * * * * * *",
"############### * # * #   G     G     G   # * # * ###############",
"              # * * * #                   # * * * #              ",
"############### * # * ##################### * # * ###############",
"              # * # * * * * * * P * * * * * * # * #              ",
"############### * ########### * # * ########### * ###############",
"# * * * * * * * * # * * * * * * # * * * * * * # * * * * * * * * #",
"# * ########### * # * ##################### * # * ########### * #",
"# * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * #",
"# * ########### * ########### * # * ########### * ########### * #",
"# * * * * * * * * * * * * * * * # * * * * * * * * * * * * * * * #",
"#################################################################"
							};
			for(int i = 0 ; i<21 ;i++)
			{
				for(int j = 0 ; j<65 ; j++)
				{
					this->m[i][j] = a[i][j];
				}
			}	 
		}
		void putboard()
		{
			for(int i = 0 ; i<21 ;i++)
			{
				for(int j=0; j<65 ; j++)
				{
					cout<<this->m[i][j];
				}
				cout<<endl;
			}	 
		}
		void changePacmanUP(pacman a)
		{
			this->m[a.getY()][a.getX()] = a.getBodyPartMid();
			this->m[a.getY()+1][a.getX()] = ' ';//head
			
			this->m[a.getLeftY()][a.getLeftX()] = a.getBodyPartLeft();
			this->m[a.getLeftY()+1][a.getLeftX()] = ' ';//Left part
			
			this->m[a.getRightY()][a.getRightX()] = a.getBodyPartRight();
			this->m[a.getRightY()+1][a.getRightX()] = ' ';//Right part
		}
		void changePacmanDown(pacman a)
		{
			this->m[a.getY()-1][a.getX()] = ' ';//head
			this->m[a.getY()][a.getX()] = a.getBodyPartMid();
			
			this->m[a.getLeftY()][a.getLeftX()] = a.getBodyPartLeft();
			this->m[a.getLeftY()-1][a.getLeftX()] = ' ';//Left part
			
			this->m[a.getRightY()][a.getRightX()] = a.getBodyPartRight();
			this->m[a.getRightY()-1][a.getRightX()] = ' ';//Right part
		}
		void changePacmanLeft(pacman a)
		{
			this->m[a.getY()][a.getX()] = a.getBodyPartMid();
			//gets cleared by body parts
			
			this->m[a.getLeftY()][a.getLeftX()] = a.getBodyPartLeft();//leftpart
			//getscleared by head
			
			this->m[a.getRightY()][a.getRightX()] = a.getBodyPartRight();
			this->m[a.getRightY()][a.getRightX()+1] = ' ';//Right part
		}
		void changePacmanRight(pacman a)
		{
			this->m[a.getY()][a.getX()] = a.getBodyPartMid();
			//gets cleared by body parts
			
			
			this->m[a.getLeftY()][a.getLeftX()] = a.getBodyPartLeft();
			this->m[a.getLeftY()][a.getLeftX()-1] = ' ';//Left part
			
			this->m[a.getRightY()][a.getRightX()] = a.getBodyPartRight();//Right part
			//getscleared by head.
		}
		void changeGhost(ghost a,int pax,int pay)
		{
			this->m[pay][pax] = ' ';//head
			this->m[a.getY()][a.getX()] = a.getBodyPartMid();
			
			this->m[a.getLeftY()][a.getLeftX()] = a.getBodyPartLeft();
			this->m[pay][pax-1] = ' ';//Left part
			
			this->m[a.getRightY()][a.getRightX()] = a.getBodyPartRight();
			this->m[pay][pax+1] = ' ';//Right part
		}
		
};
movealgo()
{
	
}
int main()
{
	map m;
	int ax=1,ay =0 ;
	int pax,pay;
	ghost g(10,10);
	pacman o(5,5);
	for(;;)
	{
		system("cls");
		m.putboard();
		m.changePacmanDown(o);
		if(ax == 49)
		{
			ax == 0;
		}
		if(ay == 7)
		{
			ay = 1;
		}
		ax = (2*ax)-1;
		pax = g.getX();
		pay = g.getY();
		ay++;
		
		g.setX(ax);
		g.setY(ay);
		g.setBody();
		m.changeGhost(g,pax,pay);
//		Sleep();
		switch(getch())
		{
			case 119:
				o.changeY('c');
				m.changePacmanUP(o);
				break;
			case 115:
				o.changeY(0);
				m.changePacmanDown(o);
				break;
			case 97:
				o.changeX('d');
				m.changePacmanLeft(o);
				break;
			case 100:
				o.changeX(0);
				m.changePacmanRight(o);
			
		}
		
		
	}
}