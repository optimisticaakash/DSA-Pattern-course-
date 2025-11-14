//Brute force
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dNode = new ListNode(0);
        dNode->next = head;
        int cnt = 0;
        ListNode* currNode = head;
        while(currNode != NULL){
            cnt++;
            currNode=currNode->next;
        }
        //0 1 2 3 4 5.   n = 2 ,d = 5 - 2 = 3
        //      p c

        int d = cnt - n;
        ListNode* prevNode = dNode;
        currNode = head;
        while(d--){//loop ke end me curr whan hoga jo node delete hona hai
            currNode=currNode->next;
            prevNode=prevNode->next;
        }

        prevNode->next = currNode->next;
        delete currNode;

        return dNode->next;
    }
};

//T.C : O(2N)

//optimal approach using two pointer
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dNode = new ListNode(0);
        dNode->next = head;
        int cnt = 0;
        ListNode* currNode = head;

        while(currNode != NULL && cnt < n){//currNode ko n nodes aage bhej diya
            cnt++;
            currNode=currNode->next;
        }
     
        ListNode* prevNode = dNode;
        ListNode* delNode = head;
        
        while(currNode != NULL){
            currNode=currNode->next;
            delNode=delNode->next;
            prevNode=prevNode->next;
        }

        prevNode->next = delNode->next;
        delete delNode;

        return dNode->next;
    }
};
