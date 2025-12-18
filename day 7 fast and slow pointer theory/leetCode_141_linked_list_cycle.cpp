//approach1 : using unordered_set
class Solution {
public:
    //bruteforce
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> map;

        ListNode* temp = head;

        while( temp != NULL){
            if(map.count(temp)){//mtlb ye node already visited hai
                return true;
            }

            map.insert(temp);

            temp = temp->next; 
        }

        //endtk pahuch gye koi cycle nhi 
        return false;
    }
};

//T.C : O(N);
//S.C : O(N);


//Approach 2 : using slow fast pointer (flyod algortthm)
class Solution {
public:
    //optimised
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow=slow->next;
            fast=fast->next->next;

            if(slow!= NULL && slow == fast){
                return true;
            }
        }

        return false;
    }
};
//T.C : O(N)
//S.C :O(1)
