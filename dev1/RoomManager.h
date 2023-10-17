#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct Room
{
	int room_id;
	int hotel_id;
	bool is_occupied;
} Room;



class RoomManager
{
public:
	RoomManager();
	~RoomManager();

public:
	bool Insert_room(Room& rm, int port);//插入一个对象
	bool Update_room(Room& rm, int port);//根据id，更新对象
	bool Delete_room(int hotel_id,int room_id, int port);//删除某个hotel_id的某一个room_id房间
	vector<Room> Get_rooms(int hotel_id, int port);//获取所有的房间信息
	vector<Room> Get_room(int hotel_id,int room_id, int port);//获取某一家hotel的信息

	bool insert_room(Room& rm, int port);//插入一个对象
	bool update_room(Room& rm, int port);//根据id，更新对象
	bool delete_room(int hotel_id, int room_id, int port);//删除某个hotel_id的某一个room_id房间
	vector<Room> get_rooms(int hotel_id, int port);//获取所有的房间信息
	vector<Room> get_room(int hotel_id, int room_id, int port);//获取某一家hotel的信息

	static RoomManager* GetInstance()
	{
		static RoomManager RoomManager;
		return &RoomManager;
	}

private:
	MYSQL* con;
	const char* host = "127.0.0.1";
	const char* user = "root";
	const char* pw = "55555";
	const char* database_name = "itemsql";
	const int port = 3306;
};
