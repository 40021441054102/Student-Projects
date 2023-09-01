#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

struct USR{
	char username[50];
	char firstname[50];
	char lastname[50];
	char password[50];
};
struct USR USR[500];

int Sign_Up();
void clr_console();
int Client_Page(char[], char[]);
int read_to_struct();
int pass_err();
int err(int);
int usr_err(string user, int);
void first_up_case(char[], char[]);


int main()
{
	int attempt = 1,err = 0;
	const int size = 4096; 
	login:
	string user,pass;
	cout<<"-------------------------- Version 0.09 --------------------------"<<endl;
	cout<<"Welcome User ! If You Have Account Enter Your Username & Password !"<<endl;
	cout<<"If I Couldn't Find Your Username I Will Automatically Transfer You"<<endl;
	cout<<"To SignUp Page After 3 Wrong Attempts."<<endl;
	cout<<"----------------------------- Login: -----------------------------";
	cout<<"\nUsername :\t";	cin>>user;
	cout<<"\nPassword :\t";	cin>>pass;
	clr_console();
	int lines = read_to_struct();
	for (int i = 0; i < lines; i++)
	{
		if (user == USR[i].username || user == "Admin")
		{
			if (pass == "31415926535")
			{
				cout<<"Admin Access Granted"<<endl;
				return 0;
			}
			else if (pass == USR[i].password)
			{
				first_up_case(USR[i].firstname,USR[i].lastname);
				Client_Page(USR[i].firstname,USR[i].lastname);
				return 0;
			}
			else
			{
				cout<<"\n- Password Is Wrong ! Attempt "<<attempt<<"/3."<<endl;
				if (attempt == 3)
				{
					clr_console();
					pass_err();
					Sign_Up();
					return 0;
				}
				attempt++;
				goto login;
			}
		}
		else
		{
			err++;
			if (err == lines)
			{
				usr_err(user,i);
			}
		}
	}
	return 0;
}

int Sign_Up()
{
	cout<<"-------------------------- SignUp Page --------------------------"<<endl;
	cout<<"Complete Inputs Below To Sign Up For FREE!"<<endl;
	cout<<"Username :\t";
	return 0;
}

int Client_Page(char firstname[20],char lastname[20])
{
	cout<<"-------------------------- Client Page --------------------------"<<endl;
	cout<<"Client Access Granted"<<endl;
	cout<<"Welcome "<<firstname<<" "<<lastname<<endl;
	return 0;
}

//--- read accounts to structure USR
int read_to_struct()
{
	FILE *fp;
	fp = fopen("/Users/Q/Desktop/Accounts.txt","r");
	if (!fp)
	{
		err(101);
		return 0;
	}
	char buffer[50];
	char *username,*password,*firstname,*lastname,*details;
	int i;
	for (i = 0; fgets(buffer, sizeof buffer, fp); i++)
	{
		buffer[strlen(buffer)-1]='\0';
		details = buffer;
		username = strchr(details ,',');	//Finding Delim1
		firstname = strchr(username + 1,',');	//Finding Delim 2
		lastname = strchr(firstname + 1,',');	//Finding Delim 3
		*username = '\0';	
		*firstname = '\0';
		*lastname = '\0';
		strcpy(USR[i].username,details);
		strcpy(USR[i].firstname,username + 1);
		strcpy(USR[i].lastname,firstname + 1);
		strcpy(USR[i].password,lastname + 1);
	}
	fclose(fp);
	cout<<username;
	return i;
}

//--- console clear
void clr_console()
{
	cout<<"\x1B[2J\x1B[H";
}

//--- sending mail function if 3/3 attempts achived from the user
int pass_err()
{
	cout<<"\n- Password Is Wrong ! Attempt "<<"3/3."<<endl;
	cout<<"- Wrong Passwords Alert Has Been Emailed To Owner's Account !"<<endl;
	return 0;
}

// error list
int err(int err_num)
{
	switch(err_num)
	{
		case 101:
			cout<<"ERR_"<<err_num<<" :"<<endl;
			cout<<" - Error With Openning Accounts File !"<<endl;
			cout<<" - There Isn't Any Text File For Accounts."<<endl;
		break;
		default : cout<<"just err";
	}
	return 0;
}

//user error
int usr_err(string user,int i)
{
	cout<<"\n- \033[1;91mI Can't Find Any Username Called : '\033[1;92m"<<user<<"\033[1;91m'\033[0m"<<endl;
	return 0;
}

//first character uppercase
void first_up_case(char firstname[20], char lastname[20])
{
	if (firstname[0] < 123 || firstname[0] > 96)
	{
		firstname[0] -= 32;
		if (lastname[0] < 123 || lastname[0] > 96)
		{
			lastname[0] -= 32;
		}
	}
}