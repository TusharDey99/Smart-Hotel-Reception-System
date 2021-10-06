#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

int n, Subtotal, rmsrvs, visit, amnt=0, cnt=0, two=0, three=0, four=0, k=0, c=0;
string res = "";

int RoomChoose(int asso, int RM1[], int RM2[], int RM3[], int RM4[], int RM5pp[])
{
	string line;
	ofstream file;
	int rmno;
	switch(asso)
	{
		case 1:
			{
				ifstream file1("ForOne.txt");

				while(getline(file1, line))
				{
					cout<<line<<endl;
				}

				file.close();
			}
		break;

		case 2:
			{
				ifstream file2("ForTwo.txt");

				while(getline(file2, line))
				{
					cout<<line<<endl;
				}

				file.close();
			}
		break;

		case 3:
			{
				ifstream file3("ForThree.txt");

				while(getline(file3, line))
				{
					cout<<line<<endl;
				}

				file.close();
			}
		break;

		case 4:
			{
				ifstream file4("ForFour.txt");

				while(getline(file4, line))
				{
					cout<<line<<endl;
				}

				file.close();
			}
		break;

		case 5:
		{
				ifstream file5("ForFive++.txt");

				while(getline(file5, line))
				{
					cout<<line<<endl;
				}

				file.close();
			}
		break;

		default:
			if(asso>=6 and asso<=11)
			{
				ifstream file5("ForFive++.txt");

				while(getline(file5, line))
				{
					cout<<line<<endl;
				}

				file.close();
			}

			else if(asso>=11)
				cout<<"Its not possible for us to provide options for more than 11 people at the same time."<<endl<<"The manager will be here soon to assist you."<<endl ;
		break;
	}

	if(asso>=1 and asso<=11)
	{
		cout<<endl<<"Enter the number of the room you desire: ";
		cin>>rmno;

		if(asso == 1)
			return RM1[rmno];
		else if(asso == 2)
			return RM2[rmno];
		else if(asso == 3)
			return RM3[rmno];
		else if(asso == 4)
			return RM4[rmno];
		else
			return RM5pp[rmno];
	}
}

int *SpecialService()
{
	static int spcl[4];
	cout<<"Below are a list of some of the special services we provide. Feel free to choose."<<endl;
	cout<<"1. Spa- 3000TK"<<endl;
	cout<<"2. Gym- 1000TK"<<endl;
	cout<<"3. Car-rental- 5000TK"<<endl;
	cout<<"4. Private Swimming Pool- 8000TK"<<endl;
	cout<<"5. Dont Need Special Service."<<endl;
	cout<<endl<<"How many special services would you choose: ";
	cin>>n;

	if(n<1 or n>4)
	{
		cout<<"Try again."<<endl;
		SpecialService();
	}

	cout<<endl<<"Enter your choices: ";
	if(n>0)
	{
		for(int i=0; i<n; i++)
		cin>>spcl[i];
	}
	else
		spcl[0] = 0;

	return spcl;
}

void BankTransfer()
{
	int Mt[4][4], scn1, vercode, vercodein;
	int bnkacno[] = {9, 7, 5, 3, 8, 1, 2, 1, 6, 7, 3, 3, 9, 1, 2, 6};
	srand(time(0));
	ofstream file;

	cout<<"This is our bank account number: 9753 81216 7339 126"<<endl;
	cout<<"Scan this Accitrix to pay automatically:"<<endl<<endl;
	int k=0;
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			Mt[i][j] = bnkacno[k];
			k++;
		}
	}

	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			cout<<Mt[i][j]<<"   ";
		}
		cout<<endl;
	}

	cout<<"Press 1 to scan the Accitrix: ";
	cin>>scn1;

	if(scn1==1)
	{
		vercode = rand() % 1000;
		file.open("Verfication Bank.txt", ios::out|ios::app);
		file<<vercode<<endl<<endl;

		cout<<"We have send verification code to your phone number. Please enter the code here: ";
		cin>>vercodein;

		if(vercodein==vercode)
		{
			cout <<"Verification Loading..";
		    Sleep(500);
		    system("cls");
		    cout <<"Verification Loading....";
		    Sleep(500);
		    system("cls");
		    cout <<"Verification Loading......";
		    Sleep(500);
		    system("cls");
		    cout <<"Verification Loading........";
			cout<<"Verification is complete."<<endl;

			cout<<"Payment is complete."<<endl<<endl;;
			cout<<"Your room number is: "<<rand()%500<<". Please use the verification code "<<vercode<<" for room unlocking."<<endl;
			c++;
		}
		else
		{
			cout<<"Something went wrong. Please try again."<<endl;
			BankTransfer();
		}
	}
	else
	{
		cout<<"Something went wrong. Please try again."<<endl;
		BankTransfer();
	}
}

