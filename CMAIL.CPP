
/************************************************************************
                        HEADER FILES
************************************************************************/


#include<fstream.h>
#include<time.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<string.h>
#include<process.h>

/****************************************************************************
		  FUNCTIONS USED IN PROJECT
*****************************************************************************/


ifstream finacc,fininbox;
ofstream foutacc,foutinbox;
fstream f;
int ch1,x,y,y1,l,recno=0;
char suname[15],mm[5];
void to_get_password();
void login_page();
void signup();
void signup_page();
void m1();
void signin();
void login_id(int);
void send_mail(char f[15]);
void login_in_to_id(char r[15]);









/***************************************************************************
	       CLASSES USED IN PROJECT
****************************************************************************/



class user
{
		char sqa[10],usernm1[15],pswrd[15],id[20];
	public:
		int match_un(char usrnm[15]);
		void signup(char y[20],char t[20],char u[20], char e[20]);
		void disdata();
		int match_id(char id1[20]);
		void password();
		int sqq(char id2[20]);
		int match_pass(char pass[20]);
		void change_pass();

}cmail;

class inbox
{
		char from[15], to[75], text[20],sub[45],date[20],time[10];
		int ch;
	public:
		void setch(int);
		void writin(char ch[]);
		int retch(int);
		void date1();
		void time1();
		void to_send(char r[15],char p[15] );
		int match_to_send(char r[15]);
		void see_inbox(int);
		void see_sent_mail(int);
		int match_to_sent_mail(char r[15]);
}box;

void user::signup(char y[20],char t[20],char u[20], char e[20])
{
	strcpy(usernm1,y);
	strcpy(id,t);
	strcpy(sqa,u);
	strcpy(pswrd,e);
}


int user::match_pass(char pass2[20])
{
	return(strcmp(pswrd,pass2));
}

int user::match_id(char id1[20])
{
	return (strcmp(id,id1));
}

void user::password()
{
	gotoxy(15,25);
	cout<<" Your Password is:";
	puts(pswrd);
	getch();
}

int user::sqq(char sq2[20])
{
	return(strcmp(sq2,sqa));
}

void user::disdata()
{
	clrscr();
	cout<<"\nID:" ;
	puts(id);
	cout<<"\nPassword:";
	puts(pswrd);
}

void inbox::date1()
{
	int n,i,temp=0,temp1=0;
	_strdate(date);
	i=0;
	temp=date[i];
	i++;
	temp1=date[i];
	i=i+2;
	date[0]=date[i];
	i++;
	date[1]=date[i];
	date[i]=temp1;
	date[i-1]=temp;

}

void inbox::time1()
{
	_strtime(time);
}
int inbox::match_to_sent_mail(char r[15])
{
	return(strcmpi(from,r));
}

void inbox::see_sent_mail(int r)
{

	cout<<"To:";
	puts(to);
	gotoxy(30,r-2);
	cout<<date<<"  "<<time;
	cout<<"\nsubject : ";
	puts(sub);
	cout<<"\nMessage: ";
	puts(text);
}

int inbox::match_to_send(char r[15])
{
	return(strcmpi(to,r));
}


void inbox::see_inbox(int r)
{
	cout<<"\n\nFROM:";
	puts(from);
	cout<<"\n\nTO : ";
	puts(to);
	cout<<"\n\ndate : "<<date<<"\n \ntime : "<<time;
	cout<<"\n\nsubject : ";
	puts(sub);
	cout<<"\n\nMessage: ";
	puts(text);
}

void inbox::to_send(char to1[15], char from1[20])
{
	strcpy(to,to1);
	strcpy(from,from1);
	gotoxy(4,9);
	cout<<"From:";
	gotoxy(9,9);
	puts(from);
	gotoxy(strlen(from)+9,9);
	cout<<"@cmail.com";
	gotoxy(4,12);
	cout<<"Subject:(max. 45 characters) ";
	gotoxy(34,12);
	gets(sub);
	gotoxy(4,15);
	cout<<"Message:";
	gotoxy(5,45);
	cout<<"press enter to send message ";
	gotoxy(14,15);
	gets(text);

	date1();
	time1();
}

