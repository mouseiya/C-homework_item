#include "RoomManager.h"

RoomManager::RoomManager()
{
    con = mysql_init(NULL);

    mysql_options(con, MYSQL_SET_CHARSET_NAME, "GBK");

    if (!mysql_real_connect(con, host, user, pw, database_name, port, NULL, 0))
    {
        std::cout << "Failed to connect." << std::endl;
        exit(0);
    }
}

RoomManager::~RoomManager()
{
    mysql_close(con);
}

//插入一个对象
bool RoomManager::Insert_room(Room& rm, int port)
{
    MYSQL* con = mysql_init(NULL);
    if (!mysql_real_connect(con, host, user, pw, database_name, port, NULL, 0))
    {
        fprintf(stderr, "Failed to connect to MySQL server11111 : Error:%s\n", mysql_error(con));
        return false;
    }

    vector<Room> rooms = Get_room(rm.hotel_id, rm.room_id, 3306);

    if (!rooms.empty())
    {
        cout << "Error: Room with the same id already exists." << endl;
        return false;
    }

    char sql[10000];
    sprintf_s(sql, sizeof(sql), "insert into room_table (hotel_id, room_id, is_occupied) values (%d, %d, %d)", rm.hotel_id, rm.room_id, rm.is_occupied);
    if (mysql_query(con, sql))
    {
        fprintf(stderr, "Failed to insert data : Error:%s\n", mysql_error(con));
        return false;
    }

    return true;
}

//根据id，更新对象
bool RoomManager::Update_room(Room& rm, int port)
{
    MYSQL* con = mysql_init(NULL);
    if (!mysql_real_connect(con, host, user, pw, database_name, port, NULL, 0))
    {
        fprintf(stderr, "Failed to connect to MySQL server22222 : Error:%s\n", mysql_error(con));
        return false;
    }

    vector<Room> rooms = Get_room(rm.hotel_id, rm.room_id, 3306);

    if (rooms.empty())
    {
        cout << "Error: Room with the specified id does not exist." << endl;
        return false;
    }

    char sql[10000];
    sprintf_s(sql, sizeof(sql), "UPDATE room_table SET is_occupied = %d "
        "where hotel_id = %d and room_id = %d ", rm.is_occupied, rm.hotel_id, rm.room_id);

    if (mysql_query(con, sql))
    {
        fprintf(stderr, "Failed to update data : Error:%s\n", mysql_error(con));
        return false;
    }
    return true;
}

//删除某个hotel_id的某一个room_id房间
bool RoomManager::Delete_room(int hotel_id, int room_id,int port)
{
    MYSQL* con = mysql_init(NULL);
    if (!mysql_real_connect(con, host, user, pw, database_name, port, NULL, 0))
    {
        fprintf(stderr, "Failed to connect to MySQL server33333 : Error:%s\n", mysql_error(con));
        return false;
    }

    vector<Room> rooms = Get_room(hotel_id, room_id, 3306);

    if (rooms.empty())
    {
        cout << "Error: Room with the specified id does not exist." << endl;
        return false;
    }

    char sql[10000];
    sprintf_s(sql, sizeof(sql), "DELETE FROM room_table WHERE hotel_id = %d and room_id = %d", hotel_id, room_id);

    if (mysql_query(con, sql))
    {
        fprintf(stderr, "Failed to delete data : Error:%s\n", mysql_error(con));
        return false;
    }

    return true;
}

//获取所有的房间信息
vector<Room> RoomManager::Get_rooms(int hotel_id, int port)
{
    MYSQL* con = mysql_init(NULL);
    if (!mysql_real_connect(con, host, user, pw, database_name, port, NULL, 0))
    {
        fprintf(stderr, "Failed to connect to MySQL server44444 : Error:%s\n", mysql_error(con));
        return vector<Room>();
    }

    vector<Room> roomlist;

    char sql[1000];
    sprintf_s(sql, sizeof(sql), "SELECT * FROM room_table WHERE hotel_id = %d", hotel_id);

    if (mysql_query(con, sql))
    {
        fprintf(stderr, "Failed to select data : Error:%s\n", mysql_error(con));
    }

    MYSQL_RES* res = mysql_store_result(con);

    MYSQL_ROW row;

    while ((row = mysql_fetch_row(res)))
    {
        Room rm;
        rm.room_id = atoi(row[0]);
        rm.hotel_id = atoi(row[1]);
        rm.is_occupied = atoi(row[2]);
        roomlist.push_back(rm);
    }

    mysql_free_result(res); // 释放结果集资源

    //if (!roomlist.size()) cout << "No room information is available" << endl;

    return roomlist;
}

//获取某一家hotel的信息
vector<Room> RoomManager::Get_room(int hotel_id, int room_id, int port) 
{
    MYSQL* con = mysql_init(NULL);
    if (!mysql_real_connect(con, host, user, pw, database_name, port, NULL, 0))
    {
        fprintf(stderr, "Failed to connect to MySQL server55555 : Error:%s\n", mysql_error(con));
        return vector<Room>();
    }

    vector<Room> room_list;

    string query = "SELECT * FROM room_table WHERE hotel_id = " + to_string(hotel_id) + " AND room_id = " + to_string(room_id);

    if (mysql_query(con, query.c_str())) {
        cout << "Error: Failed to select data from room_table." << endl;
        return room_list;
    }

    MYSQL_RES* result = mysql_store_result(con);
    if (result == NULL) {
        cout << "Error: Failed to get result from room_table." << endl;
        return room_list;
    }

    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        Room rm;
        rm.hotel_id = atoi(row[0]);
        rm.room_id = atoi(row[1]);
        rm.is_occupied = atoi(row[2]);
        room_list.push_back(rm);
    }

    mysql_free_result(result);

    return room_list;
}

bool RoomManager::insert_room(Room& rm, int port)
{
    return GetInstance()->insert_room(rm, 3306);
}

bool RoomManager::update_room(Room& rm, int port)
{
    return GetInstance()->update_room(rm, 3306);
}

bool RoomManager::delete_room(int hotel_id, int room_id, int port)
{
    return GetInstance()->delete_room(hotel_id, room_id, 3306);
}

vector<Room> RoomManager::get_rooms(int hotel_id, int port)
{
    return GetInstance()->get_rooms(hotel_id, 3306);
}

vector<Room> RoomManager::get_room(int hotel_id, int room_id, int port)
{
    return GetInstance()->get_room(hotel_id, room_id, 3306);
}
