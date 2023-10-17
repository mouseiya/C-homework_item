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
	bool Insert_room(Room& rm, int port);//����һ������
	bool Update_room(Room& rm, int port);//����id�����¶���
	bool Delete_room(int hotel_id,int room_id, int port);//ɾ��ĳ��hotel_id��ĳһ��room_id����
	vector<Room> Get_rooms(int hotel_id, int port);//��ȡ���еķ�����Ϣ
	vector<Room> Get_room(int hotel_id,int room_id, int port);//��ȡĳһ��hotel����Ϣ

	bool insert_room(Room& rm, int port);//����һ������
	bool update_room(Room& rm, int port);//����id�����¶���
	bool delete_room(int hotel_id, int room_id, int port);//ɾ��ĳ��hotel_id��ĳһ��room_id����
	vector<Room> get_rooms(int hotel_id, int port);//��ȡ���еķ�����Ϣ
	vector<Room> get_room(int hotel_id, int room_id, int port);//��ȡĳһ��hotel����Ϣ

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
