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
        Node*Dummy=new Node(0);
        Node*ptr=Dummy;
        unordered_map<Node*,Node*>mp;
        Node*temp=head;
        while(temp)
        {
            ptr->next=new Node(temp->val);
            ptr=ptr->next;
            mp[temp]=ptr;
            temp=temp->next;
        }
        temp=head;
        ptr=Dummy->next;
        while(temp)
        {
            ptr->random=mp[temp->random];
            ptr=ptr->next;
            temp=temp->next;
        }
        return Dummy->next;
    }
};