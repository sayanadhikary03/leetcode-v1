class Solution {
public:
    // Custom comparator to order the min-heap by node value
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap to store the active head nodes of the lists
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        
        // Push the head of each non-empty linked list into the heap
        for (ListNode* head : lists) {
            if (head != nullptr) {
                minHeap.push(head);
            }
        }
        
        // Dummy node acts as the placeholder start of our merged list
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        
        // Process the heap until it is empty
        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();
            
            // Append the smallest node to our result list
            tail->next = smallest;
            tail = tail->next;
            
            // If the popped node has a next node, push it into the heap
            if (smallest->next != nullptr) {
                minHeap.push(smallest->next);
            }
        }
        
        ListNode* result = dummy->next;
        delete dummy; // Free the allocated memory for the dummy node
        return result;
    }
};