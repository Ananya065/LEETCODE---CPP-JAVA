class Solution {
public:
    bool asteroidsDestroyed(int mass, std::vector<int>& asteroids) {
   
        std::sort(asteroids.begin(), asteroids.end());
        
        
        long long current_mass = mass;
        
        for (int asteroid : asteroids) {
            if (current_mass < asteroid) {
                return false;
            }
            current_mass += asteroid;
        }
        
        return true;
    }
};
