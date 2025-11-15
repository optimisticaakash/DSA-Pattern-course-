//link : https://neetcode.io/problems/lowest-common-ancestor-of-a-binary-tree-iii?list=neetcode250

//Approach1 : brute force - storing all ancestor nodes of a given node , then find the first common node

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*> st;

        while(p != NULL){
            st.insert(p);
            p=p->parent;
        }

        while(q != NULL){
            if(st.find(q) != st.end()){
                return q;
            }
            q = q->parent;
        }

        return NULL;//ispr kbhi ayega hi nhi bcz p and q exist in tree
    }
};

//T.C : O(N)
//S.C : O(N)


//Approach2 : using linkedlist traversal method to find intersection
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* p1 = p;
        Node* q1 = q;

        while(p1 != q1){

            p1 = (p1 != NULL) ? p1->parent : q;
            q1 = (q1 != NULL) ? q1->parent : p;
        }

        return p1;
    }
};

//T.C : O(N)
//S.C : O(1)
