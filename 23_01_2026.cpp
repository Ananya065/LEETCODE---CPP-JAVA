/*
 * LOGIC EXPLANATION:
 * 1. Efficient Tracking: We use a doubly linked list to store the values. 
 * This allows us to merge neighbors in O(1) time.
 * 2. Min-Heap (Set): We store pairs as {sum, leftmost_id} in a std::set. 
 * The set naturally keeps the minimum sum at the top and breaks ties 
 * using the lower ID (leftmost).
 * 3. Lazy Merging: When we merge two nodes, we remove their old neighbor 
 * pairs from the set and insert new ones.
 * 4. Termination: We maintain a count of 'inverted' pairs (where a > b). 
 * When this count hits zero, the array is sorted.
 */

struct Node {
    long long val;
    int id;
    Node *prev = nullptr, *next = nullptr;
};

class Solution {
public:
    int minimumPairRemoval(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        std::set<std::pair<long long, int>> pq; 
        std::vector<Node*> nodes(n);
        int invertedCount = 0;

        for (int i = 0; i < n; ++i) {
            nodes[i] = new Node{ (long long)nums[i], i };
            if (i > 0) {
                nodes[i]->prev = nodes[i - 1];
                nodes[i - 1]->next = nodes[i];
                pq.insert({ nodes[i-1]->val + nodes[i]->val, nodes[i-1]->id });
                if (nodes[i-1]->val > nodes[i]->val) invertedCount++;
            }
        }

        int operations = 0;
        while (invertedCount > 0 && !pq.empty()) {
            
            auto it = pq.begin();
            long long s = it->first;
            int leftId = it->second;
            pq.erase(it);

            Node* left = nodes[leftId];
            Node* right = left->next;

           
            if (left->prev && left->prev->val > left->val) invertedCount--;
            if (left->val > right->val) invertedCount--;
            if (right->next && right->val > right->next->val) invertedCount--;

            
            if (left->prev) pq.erase({ left->prev->val + left->val, left->prev->id });
            if (right->next) pq.erase({ right->val + right->next->val, right->id });

            
            left->val = s;
            left->next = right->next;
            if (right->next) right->next->prev = left;

            
            if (left->prev && left->prev->val > left->val) invertedCount++;
            if (left->next && left->val > left->next->val) invertedCount++;

            
            if (left->prev) pq.insert({ left->prev->val + left->val, left->prev->id });
            if (left->next) pq.insert({ left->val + left->next->val, left->id });

            operations++;
        }

        return operations;
    }
};
