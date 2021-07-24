#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<ctime>
using namespace std;

/*------------------------- class doctor ------------------------*/

class doctor
{
	string buffer,dname,daddress,did,age;
	string didlist[100];
    int count,addlist[100];
 	public:
 
 		void createindex();
 		string extractdid(string);
 		void sortindex();
 		void insert();
 		void display_doctor();
 		void print();
 		void search(string); 
 		int searchindex(string);
 		void remove(string);
} d;


/*------------------------- class patient ------------------------*/


class patients
{
    public:
           string pid,paddress,page,pname,pproblem;
           string pidlist[100];
           int count,addlist[100];
           void createindex();
           void remove(string);
           void insert();
           int searchindex(string);
           void search(string);
           void sortindex();
           void display_p_record();
           void print();
           string extractpid(string);
}pa;

class Nurse
{
    public:
        string nid,nage,naddr,nname;
        string nidlist[100];
        int count,addlist[100];
        void createindex();
        void insert();
        void display_n_record();
        void print();
        void remove(string);
        int searchindex(string);
        void search(string);
        void sortindex();
        string extractnid(string);
}n;
class Receptionist
{
    public:
        string rid,rage,raddr,rname;
        string ridlist[100];
        int count,addlist[100];
        void createindex();
        void insert();
        void display_r_record();
        void print();
        void remove(string);
        int searchindex(string);
        void search(string);
        void sortindex();
        string extractid(string);
}r;

class Wards
{
    public:
        string wno,wname,totalb;
        string wnolist[100];
        int count,addlist[100];
        void createindex();
        void insert();
        void display_w_record();
        void print();
        void remove(string);
        int searchindex(string);
        void search(string);
        void sortindex();
        string extractid(string);
}w;



/* ---------------doctor functions starts from here----------------- */

void doctor::createindex() {
    fstream file;
	int pos;
	string buffer,did;
     	count=-1;
     	file.open("doctor.txt",ios::in);
     	while(!file.eof())
	{
           pos=file.tellg();
           buffer.erase();
           getline(file,buffer);
           if(buffer[0]!='*')
           {
                      if(buffer.empty())
                      break;
                      did=extractdid(buffer);
                      didlist[++count]=did;
                      addlist[count]=pos;
           }
     }
     file.close();
     sortindex();
     buffer.erase();
 }
 
 void doctor::insert()
 {
     string buffer,dname,daddress,did,age;
     int pos;
     fstream fp;

	 cout << "\nID\n";
     cin >> did;
     cout << "\nEnter Name\n";
     cin >> dname;
     cout << "\nAge\n";
     cin >> age;
     cout << "\nAddress\n";
     cin >> daddress;

     buffer=did+"|"+dname+"|"+age+"|"+daddress+" $\n";
     fp.open("doctor.txt",ios::out|ios::app);   
     pos=fp.tellp();
     fp<<buffer;
     fp.close();
     didlist[++count]=did;
     addlist[count]=pos;
     sortindex();
     cout<<"\nDoctor added Successfully....\n";
 }
 
 string doctor::extractdid(string buffer)
 {
     string did;
     int i=0;
     did.erase();
     while(buffer[i]!='|')
     did+=buffer[i++];
     return did;
 }
 
 void doctor::sortindex()
 {
     int i,j,tempadd;
     string tempid;
     for(i=0;i<=count;i++)
     {
           for(j=i+1;j<=count;j++)
           {
               if(didlist[i]>didlist[j])

                {
                      tempid=didlist[i];
			          didlist[i]=didlist[j];
                      didlist[j]=tempid;
                      tempadd=addlist[i];

                      addlist[i]=addlist[j];
                      addlist[j]=tempadd;
                }
           }
     }
     /*
     cout<<"\n-------INDEXLIST--------\n";
     cout<<"\n ID\tINDEX";
     for(i=0;i<=count;i++)
     cout<<"\n"<<adminlist[i]<<"\t"<<addlist[i]<<endl;
    */
 }
 
 void doctor::search(string key)
 {
     int pos=0,t;
     string buffer;
     fstream file;
     buffer.erase();
     pos=searchindex(key);
     if(pos==-1)
     	cout<<"Record not found\n";
     else if(pos>=0)
     {
           file.open("doctor.txt");
           t=addlist[pos];
           file.seekp(t,ios::beg);
           getline(file,buffer);
           cout<<"Record found\n";
           cout<<"\nRecord:"<<buffer;
           file.close(); 
     }
 }
 
 int doctor::searchindex(string key)
 {
     int low=0,high=count,mid=0,flag=0;
     while(low<=high)
     {
           mid=(low+high)/2;
           if(didlist[mid]==key)
           {
                flag=1;
                break;
           }
           else if(didlist[mid]<key)
                low=mid+1;
           else if(didlist[mid]>key)
                high=mid-1;
     }
     if(flag)
           return mid;
     else
           return -1;
 }
 
 void doctor::remove(string key)
 {
  	fstream fp;
 	char delch='*';
	int pos=0,i,address;
	string buffer,did,dname,age,daddress;
	fstream file;
  	pos=searchindex(key);
  	if(pos>=0)
  	{
       file.open("doctor.txt");
       address=addlist[pos];
       file.seekp(address,ios::beg);
       file.put(delch);
       file.close();
       cout<<"Record has been deleted\n";
       for(i=pos;i<count;i++)
       {
       didlist[i]=didlist[i+1];
       addlist[i]=addlist[i+1];
       } 
      count--;
  }  else
       cout<<"Record not found\n";
  cout<<"\nUpdated file is\n";
  system("cat doctor.txt");
 }
  void doctor::display_doctor(){
     cout<<"The Doctor details are";
     system("cat doctor.txt");
 }
 void doctor::print()
 {
	cout<<"Doctor Id:"<<did<<" Doctor Name:"<<dname<<" Address:"<<daddress<<"Age :"<<age<<endl;
 }


