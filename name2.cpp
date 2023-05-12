// Hash_table.cpp : term file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <Windows.h>

using namespace std;

// set up 
//========================== Data ============================
struct Date // Initiate the Date type data
{
    int day;
    int month;
    int year;
};

int checkDay(int day, int month, int year)
{
    if (month <= 0 || month > 12)
    {
        return -2;
    }
    int daysPerMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && day == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
    {
        return 1;
    }
    if (day > 0 && day <= daysPerMonth[month])
    {
        return 1;
    }
    return -1;
}

string StringToUpper(string strToConvert)   // covert lower --> upper
{
    std::transform(strToConvert.begin(), strToConvert.end(), strToConvert.begin(), ::toupper);

    return strToConvert;
}

struct Employee // initiate the Employee type
{
    int ID; //MS nhan vien 
    string emName;
    string iden_ID; //CCCD
    Date birthDay; //Employee's birthday 
    string gender;
    string phone_Num;
    string Address;
    int working_time; // Employee's workingtime 
    string position; // Employee's position
    int Salary; // Salary after caculating by multiple between working time and their salary per hour
    Employee() {} //constructor 

    void inputEmployeeMODI(int EmID)
    {

        this->ID = EmID;

        cout << "Enter the Employee's Name :" << endl;
        cin.ignore();
        getline(cin, this->emName);

        bool flag = false;
        do
        {
            flag = true;
            cout << "Enter the Employee's Identify ID:" << endl;
            //cin.ignore();
            getline(cin, this->iden_ID);
            for (int i = 0; i < iden_ID.length(); i++) {
                if (!isdigit(iden_ID[i]))
                {
                    cout << "Invalid input!\n";
                    flag = false;
                    break;
                }
            }
        } while (flag == false);



        cout << "Enter the Employee's Birthday :" << endl;

        do {
            do
            {
                cout << "Input employee day of birth: ";
                cin >> this->birthDay.day;

                if (this->birthDay.day < 1 || this->birthDay.day > 31) {
                    cout << "Please, Input employee day of birth Again (1 -. 31): " << endl;
                }
            } while (this->birthDay.day < 1 || this->birthDay.day > 31);		// check lai

            do
            {
                cout << "Input employee month of birth: ";
                cin >> this->birthDay.month;
                if (this->birthDay.month < 1 || this->birthDay.month > 12) {
                    cout << "Please, Input employee month of birth Again (1 -. 12): " << endl;
                }
            } while (this->birthDay.month < 1 || this->birthDay.month > 12);		// check lai

            do
            {
                cout << "Input student year of birth: ";
                cin >> this->birthDay.year;
                if (this->birthDay.year < 1980 || this->birthDay.year > 2022) {
                    cout << "Please, Input employee year of birth Again (1980 -. 2022): " << endl;
                }
            } while (this->birthDay.year < 1980 || this->birthDay.year > 2022);		// check lai

            if (checkDay(this->birthDay.day, this->birthDay.month, this->birthDay.year) < 0) {
                cout << "Please, Input birthday again!\n";
            }
        } while (checkDay(this->birthDay.day, this->birthDay.month, this->birthDay.year) < 0);
        char dgender;
        cout << "Enter gender (M/m or F/f): ";
        cin >> dgender;

        switch (dgender)
        {
        case 'M':
        case 'm':
            this->gender = "Male";
            break;
        case 'F':
        case 'f':
            this->gender = "Female";
            break;
        default:
            cout << "Unspecified Gender" << endl;
        }


        do
        {
            flag = true;
            cout << "Enter the Employee's Phone number  :" << endl;

            cin.ignore();
            getline(cin, this->phone_Num);
            for (int i = 0; i < phone_Num.length(); i++) {
                if (!isdigit(phone_Num[i]))
                {
                    cout << "Invalid input!\n";
                    flag = false;
                    break;
                }
            }
        } while (flag == false);




        cout << "Enter the Employee's Address  :" << endl;
        getline(cin, this->Address);
        cout << "Enter the Employee's Working Time  :" << endl;
        cin >> this->working_time;
        cout << "Enter the Employee's position in company  :" << endl;
        cout << "* labor / guard / cashier *" << endl;
        cin.ignore();
        cin >> this->position;
        this->Salary = salaryFunction();

    }


