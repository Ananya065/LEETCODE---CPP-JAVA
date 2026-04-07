class Robot {
private:
    int w, h, total;
    int pos = 0;
    bool moved = false;

public:
    Robot(int width, int height) {
        w = width;
        h = height;
        total = 2 * (w - 1) + 2 * (h - 1);
    }
    
    void step(int num) {
        moved = true;
        pos = (pos + num) % total;
    }
    
    vector<int> getPos() {
        if (pos < w) return {pos, 0}; 
        if (pos < w + h - 1) return {w - 1, pos - (w - 1)}; 
        if (pos < 2 * w + h - 2) return {w - 1 - (pos - (w + h - 2)), h - 1}; 
        return {0, h - 1 - (pos - (2 * w + h - 3))}; 
    }
    
    string getDir() {
        if (!moved) return "East";
        
        if (pos == 0) return "South";
        
        if (pos < w) return "East";
        if (pos < w + h - 1) return "North";
        if (pos < 2 * w + h - 2) return "West";
        return "South";
    }
};
