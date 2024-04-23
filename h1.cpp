#include<iostream>
using namespace std;


class hospital{
    string address;
    public:
    static int beds;
    hospital(){
        address="madhubani,bihar,INDIA";    //use of constructor
    }

};
int hospital::beds=100;

class info:public hospital{
    private:
    string name;
    int age;
    public:
    void get(){
        cout<<"Enter your details: ";
        cin>>name;
        cout<<"Enter your age: ";
        cin>>age;
        cout<<endl;
    }
    void show(){
        cout<<"NAME: "<<name<<endl;
        cout<<"AGE: "<<age;
        cout<<endl<<endl;
    }
};

class patient:public info{
    int id;
    public:
    void get(){
        cout<<"Patients details......\n\n";
         info::get();
        cout<<"Enter the id: ";
        cin>>id;
       
        cout<<"\nPatient capacity decreased\n\n"<<--beds;
         cout<<endl;


    }

    void show(){
        cout<<"Patients Details...\n\n";
        info::show();
        cout<<"Patient ID: "<<id;
        cout<<endl<<endl;

    }
    int retid(){
        return id;
    }
};

class employee:public info{
    int id;
    int level;
    float sal;

    public:

    void get(){
        cout<<"Employee details...\n\n";
        info::get();
        cout<<"Enter employee ID: ";
        cin>>id;
        cout<<"\n[1]Doctor\n[2]Nurse\n[3]Worker";
        cout<<"\n\n\tEnter the level of job: ";
        cin>>level;
    }

    void show(){
        cout<<"Employee details....\n\n";
        info::show();
        cout<<"Employee ID: "<<id;
        cout<<endl;
        cout<<"Employee salary: "<<sal;

    }

    friend void calcsal(employee&);  //friend function
};

void calcsal(employee& e){
    int hours;
    cout<<"\nEnter the work hours: ";
    cin>>hours;
    switch (e.level)
    {
    case 1:
        e.sal=500*hours;
        break;
    case 2:
        e.sal=300*hours;
        break;
    case 3:
        e.sal=100*hours;
        break;
    default:
         cout<<"\n\nUnexpected Result!\n\n";
    }
}

void add(int a,int b){
    cout<<"\nAddition of selected tablets: "<<a+b<<endl;
}
void add(float a,float b){
    cout<<"\nAddition of selected syrup: "<<a+b<<endl;
}

class biling{
    int daysofstay;
    int noofmed;
    int bills;
    
    public:
    void bill(){
        cout<<"Enter your days of stay!: ";
        cin>>daysofstay;
        cout<<"\nEnter the no of medicines taken: ";
        cin>>noofmed;
        bills=daysofstay*noofmed*200;
    }
    void show(){
        cout<<"\nThe bill is: Rs"<<bills;
    }
    
};

class scan{
      public:
      void display(){
        cout<<"Scans Available:\n[1]X-ray\n[2]MRI-scan\n[3]CT-scan";
      }
};

class time_scan{
    public:
    void display(){
         cout<<"Scans Available:\n[1]X-ray(10 mins)\n[2]MRI-scan(50 mins)\n[3]CT-scan(30 mins)";
    }
};

class ty_pe:public scan,public time_scan{        /*HERE HEIRACHICAL INHERIATNCE IS USED!
                                                          */
    int type;
    public:
    void get(){
        cout<<"\nEnter your type: ";
        cin>>type;
    }
    void show(){
        cout<<"\nSELECTED TYPE: "<<type;
    }

};

class cafe{
    float amount;
    int type;
    public:
    cafe(){
        type=0;
        amount=0.0;
    }
   
    void get(){
        do{
    cout<<"\nEnter your type: \n[1]Tea\n[2]Coffee\n[3]Biscuits\n\n[0]EXIT";
    cin>>type;
    switch(type){
        case 1:
        amount+=200;
        break;
        case 2:
        amount+=400;
        break;
        case 3:
        amount+=500;
        break;
        case 0:
        break;
        default:
        cout<<"\nUnexpected result";
        break;
    }}while(type!=0);
    
    
    
    }

    void show(){
        cout<<"\n\nPlease Pay With CARD OR CASH! .....THANK YOU\n\n";
        cout<<"\nYOUR FINAL AMOUNT IS: "<<amount;
    }

  



};
  inline void fun1(){
        cout<<"+++++++++WELCOME TO SOHAIL HAFSAH HOSPITAL+++++++++";
    }


    class level_1{
        public:
        virtual void display(){
            cout<<"hourly salary of type-1 employee: Rs500";
        }
        void show(){
            cout<<"hourly salary of type-1 employee: Rs500";
        }
    };
    class level_2:public level_1{
               public:
               void display(){
                cout<<"\nhourly salary of type-2 employee: Rs300\n";
               }
               void show(){
                 cout<<"\nhourly salary of type-2 employee: Rs300\n";
               }

    };

int main(){
     fun1();
     
     patient p[500];   //one dimensional array of object
     int k;
     int i=0;
     do{
        cout<<"\n\n{1}ADMISSION\n{2}PATIENT DETAILS\n{3}EXIT\nYour choice: ";
        cin>>k;
        switch(k){
            case 1:
            if(i==500){
                cout<<"\nBeds are full.NO SPACE\n";
            }else{
            p[i].get();
            ++i;}
            
            break;
            case 2:
            int id,j;
             j=0;
            cout<<"Enter the id : ";
            cin>>id;
            while(j<id){
                  if(id==p[j].retid()){
                    p[j].show();
                    break;
                  }++j;
            }
            break;
            case 3:
            break;
            default:cout<<"\nWrong choice\n";
        }
     }while(k!=3);

     employee e;
     e.get();

     level_1 *t=new level_2();
     t->display();   //virtual function pointing to the function of derived class
     t->show();        //non_virtual function pointing to funtion of base class

     calcsal(e);  //use of FRIEND FUNCTION
     e.show();


     int a,b;
     cout<<"\n\nEnter the no of tablets for morning: ";
     cin>>a;
     cout<<"\n\nEnter the no of Tablets for Evening: ";
     cin>>b;
     add(a,b);   //function overloading with integer as a argument
     

     float x,y;
     cout<<"\n\nEnter the ml of syrup taken for morning:  ";
     cin>>x;
     cout<<"\n\nEnter the ml of syrup taken for evening:  ";
     cin>>y;
     add(a,b);   //function overloading with float as a argument


     

     




     

}