int LuckyWinner()
{
	string cryptoadrs;
	cout<<"Than you have a chance to win a massive discount on the final cost."<<endl;
	cout<<"Enter the previous crypto wallet address that you paid to: ";
	cin>>cryptoadrs;

	int T[37][37];

	for(int i=0; i<=36; i++)
		T[i][0] = 0;

	for(int i=0; i<=36; i++)
		T[0][i] = 0;

	for(int i=1; i<=36; i++)
	{
		for(int j=1; j<=36; j++)
		{
			if(cryptoadrs[i-1]==res[j-1])
				T[i][j] = T[i-1][j-1] + 1;

			else
			{
				if(T[i-1][j]>=T[i][j-1])
					T[i][j] = T[i-1][j];

				else
					T[i][j] = T[i][j-1];
			}
		}
	}

	int i=36, j=36;
	while(T[i][j]!=0)
	{
		if(cryptoadrs[i-1]==res[j-1])
		{
			k++;
			i--;
			j--;
		}

		else if(T[i-1][j]>=T[i][j-1])
			i--;

		else
			j--;
	}

	cout<<k<<endl<<endl;
}

void CryptoCurrency()
{
	int wc;
	float cnvrt;
	ofstream file;
	cout<<"Choose which crypto you would like to pay with: "<<endl;
	cout<<"1. Bitcoin."<<endl;
	cout<<"2. Bitcoin Cash."<<endl;
	cout<<"3. Ethereum."<<endl;
	cout<<"4. Litecoin."<<endl;
	cout<<"Enter your choice: ";
	cin>>wc;
	cout<<endl;

	if(wc>0 and wc<=4)
	{
		int scn, vercode, vercodein;
		ofstream file;
	    char alphabet[36] = {'a', 'b', 'c', '0', 'd', 'e', 'f', '1', 'g',
	                         'h', 'i', '2', 'j', 'k', 'l', '3', 'm', 'n',
	                         'o', '4', 'p', 'q', 'r', '5', 's', 't', 'u',
	                         '6', 'v', 'w', 'x', '7', 'y', 'z', '8', '9'};

	    srand(time(NULL));
	    for (int i=0; i<36; i++)
	        res = res + alphabet[rand() % 36];

	    file.open("Crypto Address.txt", ios::out|ios::app);
	    file<<res<<endl<<endl;

	    cout<<"Have you stayed at our hotel before and paid in crypto?"<<endl<<"1. Yes."<<endl<<"2. No."<<endl;
		cout<<"Enter your choice: ";
		cin>>visit;

		if(visit==1)
		{
			LuckyWinner();
			if(k<=5)
				k = k*5;

			else
				k = k*1;

			cout<<"Congratulation!!! You have gained "<<k<<"% discount on total cost.";
			if(wc==1)
			{
				cnvrt = (float)(Subtotal-((Subtotal*k)/100)) / 3000000;
				cout<<"You will pay "<<cnvrt<<" Bitcoin(s)."<<endl;
			}
			else if(wc==2)
			{
				cnvrt = (float)(Subtotal-((Subtotal*k)/100)) / 50000;
				cout<<"You will pay "<<cnvrt<<" Bitcoin Cash(s)."<<endl;
			}
			else if(wc==3)
			{
				cnvrt = (float)(Subtotal-((Subtotal*k)/100)) / 190000;
				cout<<"You will pay "<<cnvrt<<" Ethereum(s)."<<endl;
			}
			else
			{
				cnvrt = (float)(Subtotal-((Subtotal*k)/100)) / 13000;
				cout<<"You will pay "<<cnvrt<<" Litecoin(s)."<<endl;
			}
		}

		else
		{
			if(wc==1)
			{
				cnvrt = (float)Subtotal / 3000000;
				cout<<"You will pay "<<cnvrt<<" Bitcoin(s)."<<endl;
			}
			else if(wc==2)
			{
				cnvrt = (float)Subtotal / 50000;
				cout<<"You will pay "<<cnvrt<<" Bitcoin Cash(s)."<<endl;
			}
			else if(wc==3)
			{
				cnvrt = (float)Subtotal / 190000;
				cout<<"You will pay "<<cnvrt<<" Ethereum(s)."<<endl;
			}
			else
			{
				cnvrt = (float)Subtotal / 13000;
				cout<<"You will pay "<<cnvrt<<" Litecoin(s)."<<endl;
			}
		}

	    cout<<"This is our cryptocurrency wallet address number: ";
	    cout<<res<<endl;

	    char M[6][6];
		int k=0;
	    for(int i=0; i<6; i++)
	    {
	    	for(int j=0; j<6; j++)
	    	{
	    		M[i][j] = res[k];
	    		k++;
			}
		}

		cout<<endl<<"Scan this Addressix to go payment directly: "<<endl;

		for(int i=0; i<6; i++)
	    {
	    	for(int j=0; j<6; j++)
	    	{
	    		cout<<M[i][j]<<"  ";
			}
			cout<<endl;
		}

		cout<<"Press 1 to scan the Addressix: ";
		cin>>scn;

		if(scn==1)
		{
			ofstream file;
			vercode = rand() % 1000;
			file.open("Verfication Crypto.txt", ios::out|ios::app);
			file<<vercode<<endl<<endl;

			cout<<"We have send verification code to your phone number. Please enter the code here: ";
			cin>>vercodein;

			if(vercodein==vercode)
			{
				cout <<"Verification Loading..";
			    Sleep(500);
			    system("cls");
			    cout <<"Verification Loading....";
			    Sleep(500);
			    system("cls");
			    cout <<"Verification Loading......";
			    Sleep(500);
			    system("cls");

			    cout <<"Verification Loading........";
				cout<<"Verification is complete."<<endl;

				cout<<"Payment is complete."<<endl<<endl;;
				cout<<"Your room number is: "<<rand()%500<<". Please use the verification code "<<vercode<<" for room unlocking."<<endl;
				c++;
			}
			else
			{
				cout<<"Something went wrong. Please try again."<<endl;
				CryptoCurrency();
			}
		}
		else
		{
			cout<<"Something went wrong. Please try again."<<endl;
			CryptoCurrency();
		}
	}
	else
	{
		cout<<"Try Again."<<endl;
		CryptoCurrency();
	}
}

