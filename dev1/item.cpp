//#include <iostream>
//#include <string>
//#include "UserManager.h"
//
//using namespace std;
//
//int main() {
//    char username[30] = "admin";
//    char password[50] = "password";
//
//    char inputUsername[30];
//    char inputPassword[50];
//
//    cout << "�������û���: ";
//    cin >> inputUsername;
//    cout << "����������: ";
//    cin >> inputPassword;
//
//    User user1;
//    user1.id = 3;
//    strcpy_s(user1.account, sizeof(user1.account), username);
//    strcpy_s(user1.password, sizeof(user1.password), password);
//
//    //cout << inputUsername << " " << username << " " << user1.account << endl;
//    //cout << inputPassword << " " << password << " " << user1.password << endl;
//
//    UserManager::GetInstance()->insert_user(user1);
//
//    if (strcmp(inputUsername,username)==0 && strcmp(inputPassword,password)==0) {
//        cout << "��¼�ɹ�����ӭ������" << username << "��" << endl;
//    }
//    else {
//        cout << "�û�����������������ԣ�" << endl;
//    }
//
//    return 0;
//}