    Employee(int id, string name, string idenid, int bDay, int bMon, int byear, char gen, string phone, string Address, int working, string position)
    {
        this->ID = id;
        this->emName = name;
        this->iden_ID = idenid;
        this->birthDay.day = bDay;
        this->birthDay.month = bMon;
        this->birthDay.year = byear;
        switch (gen)
        {
        case 'M':
        case 'm':
            this->gender = "Male";
            break;
        case 'F':
        case 'f':
            this->gender = "Female";
            break;
        default:
            cout << "Unspecified Gender" << endl;
        }
        //this->gender = gen;
        this->phone_Num = phone;
        this->Address = Address;
        this->working_time = working;
        this->position = position;
        this->Salary = salaryFunction();
    }

    int salaryFunction()
    {
        int iSalary = 0;
        if (this->position == "guard")
        {
            iSalary = this->working_time * 22000;
            return iSalary;
        }
        if (this->position == "labor")
        {
            iSalary = this->working_time * 30000;
            return iSalary;
        }
        if (this->position == "cashier")
        {
            iSalary = this->working_time * 25000;
            return iSalary;
        }
        else return 0;
    }
    void inputEmployee()
    {
        cout << "Enter the Employee's ID :\n";
        cin >> this->ID;



        cout << "Enter the Employee's Name :" << endl;
        cin.ignore();
        getline(cin, this->emName);


        bool flag = false;
        do
        {
            flag = true;
            cout << "Enter the Employee's Identify ID:" << endl;
            //cin.ignore();
            getline(cin, this->iden_ID);
            for (int i = 0; i < iden_ID.length(); i++) {
                if (!isdigit(iden_ID[i]))
                {
                    cout << "Invalid input!\n";
                    flag = false;
                    break;
                }
            }
        } while (flag == false);



        cout << "Enter the Employee's Birthday :" << endl;

        do {

            do
            {
                cout << "Input employee day of birth: ";
                cin >> this->birthDay.day;

                if (this->birthDay.day < 1 || this->birthDay.day > 31) {
                    cout << "Please, Input employee day of birth Again (1 - 31): " << endl;
                }
            } while (this->birthDay.day < 1 || this->birthDay.day > 31);		// check lai

            do
            {
                cout << "Input employee month of birth: ";
                cin >> this->birthDay.month;
                if (this->birthDay.month < 1 || this->birthDay.month > 12) {
                    cout << "Please, Input employee month of birth Again (1 - 12): " << endl;
                }
            } while (this->birthDay.month < 1 || this->birthDay.month > 12);		// check lai

            do
            {
                cout << "Input student year of birth: ";
                cin >> this->birthDay.year;
                if (this->birthDay.year < 1980 || this->birthDay.year > 2022) {
                    cout << "Please, Input employee year of birth Again (1980 - 2022): " << endl;
                }
            } while (this->birthDay.year < 1980 || this->birthDay.year > 2022);		// check lai

            if (checkDay(this->birthDay.day, this->birthDay.month, this->birthDay.year) < 0) {
                cout << "Please, Input birthday again!\n";
            }
        } while (checkDay(this->birthDay.day, this->birthDay.month, this->birthDay.year) < 0);
        char dgender;
        cout << "Enter gender (M/m or F/f): ";
        cin >> dgender;

        switch (dgender)
        {
        case 'M':
        case 'm':
            this->gender = "Male";
            break;
        case 'F':
        case 'f':
            this->gender = "Female";
            break;
        default:
            cout << "Unspecified Gender" << endl;
        }


        do
        {
            flag = true;
            cout << "Enter the Employee's Phone number: " << endl;

            cin.ignore();
            getline(cin, this->phone_Num);
            for (int i = 0; i < phone_Num.length(); i++) {
                if (!isdigit(phone_Num[i]))
                {
                    cout << "Invalid input!\n";
                    flag = false;
                    break;
                }
            }
        } while (flag == false);



        cin.ignore();
        cout << "Enter the Employee's Address  :" << endl;
        getline(cin, this->Address);

        cout << "Enter the Employee's Working Time  :" << endl;
        cin >> this->working_time;
        cout << "Enter the Employee's position in company  :" << endl;
        cout << "* labor / guard / cashier *" << endl;
        cin.ignore();
        cin >> this->position;
        this->Salary = salaryFunction();

    }
    void print() { //print table - "\t" ( tuong ungs voi mot tab )  
        cout << "|" << setw(4) << left << this->ID << "|"
            << setw(9) << left << StringToUpper(this->emName) << "|"
            << setw(9) << left << this->iden_ID << "|"
            << this->birthDay.day << "/" << this->birthDay.month << "/" << this->birthDay.year << "\t" << "|"
            << setw(9) << left << StringToUpper(this->gender) << "|"
            << setw(14) << left << this->phone_Num << "|"
            << setw(19) << left << StringToUpper(this->Address) << "|"
            << setw(14) << left << this->working_time << "|"
            << setw(9) << left << StringToUpper(this->position) << "|"
            << left << this->Salary << "|" << endl;// << "|" << '\n';

            //<< setw(14) << left << "|" << this->Salary  << endl;// << "|" << '\n';
    }
    
