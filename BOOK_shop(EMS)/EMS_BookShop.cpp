#include <iostream>
#include <cstring>
#include<fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <ctime>
#include <chrono>

#pragma warning(disable : 4996).

using namespace std;
const int size = 10;
struct Books {
    int Id;
    string Title;
    string Catogry;
    string Author_Name;
    string Publication_Year;
    float Price;
    int Quantity_in_Stock;

}sb[10];

struct Customer {
    int ID;
    string UserName;
    string Password;
    string Email;
    string Address;
    string Phone;
}allCustomers[15];

struct Date {
    int Days;
    int Month;
    int Years;

};


struct Order {
    int  Customer_Id;
    Date Order_date;
    float Total_Price;
    Date Ship_date;
    int noOfBooks;
    int List_of_Book_IDs[10];
}orders[10];

//read from books file to books struct
void booksToStruct() {
    ifstream s_book;
    string tempid;
    float tempprice;
    s_book.open("Book.txt", ios::app);
    if (s_book.fail()) {
        cout << "ERROR ...... Failed file" << endl;
    }
    else {
        int w = 0;

        while (!s_book.eof()) {
            s_book >> sb[w].Id >> sb[w].Quantity_in_Stock >> sb[w].Price;
            getline(s_book, sb[w].Title, ',');
            getline(s_book, sb[w].Catogry, ',');
            getline(s_book, sb[w].Author_Name, ',');
            getline(s_book, sb[w].Publication_Year, ',');
            ++w;
        }
    }
   
}


int i = 0, o = 0, currentCustomer;
int nowodd, nowodm, nowody, nowsdd, nowsdm, nowsdy;
int booklist[10];

//customer functions
//read from file to struct
void CustomersToStruct() {
    ifstream inFile("Customers.txt", ios::app);
    int tempid;
    //divide address
    string tempusername, temppassword, tempemail, tempaddress, city, area, streetname, buildno, floor, tempphone;
    if (inFile.fail()) {
        cout << "Error opening customer records file (Customers.txt)" << endl;
        exit(1);
    }
    i = 0;
    while (!inFile.eof()) {
        inFile >> tempid >> tempusername >> temppassword >> tempemail >> tempaddress >> tempphone;
        allCustomers[i].ID = tempid;
        allCustomers[i].UserName = tempusername;
        allCustomers[i].Password = temppassword;
        allCustomers[i].Email = tempemail;
        allCustomers[i].Address = tempaddress;
        allCustomers[i].Phone = tempphone;
        i++;
    }

   
}

void signUp() {
    ++i;
    currentCustomer = i;
    allCustomers[i].ID = i;
    string username, password, email, address, phone, city, area, street, building, floor;
    cout << "Enter Username : ";
    cin >> username;
    allCustomers[i].UserName = username;
    cout << "Enter Password : ";
    cin >> password;
    allCustomers[i].Password = password;
    cout << "Enter Email : ";
    cin >> email;
    allCustomers[i].Email = email;
    cout << "Enter Address : \n";
    cout << "City : ";
    cin >> city;
    cout << "Area : ";
    cin >> area;
    cout << "Street Number : ";
    cin >> street;
    cout << "Building Number : ";
    cin >> building;
    cout << "Floor : ";
    cin >> floor;
    address = city + "," + area + "," + street + "," + building + "," + floor;
    allCustomers[i].Address = address;
    cout << "Enter Phone Number : ";
    cin >> phone;
    allCustomers[i].Phone = phone;
    ofstream outFile;
    outFile.open("Customers.txt", ios::app);
    outFile << '\n' << '\n' << i << '\n' << username << '\n' << password << '\n' << email << '\n' << address << '\n' << phone;
    outFile.close();
    system("cls");
}

///////////////////////////   write to file after editing  /////////////////////////