/*  ------------- Nurse starts from here -----------*/

void Nurse::createindex() {
    fstream file;
	int pos;
	string buffer,nid;
    count=-1;
    file.open("nurse.txt",ios::in);
    while(!file.eof())
	{
       pos=file.tellg();
       buffer.erase();
       getline(file,buffer);
       if(buffer[0]!='*')
       {
          if(buffer.empty())
             break;
          nid=extractnid(buffer);
          nidlist[++count]=nid;
          addlist[count]=pos;
       }
    }
    file.close();
    sortindex();
    buffer.erase();
 }
 
 void Nurse::insert()
 {
    string buffer,nname,naddr,nid,nge;
    int pos;
    fstream fp;

	cout << "\nID\n";
    cin >> nid;
    cout << "\nEnter Name\n";
    cin >> nname;
    cout << "\nAge\n";
    cin >> nage;
    cout << "\nAddress\n";
    cin >> naddr;

    buffer=nid+"|"+nname+"|"+nage+"|"+naddr+" $\n";
    fp.open("nurse.txt",ios::out|ios::app);   
    pos=fp.tellp();
    fp<<buffer;
    fp.close();
    nidlist[++count]=nid;
    addlist[count]=pos;
    sortindex();
    cout<<"\nNurse added Successfully....\n";
 }
 
 string Nurse::extractnid(string buffer)
 {
     string nid;
     int i=0;
     nid.erase();
     while(buffer[i]!='|')
     nid+=buffer[i++];
     return nid;
 }
 void Nurse::sortindex()
 {
     int i,j,tempadd;
     string tempid;
     for(i=0;i<=count;i++)
     {
           for(j=i+1;j<=count;j++)
           {
               if(nidlist[i]>nidlist[j])

                {
                      tempid=nidlist[i];
			          nidlist[i]=nidlist[j];
                      nidlist[j]=tempid;
                      tempadd=addlist[i];

                      addlist[i]=addlist[j];
                      addlist[j]=tempadd;
                }
           }
     }
     /*
     cout<<"\n-------INDEXLIST--------\n";
     cout<<"\n ID\tINDEX";
     for(i=0;i<=count;i++)
     cout<<"\n"<<adminlist[i]<<"\t"<<addlist[i]<<endl;
	*/
 }
 
 void Nurse::search(string key)
 {
     int pos=0,t;
     string buffer;
     fstream file;
     buffer.erase();
     pos=searchindex(key);
     if(pos==-1)
         cout<<"Record not found\n";
     else if(pos>=0)
     {
           file.open("nurse.txt");
           t=addlist[pos];
           file.seekp(t,ios::beg);
           getline(file,buffer);
           cout<<"Record found\n";
           cout<<"\nRecord:"<<buffer;
           file.close(); 
     }
 }
 
 int Nurse::searchindex(string key)
 {
     int low=0,high=count,mid=0,flag=0;
     while(low<=high)
     {
           mid=(low+high)/2;
           if(nidlist[mid]==key)
           {
                flag=1;
                break;
           }
           else if(nidlist[mid]<key)
                low=mid+1;
           else if(nidlist[mid]>key)
                high=mid-1;
     }
     if(flag)
           return mid;
     else
           return -1;
 }
 
 void Nurse::remove(string key)
 {
  	fstream fp;
 	char delch='*';
	int pos=0,i,address;
	string buffer,nid,nname,nage,naddr;
	fstream file;
  	pos=searchindex(key);
  	if(pos>=0)
  	{
       file.open("nurse.txt");
       address=addlist[pos];
       file.seekp(address,ios::beg);
       file.put(delch);
       file.close();
       cout<<"Record has been deleted\n";
       for(i=pos;i<count;i++)
       {
       nidlist[i]=nidlist[i+1];
       addlist[i]=addlist[i+1];
       } 
      count--;
  }  else
       cout<<"Record not found\n";
  cout<<"\nUpdated file is\n";
  system("cat nurse.txt");
 }
  void Nurse::display_n_record(){
     cout<<"The Nurse details are";
     system("cat nurse.txt");
 }
 void Nurse::print()
 {
	cout<<"Nurse Id:"<<nid<<" Nurse Name:"<<nname<<" Age: "<<nage<<" Address :naddr"<<endl;
 }