    //========================================
    
    void printt() { 
        cout << this->ID << "," 
			 << this->emName << "," 
			 << this->iden_ID << "," 
			 << this->birthDay.day << "/" << this->birthDay.month << "/" << this->birthDay.year  << ","
             << this->gender << ","
             << this->phone_Num << ","
             << this->Address << ","
             << this->working_time << ","
             << this->position << ","
             << this->Salary ;
    }

};
//============================================= linked list===============================================
struct Node // a node in linked list
{
public:
    Employee emData; // data of the employee
    Node* next; //pointer which contain the address of the next node
    void Init(Employee nv) {
        emData = nv;
        next = NULL;
    }
};
struct list_Employee
{
    int id;
    Employee* value;
};
class SinglyList // a list in the hash array 
{
private:
    Node* pHead = NULL; // the root node which will control elements in array 
    int len; // the length of a single list
public:
    //Node* pHead;
    SinglyList() {
        pHead = NULL;
        len = 0;
    }
    Node* getRoot()
    {
        return pHead;
    }
    bool isEmptyL() {
        return pHead == NULL;
    }
    int addtoTail(Employee nv) { // add an element into list
        Node* p = new Node();
        p->emData = nv;
        p->next = NULL;
        if (isEmptyL()) { // Check whether the list is empty or not , if true , push the value as the 1st element
            pHead = p;
            len++;
            return 1;
        }
        else { // if not go to the previous element in list and add value to the next node
            Node* temp = pHead; // initiate the variable for while loop
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = p;
            len++;
            return 1;
        }
        return 0;
    }
    int removeNode(int EmID)
    {
        Node* temp = pHead; // Store head node
        int finalnodecheck = 0;
        if (isEmptyL()) { // Check whether the list is empty or not , if true , push the value as the 1st element
            cout << "Can't find any Employee with that ID \n";
            return 0;
        }
        // If head needs to be removed
        else if (temp->emData.ID == EmID)
        {
            // Change head
            pHead = temp->next;

            // Free old head
            free(temp);
            return 1;
        }
        else { // if not go to the previous element in list and add value to the next node
            // initiate the variable for while loop
            while (temp->next->emData.ID != EmID) {
                temp = temp->next;
            }
            // If position is more than number of nodes
            if (temp == NULL || temp->next == NULL)
                return 0;

            // Node temp->next is the node to be deleted
            // Store pointer to the next of node to be deleted
            Node* next = temp->next->next;

            // Unlink the node from linked list
            free(temp->next); // Free memory

            // Unlink the deleted node from list
            temp->next = next;

            return 1;
        }
        return 0;
    }
    Employee searchNode(int EmID)
    {
        Node* temp = pHead; // Store head node
        int finalnodecheck = 0;
        if (isEmptyL()) { // Check whether the list is empty or not , if true , push the value as the 1st element
            cout << "Can't find any Employee with that ID \n";
            Employee temp1;
            return temp1;
        }
        else
        {
            while (temp->emData.ID != EmID) {
                temp = temp->next;
            }
            return temp->emData;
        }
    }
    void printList() {

        cout << setw(5) << left << "|ID"
            << setw(10) << left << "|Name"
            << setw(10) << left << "|CCCD"
            << setw(15) << left << "|Birhday"
            << setw(10) << left << "|Gender"
            << setw(15) << left << "|Phone"
            << setw(20) << left << "|Address"
            << setw(15) << left << "|Working_time"
            << setw(10) << left << "|Position"
            << setw(15) << left << "|Salary" << "\n";

        //<< setw(15) << left << "|Salary" << "|" << "\n";
        for (Node* k = pHead; k != NULL; k = k->next) {

            k->emData.print();
            cout << '\n';

        }

    }