void customersData() {
    ofstream outFile;
    outFile.open("Customers.txt", ios::trunc);
    for (int k = 0; k < i; ++k) {
        if (k == i - 1) {
            outFile << allCustomers[k].ID << '\n' << allCustomers[k].UserName << '\n' << allCustomers[k].Password << '\n' << allCustomers[k].Email << '\n' << allCustomers[k].Address << '\n' << allCustomers[k].Phone;

        }
        else {
            outFile << allCustomers[k].ID << '\n' << allCustomers[k].UserName << '\n' << allCustomers[k].Password << '\n' << allCustomers[k].Email << '\n' << allCustomers[k].Address << '\n' << allCustomers[k].Phone << endl << endl;
        }
    }

}

///////////////////////////  edit books in file ////////////////////

void editedBooks() {
    ofstream outFile;
    outFile.open("Book.txt", ios::trunc);
    for (int k = 0; k < 10; ++k) {
        if (k == 9) {
            outFile << sb[k].Id << " " << sb[k].Quantity_in_Stock << " " << sb[k].Price << sb[k].Title << "," << sb[k].Catogry << "," << sb[k].Author_Name << "," << sb[k].Publication_Year << ",\n";

        }
        else {
            outFile << sb[k].Id << " " << sb[k].Quantity_in_Stock << " " << sb[k].Price << sb[k].Title << "," << sb[k].Catogry << "," << sb[k].Author_Name << "," << sb[k].Publication_Year << "," << endl;
        }
    }
}

//////////////////////////  edit information  //////////////////////////////

void editInformation() {
    system("cls");
    cout << "If you'd like to change your : \n";
    cout << " 1- Username\n" << "2- Password\n" << "3- Email Address\n" << "4- Home Address\n" << "5- Phone Number\n";
    cout << "Please enter the number correspondent to it.\n";
    int n;
    string newVariable;
    string city, area, street, building, floor;
    cin >> n;
    switch (n) {
    case 1:
        cout << "Username : " << allCustomers[currentCustomer].UserName << '\n';
        cout << "Enter new username.\n";
        cin >> newVariable;
        if (newVariable != allCustomers[currentCustomer].UserName) {
            allCustomers[currentCustomer].UserName = newVariable;
            cout << "All changes saved.\n";
        }
        else {
            cout << "New username can't be the same as the old one.\n";
        }
        break;
    case 2:
        cout << "Password : **" << '\n';
        cout << "Enter new password.\n";
        cin >> newVariable;
        if (newVariable != allCustomers[currentCustomer].Password) {
            allCustomers[currentCustomer].Password = newVariable;
            cout << "All changes saved.\n";
        }
        else {
            cout << "New password can't be the same as the old one.\n";
        }
        break;
    case 3:
        cout << "Email Address : " << allCustomers[currentCustomer].Email << '\n';
        cout << "Enter new email address.\n";
        cin >> newVariable;
        if (newVariable != allCustomers[currentCustomer].Email) {
            allCustomers[currentCustomer].Email = newVariable;
            cout << "All changes saved.\n";
        }
        else {
            cout << "New email can't be the same as the old one.\n";
        }
        break;
    case 4:
        cout << "Home Address : " << allCustomers[currentCustomer].Address << '\n';
        cout << "Enter new home address.\n";
        cout << "City : ";
        cin >> city;
        cout << "Area : ";
        cin >> area;
        cout << "Street Number : ";
        cin >> street;
        cout << "Building Number : ";
        cin >> building;
        cout << "Floor : ";
        cin >> floor;
        newVariable = city + "," + area + "," + street + "," + building + "," + floor;
        if (newVariable != allCustomers[currentCustomer].Address) {
            allCustomers[currentCustomer].Address = newVariable;
            cout << "All changes saved.\n";
        }
        else {
            cout << "New address can't be the same as the old one.\n";
        }
        break;

    case 5:
        cout << "Phone Number : " << allCustomers[currentCustomer].Phone << '\n';
        cout << "Enter new phone number.\n";
        cin >> newVariable;
        if (newVariable != allCustomers[currentCustomer].Phone) {
            allCustomers[currentCustomer].Phone = newVariable;
            cout << "All changes saved.\n";
        }
        else {
            cout << "New phone number can't be the same as the old one.\n";
        }
        break;
    }
    customersData();

}

