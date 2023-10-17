#include "RoomManager.h"
#include "HotelManager.h"

int main()
{
	Room rm1;
	rm1.hotel_id = 2;
	rm1.room_id = 301;
	rm1.is_occupied = true;

	RoomManager::GetInstance()->insert_room(rm1, 3306);
	vector<Hotel> hotels = HotelManager::GetInstance()->get_hotel(1, 3306);

	for (auto& htl : hotels)
	{
		cout << htl.hotel_id << " " << htl.hotel_name << " " << htl.spare_room << " " << htl.spare_room << " " << htl.user_assess << endl;
	}

	cout << "Rooms :" << endl;

	vector<Room> rooms =  RoomManager::GetInstance()->get_rooms(2, 3306);

	for (auto& rm : rooms)
	{
		cout << rm.room_id << " " << rm.hotel_id << " " << rm.is_occupied << endl;
	}

	return 0;
}