    void modiEmp(int EmID)
    {
        Node* temp = pHead; // Store head node
        Employee modi;
        modi.inputEmployeeMODI(EmID);
        Node* p = new Node();
        p->emData = modi;
        p->next = NULL;
        int finalnodecheck = 0;
        if (isEmptyL()) { // Check whether the list is empty or not , if true , push the value as the 1st element
            cout << "Can't find any Employee with that ID \n";
            Employee temp1;
        }
        else if (temp->emData.ID == EmID)
        {
            // Change head 
            pHead = p;
            // Free old head
            free(temp);
        }
        else
        {
            while (temp->next->emData.ID != EmID) {
                temp = temp->next;
            }
            // Node temp->next is the node to be deleted
           // Store pointer to the next of node to be deleted
            Node* next = temp->next->next;

            // Unlink the node from linked list
            //free(temp->next); // Free memory

            // Unlink the deleted node from list
            temp->next = p;
            p->next = next;

        }
    }

};



//================================ Hash table ============================



class Hashtable
{



private:
    int hashGroups = 11; //the bucket capacity 
    SinglyList* EmBucket; // the node pointer to the main array
    /*
    * List 1 - Index 0,
    * List 2 - Index 1,
    * ...
    */
public:
    Hashtable(int ListNum)
    {
        this->hashGroups = ListNum;
        EmBucket = new SinglyList[hashGroups]; //point to the node array 
    }
    bool isEmpty(); // check whether bucket empty or not
    int  hashFunction(Employee value);
    void insertEmp(Employee value);
    void removeEmp(int EmID);
    void searchTable(int EmID);
    void printTable();
    void hash_to_list(list_Employee list[], int& k);
    void modiEm(int EmID);
};


void Hashtable::modiEm(int EmID)
{
    Employee term;
    int hashValue = EmID % hashGroups;
    term = EmBucket[hashValue].searchNode(EmID);
    if (term.ID < 0)
    {
        cout << "Can't find any Employee with that ID \n";
    }
    else
    {
        EmBucket[hashValue].modiEmp(EmID);
    }
}

void Hashtable::hash_to_list(list_Employee list[], int& k)
{
    k = 0;
    for (int i = 0; i < hashGroups; i++)
    {
        if (EmBucket[i].isEmptyL() == false)
        {
            Node* p = EmBucket[i].getRoot();
            while (p != NULL)
            {
                list[k].id = p->emData.ID;
                list[k].value = &p->emData;
                k++;
                p = p->next;
            }

        }
    }
}

bool Hashtable::isEmpty()
{
    int sum = 0;
    for (int i = 0; i < hashGroups; i++)
    {
        if (EmBucket[i].isEmptyL() == false)
        {
            sum++;
        }
    }
    return sum == 0;
}
int  Hashtable::hashFunction(Employee value)
{
    return value.ID % hashGroups;

}
void Hashtable::insertEmp(Employee value)
{
    int hashValue = hashFunction(value);
    EmBucket[hashValue].addtoTail(value);
}
void Hashtable::removeEmp(int EmID)
{
    int hashValue = EmID % hashGroups;
    EmBucket[hashValue].removeNode(EmID);
    return;
}
void Hashtable::printTable()
{
    for (int i = 0; i < hashGroups; i++)
    {
        if (EmBucket[i].isEmptyL() == true) continue;
        cout << "[BUCKET] : No." << i << endl;
        cout << "======================================================================================================================" << endl;
        EmBucket[i].printList();
        cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
    }
    return;

}
void Hashtable::searchTable(int EmID)
{
    Employee term;
    int hashValue = EmID % hashGroups;
    term = EmBucket[hashValue].searchNode(EmID);
    if (term.ID < 0)
    {
        //cout << "Can't find any Employee with that ID \n";
    }
    else
    {
        term.print();
    }

}


//======================================================================================
void swap(list_Employee& a, list_Employee& b)
{
    list_Employee c = a;
    a = b;
    b = c;
}

void Increase(list_Employee list[], int k, int index)
{

    for (int i = 0; i < k - 1; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            if (index == 1)
            {
                if (list[i].id > list[j].id)
                {
                    swap(list[i], list[j]);
                }
            }
            if (index == 2)
            {
                if (list[i].value->Salary > list[j].value->Salary)
                {
                    swap(list[i], list[j]);
                }
            }
            if (index == 3)
            {
                if (list[i].value->working_time > list[j].value->working_time)
                {
                    swap(list[i], list[j]);
                }
            }


        }
    }
}

