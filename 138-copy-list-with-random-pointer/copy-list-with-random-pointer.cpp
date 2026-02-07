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
        if(!head)
        {
            return head;
        }
        Node*temp=head;
        while(temp)
        {
            Node*forward=temp->next;
            Node*copy=new Node(temp->val);
            temp->next=copy;
            copy->next=forward;
            temp=forward;
        }
        temp=head;
        while(temp)
        {
           if(temp->random)
           {
             temp->next->random=temp->random->next;
           }
           temp=temp->next->next;
        }
        temp=head;
        Node*copyHead=temp->next;
        Node*copy=temp->next;
        while(temp)
        {
            temp->next=temp->next->next;
            if(copy->next)
            {
            copy->next=copy->next->next;
            }
            temp=temp->next;
            copy=copy->next;
        }
        return copyHead;
    }
};