int user::match_un(char usrnm[15])
{
		return(strcmp(usrnm,id));
}


void inbox::writin(char ch[])
{

	int i=0;
	int len=strlen(from);
	strcpy(ch,from);
	for(i=len;i<10;i++)
		ch[i]=' ';
	len=strlen(sub);
	for(i=0;i<len;i++)
		ch[10+i]=sub[i];
for(i=len+10;i<60;i++)
		ch[i]=' ';
for(i=0;i<=10;i++)
		ch[60+i]=date[i];
ch[60+i]='\0';
}


void text(int x,int y,int sel,char txt[75])
 {
	if(!sel) //Item is selected
{
	textbackground(WHITE);
		textcolor(BLACK);
	 }
	else
	{
		textbackground(BLACK);
		textcolor(WHITE);
	}
	gotoxy(x,y);
cputs(txt);
 }
int displayinbox(char nm[20],char ch[])
{
int q=0,x=1,y=10,sel=1;
fininbox.open("inbox.dat",ios::binary|ios::in);
while(fininbox.read((char*)&box,sizeof(box)))
     {

	if(box.match_to_send(nm)==0)
	{

		q++;
	}


     }
fininbox.close();
if(q==0)
     {
	return -1;
     }

fininbox.open("inbox.dat",ios::binary|ios::in);
if(q>=0)
     {
		int n=0;
		char str[15][75];
		while(n<15&&n<q)
		{
			fininbox.read((char*)&box,sizeof(box));
			if(box.match_to_send(nm)==0)
			{
				box.writin(str[n]);
				n++;
			}
		}

	int num=q;
	if(q>15) num=15;
	cout<<"\n\n FROM\t\tSUBJECT\t\t\t\t\t\tDATE";
	gotoxy(2,45);
	cout<<"total mails :"<<num;
	cout<<"\npress enter to select mail you want to see ";
	cout<<"\npress escape to exit inbox ";
	textbackground(WHITE);textcolor(BLACK);
	gotoxy(x,y);cputs(str[0]);
	textbackground(BLACK);textcolor(WHITE);

	for(int i=1;i<num;i++)
	{
		gotoxy(x,y+i);
		cputs(str[i]);
	}


	char key=72;
	while(key!='\n') //Until Enter Key is pressed
	{
		key=getch();

	//Otherwise pressing any invalid key will remove the selection.
	//Note : 49 is the ascii code of '1'
		if((key==72)||(key==80)||(key==27))
			text(x,y+sel-1,1,str[sel-1]);

		switch(key)
		{
			case 72://UP
				if(sel==1) text(x,y+num-1,0,str[num-1]);
				else text(x,y+sel-2,0,str[sel-2]);

				if(sel==1) sel=num;
				else sel--;
				break;
			case 80: //DOWN
				if(sel==num) text(x,y,0,str[0]);
				else text(x,y+sel,0,str[sel]);

				if(sel==num) sel=1;
				else sel++;
				break;

			case 13://ENTER
				fininbox.close();
				strcpy(ch,str[sel-1]);
				return sel;

			case 27:sel=0; goto end; //Escape Button.
			default:break;
		}
	 }
	end:
	strcpy(ch,str[sel-1]);

     }
fininbox.close();
textcolor(WHITE); textbackground(BLACK);
return sel;

}



