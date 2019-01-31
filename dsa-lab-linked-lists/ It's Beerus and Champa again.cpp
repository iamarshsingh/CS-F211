/*
    Problem Setter: Samarth Jain
    Solution of: Arshdeep Singh
    Github Link: https://github.com/iamarshsingh/CS-F211
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

// ||START EDITING||
/*
 * Complete the 'combineList' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST head1
 *  2. INTEGER_SINGLY_LINKED_LIST head2
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* combineList(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* head = NULL;
    
    if(head1==NULL && head2==NULL){
        return head;
    }
    if(head1==NULL){
        SinglyLinkedListNode* curr2 = head2;
        SinglyLinkedListNode* beh2 = NULL;
        SinglyLinkedListNode* next2 = head2->next;
        SinglyLinkedListNode* node2;

        while(curr2!=NULL){
            
            if(next2==NULL){
                curr2->next = beh2;
                node2 = curr2;
                break;
            }
            
            curr2->next = beh2;
            beh2 =curr2;
            curr2 = next2;
            next2 = next2->next;
            
        }
        
        return node2;
    }
    if(head2==NULL){
        return head1;
    }
    
    SinglyLinkedListNode* curr = head1;
    head = curr;
    SinglyLinkedListNode* node1 = head1->next;
    SinglyLinkedListNode* curr2 = head2;
    SinglyLinkedListNode* beh2 = NULL;
    SinglyLinkedListNode* next2 = head2->next;
    SinglyLinkedListNode* node2;

    while(curr2!=NULL){

        if(next2==NULL){
            curr2->next = beh2;
            node2 = curr2;
            break;
        }

        curr2->next = beh2;
        beh2 =curr2;
        curr2 = next2;
        next2 = next2->next;

    }
    /*
    while(node1!=NULL){
        cout<<node1->data<<" ";
        node1=node1->next;
    }
    while(node2!=NULL){
        cout<<node2->data<<" ";
        node2=node2->next;
    }
    */
    while(node1!=NULL || node2!=NULL){
        if(node2!=NULL){
            curr->next = node2;
            curr = curr->next;
            node2 = node2->next;
        }
        if(node1!=NULL){
            curr->next = node1;
            curr = curr->next;
            node1 = node1->next;
        }
    }
    return head;
}

// ||END EDITING||

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    SinglyLinkedList* head1 = new SinglyLinkedList();

    string head1_count_temp;
    getline(cin, head1_count_temp);

    int head1_count = stoi(ltrim(rtrim(head1_count_temp)));

    for (int i = 0; i < head1_count; i++) {
        string head1_item_temp;
        getline(cin, head1_item_temp);

        int head1_item = stoi(ltrim(rtrim(head1_item_temp)));

        head1->insert_node(head1_item);
    }

    SinglyLinkedList* head2 = new SinglyLinkedList();

    string head2_count_temp;
    getline(cin, head2_count_temp);

    int head2_count = stoi(ltrim(rtrim(head2_count_temp)));

    for (int i = 0; i < head2_count; i++) {
        string head2_item_temp;
        getline(cin, head2_item_temp);

        int head2_item = stoi(ltrim(rtrim(head2_item_temp)));

        head2->insert_node(head2_item);
    }

    SinglyLinkedListNode* answer = combineList(head1->head, head2->head);

    print_singly_linked_list(answer, " ", fout);
    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
