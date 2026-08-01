#include <vector>
#include <map>
#include <cmath>

using namespace std;

class CountSquares {
private:
    map<pair<int, int>, int> points;

public:
    CountSquares() {}
    
    void add(vector<int> point) {
        points[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int px = point[0];
        int py = point[1];
        int res = 0;

        for (const auto& [p, c] : points) {
            int x = p.first;
            int y = p.second;

            if (x == px || abs(x - px) != abs(y - py)) {
                continue;
            }

            auto itA = points.find({px, y});
            auto itB = points.find({x, py});

            if (itA != points.end() && itB != points.end()) {
                res += c * itA->second * itB->second;
            }
        }

        return res;
    }
};