void Decrease(list_Employee list[], int k, int index)
{

    for (int i = 0; i < k - 1; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            if (index == 1)
            {
                if (list[i].id < list[j].id)
                {
                    swap(list[i], list[j]);
                }
            }
            if (index == 2)
            {
                if (list[i].value->Salary < list[j].value->Salary)
                {
                    swap(list[i], list[j]);
                }
            }
            if (index == 3)
            {
                if (list[i].value->working_time < list[j].value->working_time)
                {
                    swap(list[i], list[j]);
                }
            }
        }
    }
}







void PrintEMList(list_Employee list[], int k)
{
    cout << "=======================================================================================================================\n";
    cout << setw(5) << left << "ID"
        << setw(10) << left << "Name" << "\t"
        << setw(10) << left << "CCCD"
        << setw(14) << left << "Birhday"
        << setw(10) << left << "Gender"
        << setw(15) << left << "Phone"
        << setw(20) << left << "Address"
        << setw(15) << left << "Working_time"
        << setw(10) << left << "Position"
        << setw(15) << left << "Salary" << "\n";

    for (int i = 0; i < k; i++)
    {
        //cout << "ID :";
        list[i].value->print();
        cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "\n";
    }
    cout << endl;
}

void PrintEMListt(list_Employee list[], int k)
{
    for (int i = 0; i < k; i++)
    {
        //cout << "ID :";
        list[i].value->printt();
        cout << "\n";
    }
    cout << endl;
}



