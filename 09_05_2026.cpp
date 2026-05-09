class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int layers = min(m, n) / 2;

        for (int l = 0; l < layers; ++l) {
            vector<int> layerElements;
            
            for (int j = l; j < n - l; ++j) layerElements.push_back(grid[l][j]);
            for (int i = l + 1; i < m - l; ++i) layerElements.push_back(grid[i][n - 1 - l]);
            for (int j = n - 2 - l; j >= l; --j) layerElements.push_back(grid[m - 1 - l][j]);
            for (int i = m - 2 - l; i > l; --i) layerElements.push_back(grid[i][l]);

            int size = layerElements.size();
            int shift = k % size;
            
            if (shift == 0) continue;

            vector<int> rotated(size);
            for (int i = 0; i < size; ++i) {
                rotated[i] = layerElements[(i + shift) % size];
            }

            int idx = 0;
            for (int j = l; j < n - l; ++j) grid[l][j] = rotated[idx++];
            for (int i = l + 1; i < m - l; ++i) grid[i][n - 1 - l] = rotated[idx++];
            for (int j = n - 2 - l; j >= l; --j) grid[m - 1 - l][j] = rotated[idx++];
            for (int i = m - 2 - l; i > l; --i) grid[i][l] = rotated[idx++];
        }

        return grid;
    }
};