void main()
{
	clrscr();
	m1();//first menu

}
void color(int x1,int x2,int y1,int y2,int c)
{
	textbackground(c);
	for(int i=x1;i<=x2;i++)
	for(int j=y1;j<=y2;j++)
	    {
		gotoxy(i,j);
		cprintf(" ");
	    }
}
void m1()
{
	clrscr();
	color(0,80,0,60,5);
	gotoxy(1,1);
	for(y=0;y<20;y++)
	{
		gotoxy(24,y);
		y1=y-1;
		cout<<"1. Create a new id";
		gotoxy(1,y1);
		clreol();
		delay(20);
	}
	gotoxy(1,1);
	cout<<"\n\t\t\tWELCOME TO CMAIL ";
	for(x=1;x<25;x++)
	{
		gotoxy(1,23);
		clreol();
		gotoxy(x,23);
		cout<<"2. Login";
		delay(20);
	}
	for(x=68;x>23;x--)
	{
		gotoxy(x,27);
		cout<<"3. Exit";
		delay(20);
		clreol();
	}
	for(y=50;y>33;y--)
	{
		gotoxy(24,y);
		cout<<"Your Choice:";
		delay(40);
		gotoxy(1,y+1);
		clreol();
	}

	gotoxy(36,34);
	cout<<"            ";
	gotoxy(36,34);
	cin>>ch1;
	while(cin.fail())
	{
		gotoxy(11,38);
		cout<<"Please enter a number not a character.";
		getch();
		gotoxy(11,38);
		clreol();
		cin.clear();
		cin.ignore(1,'\n');
		gotoxy(1,18);
		clreol();
		cin.clear();
		cin.ignore(1,'\n');
		gotoxy(24,34);
		cout<<"Your Choice:                      ";
		gotoxy(36,34);
		cin>>ch1;
	}//while of cin fail closes.
	while(ch1!=1&&ch1!=2&&ch1!=3)
	{
		gotoxy(11,38);
		cout<<"Please give a suitable input.\n";
		getch();
		gotoxy(11,38);
		clreol();
		gotoxy(24,34);
		cout<<"Your Choice:                      ";
		gotoxy(36,34);
		cin>>ch1;
	}
	textbackground(BLACK);
	switch(ch1)
	{
		case 1:signup();
		break;
		case 2:signin();
		break;
		case 3:exit(0);
	}//switch(ch1) closes
	m1();
}//function m1 closes


void signin()
{
	char usrnm[15],pswrd[15],hh[20];
	recno=0;
	int found=0;
	int i=0,ch;
	finacc.open("AMEY.dat",ios::binary);
	clrscr();
	color(0,80,0,60,GREEN);
	login_page();
	gotoxy(49,21);
	cout<<"@cmail.com";
	gotoxy(49,19);
	gets(usrnm);
	fflush(stdin);
		x=49;
		y=29;
		do
		{
			gotoxy(x,y);
			ch=getch();
			gotoxy(x,y);
			if(x>=49)
			{
				if((int)ch!=13)
				{
					if((int)ch!=8)
					{
						cout<<"*";
						x++;
					}
					else if(x>49)
					{
							x--;
							gotoxy(x,y);
							cout<<" ";
					}
					if((int)ch!=8&&x>=49)
					{
						pswrd[i]=ch;
						i++;
					}
					else if(x>=49)
					{
						if(i>0)
							i--;
						else
							i=0;
						pswrd[i]='\0';
					}
				}
			}
			else
			x=49;
		}while((int)ch!=13);
		pswrd[i]='\0';
	while(finacc.read((char*)&cmail,sizeof(cmail)))
	{
		if(cmail.match_un(usrnm)==0)
			   {
				if(cmail.match_pass(pswrd)==0)
					found=1;
			   }
		else
			recno++;
	}
	finacc.close();
if(strlen(usrnm)==0||strlen(pswrd)==0)
	 {
	gotoxy(40,40);
	cout<<"Any of the above fields can't be empty.";
	gotoxy(40,42);
	cout<<"So, please enter the data again.";
	gotoxy(3,46);
	cout<<"To return to main menu, press M ";
	gotoxy(3,48);
	cout<<"If you forgot your password, press F otherwise press any key:";
	gets(mm);
	if(strcmpi(mm,"m")==0)
		m1();
	if(strcmpi(mm,"f")==0)
		   to_get_password();
	signin();
	 }
if(found==1)
		login_in_to_id(usrnm);
else
   {
	gotoxy(40,40);
	cout<<"PASSWORD OR USERNAME INCORRECT";
	getch();
	cout<<endl;
	gotoxy(3,46);
	cout<<"To return to main menu, Press M ";
	gotoxy(3,48);
	cout<<"If you forgot your password, Press F otherwise press any key:";
	gets(mm);
	if(strcmpi(mm,"m")==0)
		m1();
	if(strcmpi(mm,"f")==0)
		to_get_password();
	signin();
   }
gotoxy(10,40);
cout<<"Please wait Your account is in process of logout";
for(int l=0;l<15;l++)
   {
		cout<<".";
		delay(100);
   }
gotoxy(15,45);
cout<<"Your Account Has Been Succesfully Logged out";
getch();
m1();
getch();
}


