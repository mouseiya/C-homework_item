//#include "HotelManager.h"
//
//int main()
//{
//	Hotel hotel;
//	hotel.hotel_id = 1;
//	strcpy_s(hotel.hotel_name, sizeof(hotel.hotel_name), "My hotel");
//	hotel.user_assess = 8;
//	hotel.spare_room = 60;
//
//	HotelManager::GetInstance()->insert_hotel(hotel);
//
//	vector<Hotel> hotels= HotelManager::GetInstance()->get_hotels();
//
//	for (auto& htl : hotels)
//	{
//		cout << htl.hotel_id << " " << htl.hotel_name << " " << htl.user_assess << " " << htl.spare_room << endl;
//	}
//
//	return 0;
//}