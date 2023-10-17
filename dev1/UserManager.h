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
	bool Insert_user(User& u, int port);//传入一个User对象，插入到user_table中
	bool Update_user(User& u, int port);//传入一个User对象，更具id更新数据
	bool Delete_user(int id, int port);//传入一个id，删除数据
	vector<User> Get_users(string condition, int port);//获取所有用户信息
	bool ValidateUser(const char* inputUsername, const char* inputPassword, int port);//传入账户和密码与数据库信息进行比对，用于密码登录
	
	bool insert_user(User& u, int port);//传入一个User对象，插入到user_table中
	bool update_user(User& u, int port);//传入一个User对象，更具id更新数据
	bool delete_user(int id, int port);//传入一个id，删除数据
	vector<User> get_users(string condition, int port);//获取所有用户信息
	bool validateUser(const char* inputUsername, const char* inputPassword, int port);//传入账户和密码与数据库信息进行比对，用于密码登录

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