void signup()
{
	clrscr();
	color(0,80,0,60,4);
	int y=2,x,temp,ch,rem,welcome,p=0,s=1;
	char name[20],sqa[15],pswrd[15],user[20],cpaswrd[15],ans[5];
	long int pn;
	int i=0,g=1;;
	gotoxy(3,3);
	cout<<"Your name:";
	gets(name);
	fflush(stdin);
	do
	{
		if(p>0)
		{
			i=0;
			gotoxy(8,14);
			cout<<"The above passwords do not match.\n";
			getch();
			gotoxy(8,14);
			clreol();
			gotoxy(20,11);
			clreol();
			gotoxy(43,7);
			clreol();
		}
		gotoxy(3,7);
		cout<<"Enter the password (Max. 15 characters):";
		x=43;
		y=7;
		do
		{
			gotoxy(x,y);
			ch=getch();
			gotoxy(x,y);
			if(x>=43)
			{
				if((int)ch!=13)
				{
					if((int)ch!=8)
					{
						cout<<"*";
						x++;
					}
					else if(x>43)
					{
							x--;
							gotoxy(x,y);
							cout<<" ";
					}
					if((int)ch!=8&&x>=43)
					{
						pswrd[i]=ch;
						i++;
					}
					else if(x>=43)
					{
						if(i>0)
							i--;
						else
							i=0;
						pswrd[i]='\0';
					}
				}
			}
			else
			x=43;
		}while((int)ch!=13);
		pswrd[i]='\0';
		i=0;
		gotoxy(3,11);
		cout<<"Confirm Password:";
		x=20;
		y=11;
		do
		{
			gotoxy(x,y);
			ch=getch();
			gotoxy(x,y);
			if(x>=20)
			{
				if((int)ch!=13)
				{
					if((int)ch!=8)
					{
						cout<<"*";
						x++;
					}
					else if(x>20)
					{
							x--;
							gotoxy(x,y);
							cout<<" ";
					}
					if((int)ch!=8&&x>=20)
					{
						cpaswrd[i]=ch;
						i++;
					}
					else if(x>=20)
					{
						if(i>0)
							i--;
						else
							i=0;
						cpaswrd[i]='\0';
					}
				}
			}
			else
			x=20;
		}while((int)ch!=13);
		cpaswrd[i]='\0';
		p++;
	}while(strcmp(pswrd,cpaswrd)!=0);
	gotoxy(3,15);
	cout<<"e-mail id:";
	gets(user);
	l=strlen(user);
	gotoxy(l+13,15);
	cout<<"@cmail.com";
	gotoxy(3,21);
	cout<<"\t\t\t   SECURITY QUESTION";
	gotoxy(3,24);
	cout<<"Ques. What is the number of members in your family?";
	gotoxy(3,27);
	cout<<"Ans.  ";
	gets(sqa);
	fflush(stdin);
	gotoxy(23,30);
	cout<<"LOADING PLEASE WAIT";
	for(int l=0;l<15;l++)
	{
		cout<<".";
		delay(100);
	}
	if(strlen(name)==0||strlen(pswrd)==0||strlen(user)==0||strlen(sqa)==0)
	{
		g=0;
		gotoxy(20,32);
		cout<<"Any of the above fields can't be empty.";
	}
	else
	{
		finacc.open("AMEY.dat",ios::in|ios::binary);
		while(finacc.read((char*)&cmail,sizeof(cmail)))
		{
			if(cmail.match_id(user)==0)
			   {
					g=0;
					gotoxy(20,32);
					cout<<"This ID has been already created.";
			   }
		}
		finacc.close();
	}
	if(g==1)
	{
		foutacc.open("AMEY.dat",ios::binary|ios::app);
		cmail.signup(name,user,sqa,pswrd);
		foutacc.write((char*)&cmail,sizeof(cmail));
		foutacc.close();
		gotoxy(20,32);
		cout<<"e-mail  ID  SUCCESSFULLY  CREATED";
		getch();
	}
	if(g==0)
	{
		gotoxy(1,40);
		cout<<"To return to main menu, press M";
		gotoxy(1,42);
		cout<<"or else press any other key to enter the data again:";
		gets(ans);
		fflush(stdin);
		if(strcmpi(ans,"m")==0)
			m1();
		else
			signup();
	}
}