/////////////////////////////   search for book  ////////////////////////////////

void search_books(Books sb[], const int size) {

    system("cls");
    fstream s_book;
    s_book.open("Book.txt", ios::in);

    if (s_book.fail()) {
        cout << "ERROR ...... Failed file" << endl;
    }
    else {


        for (int i = 0; i < size && !s_book.eof(); ++i) {
            s_book >> sb[i].Id >> sb[i].Quantity_in_Stock >> sb[i].Price;
            getline(s_book, sb[i].Title, ',');
            getline(s_book, sb[i].Catogry, ',');
            getline(s_book, sb[i].Author_Name, ',');
            getline(s_book, sb[i].Publication_Year, ',');

        }
    }
    cout << "------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "How do you want to find your book?" << "\n";
    cout << " Title: 1 \n" << " Category: 2 \n" << " Author Name: 3 \n";
    cout << "\n" << "   Enter 1 or 2 or 3   " << endl;
    cout << " Please enter your number of choice:  ";
    int number;
    cin >> number;
    cin.ignore();
    cout << "Search for: \n";
    string searched;
    getline(cin, searched);
    bool found = false;

    if (number == 1) {
        string result;
        result = " " + searched;
        for (int y = 0; y < 10; y++) {
            if (sb[y].Title == result) {
                found = true;
                //cout << "\t id : " << sb[y].Id << endl;
                cout << "\t Title is :" << sb[y].Title << endl;
                cout << "\t Category is : " << sb[y].Catogry << endl;
                cout << "\t Author Name is : " << sb[y].Author_Name << endl;
                cout << "\t Publication Year is : " << sb[y].Publication_Year << endl;
                //cout << "\t quantity is : " << sb[y].Quantity_in_Stock << endl;
                cout << "\t Price is : $" << sb[y].Price << endl;
                cout << "-----------------------------------------------------------" << endl;
            }
        }
    }
    else if (number == 2) {
        for (int y = 0; y < 10; y++) {
            if (sb[y].Catogry == searched) {
                found = true;
                cout << "\t Title is : " << sb[y].Title << endl;
                cout << "\t Category is : " << sb[y].Catogry << endl;
                cout << "\t Author Name is : " << sb[y].Author_Name << endl;
                cout << "\t Publication Year is : " << sb[y].Publication_Year << endl;
                //cout << "\t quantity is : " << sb[y].Quantity_in_Stock << endl;
                cout << "\t Price is : $" << sb[y].Price << endl;
                cout << "-----------------------------------------------------------" << endl;
            }
        }
    }
    else {
        for (int y = 0; y < 10; y++) {
            if (sb[y].Author_Name == searched) {
                found = true;
                cout << "\t Title is : " << sb[y].Title << endl;
                cout << "\t Category is : " << sb[y].Catogry << endl;
                cout << "\t Author Name is : " << sb[y].Author_Name << endl;
                cout << "\t Publication Year is : " << sb[y].Publication_Year << endl;
                //cout << "\t quantity is : " << sb[y].Quantity_in_Stock << endl;
                cout << "\t Price is : $" << sb[y].Price << endl;
                cout << "-----------------------------------------------------------" << endl;
            }
        }
    }

    if (!found) {
        cout << "  Not found. ";
    }
}

       ////////////////////   reads customer data from file to struct //////////////////////

