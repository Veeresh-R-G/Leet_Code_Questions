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
private:
    void print(Node* node){
        
        Node* t = node;

        while(t != nullptr){
            cout << t->val << " ";
            t = t->next;
        }
        cout << endl;
    }
public:
    Node* copyRandomList(Node* head) {
        
        //inserting the node 
        if(head == nullptr){
            return nullptr;
        }
        Node* temp = head;
        while(temp != nullptr){
            
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }

        temp = head;
        // print(temp);

        //Setting of the random pointers
        while(temp){

            if(temp->next){
                temp->next->random = temp->random ? temp->random->next : nullptr;
            }
            
            temp = temp->next->next;
        }

        Node* orig = head;
        Node* copy = head->next;
        Node* tempo = copy;

        while(orig && copy){
            orig->next = orig->next->next;
            copy->next = copy->next ? copy->next->next : nullptr;
            orig = orig->next;
            copy = copy->next;
        }


        return tempo;
    }
};