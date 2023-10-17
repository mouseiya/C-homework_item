#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct User
{
	int id;
	char account[30];
	char password[50];
} User;

class UserManager
{
public:
	UserManager();
	//UserManager(int user_id, char user_account[], char user_password[]);
	~UserManager();

public:
	bool Insert_user(User& u, int port);//����һ��User���󣬲��뵽user_table��
	bool Update_user(User& u, int port);//����һ��User���󣬸���id��������
	bool Delete_user(int id, int port);//����һ��id��ɾ������
	vector<User> Get_users(string condition, int port);//��ȡ�����û���Ϣ
	bool ValidateUser(const char* inputUsername, const char* inputPassword, int port);//�����˻������������ݿ���Ϣ���бȶԣ����������¼
	
	bool insert_user(User& u, int port);//����һ��User���󣬲��뵽user_table��
	bool update_user(User& u, int port);//����һ��User���󣬸���id��������
	bool delete_user(int id, int port);//����һ��id��ɾ������
	vector<User> get_users(string condition, int port);//��ȡ�����û���Ϣ
	bool validateUser(const char* inputUsername, const char* inputPassword, int port);//�����˻������������ݿ���Ϣ���бȶԣ����������¼

	static UserManager* GetInstance()
	{
		static UserManager UesrManager;
		return &UesrManager;
	}

private:
	MYSQL* con;
	const char* host = "127.0.0.1";
	const char* user = "root";
	const char* pw = "55555";
	const char* database_name = "itemsql";
	const int port = 3306;
};