void Payment()
{
	int pm;
	cout<<"How would you like to pay?"<<endl;
	cout<<"1. Bank Transfer."<<endl;
	cout<<"2. Pay via Cryptocurrency."<<endl;
	cout<<"Enter your choice: ";
	cin>>pm;
	cout<<endl;
	switch(pm)
	{
		case 1:
			{
				BankTransfer();
			}
		break;

		case 2:
		{
			CryptoCurrency();
		}
		break;

		default:
		{
			cout<<"Wrong Input. Try again."<<endl;
			Payment();
		}
		break;
	}
}

int main()
{
	string name;
	int asso, stay, rmno, pm, phn, prkchoc;
	long long int nidpass;
	ofstream file;

	int RM1[5] = {0, 2990, 2090, 3999, 5999};
	int RM2[5] = {0, 3499, 4899, 5000, 5999};
	int RM3[6] = {0, 6000, 5000, 4000, 8000, 10000};
	int RM4[6] = {0, 6000, 4970, 3999, 8990, 9999};
	int RM5pp[3] = {0, 25000, 65000};
	int spclcst[] = {0, 3000, 1000, 5000, 8000, 0};

	file.open("Customer Information.txt", ios::out|ios::app);

	if(c<=500)
	{
		cout<<"Welcome to Riden Gaurd Hotels. Please Enter Your Information Below."<<endl;

		cout<<"Enter your name: ";
		getline(cin, name);
		file<<name<<endl;

		cout<<"Enter your phone number: ";
		cin>>phn;
		file<<phn<<endl;

		cout<<"Enter your NID/Passport NO: ";
		cin>>nidpass;
		file<<nidpass<<endl;

		cout<<"Enter the number of people(including you within 11 people): ";
		cin>>asso;
		file<<asso<<endl;

		int j=0;
		while(j<1 and asso<=11)
		{
			cout<<"Enter total time of your stay(daywise): ";
			cin>>stay;
			file<<stay<<endl<<endl;

			cout<<endl;
			cout<<"Food costs are included within the room price. But having room service will cost you extra 1999TK."<<endl<<"Note that room service is only available for breakfast and snacks. Do you want room service?"<<endl;
			cout<<"1.Yes."<<endl<<"2. No."<<endl;
			cout<<"Enter your choice: ";
			cin>>rmsrvs;

			cin.ignore();
			cout<<endl;

			system("cls");

			int rmcst = RoomChoose(asso, RM1, RM2, RM3, RM4, RM5pp);
			cout<<endl;

			system("cls");

			int *spclret = SpecialService();
			cout<<endl;

			system("cls");

			int total2 = 0;
			for(int i=0; i<n; i++)
				total2 = total2 + spclcst[spclret[i]];

			Subtotal = stay*(rmcst+total2);
				rmsrvs==1 ? Subtotal = Subtotal + 1999*stay : Subtotal;
				prkchoc==1 ? Subtotal = Subtotal + amnt*stay : Subtotal;

			cout<<"Final Overview"<<endl;
			cout<<"Number of people: "<<asso<<endl;
			cout<<"Duration of stay: "<<stay<<endl;
			cout<<"Room Service Taken?: ";
				rmsrvs==1?cout<<"Yes.":cout<<"No.";
			cout<<endl<<"Cost of room(for "<<asso<<"): "<<rmcst<<endl;
			cout<<"Special Services Taken: "<<n<<endl;
			cout<<endl<<"Your total cost is: "<<Subtotal<<endl;
			cout<<endl;

			Payment();
			j++;
		}

		if(asso>11)
			cout<<"More than 11 people at the same time are not suitable to fit in in this hotel. The manager will be here soon to discuss your accomodation. Thank You.";
	}

	return 0;
}