/* ----------------Receptinoist starts here------------*/

void Receptionist::createindex() 
{
    fstream file;
	int pos;
	string buffer,rid;
    count=-1;
    file.open("recep.txt",ios::in);
    while(!file.eof())
	{
           pos=file.tellg();
           buffer.erase();
           getline(file,buffer);
           if(buffer[0]!='*')
           {
              if(buffer.empty())
                break;
              rid=extractid(buffer);
              ridlist[++count]=rid;
              addlist[count]=pos;
           }
     }
     file.close();
     sortindex();
     buffer.erase();

 }
 void Receptionist::insert()
 {
    string buffer,rname,raddr,rid,rage;
    int pos;
    fstream fp;
    cout << "\nID\n";
    cin >> rid;
    cout << "\nEnter Name\n";
    cin >> rname;
    cout << "\nAge\n";
    cin >> rage;
    cout << "\nAddress\n";
    cin >> raddr;

    buffer=rid+"|"+rname+"|"+rage+"|"+raddr+" $\n";
    fp.open("recep.txt",ios::out|ios::app);
    
    pos=fp.tellp();
    fp<<buffer;
    fp.close();
    ridlist[++count]=rid;
    addlist[count]=pos;
    sortindex();
    cout<<"\nReceptionist added Successfully....\n";
 }
 
 string Receptionist::extractid(string buffer)
 {
     string rid;
     int i=0;
     rid.erase();
     while(buffer[i]!='|')
     rid+=buffer[i++];
     return rid;
 }
 void Receptionist::sortindex()
 {
     int i,j,tempadd;
     string tempid;
     for(i=0;i<=count;i++)
     {
           for(j=i+1;j<=count;j++)
           {
               if(ridlist[i]>ridlist[j])

                {
                      tempid=ridlist[i];
			          ridlist[i]=ridlist[j];
                      ridlist[j]=tempid;
                      tempadd=addlist[i];

                      addlist[i]=addlist[j];
                      addlist[j]=tempadd;
                }
           }
     }
     /*
     cout<<"\n-------INDEXLIST--------\n";
     cout<<"\n ID\tINDEX";
     for(i=0;i<=count;i++)
     cout<<"\n"<<adminlist[i]<<"\t"<<addlist[i]<<endl;
	*/
 }
 
 void Receptionist::search(string key)
 {
     int pos=0,t;
     string buffer;
     fstream file;
     buffer.erase();
     pos=searchindex(key);
     if(pos==-1)
           cout<<"Record not found\n";
     else if(pos>=0)
     {
           file.open("recep.txt");
           t=addlist[pos];
           file.seekp(t,ios::beg);
           getline(file,buffer);
           cout<<"Record found\n";
           cout<<"\nRecord:"<<buffer;
           file.close(); 
    }
 }
 
 int Receptionist::searchindex(string key)
 {
     int low=0,high=count,mid=0,flag=0;
     while(low<=high)
     {
           mid=(low+high)/2;
           if(ridlist[mid]==key)
           {
                flag=1;
                break;
           }
           else if(ridlist[mid]<key)
                low=mid+1;
           else if(ridlist[mid]>key)
                high=mid-1;
     }
     if(flag)
           return mid;
     else
           return -1;
 }
 
 void Receptionist::remove(string key)
 {
  	fstream fp;
 	char delch='*';
	int pos=0,i,address;
	string buffer,rid,rname,rage,raddr;
	fstream file;
  	pos=searchindex(key);
  	if(pos>=0)
  	{
       file.open("recep.txt");
       address=addlist[pos];
       file.seekp(address,ios::beg);
       file.put(delch);
       file.close();
       cout<<"Record has been deleted\n";
       for(i=pos;i<count;i++)
       {
       ridlist[i]=ridlist[i+1];
       addlist[i]=addlist[i+1];
       } 
      count--;
  	}  
  	else
       cout<<"Record not found\n";
  	cout<<"\nUpdated file is\n";
  	system("cat recep.txt");
 }
 void Receptionist::display_r_record()
 {
     cout<<"The Receptionist details are";
     system("cat recep.txt");
 }
 void Receptionist::print()
 {
	cout<<"Receptionist ID:"<<rid<<" Receptionist Name:"<<rname<<" Age:"<<rage<<" Address:raddr"<<endl;
 }