void send_mail(char frm[15])
{
	clrscr();
	color(0,80,0,60,1);
	char to[15],from1[15];
	int s=1;
	for(int i=2; i<78; i++)
	{
		gotoxy(i,7);
		cout<<"-";
		gotoxy(i,10);
		cout<<"-";
		gotoxy(i,13);
		cout<<"-";
	}
	finacc.open("AMEY.dat",ios::binary);
	gotoxy(4,6);
	cout<<"To:";
	gotoxy(7,6);
	gets(to);
	gotoxy(strlen(to)+7,6);
	cout<<"@cmail.com";
	while(finacc.read((char*)&cmail,sizeof(cmail)))
	 {
		if(cmail.match_id(to)==0)
		{
			s=0;
			break;
		}
	 }
	finacc.close();
	if(s!=0)
	 {
		gotoxy(3,16);
		cout<<"ID does not exit";
		getch();
		login_in_to_id(frm);
	 }

	else
	 {
		foutinbox.open("inbox.dat",ios::binary|ios::app);
		box.to_send(to,frm);
		foutinbox.write((char*)&box,sizeof(box));
		foutinbox.close();
	 }
}

void login_in_to_id(char nm[15])
{
	int ch,q,u=5;
	while(ch!=4)
	{
		u=5;
		clrscr();
		color(0,80,0,60,6);
		int y=2,z=2,x;
		gotoxy(26,11);
		cout<<"***** Login  Menu *****";
		gotoxy(30,18);
		cout<<"1. Compose";
		gotoxy(30,21);
		cout<<"2. Inbox ";
		gotoxy(30,24);
		cout<<"3. Sent Mail";
		gotoxy(30,27);
		cout<<"4. Logout";
		gotoxy(30,30);
		cout<<"Your Choice:";
		cin>>ch;
		while(cin.fail())
		{
			gotoxy(15,38);
			cout<<"Please give a suitable input.";
			getch();
			gotoxy(15,38);
			clreol();
			cin.clear();
			cin.ignore(1,'\n');
			gotoxy(44,30);
			clreol();
			cin.clear();
			gotoxy(44,30);
			cin>>ch1;
		}//while of cin fail closes.
		while(ch!=1&&ch!=2&&ch!=3&&ch!=4)
		{
			gotoxy(15,42);
			cout<<"Please give a suitable input.\n";
			getch();
			gotoxy(15,42);
			clreol();
			cin.clear();
			cin.ignore(1,'\n');
			gotoxy(42,33);
			clreol();
			cin.clear();
			gotoxy(42,33);
			cin>>ch;
		}
		switch(ch)
		{
			case 1:send_mail(nm);
				break;
			case 2:  q=1;
				while(q!=0)
				{
				clrscr();
				color(0,80,0,50,BLUE);
				gotoxy(1,1);
				char ch1[75];
				char ch2[75];
				cout<<"\t\t************INBOX**********";
				q=displayinbox(nm,ch1);
				fininbox.open("inbox.dat",ios::binary);
				if(q==-1)
				{
				color(0,80,0,50,RED);
				gotoxy(30,25);
				cout<<"INBOX IS EMPTY";
				break;
				}
				else if(q!=0)
				{
				while(fininbox.read((char*)&box,sizeof(box)))
				   {    box.writin(ch2);
					if(strcmp(ch1,ch2)==0)
					{
					color(0,80,0,60,RED);
					clrscr();
					  box.see_inbox(1);
					getch();
					cout<<"\n\npress any key to go back";
					}
				   }
				}
				fininbox.close();

				}
				break;
			case 3:clrscr();
				color(0,80,0,60,4);
				u=5,q=0;
				fininbox.open("inbox.dat",ios::binary);
				while(fininbox.read((char*)&box,sizeof(box)))
				{
					if(box.match_to_sent_mail(nm)==0)
					{
						q++;
						if(q<=7)
						{
							gotoxy(1,u);
							box.see_sent_mail(u+2);
							u+=5;
						}
						if((q%7)==0)
						{
							u=5;
							gotoxy(40,40);
							cout<<"MORE MAILS....";
							getch();
							clrscr();
						}
						if(q>7)
						{
							gotoxy(1,u);
							box.see_sent_mail(u+2);
							u+=5;
						}
					}
				}
				if(q==0)
				cout<<"NO SENT MAILS ";
			fininbox.close();
			getch();
			break;
		case 4:break;
	}
	if(ch==4)
		break;
   }
}

