#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include<vector>
#include<queue>
#include<deque>
#include<set>
#include<stack>
#include <unordered_set>
#include<map>
#include<unordered_map>
#include<bitset>
#include<chrono>
#include<iomanip>
#include<sstream>
#include<ctime>
#define ll long long
#define dd double
#define all(v) v.begin(),v.end()
using namespace std;
void fast() { ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); }
class book {
private:
    int ISBN;
    string BookName;
    string AuthorName;
    int NumOfPages;
    vector<string> TitleOfPages;
    int CountOfPages;
public:
    book() {
        ISBN = 0;
        BookName = "";
        AuthorName = "";
        NumOfPages = 0;
        CountOfPages = 1;
    }
    book(int isbn, string bn, string an, int np, vector<string>& tp) {
        ISBN = isbn;
        BookName = bn;
        AuthorName = an;
        NumOfPages = np;
        TitleOfPages = tp;
    }
    const int GetISBN() {
        return ISBN;
    }
    void SetISBN(const int isbn) {
        ISBN = isbn;
    }
    const string& GetBookName() {
        return BookName;
    }
    void SetBookName(const string bn) {
        BookName = bn;
    }
    const string& GetAuthorName() {
        return AuthorName;
    }
    void SetAuthorName(const string an) {
        AuthorName = an;
    }
    const int GetNumOfPages() {
        return NumOfPages;
    }
    void SetNumOfPages(const int np) {
        NumOfPages = np;
    }
    const vector<string>& GetTitleOfPages() {
        return TitleOfPages;
    }
    void SetTitleOfPages(const vector<string>& tp) {
        TitleOfPages = tp;

    }
    const int Getcount() {
        return CountOfPages;
    }
    void Setcount(const int c) {
        CountOfPages = c;
    }
    void NextPage() {
        CountOfPages++;
        if (CountOfPages > NumOfPages) {
            cout << "you are already finished reading this book.stop reading or move to the Previous Page \n";
            CountOfPages--;
            return;
        }
        cout << "Current page: " << CountOfPages << "/" << NumOfPages << "\n";
        cout << TitleOfPages[CountOfPages - 1] << " " << BookName << "\n";
        Setcount(CountOfPages);
    }
    void PreviousPage() {
        CountOfPages--;
        if (CountOfPages == 0) {
            cout << "you are already in first page. stop reading or go to Next Page\n";
            CountOfPages++;
            return;
        }
        cout << "Current page: " << CountOfPages << "/" << NumOfPages << "\n";
        cout << TitleOfPages[CountOfPages - 1] << " " << BookName << "\n";
        Setcount(CountOfPages);
    }
    void counpages() {
        cout << "Current page: " << CountOfPages << "/" << NumOfPages << "\n";
        cout << TitleOfPages[CountOfPages - 1] << " " << BookName << "\n";
    }
};
vector<book>UserBook;
vector<book>Book;
class user;
map<string, user>users_database;
class user {
private:
    string UserName;
    string Password;
    string Name;
    string Email;
public:
    user() {}
    user(string un, string p, string n, string e) {
        UserName = un;
        Password = p;
        Name = n;
        Email = e;
    }
    const string& GetUserName() {
        return UserName;
    }
    void SetUserName(const string un) {
        UserName = un;
    }
    const string& GetPassword() {
        return Password;
    }
    void SetPassword(const string p) {
        cout << "please enter an 8-character password\n";
        Password = p;
    }
    const string& GetName() {
        return Name;
    }
    void SetName(const string n) {
        Name = n;
    }
    const string& GetEmail() {
        return Email;
    }
    void SetEmail(const string e) {
        Email = e;
    }
    void SignUp() {
        cout << "Enter your name (no spaces): ";
        cin >> Name;
        cout << "Enter your email (no spaces): ";
        cin >> Email;
        cout << "Password (enter an 8-character password): ";
        cin >> Password;
        cout << "UserName (no spaces): ";
        cin >> UserName;
        SetUserName(UserName);
        users_database[UserName] = *this;
    }
    void ViewProfile() {
        cout << "Name: " << GetName() << "\n";
        cout << "Email: " << GetEmail() << "\n";
        cout << "User Name: " << GetUserName() << "\n";
    }

