/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node*newHead=NULL,*curr=head,*prev=NULL;
        unordered_map<Node*,Node*>mp;
        mp[NULL]=NULL;
        while(curr)
        {
            Node*NewNode=new Node(curr->val);
            if(!newHead)
            {
                newHead=NewNode;
                prev=NewNode;
            }
            else
            {
                prev->next=NewNode;
                prev=NewNode;
            }
            mp[curr]=prev;
            curr=curr->next;
        }
        prev=newHead,curr=head;
        while(curr)
        {
            prev->random=mp[curr->random];
            curr=curr->next;
            prev=prev->next;
        }
        return newHead;
    }
};