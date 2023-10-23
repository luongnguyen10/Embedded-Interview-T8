#include <iostream>
#include <vector>

using namespace std;

class Position {
public:
    int x, y;

    Position(int x = 0, int y = 0) : x(x), y(y) {}

    bool operator==(const Position& other) const {
        return (x == other.x && y == other.y);
    }
};

class NavigationSystem {
private:
    vector<vector<int>> parkingMap;
    Position currentPos;

public:
    NavigationSystem(const vector<vector<int>>& map) : parkingMap(map), currentPos(0, 0) {}

    void setCurrentPosition(const Position& pos) {
        currentPos = pos;
    }

    Position getCurrentPosition() const {
        return currentPos;
    }

    void calculateRoute(const Position& targetPos) {
        // Implement your route calculation logic here
        // You can use algorithms like A* or Dijkstra's to find the path
    }

    void guideMovement(const Position& targetPos) {
        // Implement the movement guidance logic here
        // This function should guide the car from the current position to the target position
    }
};

int main() {
    vector<vector<int>> map = {
        {0, 0, 1},
        {0, 1, 0},
        {1, 0, 0}
    };

    NavigationSystem navigation(map);

    Position initialPosition(0, 2); // Initial position of the car
    Position targetPosition; // Set your target position

    navigation.setCurrentPosition(initialPosition);
    navigation.calculateRoute(targetPosition);
    navigation.guideMovement(targetPosition);

    return 0;
}
