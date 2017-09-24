/*Create employee bio-data using following classes 
1) Personal record 
2)Professional record 
3)Academic record. 
Assume appropriate data members and member function to accept required
data & print bio-data. Create bio-data using multiple inheritance using C++.
*/

#include<iostream>
#include<cstdlib>
#include<stdio.h>
using namespace std;


class PerRec
{
	protected:	
	char name[50], gen[5], DOB[15],BlGr[5], ConAdd[150], mailID[50] ;
	long mobile;
 
	public:
	void getPerRec()
	{
		cout<<"\n\nHello User...\nPlease enter your Personal details - \nName - ";
		gets(name);
		cout<<"Gender - ";
		gets(gen);
		cout<<"Date of Birth - ";
		gets(DOB);
		cout<<"Blood Group - ";
		gets(BlGr);
		cout<<"Contact Address - ";
		gets(ConAdd);
		cout<<"Mobile Number - ";
		cin>>mobile;
		cin.ignore();
		cout<<"Mail ID - ";
		gets(mailID);
	}
};

class ProfessRec
{
	protected:	
	char ComNm[50], desgination[30], project[150], internship[70] ;
	int exp;
	 
	public:	
	void getProfessRec()
	{
		cout<<"\nPlease enter your Professional Record details - \nCompany Name - ";
		gets(ComNm);
		cout<<"Desgination - ";
		gets(desgination);
		cout<<"Experience - ";
		cin>>exp;
		cin.ignore();
		cout<<"Project - ";
		gets(project);
		cout<<"Internship - ";
		gets(internship);
	}
};

class AcedRec
{
	protected:	
	char qual[50], col[60], sch[60], univer[50], excor[50] ;
 
	public:	
	void getAcadRec()
	{
		cout<<"\nPlease enter your Academic details - \nQualifications - ";
		gets(qual);
		cout<<"University - ";
		gets(univer);
		cout<<"Junior college & Board - ";
		gets(col);
		cout<<"School & Board - ";
		gets(sch);
		cout<<"Extra Curricular  - ";
		gets(excor);
	}
};


class BioData: public PerRec, public ProfessRec, public AcedRec
{
	public:
	void displayPer()
	{
		cout<<"\nPersonal Details:\nName - ";
		puts(name);
		cout<<"Gender - ";
		puts(gen);
		cout<<"Date of Birth - ";
		puts(DOB);
		cout<<"Blood Group - ";
		puts(BlGr);
		cout<<"Contact Address - ";
		puts(ConAdd);
		cout<<"Mobile Number - ";
		cout<<mobile<<endl;
		cout<<"Mail ID - ";
		puts(mailID);
	}

	void displayPro()
	{
		cout<<"\n\nProfessional Record details - \nCompany Name - ";
		puts(ComNm);
		cout<<"Desgination - ";
		puts(desgination);
		cout<<"Experience - ";
		cout<<exp<<endl;
		cout<<"Project - ";
		puts(project);
		cout<<"Internship - ";
		puts(internship);
	}
	
	void displayAcad()
	{
		cout<<"\n\n\nAcademic details - \nQualifications - ";
		puts(qual);
		cout<<"University - ";
		puts(univer);
		cout<<"Junior college & Board - ";
		puts(col);
		cout<<"School & Board - ";
		puts(sch);
		cout<<"Extra Curricular  - ";
		puts(excor);
	}

};


int main()
{
	int ch = 0, j = 0;	
	BioData obd;
	
	while(ch!=4)
	{	cout<<"\n\nWhich details would you like to enter - \n1. Personal Details\n2. Professional Details\n3. Academic Details\n4. Display & exit	\nChoice - ";
		cin>>ch;
		cin.ignore();
		
		switch(ch)
		{
			case 1: obd.getPerRec(); break;
			case 2: obd.getProfessRec(); break;
			case 3: obd.getAcadRec(); break;
			case 4: cout<<"\nBiodata entry complete....\nDisplaying Biodata details - \n\nBiodata\n";
				obd.displayPer();
				obd.displayPro(); 
				obd.displayAcad(); 
				cout<<"\nProgram Terminated....\n";break;
			default: cout<<"Wrong option...\nTry again...\n\n";
		}
		
		
	}
	
	return 0;
}
	
