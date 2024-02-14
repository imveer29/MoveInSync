#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
// User Authentication
class UserManager
{
public:
    bool authenticateUser(const string &username, const string &password)
    {
        const string adminUsername = "Chandraveer";
        const string adminPassword = "30024092";

        if (username == adminUsername && password == adminPassword)
        {
            cout << "Authentication successful." << endl;
            return true;
        }
        else
        {
            cout << "Authentication failed. Invalid username or password." << endl;
            return false;
        }
    }
};

class MeetingRoomAllocator
{
private:
    vector<int> roomCapacities;

public:
    MeetingRoomAllocator(vector<int> &capacities) : roomCapacities(capacities)
    {
        // Ensure room capacities are sorted for binary search
        sort(roomCapacities.begin(), roomCapacities.end());
    }
    int findRoom(int requiredCapacity)
    {
        int low = 0, high = roomCapacities.size() - 1;
        int ans = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (roomCapacities[mid] >= requiredCapacity)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
    int allocateMeetingRoom(int requiredCapacity)
    {
        // Use binary search to find the nearest or equal capacity room
        int idx = findRoom(requiredCapacity);

        // Check if a suitable room is found
        if (idx != -1)
        {
            return roomCapacities[idx];
        }
        else
        {
            return -1; // Indicate no suitable room found
        }
    }
};

int main()
{
    // Sample usage
    UserManager userManager;

    // Authenticate admin
    string name, password;
    cout << "Enter Name: ";
    cin >> name;
    cout << endl;
    cout << "Enter Password: ";
    cin >> password;
    if (userManager.authenticateUser(name, password))
    {
        // Admin uploads floor plan
        vector<int> roomCapacities = {83, 72, 45, 33, 25, 73, 18, 60, 16, 38, 43, 53, 84, 44, 99, 89, 43, 4, 29, 25, 45, 19, 33, 7, 60, 31, 28, 50, 100, 10, 97, 69, 67, 76, 63, 84, 31, 57, 33, 35, 94, 20, 73, 45, 50, 54, 18, 71, 71, 93};
        MeetingRoomAllocator allocator(roomCapacities);

        // Run queries
        cout << "Enter number of meeting: ";
        int number_of_meetings;
        cin >> number_of_meetings;
        for (int i = 0; i < number_of_meetings; ++i)
        {
            int requiredCapacity;
            cout << "Enter required meeting room capacity: ";
            cin >> requiredCapacity;

            int allocatedCapacity = allocator.allocateMeetingRoom(requiredCapacity);
            if (allocatedCapacity != -1)
            {
                cout << "Meeting room allocated with capacity: " << allocatedCapacity << endl;
            }
            else
            {
                cout << "No suitable meeting room found." << endl;
            }
        }
    }

    return 0;
}
