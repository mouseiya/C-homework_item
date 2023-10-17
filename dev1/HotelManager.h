#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct Hotel
{
	int hotel_id;
	char hotel_name[30];
	int user_assess;
	int spare_room;
} Hotel;



class HotelManager
{
public:
	HotelManager();
	~HotelManager();

	

public:
	bool Insert_hotel(Hotel& htl, int port);//传入一个Hotel对象，插入进hotel_table中
	bool Update_hotel(Hotel& htl, int port);//传入一个Hotel对象，根据id更新数据
	bool Delete_hotel(int id, int port);//传入一个hotel_id，删除在hotel_table中的信息
	vector<Hotel> Get_hotels(string condition , int port);//传入一个空字符串，获取所有hotel的信息
	vector<Hotel> Get_hotel(int id, int port);//获取某一个hotel的信息

	bool insert_hotel(Hotel& htl, int port);//传入一个Hotel对象，插入进hotel_table中
	bool update_hotel(Hotel& htl, int port);//传入一个Hotel对象，根据id更新数据
	bool delete_hotel(int id, int port);//传入一个hotel_id，删除在hotel_table中的信息
	vector<Hotel> get_hotels(string condition, int port);//传入一个空字符串，获取所有hotel的信息
	vector<Hotel> get_hotel(int id, int port);//获取某一个hotel的信息

	//用于数据库连接
	static HotelManager* GetInstance()
	{
		static HotelManager HotelManager;
		return &HotelManager;
	}

private:
	MYSQL* con;
	const char* host = "127.0.0.1";
	const char* user = "root";
	const char* pw = "55555";
	const char* database_name = "itemsql";
	const int port = 3306;
};

