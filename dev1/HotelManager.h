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
	bool Insert_hotel(Hotel& htl, int port);//����һ��Hotel���󣬲����hotel_table��
	bool Update_hotel(Hotel& htl, int port);//����һ��Hotel���󣬸���id��������
	bool Delete_hotel(int id, int port);//����һ��hotel_id��ɾ����hotel_table�е���Ϣ
	vector<Hotel> Get_hotels(string condition , int port);//����һ�����ַ�������ȡ����hotel����Ϣ
	vector<Hotel> Get_hotel(int id, int port);//��ȡĳһ��hotel����Ϣ

	bool insert_hotel(Hotel& htl, int port);//����һ��Hotel���󣬲����hotel_table��
	bool update_hotel(Hotel& htl, int port);//����һ��Hotel���󣬸���id��������
	bool delete_hotel(int id, int port);//����һ��hotel_id��ɾ����hotel_table�е���Ϣ
	vector<Hotel> get_hotels(string condition, int port);//����һ�����ַ�������ȡ����hotel����Ϣ
	vector<Hotel> get_hotel(int id, int port);//��ȡĳһ��hotel����Ϣ

	//�������ݿ�����
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