int main()
{
    int id, chon = 0, k = 0, n = 0;
    Hashtable HashTb(10);
    Employee term, result;
    string arr[1000];
    int field, luachon;


    list_Employee ListEm[10];

    do
    {
        system("cls");
        printf("\n\n\n");
        printf("\---------------------------------\n");
        printf("\ |1. Tim Kiem nhan vien ma ID    |\n");
        printf("\ |2. Xuat danh sach nhan vien    |\n");
        printf("\ |3. Xoa nhan vien theo ma ID    |\n");
        printf("\ |4. Them mot nhan vien          |\n");
        printf("\ |5. Sua nhan vien theo ID       |\n");
        printf("\ |6. Thoat                       |\n");
        printf("\---------------------------------\n");

        printf("Moi ban chon: ");
        cin >> chon;
        switch (chon)
        {
        
        case 1:
            cout << "Nhap ID ban muon tim kiem: "; cin >> id;
            cout << "---------------------------------------timkiem----------------------------------" << endl;
            HashTb.searchTable(id);
            system("tamdung");
            break;
        case 2:

            //cout << "\n Sap xep thong tin nhan vien TANG/GIAM theo ID/SALARY/WORKING_TIME" << endl;
            //cout << "Nhap 0 de thoat sap xep!" << endl;


            while (true)
            {

                system("cls");
                cout << "\n Sap xep thong tin nhan vien TANG/GIAM theo ID/SALARY/WORKING_TIME" << endl;
                printf(" ---------------------Dachsach----------------------\n");
                printf(" |1. Xuat danh sach nhan vien                      |\n");
                printf(" |2. Xuat danh sach nhan vien theo ID              |\n");
                printf(" |3. Xuat danh sach nhan vien theo Salary          |\n");
                printf(" |4. Xuat danh sach nhan vien theo Working time    |\n");
                printf(" |5. Thoat                                         |\n");
                printf(" ---------------------------------------------------\n");
                /*cout << "\n**Note: id hoac ID";
                cout << "\n**Note: Salary hoac salary hoac s hoac S" << endl;
                cout << "**Note: 0 Thoat sap xep" << endl;*/
                cout << "\n Xin vui long nhap lua chon: ";
                cin >> field;

                if (field == 0) {     // thoat khoi vong lap nhap field: khong can nhap id hoac salary de sap xep
                    break;
                }
                else {
                    while (true)
                    {
                        system("cls");

                        if (field == 1) {
                            cout << "\t\t\t----------------------------List of Employee------------------------------\n";
                            HashTb.hash_to_list(ListEm, k);
                            PrintEMList(ListEm, k);
                            system("pause");
                            break;
                        }
                        
                        else if (field == 2) {
                            printf(" --------------------MENU TANG GIAM - ID----------------\n");
                            printf(" |1. Xap xep tang dan                                   |\n");
                            printf(" |2. Xap xep giam dan                                   |\n");
                            printf(" |3. Thoat                                              |\n");
                            printf(" --------------------------------------------------------\n");
                            cout << "\n Vui long nhap lua chon: ";
                            cin >> luachon;
                            if (luachon == 1) {
                                cout << "\t\t\t-----------------------Increase List By ID--------------------------------\n";
                                HashTb.hash_to_list(ListEm, k);
                                Increase(ListEm, k, 1);
                                PrintEMList(ListEm, k);
                            }
                            else if (luachon == 2) {
                                cout << "\t\t\t-----------------------Decrease List By ID---------------------------------\n";
                                HashTb.hash_to_list(ListEm, k);
                                Decrease(ListEm, k, 1);
                                PrintEMList(ListEm, k);
                            }
                            else if (luachon == 3)        // thoat khoi sap xep theo ID
                            {
                                break;
                            }
                            else {
                                cout << "\nNhap lai!" << endl;
                            }
                            system("pause");

                        }
                        else if (field == 3) {
                            printf(" --------------------MENU TANG GIAM - SALARY----------------\n");
                            printf(" |1. Xap xep tang dan                                       |\n");
                            printf(" |2. Xap xep giam dan                                       |\n");
                            printf(" |3. Thoat                                                  |\n");
                            printf(" -----------------------------------------------------------\n");

                            cout << "\n Vui long nhap lua chon: ";
                            cin >> luachon;

                            if (luachon == 1) {
                                cout << "\t\t\t--------------------Increase List By Salary---------------------------------\n";
                                HashTb.hash_to_list(ListEm, k);
                                Increase(ListEm, k, 2);
                                PrintEMList(ListEm, k);
                            }
                            else if (luachon == 2) {
                                cout << "\t\t\t---------------------Decrease List By Salary---------------------------------\n";
                                HashTb.hash_to_list(ListEm, k);
                                Decrease(ListEm, k, 2);
                                PrintEMList(ListEm, k);
                            }

                            else if (luachon == 3)    // thoat khoi sap xep theo Salary
                            {
                                break;
                            }
                            else {
                                cout << "\nNhap lai!" << endl;
                                break;
                            }
                            system("pause");

                        }
                        else if (field == 5) {
                            printf(" --------------------MENU TANG GIAM - WORKING TIME----------------\n");
                            printf(" |1. Xap xep tang dan                                             |\n");
                            printf(" |2. Xap xep giam dan                                             |\n");
                            printf(" |0. Thoat                                                        |\n");
                            printf(" -----------------------------------------------------------------\n");

                            cout << "\n Vui long nhap lua chon: ";
                            cin >> luachon;

                            if (luachon == 1) {
                                cout << "\t\t\t-----------------------Increase List By Working Time--------------------------------\n";
                                HashTb.hash_to_list(ListEm, k);
                                Increase(ListEm, k, 3);
                                PrintEMList(ListEm, k);
                            }
                            else if (luachon == 2) {
                                cout << "\t\t\t----------------------Decrease List By Working Time--------------------------------\n";
                                HashTb.hash_to_list(ListEm, k);
                                Decrease(ListEm, k, 3);
                                PrintEMList(ListEm, k);
                            }

                            else if (luachon == 0)    // thoat khoi sap xep theo Salary
                            {
                                break;
                            }
                            else {
                                cout << "\nNhap lai!" << endl;
                                break;
                            }
                            system("pause");

                        }
                        else {
                            cout << "\n Xin vui long nhap lai!" << endl;
                            break;
                        }

                    }
                }

            }
            system("pause");
            break;
        case 3:
            cout << "Nhap ID ban muon xoa: "; cin >> id;
            HashTb.removeEmp(id);
            system("pause");
            break;
        case 4:
            term.inputEmployee();
            HashTb.insertEmp(term);
            system("pause");
            break;
        case 5:
            int empID;
            cout << "Enter the Employee's ID you want to modify : ";
            cin >> empID;
            HashTb.modiEm(empID);
            system("pause");
            break;

        case 6:
            break;
        default:
            printf("Ban chon sai. Moi ban chon lai MENU!\n");
            system("pause");
            break;
        }
    } while (chon != 8);
    return 0;

}
