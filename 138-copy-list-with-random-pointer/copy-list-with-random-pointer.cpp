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
        Node*Dummy=new Node(-1);
        Dummy->next=head;
        Node*temp=head;
        while(temp)
        {
            Node*NewNode=new Node(temp->val);
            NewNode->next=temp->next;
            temp->next=NewNode;
            temp=NewNode->next;
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
        Node*tail=Dummy;
        temp=head;
        while(temp)
        {
            tail->next=temp->next;
            tail=tail->next;
            temp->next=tail->next;
            temp=temp->next;
        }
       return Dummy->next;
    }
};