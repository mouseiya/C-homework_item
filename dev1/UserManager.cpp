#include "UserManager.h"


UserManager::UserManager()
{
	con = mysql_init(NULL);

	mysql_options(con, MYSQL_SET_CHARSET_NAME, "GBK");

    if (!mysql_real_connect(con, host, user, pw, database_name, port, NULL, 0))
    {
        std::cout << "Failed to connect." << std::endl;
        exit(0);
    }
}

UserManager::~UserManager()
{
    mysql_close(con);
}

//传入一个User对象，插入到user_table中
bool UserManager::Insert_user(User& u, int port)
{
    MYSQL* con = mysql_init(NULL);
    if (!mysql_real_connect(con, host, user, pw, database_name, port, NULL, 0))
    {
        fprintf(stderr, "Failed to connect to MySQL server : Error:%s\n", mysql_error(con));
        return false;
    }

    vector<User> users = Get_users("WHERE id = " + to_string(u.id), 3306);
    
    if (!users.empty())
    {
        //cout << "Error: User with the same id already exists." << endl;
        return false;
    }

    char sql[10000];
    sprintf_s(sql, sizeof(sql), "insert into user_table ( id, account, password) values (%d, '%s', '%s')", u.id, u.account, u.password);
    if (mysql_query(con, sql))
    {
        fprintf(stderr, "Failed to insert data : Error:%s\n", mysql_error(con));
        return false;
    }

    return true;
}

//传入一个User对象，更具id更新数据
bool UserManager::Update_user(User& u, int port)
{
    MYSQL* con = mysql_init(NULL);
    if (!mysql_real_connect(con, host, user, pw, database_name, port, NULL, 0))
    {
        fprintf(stderr, "Failed to connect to MySQL server : Error:%s\n", mysql_error(con));
        return false;
    }

    char sql[10000];
    sprintf_s(sql, sizeof(sql), "UPDATE user_table SET account = '%s', password = '%s' "
        "where id = %d", u.account, u.password, u.id);

    if (mysql_query(con, sql))
    {
        fprintf(stderr, "Failed to update data : Error:%s\n", mysql_error(con));
        return false;
    }

    return true;
}

//传入一个id，删除数据
bool UserManager::Delete_user(int id, int port)
{
    MYSQL* con = mysql_init(NULL);
    if (!mysql_real_connect(con, host, user, pw, database_name, port, NULL, 0))
    {
        fprintf(stderr, "Failed to connect to MySQL server : Error:%s\n", mysql_error(con));
        return false;
    }

    vector<User> users = Get_users("WHERE id = " + to_string(id), 3306);
    if (users.empty())
    {
        //cout << "Error: User with the specified id does not exist." << endl;
        return false;
    }
    
    char sql[10000];
    sprintf_s(sql, sizeof(sql), "DELETE FROM user_table WHERE id = %d", id);

    if (mysql_query(con, sql))
    {
        fprintf(stderr, "Failed to delete data : Error:%s\n", mysql_error(con));
        return false;
    }

    return true;
}

//获取所有用户信息
vector<User> UserManager::Get_users(string condition, int port)
{
    MYSQL* con = mysql_init(NULL);
    if (!mysql_real_connect(con, host, user, pw, database_name, port, NULL, 0))
    {
        fprintf(stderr, "Failed to connect to MySQL server : Error:%s\n", mysql_error(con));
        return vector<User>();
    }

    vector<User> userlist;

    char sql[10000];
    sprintf_s(sql, sizeof(sql), "SELECT * FROM user_table %s", condition.c_str());

    if (mysql_query(con, sql))
    {
        fprintf(stderr, "Failed to select data : Error:%s\n", mysql_error(con));
    }

    MYSQL_RES* res = mysql_store_result(con);

    MYSQL_ROW row;

    while ((row = mysql_fetch_row(res)))
    {
        User user;
        user.id = atoi(row[0]);
        strcpy_s(user.account, sizeof(user.account), row[1]);
        strcpy_s(user.password, sizeof(user.password), row[2]);
        userlist.push_back(user);
    }

    mysql_free_result(res); // 释放结果集资源

    //if (!userlist.size()) cout << "No user information is avilable" << endl;

    return userlist;
}

//传入账户和密码与数据库信息进行比对，用于密码登录
bool UserManager::ValidateUser(const char* inputUsername, const char* inputPassword, int port)
{
    MYSQL* con = mysql_init(NULL);
    if (!mysql_real_connect(con, host, user, pw, database_name, port, NULL, 0))
    {
        fprintf(stderr, "Failed to connect to MySQL server : Error:%s\n", mysql_error(con));
        return false;
    }

    vector<User> users = UserManager::GetInstance()->Get_users("WHERE account = '" + string(inputUsername) + "'", 3306);
    if (users.empty()) {
        cout << "用户名或密码错误，请重试！" << endl;
        return false;
    }

    User user = users[0];
    if (strcmp(user.password, inputPassword) == 0) {
        cout << "登录成功！欢迎回来，" << inputUsername << "！" << endl;
        return true;
    }
    else {
        cout << "用户名或密码错误，请重试！" << endl;
        return false;
    }
}

bool UserManager::insert_user(User& u, int port)
{
    return GetInstance()->insert_user(u, 3306);
}

bool UserManager::update_user(User& u, int port)
{
    return GetInstance()->update_user(u, 3306);
}

bool UserManager::delete_user(int id, int port)
{
    return GetInstance()->delete_user(id, 3306);
}

vector<User> UserManager::get_users(string condition, int port)
{
    return GetInstance()->get_users(condition, 3306);
}

bool UserManager::validateUser(const char* inputUsername, const char* inputPassword, int port)
{
    return GetInstance()->validateUser(inputUsername, inputPassword, 3306);
}



        

