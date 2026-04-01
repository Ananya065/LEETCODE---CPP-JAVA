using namespace std;

struct Robot {
    int id;
    int pos;
    int health;
    char dir;
};

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<Robot> robots(n);
        for (int i = 0; i < n; ++i) {
            robots[i] = {i, positions[i], healths[i], directions[i]};
        }

        sort(robots.begin(), robots.end(), [](const Robot& a, const Robot& b) {
            return a.pos < b.pos;
        });

        vector<Robot> stack;
        for (auto& curr : robots) {
            if (curr.dir == 'R') {
                stack.push_back(curr);
            } else {
                while (!stack.empty() && stack.back().dir == 'R' && curr.health > 0) {
                    if (stack.back().health < curr.health) {
                        stack.pop_back();
                        curr.health -= 1;
                    } else if (stack.back().health > curr.health) {
                        stack.back().health -= 1;
                        curr.health = 0;
                    } else {
                        stack.pop_back();
                        curr.health = 0;
                    }
                }
                if (curr.health > 0) {
                    stack.push_back(curr);
                }
            }
        }

        sort(stack.begin(), stack.end(), [](const Robot& a, const Robot& b) {
            return a.id < b.id;
        });

        vector<int> result;
        for (const auto& r : stack) {
            result.push_back(r.health);
        }
        return result;
    }
};