void ordersToStruct() {
    o = 0;
    ifstream inFile("Orders.txt", ios::app);
    int tempcid = 0, tempday = 0, tempmonth = 0, tempyear = 0, shipday = 0, shipmonth = 0, shipyear = 0, n = 0;
    float tempprice;
    if (inFile.fail()) {
        cout << "Error opening customer records file (orders.txt)" << endl;
        exit(1);
    }

    while (!inFile.eof()) {
        inFile >> tempcid >> tempday >> tempmonth >> tempyear >> shipday >> shipmonth >> shipyear >> n;
        for (int y = 0; y < n; ++y) {
            inFile >> orders[o].List_of_Book_IDs[y];
        }
        inFile >> tempprice;
        orders[o].Customer_Id = tempcid;
        orders[o].Order_date.Days = tempday;
        orders[o].Order_date.Month = tempmonth;
        orders[o].Order_date.Years = tempyear;
        orders[o].Ship_date.Days = shipday;
        orders[o].Ship_date.Month = shipmonth;
        orders[o].Ship_date.Years = shipyear;
        orders[o].noOfBooks = n;
        orders[o].Total_Price = tempprice;

        o++;
    }

}

float tprice = 0;
int numofbooks;
float totalprice = 0, price;
struct tm nowlocal;

/////////////////////////////   order ////////////////////////////

void order(int numofbooks) {
    ofstream inFile;
    inFile.open("Orders.txt", ios::app);
    inFile << '\n' << '\n' << orders[o].Customer_Id << '\n' << nowodd << " " << nowodm << " " << nowody << '\n' << nowsdd << " " << nowsdm << " " << nowsdy << '\n' << numofbooks << '\n';
    for (int k = 0; k < numofbooks; ++k) {
        if (k != numofbooks - 1) {
            inFile << orders[o].List_of_Book_IDs[k] << " ";
        }
        else {
            inFile << orders[o].List_of_Book_IDs[k];
        }
    }
    inFile << '\n' << totalprice;
    inFile.close();
}

///////////////////////////////  add order ////////////////////////////////

void add_order() {
    system("cls");
    o++;
    for (int i = 0; i < 10; ++i) {
        if (sb[i].Quantity_in_Stock != 0) {
            cout << "Book Title: " << sb[i].Title << '\n';
            cout << "Category: " << sb[i].Catogry << '\n';
            cout << "Author Name: " << sb[i].Author_Name << '\n';
            cout << "Year Published: " << sb[i].Publication_Year << '\n';
            cout << "Book ID: " << sb[i].Id << '\n';
            //cout << sb[i].Quantity_in_Stock << '\n';
            cout << "Price: " << sb[i].Price << '\n';
            cout << "-------------------------------------------------\n";
        }
        else {
            continue;
        }
    }
    orders[o].Customer_Id = allCustomers[currentCustomer].ID;
    time_t now;
    now = time(NULL);
    nowlocal = *localtime(&now);
    nowodd = nowlocal.tm_mday;
    orders[o].Order_date.Days = nowodd;
    nowodm = nowlocal.tm_mon + 1;
    orders[o].Order_date.Month = nowodm;
    nowody = nowlocal.tm_year + 1900;
    orders[o].Order_date.Years = nowody;
    nowsdd = nowlocal.tm_mday + 3;
    orders[o].Ship_date.Days = nowsdd;
    nowsdm = nowlocal.tm_mon + 1;
    orders[o].Ship_date.Month = nowsdm;
    nowsdy = nowlocal.tm_year + 1900;
    orders[o].Ship_date.Years = nowsdy;
    cin.get();
    cout << " How many books do you want to buy?\n";
    cin >> numofbooks;
    orders[o].noOfBooks = numofbooks;
    cout << "The book's ID : ";
    for (int j = 0; j < numofbooks; j++)
    {
        cin >> orders[o].List_of_Book_IDs[j];
        for (int c = 0; c < 10; c++) {
            if (orders[o].List_of_Book_IDs[j] == sb[c].Id) {
                sb[c].Quantity_in_Stock--;
                totalprice += sb[c].Price;
            }
        }
        orders[o].Total_Price = totalprice;

    }
    order(numofbooks);
}

//////////////////////////////////////  login ///////////////////////////////

bool login() {
    string username, password, un, pw;
    bool found = false;
    cout << " Enter username : ";
    cin >> username;
    cout << " Enter password : ";
    cin >> password;
    for (int j = 0; j < 15; ++j) {
        if (allCustomers[j].UserName == username && allCustomers[j].Password == password) {
            currentCustomer = j;
            found = true;
        }
    }
    if (found) {
        return true;
    }
    else {
        return false;
    }
    system("cls");
}

