//#include<iostream>
//#include<vector>
//#include "UserManager.h"
//using namespace std;
//
//
//class Room {
//public:
//    int id;
//    string type;
//    bool isOccupied;
//};
//
//class Hotel {
//public:
//    string name;
//    vector<Room> rooms;
//
//    void addRoom(Room room) {
//        rooms.push_back(room);
//    }
//
//    Room* findAvailableRoom(string roomType) {
//        for (auto& room : rooms) {
//            if (room.type == roomType && !room.isOccupied) {
//                return &room;
//            }
//        }
//        return nullptr;
//    }
//
//    void displayRooms() {
//        cout << "Rooms in " << name << ":" << endl;
//        for (const auto& room : rooms) {
//            cout << "Room ID: " << room.id << ", Type: " << room.type << ", Occupied: " << (room.isOccupied ? "Yes" : "No") << endl;
//        }
//    }
//};
//
//
//
//int main() {
//    Hotel hotel;
//    hotel.name = "My Hotel";
//
//    // ���10�����˼�
//    for (int i = 101; i <= 120; i++) {
//        Room room;
//        room.id = i;
//        room.type = "��׼���˼�";
//        room.isOccupied = false;
//        hotel.addRoom(room);
//    }
//
//    // ���20���󴲷�
//    for (int i = 201; i <= 220; i++) {
//        Room room;
//        room.id = i;
//        room.type = "�󴲷�";
//        room.isOccupied = false;
//        hotel.addRoom(room);
//    }
//
//    // ���20��˫����
//    for (int i = 221; i <= 240; i++) {
//        Room room;
//        room.id = i;
//        room.type = "˫����";
//        room.isOccupied = false;
//        hotel.addRoom(room);
//    }
//
//    // ���10�����˼�
//    for (int i = 301; i <= 340; i++) {
//        Room room;
//        room.id = i;
//        room.type = "��׼���˼�";
//        room.isOccupied = false;
//        hotel.addRoom(room);
//    }
//
//    hotel.displayRooms();
//
//    string roomType;
//    cout << "Enter room type: ";
//    cin >> roomType;
//
//    Room* availableRoom = hotel.findAvailableRoom(roomType);
//
//    if (availableRoom) {
//        cout << "Room allocated. Room ID: " << availableRoom->id << endl;
//        availableRoom->isOccupied = true;
//    }
//    else {
//        cout << "No available room of type " << roomType << endl;
//    }
//
//    //hotel.displayRooms();
//
//};