    void My_Book() {
        if (UserBook.empty()) {
            cout << "Your history is empty\n";
            return;
        }
        for (int i = 0; i < UserBook.size(); i++) {
            cout << i + 1 << ": " << UserBook[i].GetBookName() << " ";
            cout << "page: " << UserBook[i].Getcount() << "/" << UserBook[i].GetNumOfPages() << "\n";
        }
        cout << "Wich book to open? \n";
        cout << "Enter number in range 1 - " << UserBook.size() << " : ";
        int N; cin >> N;
        cout << "Current page: ";
        UserBook[N - 1].counpages();

        int q;
        while (true) {
            cout << "Menu:\n";
            cout << "\t1: Next page.\n";
            cout << "\t2: Previose page.\n";
            cout << "\t3: Stop reading.\n";
            cin >> q;
            if (q == 1) {
                UserBook[N - 1].NextPage();
            }
            else if (q == 2) {
                UserBook[N - 1].PreviousPage();
            }
            else if (q == 3 || UserBook[N - 1].Getcount() == UserBook[N - 1].GetNumOfPages()) {
                break;
            }
        }
    }
    void Available_Book() {
        cout << "Our current book collection:\n";
        for (int i = 0; i < Book.size(); i++) {
            cout << "\t" << i + 1 << " " << Book[i].GetBookName() << "\n";
        }
        cout << "Wich book to read?\n";
        cout << "Enter number in range 1 - " << Book.size() << ": ";
        int n; cin >> n;
        cout << "Current page: ";
        Book[n - 1].counpages();

        int q;
        while (true) {
            cout << "Menu:\n";
            cout << "\t1: Next page.\n";
            cout << "\t2: Previose page.\n";
            cout << "\t3: Stop reading.\n";
            cin >> q;
            if (q == 1) {
                Book[n - 1].NextPage();

            }
            else if (q == 2) {
                Book[n - 1].PreviousPage();
            }
            else if (q == 3 || Book[n - 1].Getcount() == Book[n - 1].GetNumOfPages()) {
                break;
            }
        }
        UserBook.push_back(Book[n - 1]);
    }

};
user LogIn_user() {
    cout << "Username (no spaces): ";
    string UserName;
    cin >> UserName;
    cout << "Password (enter an 8-character password): ";
    string Password;
    cin >> Password;
    if (!users_database.count(UserName)) {
        cout << "Invalid user name or password, try again\n";
        return LogIn_user();
    }
    user tmp = users_database[UserName];
    if (tmp.GetPassword() != Password) {
        cout << "Invalid user name or password, try again\n";
        return LogIn_user();
    }
    return tmp;
}
class admin;
map<string, admin>admins_database;
class admin {
private:
    string UserName;
    string Password;
    string Name;
    string Email;
public:
    admin() {}
    admin(string un, string p, string n, string e) {
        UserName = un;
        Password = p;
        Name = n;
        Email = e;
    }
    const string& GetUserName() {
        return UserName;
    }
    void SetUserName(const string un) {
        UserName = un;
    }
    const string& GetPassword() {
        return Password;
    }
    void SetPassword(const string p) {
        cout << "please enter an 8-character password\n";
        Password = p;
    }
    const string& GetName() {
        return Name;
    }
    void SetName(const string n) {
        Name = n;
    }
    const string& GetEmail() {
        return Email;
    }
    void SetEmail(const string e) {
        Email = e;
    }
    void SignUp() {
        cout << "Enter your name (no spaces): ";
        cin >> Name;
        cout << "Enter your email (no spaces): ";
        cin >> Email;
        cout << "Password (enter an 8-character password): ";
        cin >> Password;
        cout << "UserName (no spaces): ";
        cin >> UserName;
        admins_database[UserName] = *this;
    }
    void ViewProfile() {
        cout << "Name: " << GetName() << "\n";
        cout << "Email: " << this->GetEmail() << "\n";
        cout << "User Name: " << this->GetUserName() << "\n";

    }
    void AddBook() {
        book book1;
        string s;
        int n;
        cout << "Enter ISBN: ";
        cin >> n;
        book1.SetISBN(n);
        cout << "Enter book name: ";
        cin >> s;
        book1.SetBookName(s);
        cout << "Enter author name: ";
        cin >> s;
        book1.SetAuthorName(s);
        cout << "Enter how many pages: ";
        cin >> n;
        book1.SetNumOfPages(n);
        cout << "Enter content of pages: \n";
        vector<string> ss(book1.GetNumOfPages());
        for (int i = 0; i < book1.GetNumOfPages(); i++) {
            cout << "page " << i + 1 << ": ";
            cin >> ss[i];
        }
        book1.SetTitleOfPages(ss);
        Book.push_back(book1);
    }
};
admin LogIn_admin() {
    string UserName, Password;
    cout << "Username (no spaces): ";
    cin >> UserName;
    cout << "Password (enter an 8-character password): ";
    cin >> Password;
    if (!admins_database.count(UserName)) {
        cout << "Invalid user name or password, try again\n";
        return LogIn_admin();
    }
    admin tmp = admins_database[UserName];
    if (tmp.GetPassword() != Password) {
        cout << "Invalid user name or password, try again\n";
        return LogIn_admin();
    }
    return tmp;
}
void OnlineBookReader() {
    book b1, b2;
    b1.SetISBN(1234);
    b1.SetBookName("c++");
    b1.SetAuthorName("dr:sara");
    b1.SetNumOfPages(4);
    vector<string>s1 = { "A","B","C","D" };
    b1.SetTitleOfPages(s1);

    b2.SetISBN(4567);
    b2.SetBookName("Herry_potter");
    b2.SetAuthorName("J.K.Rowling");
    b2.SetNumOfPages(7);
    vector<string>s2(7);
    s2 = { "the_Philosopher's_Stone","the_Chamber_of_Secrets","the_Prisoner_of_Azkaban","the_Goblet_of_Fire","the_Order_of_the_Phoenix","the_Half-Blood_Prince","the_Deathly_Hallows" };
    b2.SetTitleOfPages(s2);
    Book.push_back(b1);
    Book.push_back(b2);
    while (true) {
        cout << "Account for Admin or User? ";
        string account; cin >> account;
        if (account == "Admin") {

            admin admin1;
            cout << "Menu:\n";
            cout << "\t1: Sign Up.\n\t2: Log In.\n";
            int Choice;
            cin >> Choice;
            if (Choice == 1) {
                admin1.SignUp();
            }
            else {
                admin1 = LogIn_admin();
            }
            cout << "Hello " << admin1.GetUserName() << "\n";
            while (true) {
                cout << "Enter number in range 1 - 3:\n";
                cout << "\t1: View profile.\n";
                cout << "\t2: Add book.\n";
                cout << "\t3: Log out.\n";
                cin >> Choice;
                if (Choice == 1) {
                    admin1.ViewProfile();
                }
                else if (Choice == 2) {
                    admin1.AddBook();
                }
                else {
                    break;
                }
            }
        }
        else {
            user user1;
            cout << "Menu: \n";
            cout << "\t1: Sign Up.\n";
            cout << "\t2: Log in.\n";
            int choice; cin >> choice;
            if (choice == 1) {
                user1.SignUp();
            }
            else {
                user1 = LogIn_user();
            }

            cout << "Hello " << user1.GetUserName() << "\n";
            while (true) {
                cout << "Enter number in range 1 - 4:\n";
                cout << "\t1: View profile.\n";
                cout << "\t2: list & select from my reading history\n";
                cout << "\t3: list & select from available books\n";
                cout << "\t4: Log out\n";
                cin >> choice;
                if (choice == 1) {
                    user1.ViewProfile();
                }
                else if (choice == 2) {
                    user1.My_Book();
                }
                else if (choice == 3) {
                    user1.Available_Book();
                }
                else {
                    break;
                }
            }
        }
    }
}

int main() {

    OnlineBookReader();
}