///////////////////////////////////// showorderreceipt //////////////////////////////////////

void showorderreceipt() {
    bool found = false;
    for (int a = o - 1; a >= 0; --a) {
        if (orders[a].Customer_Id == allCustomers[currentCustomer].ID) {
            found = true;
            cout << "Order Date: " << orders[a].Order_date.Days << "/" << orders[a].Order_date.Month << "/" << orders[a].Order_date.Years << '\n';
            cout << "Shipping Date: " << orders[a].Ship_date.Days << "/" << orders[a].Ship_date.Month << "/" << orders[a].Ship_date.Years << '\n';
            cout << "List  of book IDs: \n";
            for (int z = 0; z < orders[a].noOfBooks; ++z) {
                cout << "Book" << z + 1 << ": " << orders[a].List_of_Book_IDs[z] << '\n';
            }
            //cout << '\n' << orders[a].price;
            cout << "Total price: " << orders[a].Total_Price << '\n';
            break;

        }
    }
    if (!found) {
        cout << "You haven't ordered any books yet.";
    }
}


/////////////////////////////////  show all orders  /////////////////////////////////////

void showAllOrders() {
    bool found = false;
    for (int a = 0; a < o; ++a) {
        if (orders[a].Customer_Id == allCustomers[currentCustomer].ID) {
            found = true;
            cout << "Order Date: " << orders[a].Order_date.Days << "/" << orders[a].Order_date.Month << "/" << orders[a].Order_date.Years << '\n';
            cout << "Shipping Date: " << orders[a].Ship_date.Days << "/" << orders[a].Ship_date.Month << "/" << orders[a].Ship_date.Years << '\n';
            cout << "List  of book IDs: \n";
            for (int z = 0; z < orders[a].noOfBooks; ++z) {
                cout << "Book" << z + 1 << ": " << orders[a].List_of_Book_IDs[z] << '\n';
            }
            //cout << '\n' << orders[a].price;
            cout << "Total price: " << orders[a].Total_Price << '\n' << '\n';

        }
    }
    if (!found) {
        cout << "You haven't ordered any books yet.";
    }
}

   
       ////////////////////   the main function  ////////////////////////
int num = 0;
int main()
{

    const int size = 10;
    booksToStruct();
    CustomersToStruct();
    ordersToStruct();

    int choice;
    cout << "----------------------------------------" << endl;
    cout << "               WELCOME                  " << endl;
    cout << "----------------------------------------" << endl;
    cout << "1- Sign up" << endl;
    cout << "2- Login" << endl;
    cout << "Please enter your choice : ";
    cin >> choice;
    if (choice == 1) {
        signUp();
    }
    else
    {
        bool loginsuccess = login();
        if (loginsuccess == false) {
            cout << "Incorrect username or password. Login attempt failed." << endl;
            return 0;
        }
        system("cls");
    }
    do {
        cout << endl;
        cout << endl;
        cout << "---------------------------------------------" << endl;
        cout << "             EMS BOOKSHOP\n";
        cout << "---------------------------------------------" << endl;
        cout << "To search for a book : 1 " << endl;
        cout << "To add an order : 2 " << endl;
        cout << "To edit your personal information : 3 \n";
        cout << "To show order receipt : 4 " << endl;
        cout << "To show all orders : 5 " << endl;
        cout << "Exit : 6 " << endl;
        cout << "Enter the number of your choice ... : ";
        num = 0;
        cin >> num;
        system("cls");

        if (num == 1)
        {
            Books sb[size];
            search_books(sb, size);
        }
        else if (num == 2)
        {
            add_order();
            editedBooks();
            ordersToStruct();
        }
        else if (num == 3)
        {
            editInformation();
        }
        else if (num == 4)
        {
            showorderreceipt();
        }
        else if (num == 5)
        {
            showAllOrders();
        }

    } while (num != 6);

    system("pause");
    return 0;

}