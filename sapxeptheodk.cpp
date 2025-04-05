#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Room {
    int roomNumber; // Số phòng
    char building;  // Nhà (A-Z)
    int capacity;   // Khả năng chứa
};
void sortByCapacity(vector<Room>& rooms) {
    sort(rooms.begin(), rooms.end(), [](const Room& a, const Room& b) {
        return a.capacity > b.capacity;
    });
}
void sortByBuildingAndRoom(vector<Room>& rooms) {
    sort(rooms.begin(), rooms.end(), [](const Room& a, const Room& b) {
        if (a.building == b.building) return a.roomNumber < b.roomNumber;
        return a.building < b.building;
    });
}

void sortByBuildingAndCapacity(vector<Room>& rooms) {
    sort(rooms.begin(), rooms.end(), [](const Room& a, const Room& b) {
        if (a.building == b.building) return a.capacity > b.capacity;
        return a.building < b.building;
    });
}

int main() {
    vector<Room> rooms = {{101, 'A', 50}, {102, 'B', 100}, {103, 'A', 30}};

    sortByCapacity(rooms);
    cout << "Sap xep theo kha nang chua giam dan:\n";
    for (const Room& room : rooms) {
        cout << "Phong " << room.roomNumber << " (Nha " << room.building << "): " << room.capacity << "\n";
    }

    sortByBuildingAndRoom(rooms);
    cout << "Sap xep theo nha va so phong tang dan:\n";
    for (const Room& room : rooms) {
        cout << "Phong " << room.roomNumber << " (Nha " << room.building << "): " << room.capacity << "\n";
    }

    sortByBuildingAndCapacity(rooms);
    cout << "Sap xep theo nha tang dan va kha nang chua giam dan:\n";
    for (const Room& room : rooms) {
        cout << "Phong " << room.roomNumber << " (Nha " << room.building << "): " << room.capacity << "\n";
    }

    return 0;
}