/* -------------- ward starts from here --------------*/

void Wards::createindex() {
    fstream file;
	int pos;
	string buffer,wno;
    count=-1;
    file.open("ward.txt",ios::in);
    while(!file.eof())
	{
           pos=file.tellg();
           buffer.erase();
           getline(file,buffer);
           if(buffer[0]!='*')
           {
              if(buffer.empty())
                 break;
              wno=extractid(buffer);
              wnolist[++count]=wno;
              addlist[count]=pos;
           }
     }
     file.close();
     sortindex();
     buffer.erase();
 }
 
 void Wards::insert()
 {
    string buffer,wname,wno,totalb;
    int pos;
    fstream fp;
        
    cout << "\nWard number\n";
    cin >> wno;
    cout << "\nEnter Ward Name\n";
    cin >> wname;
    cout << "\nEnter Total number of Beds present\n";
    cin >> totalb;

    buffer=wno+"|"+wname+"|"+totalb+" $\n";
    fp.open("ward.txt",ios::out|ios::app);   
    pos=fp.tellp();
    fp<<buffer;
    fp.close();
    wnolist[++count]=wno;
    addlist[count]=pos;
    sortindex();
    cout<<"\nWard added Successfully....\n";
 }
 
 string Wards::extractid(string buffer)
 {
     string wno;
     int i=0;
     wno.erase();
     while(buffer[i]!='|')
     wno+=buffer[i++];
     return wno;
 }
 
 void Wards::sortindex()
 {
     int i,j,tempadd;
     string tempid;
     for(i=0;i<=count;i++)
     {
           for(j=i+1;j<=count;j++)
           {
               if(wnolist[i]>wnolist[j])

                {
                      tempid=wnolist[i];
			          wnolist[i]=wnolist[j];
                      wnolist[j]=tempid;
                      tempadd=addlist[i];

                      addlist[i]=addlist[j];
                      addlist[j]=tempadd;
                }
           }
     }
     /*
     cout<<"\n-------INDEXLIST--------\n";
     cout<<"\n ID\tINDEX";
     for(i=0;i<=count;i++)
     cout<<"\n"<<adminlist[i]<<"\t"<<addlist[i]<<endl;
*/
 }
 
 void Wards::search(string key)
 {
     int pos=0,t;
     string buffer;
     fstream file;
     buffer.erase();
     pos=searchindex(key);
     if(pos==-1)
           cout<<"Record not found\n";
     else if(pos>=0)
     {
           file.open("ward.txt");
           t=addlist[pos];
           file.seekp(t,ios::beg);
           getline(file,buffer);
           cout<<"Record found\n";
           cout<<"\nRecord:"<<buffer;
           file.close(); 
     }
 }
 
 int Wards::searchindex(string key)
 {
     int low=0,high=count,mid=0,flag=0;
     while(low<=high)
     {
           mid=(low+high)/2;
           if(wnolist[mid]==key)
           {
                flag=1;
                break;
           }
           else if(wnolist[mid]<key)
                low=mid+1;
           else if(wnolist[mid]>key)
                high=mid-1;
     }
     if(flag)
           return mid;
     else
           return -1;
 }
 
 void Wards::remove(string key)
 {
  	fstream fp;
 	char delch='*';
	int pos=0,i,address;
	string buffer,wno,wname,totalb;
	fstream file;
  	pos=searchindex(key);
  	if(pos>=0)
  	{
       file.open("ward.txt");
       address=addlist[pos];
       file.seekp(address,ios::beg);
       file.put(delch);
       file.close();
       cout<<"Record has been deleted\n";
       for(i=pos;i<count;i++)
       {
       		wnolist[i]=wnolist[i+1];
       		addlist[i]=addlist[i+1];
       } 
      count--;
  	}  
  	else
       cout<<"Record not found\n";
  	cout<<"\nUpdated file is\n";
  	system("cat ward.txt");
 }
 
 void Wards::display_w_record()
 {
     cout<<"The Ward details are";
     system("cat ward.txt");
 }
 void Wards::print()
 {
	cout<<"Ward Number:"<<wno<<" Ward Name:"<<wname<<" Total Bed:"<<totalb<<endl;
 }


