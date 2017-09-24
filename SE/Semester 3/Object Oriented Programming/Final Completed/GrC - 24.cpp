/*

Group C
Assignment 24

Write C++ program using STL for sorting and searching with user defined records such as Person Record (Name, Birth Date, Telephone Number), item record (item code, item name, quantity and cost).

By Shiva Saran
SE-A A-03


*/

#include<iostream>
#include<list>
using namespace std;

class Records
{
	list<string>name,dob,phone,ni;
	list<string>::iterator it1,it2,it3,j,k,l,c,n;
	list<string>code;
	list<int>number;
	list<float>cost;
    list<int>::iterator no,j1;
    list<float>::iterator f,i;
public:
	void getdata()
	{
		int count;
	string n,d,p;
	cout<<"Enter the number of members in record:"<<endl;
	cin>>count;
	cin.ignore();
	for(int i=1;i<=count;i++)	
	{
		cout<<"Enter name:"<<endl;
		getline(cin, n);;
		name.push_back(n);
		cout<<"Enter date of birth:"<<endl;
		getline(cin, d);
		dob.push_back(d);
		cout<<"Enter phone number:"<<endl;
		getline(cin, p);
		phone.push_back(p);
	}
	}

	void display()
	{
			it1=name.begin();
	it2=dob.begin();
	it3=phone.begin();
	while(it1!=name.end())
	{
		cout<<*it1<<"\t"<<*it2<<"\t"<<*it3<<endl;
		it1++;
		it2++;
		it3++;
	}
}

	void searchp(string data)
	{
		int flag=0;
	it1=name.begin();
	it2=dob.begin();
	it3=phone.begin();
	while(it1!=name.end()&&it2!=dob.end()&&it3!=phone.end())
	{
		if(*it1==data)
		{
			cout<<"Record found!"<<endl;
			cout<<"Corresponding Date of Birth "<<*it2<<endl;
			cout<<"Corresponding Phone Number: "<<*it3<<endl;
			flag=1;
			break;
		}
		if(*it2==data)
		{
			cout<<"Record found!"<<endl;
			cout<<"Corresponding name "<<*it1<<endl;
			cout<<"Corresponding phone number: "<<*it3<<endl;
			flag=1;
			break;
		}
		if(*it3==data)
		{
			cout<<"Record found!"<<endl;
			cout<<"Corresponding name: "<<*it1<<endl;
			cout<<"Corresponding Date of Birth "<<*it2<<endl;
			flag=1;
			break;
		}
		it1++;
		it2++;
		it3++;
	}
	if(flag==0)
		cout<<"Record not found."<<endl;
}

	void sortp()
	{
		string temp;
    it1=name.begin();
	it2=dob.begin();
	it3=phone.begin();
	j=it1;
	k=it2;
	l=it3;
	j++;
	k++;
	l++;
	while(it1!=name.end())
    {
        while(j!=name.end())
        {
            if(*it1>*j)
            {
                temp=*it1;
                *it1=*j;
                *j=temp;
                temp=*it2;
                *it2=*k;
                *k=temp;
                temp=*it3;
                *it3=*l;
                *l=temp;
            }
            j++;
            k++;
            l++;
        }
        it1++;
        it2++;
        it3++;
    }
}

	void getlist()
	{
		
    cout<<"Enter the number of items:"<<endl;
    int c,no;
    string n;
    float f;
    cin>>c;
    for(int i=1;i<=c;i++)
    {
        cout<<"Enter item name:"<<endl;
        getline(cin, n);
        ni.push_back(n);
        cout<<"Enter item code:"<<endl;
        getline(cin, n);
        code.push_back(n);
        cout<<"Enter cost:"<<endl;
        cin>>f;
        cost.push_back(f);
        cout<<"Enter the quantity:"<<endl;
        cin>>no;
        number.push_back(no);
    }
}

