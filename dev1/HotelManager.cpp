#include "HotelManager.h"

HotelManager::HotelManager()
{
    con = mysql_init(NULL);

    mysql_options(con, MYSQL_SET_CHARSET_NAME, "GBK");

    if (!mysql_real_connect(con, host, user, pw, database_name, port, NULL, 0))
    {
        std::cout << "Failed to connect." << std::endl;
        exit(0);
    }
}

HotelManager::~HotelManager()
{
    mysql_close(con);
}

//传入一个Hotel对象，插入进hotel_table中
bool HotelManager::Insert_hotel(Hotel& htl, int port)
{
    MYSQL* con = mysql_init(NULL);
    if (!mysql_real_connect(con, host, user, pw, database_name, port, NULL, 0))
    {
        fprintf(stderr, "Failed to connect to MySQL server : Error:%s\n", mysql_error(con));
        return false;
    }

    vector<Hotel> Hotels = Get_hotels("WHERE hotel_id = " + to_string(htl.hotel_id), 3306);

    if (!Hotels.empty())
    {
        cout << "Error: Hotel with the same id already exists." << endl;
        return false;
    }

    char sql[10000];
    sprintf_s(sql, sizeof(sql), "insert into hotel_table ( hotel_id, hotel_name, user_assess, spare_room) values (%d, '%s', %d, %d)", htl.hotel_id, htl.hotel_name, htl.user_assess, htl.spare_room);
    if (mysql_query(con, sql))
    {
        fprintf(stderr, "Failed to insert data : Error:%s\n", mysql_error(con));
        return false;
    }

    return true;
}

//传入一个Hotel对象，根据id更新数据
bool HotelManager::Update_hotel(Hotel& htl, int port)
{
    MYSQL* con = mysql_init(NULL);
    if (!mysql_real_connect(con, host, user, pw, database_name, port, NULL, 0))
    {
        fprintf(stderr, "Failed to connect to MySQL server : Error:%s\n", mysql_error(con));
        return false;
    }

    vector<Hotel> hotels = Get_hotels("WHERE hotel_id = " + to_string(htl.hotel_id), 3306);
    if (hotels.empty())
    {
        cout << "Error: Hotel with the specified id does not exist." << endl;
        return false;
    }

    char sql[10000];
    sprintf_s(sql, sizeof(sql), "UPDATE hotel_table SET hotel_name = '%s', user_assess = %d, spare_room = %d "
        "where hotel_id = %d", htl.hotel_name, htl.user_assess, htl.spare_room, htl.hotel_id);

    if (mysql_query(con, sql))
    {
        fprintf(stderr, "Failed to update data : Error:%s\n", mysql_error(con));
        return false;
    }

    return true;
}

//传入一个hotel_id，删除在hotel_table中的信息
bool HotelManager::Delete_hotel(int id, int port)
{
    MYSQL* con = mysql_init(NULL);
    if (!mysql_real_connect(con, host, user, pw, database_name, port, NULL, 0))
    {
        fprintf(stderr, "Failed to connect to MySQL server : Error:%s\n", mysql_error(con));
        return false;
    }

    vector<Hotel> hotels = Get_hotels("WHERE hotel_id = " + to_string(id), 3306);
    if (hotels.empty())
    {
        cout << "Error: Hotel with the specified id does not exist." << endl;
        return false;
    }

    char sql[10000];
    sprintf_s(sql, sizeof(sql), "DELETE FROM hotel_table WHERE hotel_id = %d", id);

    if (mysql_query(con, sql))
    {
        fprintf(stderr, "Failed to delete data : Error:%s\n", mysql_error(con));
        return false;
    }

    return false;
}

//获取所有hotel的信息
vector<Hotel> HotelManager::Get_hotels(string condition, int port)
{
    MYSQL* con = mysql_init(NULL);
    if (!mysql_real_connect(con, host, user, pw, database_name, port, NULL, 0))
    {
        fprintf(stderr, "Failed to connect to MySQL server : Error:%s\n", mysql_error(con));
        return vector<Hotel>();
    }

    vector<Hotel> hotellist;

    char sql[1000];
    sprintf_s(sql, sizeof(sql), "SELECT * FROM hotel_table %s", condition.c_str());

    if (mysql_query(con, sql))
    {
        fprintf(stderr, "Failed to select data : Error:%s\n", mysql_error(con));
    }

    MYSQL_RES* res = mysql_store_result(con);

    MYSQL_ROW row;

    while ((row = mysql_fetch_row(res)))
    {
        Hotel htl;
        htl.hotel_id = atoi(row[0]);
        strcpy_s(htl.hotel_name, sizeof(htl.hotel_name), row[1]);
        htl.user_assess = atoi(row[2]);
        htl.spare_room = atoi(row[3]);
        hotellist.push_back(htl);
    }

    mysql_free_result(res); // 释放结果集资源

    //if (!hotellist.size()) cout << "No hotel information is available" << endl;

    return hotellist;
}


//获取某一个hotel的信息
vector<Hotel> HotelManager::Get_hotel(int id, int port)
{
    MYSQL* con = mysql_init(NULL);
    if (!mysql_real_connect(con, host, user, pw, database_name, port, NULL, 0))
    {
        fprintf(stderr, "Failed to connect to MySQL server : Error:%s\n", mysql_error(con));
        return vector<Hotel>();
    }

    vector<Hotel> hotel;

    char sql[1000];
    sprintf_s(sql, sizeof(sql), "SELECT * FROM hotel_table WHERE hotel_id = %d", id);

    if (mysql_query(con, sql))
    {
        fprintf(stderr, "Failed to select data : Error:%s\n", mysql_error(con));
        return hotel;
    }

    MYSQL_RES* res = mysql_store_result(con);

    MYSQL_ROW row;

    while ((row = mysql_fetch_row(res)))
    {
        Hotel htl;
        htl.hotel_id = atoi(row[0]);
        strcpy_s(htl.hotel_name, sizeof(htl.hotel_name), row[1]);
        htl.user_assess = atoi(row[2]);
        htl.spare_room = atoi(row[3]);
        hotel.push_back(htl);
    }

    mysql_free_result(res); // 释放结果集资源

    //if (!hotellist.size()) cout << "No hotel information is available" << endl;

    return hotel;
}

bool HotelManager::insert_hotel(Hotel& htl, int port)
{
    return GetInstance()->insert_hotel(htl, 3306);
}

bool HotelManager::update_hotel(Hotel& htl, int port)
{
    return GetInstance()->update_hotel(htl, 3306);
}

bool HotelManager::delete_hotel(int id, int port)
{
    return GetInstance()->delete_hotel(id, 3306);
}

vector<Hotel> HotelManager::get_hotels(string condition, int port)
{
    return GetInstance()->get_hotels(condition, 3306);
}

vector<Hotel> HotelManager::get_hotel(int id, int port)
{
    return GetInstance()->get_hotel(id, 3306);
}

