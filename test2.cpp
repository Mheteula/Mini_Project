//#include <graphics.h>
//#include <iostream>
//#include <fstream>
//#include <conio.h>
//#include <cstring>
//using namespace std;
//
//class Account {
//public:
//    char name[20];
//    char password[20];
//
//    void getdata() {
//        cout << "Enter username: ";
//        cin >> name;
//        cout << "Enter password: ";
//        cin >> password;
//    }
//};
//
//int login() {
//    readimagefile("images\\login_page\\login1.jpg", 442, 161, 442 + 475, 161 + 440);
//    int fx1 = 479, fy1 = 288;
////    setbkcolor(LIGHTBROWN);
//    settextstyle(4, 0, 3);
//
//    // Input username
//    char name[20] = {0};
//    int i = 0;
//    while ((name[i] = getch()) != 13 && i < 19) {
//        if (name[i] == 8 && i > 0) {
//            i--;
//            name[i] = '\0';
//        } 
//		else if (name[i] != 8) {
//            i++;
//            name[i] = '\0';
//        }
//        readimagefile("images\\login_page\\fill_up.jpg", fx1, fy1, fx1 + 404, fy1 + 57);
//        outtextxy(fx1 + 15, fy1 + 20, name);
//    }
//
//    cout << "name: " << name << endl;
//    char logged_in[20];
//    strcpy(logged_in, name);
//
//    // Check username in file
//    Account a2;
//    ifstream fin("datadat", ios::binary);
//    if (!fin) {
//        cerr << "Error opening file!" << endl;
//        return 0;
//    }
//
//    bool userFound = false;
//    while (fin.read(reinterpret_cast<char*>(&a2), sizeof(Account))) {
//        if (strcmp(a2.name, name) == 0) {
//            userFound = true;
//            break;
//        }
//    }
//    fin.close();
//
//    if (!userFound) {
//        cout << "Name not found!" << endl;
//        return 0;
//    }
//
//    // Input password
//    char password[20] = {0};
//    i = 0;
//    cout << "Enter password: ";
//    while ((password[i] = getch()) != 13 && i < 19) {
//        if (password[i] == 8 && i > 0) {
//            i--;
//            password[i] = '\0';
//        } else if (password[i] != 8) {
//            i++;
//            password[i] = '\0';
//        }
//        readimagefile("images\\login_page\\fill_up.jpg", fx1, fy1 + 60, fx1 + 404, fy1 + 117); // Adjust y position for password input
//        outtextxy(fx1 + 15, fy1 + 80, password);
//    }
//
//    // Check password
//    if (strcmp(a2.password, password) == 0) {
//        cout << "Logged in successfully!" << endl;
//        return 1;
//    } else {
//        cout << "Incorrect password!" << endl;
//        return 0;
//    }
//}
//
//int main() {
//    int gd = DETECT, gm;
//    initgraph(&gd, &gm, "");
//
//    // Assuming accounts are already created and stored in "datadat"
//    // Call login function
//    login();
//
//    getch();
//    closegraph();
//    return 0;
//}

