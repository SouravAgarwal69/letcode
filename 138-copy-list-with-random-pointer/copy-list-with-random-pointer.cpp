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
        Node*dummy=new Node(-1);
        Node*tail=dummy;
        Node*temp=head;
        unordered_map<Node*,Node*>mp;
        while(temp)
        {
           Node*newNode=new Node(temp->val);
           tail->next=newNode;
           tail=newNode;
           mp[temp]=newNode;
           temp=temp->next;
        }
        Node*ptr=dummy->next;
        temp=head;
        while(ptr)
        {
            ptr->random=mp[temp->random];
            ptr=ptr->next;
            temp=temp->next;
        }
        return dummy->next;
    }
};