/*--------------------------------Patinets -- starts from here ----------------------*/


void patients::createindex() 
{
    fstream file;
	int pos;
	string buffer,pid;
    count=-1;
    file.open("patients.txt",ios::in);
    while(!file.eof())
	{
           pos=file.tellg();
           buffer.erase();
           getline(file,buffer);
           if(buffer[0]!='*')
           {
                      if(buffer.empty())
                      break;
                      pid=extractpid(buffer);
                      pidlist[++count]=pid;
                      addlist[count]=pos;
           }
     }
     file.close();
     sortindex();
     buffer.erase();
 }
 
 string patients::extractpid(string buffer)
 {
     string pid;
     int i=0;
     pid.erase();
     while(buffer[i]!='|')
     pid+=buffer[i++];
     return pid;
 }
 
 void patients::insert()
 {
     string pid,pname,paage,pprob,paddr,buffer;
     int pos;
     fstream file;
     
     // ***** new add *****
     	time_t now=time(0);
		char* dt=ctime(&now);
     //cout<<"enter values for patientID, Patient Name,Patient Age,Patient Problem,Patient Address\n";
      cout<<"Enter  Patient ID \n";
      cin>>pid;
      cout<<"Enter  Patient name \n";
      cin>>pname;
      cout<<"Enter  Age \n";
      cin>>paage;
      cout<<"Enter  Patient problem \n";
      cin>>pprob;
      cout<<"Enter  Address\n";
      cin>>paddr;
     //cin>>pid>>pname>>paage>>pprob>>paddr;
      buffer=pid+"|"+pname+"|"+paage+"|"+pprob+"|"+paddr+"$"+"|"+dt+"\n";
      file.open("patients.txt",ios::out|ios::app);
      pos=file.tellp();
      file<<buffer;
      file.close();
      pidlist[++count]=pid;
      addlist[count]=pos;
      sortindex();
      cout<<"\nPatient Registered Successfully....\n";
 }
 
 void patients::sortindex()
 {
     int i,j,tempadd;
     string tempusn;
     for(i=0;i<=count;i++)
     {
           for(j=i+1;j<=count;j++)
           {
               if(pidlist[i]>pidlist[j])
                {
                      tempusn=pidlist[i];
			          pidlist[i]=pidlist[j];
                      pidlist[j]=tempusn;
                      tempadd=addlist[i];
                      addlist[i]=addlist[j];
                      addlist[j]=tempadd;
                }
           }
     }
/*     cout<<"\n------INDEXLIST-------\n";
     cout<<"\nPATIENT ID\tINDEX";
     for(i=0;i<=count;i++)
     cout<<"\n"<<pidlist[i]<<"\t"<<addlist[i]<<endl;
*/
 }
 
 void patients::search(string key)
 {
     int pos=0,t;
     string buffer;
     fstream file;
     buffer.erase();
     pos=searchindex(key);
     if(pos==-1)
         cout<<"Record not found\n";
     else if(pos>=0)
     {
           file.open("patients.txt");
           t=addlist[pos];
           file.seekp(t,ios::beg);
           getline(file,buffer);
           cout<<"Record found\n";
           cout<<"\nRecords are: \n"<<buffer;
           file.close();
    }
 }
  int patients::searchindex(string key)
 {
     int low=0,high=count,mid=0,flag=0;
     while(low<=high)
     {
           mid=(low+high)/2;
           if(pidlist[mid]==key)
           {
                flag=1;
                break;
           }
           else if(pidlist[mid]<key)
                low=mid+1;
           else if(pidlist[mid]>key)
                high=mid-1;
     }
     if(flag)
           return mid;
     else
           return -1;
 }
 
 void patients::remove(string key)
 {
  	fstream fp;
 	char delch='*';
	int pos=0,i,address;
	string buffer,pid,pname,paage,paddr,pprob;
	fstream file;
    pos=searchindex(key);
    if(pos>=0)
    {
       file.open("patients.txt");
       address=addlist[pos];
       file.seekp(address,ios::beg);
       file.put(delch);
       file.close();
       cout<<"Record has been deleted\n";
       for(i=pos;i<count;i++)
       {
       pidlist[i]=pidlist[i+1];
       addlist[i]=addlist[i+1];
       }
      count--;
    }  
    else
       cout<<"Record not found\n";
  	cout<<"\nUpdated file is\n";
  	system("cat patients.txt");
 }
 
 void patients::display_p_record()
 {
     cout<<"The Patient details are\n";
     system("cat patients.txt");
 }
 
