
#include <iostream>
#include <vector>

using namespace std;

class Position
{
    private:
        /* data */
        int x, y;

    public:
        
        Position(int x = 0,int y =0): x(x), y(y){};
        bool operator(Position other){
            return (x == other.x && y == other.y);
        }
};

class NavigationSystem{
    // Properties
    parkingMap:     // Map of Parkinglot, 0 stand for free, 1 stand for having car
    currentPos:    // Current Position on Map
    // Method
    calculateRoute( Position targetPoss) // Calculate the current position to target Position
    guideMovement( Position targetPoss)      // Export the route from current Position to target Position
    setCurrentPosition( Position pos)       // Set new current position
    getCurrentPosition( Position pos)       // Get current position
};  

int main(int argc, char const *argv[]){

    std::vector<std::vector<int> map = {
        {0, 0, 1},
        {0, 1, 0},
        {1, 0, 0}
    }
    return 0;
}