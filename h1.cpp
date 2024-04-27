#include <iostream>
using namespace std;

class hospital
{
    string address;

public:
    static int beds;
    hospital()
    {
        address = "madhubani,bihar,INDIA"; // use of constructor
    }
    void hos_message()
    {
        cout << "\t\t\t\nMAIN MENU\t\t";
        cout << "\t\t\n\t\t{1}PATIENT CORNER\t\n\t\t{2}EMPLOYER CORNER\t\n\t\t{3}CAFETERIA\n{4}EXIT FROM MAIN MENU\n";
    }
};
int hospital::beds = 100;

class info : public hospital
{
private:
    string name;
    int age;

public:
    void get()
    {
        cout << "\t\t\tEnter your Name: ";
        cin >> name;
        cout << "\t\t\tEnter your age: ";
        cin >> age;
        cout << endl;
    }
    void show()
    {
        cout << "\t\t\tNAME: " << name << endl;
        cout << "\t\t\tAGE: " << age;
        cout << endl;
    }
};

class patient : public info
{
    int id;

public:
    void get()
    {
        cout << "\t\t\tPatients details......\n\n";
        info::get();
        cout << "\t\t\tEnter the id: ";
        cin >> id;

        cout << "\n\t\t\tPatient capacity decreased\n\n"
             << --beds;
        cout << endl;
    }

    void show()
    {
        cout << "\t\t\tPatients Details...\n\n";
        info::show();
        cout << "\t\t\tPatient ID: " << id;
        cout << endl;
    }
    int retid()
    {
        return id;
    }
};

class employee : public info
{
    int id;
    int level;
    float sal;

public:
    void get()
    {
        cout << "Employee details...\n\n";
        info::get();
        cout << "Enter employee ID: ";
        cin >> id;
        cout << "\n[1]Doctor\n[2]Nurse\n[3]Worker";
        cout << "\n\n\tEnter the level of job: ";
        cin >> level;
    }

    void show()
    {
        cout << "\t\t--------Employee details....\n\n";
        info::show();
        cout << "\t\t--------Employee ID: " << id;
        cout << endl;
        cout << "\t\t--------Employee salary: " << sal;
    }

    friend void calcsal(employee &); // friend function
};

void calcsal(employee &e)
{
    int hours;
    cout << "\nEnter the work hours: ";
    cin >> hours;
    switch (e.level)
    {
    case 1:
        e.sal = 500 * hours;
        break;
    case 2:
        e.sal = 300 * hours;
        break;
    case 3:
        e.sal = 100 * hours;
        break;
    default:
        cout << "\n\nUnexpected Result!\n\n";
    }
}






class time_scan
{
public:
    void display()
    {
        cout << "Scans Available:\n[1]X-ray(10 mins)\n[2]MRI-scan(50 mins)\n[3]CT-scan(30 mins)";
    }
};

class ty_pe 
{   protected:
    int type;

public:
    void get()
    {
        cout << "\n\t\t\tEnter your type: ";
        cin >> type;
    }
    void show()
    {
        cout << "\n\t\t\tSELECTED TYPE: " << type;
    }
};
class biling:public ty_pe,public time_scan/*HERE HEIRACHICAL INHERIATNCE IS USED!*/
{
    int daysofstay;
    float noofmed;
    int bills;

public:
    void bill()
    {
        cout << "\t\t\tEnter your days of stay!: ";
        cin >> daysofstay;
        cout << "\n\t\t\tEnter the no of medicines taken: ";
        cin >> noofmed;
        time_scan::display();
        ty_pe::get();
        if(type==0){
            add();
        }else{
            add(type);
        }

        
    }
    void add()
    {
        bills = daysofstay * noofmed * 200;
    }
    void add(int a)
    {
        bills = daysofstay * noofmed * 200+a;
    }
    void show()
    {   
        ty_pe::show();
        cout << "\n\t\t\tThe bill is: Rs" << bills;
    }
};

class cafe
{
    float amount;
    int type;

public:
    cafe()
    {
        type = 0;
        amount = 0.0;
    }

    void get()
    {
        do
        {
            cout << "\n\t\t\tEnter your type: \n[1]Tea\n[2]Coffee\n[3]Biscuits\n\n[0]EXIT\n";
            cout << "\t\t\tYOUR CHOICE: ";
            cin >> type;
            switch (type)
            {
            case 1:
                amount += 200;
                break;
            case 2:
                amount += 400;
                break;
            case 3:
                amount += 500;
                break;
            case 0:
                break;
            default:
                cout << "\nUnexpected result";
                break;
            }
        } while (type != 0);
    }

    void show()
    {
        cout << "\n\n\t\t\tPlease Pay With CARD OR CASH! .....THANK YOU\n\n";
        cout << "\n\t\t\tYOUR FINAL AMOUNT IS: " << amount;
    }
};
inline void fun1()
{
    cout << "\t\t\t+++++++++WELCOME TO SOHAIL HAFSAH HOSPITAL+++++++++";
}

class level_1
{
public:
    virtual void display()
    {
        cout << "\t\t\thourly salary of type-1 employee: Rs500";
    }
    void show()
    {
        cout << "\t\t\thourly salary of type-1 employee: Rs500";
    }
};
class level_2 : public level_1
{
public:
    void display()
    {
        cout << "\n\t\t\thourly salary of type-2 employee: Rs300\n";
    }
    void show()
    {
        cout << "\n\t\t\thourly salary of type-2 employee: Rs300\n";
    }
};

int main()
{
    fun1();

    patient p[500];
    employee e[50];
    cafe caf;
    biling b[500];
    level_1 *t = new level_2(); // one dimensional array of object
    int emp = 0;
    int key;
    int k;
    int i = 0;
    do
    {
        hospital h;
        h.hos_message();
        cout << "\t\t\nENTER YOUR CHOICE:)  :";
        cin >> key;
        switch (key)
        {
        case 1:

            do
            {
                cout << "\n\n{1}ADMISSION\n{2}PATIENT DETAILS\n{3}EXIT TO MAIN MENU\nYour choice: ";
                cin >> k;
                switch (k)
                {
                case 1:
                    if (i == 500)
                    {
                        cout << "\nBeds are full.NO SPACE\n";
                    }
                    else
                    {
                        p[i].get();
                        b[i].bill();
                        ++i;
                    }

                    break;
                case 2:
                    int id, j;
                    j = 0;
                    cout << "Enter the id : ";
                    cin >> id;
                    while (j < id)
                    {
                        if (id == p[j].retid())
                        {
                            p[j].show();
                            b[j].show();
                            break;
                        }
                        ++j;
                    }
                    break;
                case 3:
                    break;
                default:
                    cout << "\nWrong choice\n";
                }
            } while (k != 3);
            break;
        case 2:

            e[emp].get();

            t->display(); // virtual function pointing to the function of derived class
            t->show();    // non_virtual function pointing to funtion of base class

            calcsal(e[emp]); // use of FRIEND FUNCTION
            e[emp].show();
            ++emp;
            break;
        case 3:
            caf.get();
            caf.show();

            break;
        case 4:
        cout<<"\n\n\t\t\tWE HOPE YOU A WONDERFUL JOURNEY!";
            exit(0);
         break;
        
        }}while (key != 4);

    
}