	void displayit()
	{
		 c=code.begin();
    n=ni.begin();
    no=number.begin();
    f=cost.begin();
    while(c!=code.end())
    {
        cout<<*c<<"\t"<<*n<<"\t"<<*no<<"\t"<<*f<<endl;
        c++;
        n++;
        no++;
        f++;
    }
}
	
	void searchlist()
	{
		string key;
	cout<<"Enter the item code:"<<endl;
	getline(cin, key);
	c=code.begin();
	n=ni.begin();
	no=number.begin();
	f=cost.begin();
	while(c!=code.end())
	{
		if(key==*c)
		{
			cout<<"Item available!"<<endl;
			cout<<"Item name: "<<*n<<endl;
			cout<<"Item quantity: "<<*no<<endl;
			cout<<"Item cost: "<<*f<<endl;
		}
		c++;
		n++;
		no++;
		f++;
	}
}

	void sortitem()
	{
		string temp;
    int tempno;
    float tempf;
    c=code.begin();
    n=ni.begin();
    no=number.begin();
    f=cost.begin();
    i=f;
    j1=no;
    k=c;
    l=n;
    i++;
    j1++;
    k++;
    l++;
    while(f!=cost.end())
    {
        while(i!=cost.end())
        {
            if(*f>*i)
            {
               tempf=*f;
               *f=*i;
               *i=tempf;

               temp=*n;
               *n=*l;
               *l=temp;

               temp=*c;
               *c=*k;
               *k=temp;

               tempno=*no;
               *no=*j1;
               *j1=tempno;
            }
            i++;
            j1++;
            k++;
            l++;
        }
        f++;
        n++;
        no++;
        c++;
    }
}

void getp()
{
	int count;
	string n,d,p;
	cout<<"Enter the number of members in record:"<<endl;
	cin>>count;
	for(int i=1;i<=count;i++)
	{
		cout<<"Enter name:"<<endl;
		getline(cin, n);
		name.push_back(n);
		cout<<"Enter date of birth:"<<endl;
		getline(cin, d);
		dob.push_back(d);
		cout<<"Enter phone number:"<<endl;
		getline(cin, p);
		phone.push_back(p);
	}
}
};


int main()
{
	Records obj;
	string key;
	int ch,chr;
	char x='y';
	do
	{
	cout<<"*********************User Defined Records*********************\n1. Personal record\n2. Item record\nChoice - ";
	cin>>ch;
	cin.ignore();
	do
	{
	if(ch==1)
	{
		cout<<"-----------------------------\n1. Enter details\n2. Display\n3. Search entry\n4. Sort records\nChoice - ";
		cin>>chr;
		cin.ignore();
		switch(chr)
		{
		case 1:
			obj.getp();
			obj.display();
			break;
		case 2:
			obj.display();
			break;
		case 3:
			cout<<"Enter either Name, Date of Birth or Phone Number you want to find - ";
			cin>>key;
			obj.searchp(key);
			break;
		case 4:
			obj.sortp();
			obj.display();
			break;
		default:
			cout<<"Wrong choice....!!!"<<endl;
		}
	}
	else if(ch==2)
	{
		cout<<"-----------------------------\n1. Enter details\n2. Display\n3. Search entry\n4. Sort records\nChoice - ";
		cin>>chr;
		cin.ignore();
		switch(chr)
		{
		case 1:
			obj.getlist();
			obj.displayit();
			break;
		case 2:
			obj.displayit();
			break;
		case 3:
			obj.searchlist();
			break;
		case 4:
			obj.sortitem();
			obj.displayit();
			break;
		default:
			cout<<"Wrong choice....!!!"<<endl;
		}
	}
	else
	{
		cout<<"Wrong choice....!!!"<<endl;
		break;
	}
	cout<<"Do you wanna to continue? Y or N\nOption - ";
	cin>>x;
	}while(x=='y'||x=='Y');
	cout<<"Do you wanna select another type of record? Y or N\nOption - ";
	cin>>x;
	}while(x=='y'||x=='Y');
	return 0;
}