void login_page()
{
	clrscr();
	char no[20];
	int i;
	color(45,74,8,35,5);
	for( i=45; i<74; i++)
	{
	gotoxy(i,7);
	   cout<<"" ;
	gotoxy(i,35);
	cout<<"";
	}
	for(i=8;i<35; i++)
	{
	gotoxy(45,i);
	cout<<"";
	gotoxy(73,i);
	cout<<"";
	}
	gotoxy(48,10);
	cout<<"SIGN IN";
	gotoxy(60,10);
	cout<<"cmail";
	gotoxy(48,15);
	cout<<"USERNAME";
	color(48,70,18,19,BLACK);
	for(i=18; i<=19;i++)
	{
		gotoxy(48,i);
		cout<<"|";
		gotoxy(70,i);
		cout<<"|";
	}
	for(i=49;i<70;i++)
	{
		gotoxy(i,17);
		cout<<"-";
		gotoxy(i,20);
		cout<<"-";
	}
	gotoxy(48,25);
	cout<<"PASSWORD";
	color(48,70,28,29,BLACK);
	for(i=28; i<=29;i++)
	{
		gotoxy(48,i);
		cout<<"|";
		gotoxy(70,i);
		cout<<"|";
	}
	for(i=49;i<70;i++)
	{
		gotoxy(i,27);
		cout<<"-";
		gotoxy(i,30);
		cout<<"-";
	}
gotoxy(15,10);
cout<<"WELCOME";
gotoxy(17,13);
cout<<"TO";
gotoxy(16,16);
cout<<"CMAIL";
gotoxy(10,22);
cout<<"****C_MAIL****";
gotoxy(7,30);
cout<<"A C  APPROACH TO E-MAIL";
}

void to_get_password()
{
	clrscr();
	char id[20],no[20];
	int x,h=1;
	gotoxy(20,5);
	cout<<"*******RECOVERY PAGE*******";
	gotoxy(15,15);
	cout<<"E-MAIL ID:";
	gets(id);
	gotoxy(strlen(id)+25,15);
	cout<<"@cmail.com";
	finacc.open("AMEY.dat",ios::binary);
	while(finacc.read((char*)&cmail,sizeof(cmail)))
	{
		  h=cmail.match_id(id);
		if(h==0)
		  {
			gotoxy(15,20);
			cout<<"What is the number of members in your family?:";
			gets(no);
			if(cmail.sqq(no)==0)
				cmail.password();
			else
			{
				gotoxy(15,25);
				cout<<"E-MAIL ID OR RECOVERY ANSWER IS INCORRECT";
				getch();
			}
			break;
		   }
	}
		if(h!=0)
		   {
			gotoxy(15,18);
			cout<<"E-MAIL ID INCORRECT";
			getch();
		   }
				finacc.close();
}