void patients::print()
{
	cout<<"Patients ID:"<<pid<<" Name:"<<pname<<" Age:"<<page<<"address:"<<paddress<<"Patient Problem"<<pproblem<<endl;
}

/*------------------Main()----*/




 int main()
 {
     int ch;
     string key;
     patients pa;
     doctor d;
     Nurse n;
     Receptionist r;
     Wards w;
   
     pa.createindex();
     d.createindex();
     n.createindex();
     r.createindex();
     w.createindex();
    while(1){

            int dch,nch,rch;
            string username="a",password="j",u,p;
            cout<<"\n\t******* HOSPITAL RECORDS MANAGEMENT USING PRIMARY INDEX *******\n";
            cout<<"\n\t\tEnter \n\t\t1. Admin\n\t\t2. Doctor\n\t\t3. Nurse\n\t\t4. Receptionist\n\t\t0. Exit\n";
            cout<<"\nEnter your choice\n";
            cin>>ch;
            switch(ch)
             {
   		         case 1:
                    cout<<"Enter your username\n";
                    cin>>u;
                    cout<<"Enter your password\n";
                    cin>>p;
                    if(u==username && p==password)
                    {
                        int ach;
                        cout<<"\nWelcome Admin\n";
          
          cout<<"\n1. ADD Doctors\t\t\t\t2. Add Nurse\n3. Add Receptionist\t\t\t4. Add ward\n";
          cout<<"---------------------------------------------------------------------\n";
          cout<<"\n5. Display doctors records\t\t6. Display Nurse records\n7. Display Receptionist Record\t\t8. Display Ward details\n";
          cout<<"\n-------------------------------------------------------------------\n";
          cout<<"\n9. Remove Doctor record\t\t\t10. Remove Nurse record\n11. Remove Receptionist record\t\t12. Remove Ward record\n";
          cout<<"\nEnter your choice\n";
                        cin>>ach;
                        switch(ach)
                        {
                            case 1:d.insert();
                                    break;
               	            case 5:d.display_doctor();
                   		            break;
                   		    case 2:n.insert();
                   		    		break;
                   		    case 6:n.display_n_record();
                   		    		break;
                	        case 3:r.insert();
                                    break;
                            case 7:r.display_r_record();
                            		break;
                        	case 4:w.insert();
                            		break;
                        	case 8:w.display_w_record();
                        			break;
                        	case 9:cout<<"Enter doctor ID :";
                        			cin>>key; 
                        			d.remove(key);
                        			cout<<"Updated file is :\n";
                        			system("cat doctor.txt");
                        			break;
                        	case 10:cout<<"Enter Nurse ID :";
                        			cin>>key; 
                        			n.remove(key);
                        			system("cat nurse.txt");
                        			break;
                        	case 11:cout<<"Enter Receptionist ID :";
                        			cin>>key; 
                        			r.remove(key);
                        			system("cat recep.txt");
                        			break;
                        	case 12:cout<<"Enter ward number :";
                        			cin>>key; 
                        			w.remove(key);
                        			system("cat ward.txt");
                        			break;

                        default:cout<<"Invalid choice";
                     	}
                	}
                	else
                	{
                		cout<<"Invalid credentials\n";
                	}

                break;

        	case 2:cout<<"Welcome doctor\n";
                   cout<<"1. Search Patient Record\n2. Display Patient Record\nEnter your choice \n";
                   cin>>dch;
                   switch(dch)
                   {
                      case 1: cout<<"enter Patient ID\n";
                              cin>>key;
							  pa.search(key);
                              break;
            	      case 2: pa.display_p_record();
             	              break;
                   }
             break;

       		 case 3: cout<<"Welcome Nurse\n";
                     cout<<"1. Search Patient Record\n2. Display Patient Record\nEnter your choice\n";
                     cin>>nch;
                     switch(nch)
                     {
                       case 1: cout<<"Enter Patient ID\n";
                               cin>>key;
                               pa.search(key);
                               break;

   		       	       case 2: pa.display_p_record();
   		       	               break;
                      }
              break;

        	  case 4: cout<<"Welcome Receptionist\n";
        	          cout<<"1. Add Patient\n2.Generate Bill\n3.Remove Patients\n";
        	          cout<<"Enter your choice\n";
        	          cin>>rch;
        	          switch(rch)
        	          {
        		         case 1: pa.insert();
        		                 break;
        	                /*	case 2:generatebill();
        		                    break;
                                */
                         case 3: cout<<"enter Patient ID\n";
                                 cin>>key;
                                 pa.remove(key);
                                 break;
        		         default:cout<<"Invalid choice";
        	          }
              break;
              
        	  case 0:exit(0);       
        	  default: cout<<"Invalid Choice";
        }

    }
 }
