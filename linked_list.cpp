#include "linked_list.h"
#include <iostream>


LinkedList::LinkedList(){
    this->head = nullptr;
    this->size = 0;


}


LinkedList::LinkedList(int data){
    this->head = new Node(data);
    this->head->next = nullptr; // Set the next pointer of the head to nullptr
    this->size = 1;
}


LinkedList::LinkedList(std::vector<int> vec){
    this->head = new Node(vec[0]);// item zero in vecotr is the head
        Node* temp = this->head; // creates a temp and sets in to head

        for(long unsigned int i = 1; i < vec.size(); i++) // loops though the vecotrs length
        {
            temp->next = new Node(vec[i]); // creates a new node in the following place
            temp = temp->next; //sets temp to next temp

        }

    this->size = vec.size(); // size of linked list equals size of vector
}

LinkedList::~LinkedList(){
    this -> head = nullptr;
    this -> size = 0;

}


void LinkedList::push_front(int data){
    Node* newNode = new Node(data);
    if (this -> head  == nullptr)
    {
        head = new Node(data);
    }
    else
    {
        
        newNode -> next = head;
         head = newNode;

    }
    size ++;
    
    /*
Node* newNode = new Node(data);
    
    // If the list is empty, make the new node the head
    if (head == nullptr) {
        head = newNode;
    } else {
        // Make the new node point to the current head
        newNode->next = head;
        
        // Update the head to point to the new node
        head = newNode;
    }
    
    // Incremen


    */

}

void LinkedList::push_back(int data){
    Node* temp = this->head;
Node* newNode =  new Node(data);

if (this->head == nullptr) 
{
    this->head = newNode;
} else
 {
    // Traverse the list to find the last node
    while (temp->next != nullptr)
     {
        temp = temp->next;
    }
    // Attach the new node to the last node
    temp->next = newNode;
}

size++;



}

void LinkedList::insert(int data, int idx){
    Node* temp = this->head;
    Node* current = new Node(data);
    int length = get_size();
    int tem = idx;
    if(this->head == nullptr)
     {
        this->head = new Node(data);
     }
    else if (idx == 0)
    {
        current -> next = head;
        head = current;

    }
    else if(idx >= length)
    {
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = current;
    }
    else 
    {
for ( int i = 1; i < tem; i++) {
    temp = temp->next;
}

// Insert current node after temp
current->next = temp->next;
temp->next = current;

    }
    this -> size++;
    

}

void LinkedList::remove(int data)
{
    Node* temp = this->head; // creates a temp which points to head
    Node* prev = nullptr; // creates a new node which points to nullptr

    // Search for the element in our list
    while(temp != nullptr && temp->data != data)// runs as long as temp is not nullptr and the data doesnt wqual the data we are looking for
    {
        prev = temp; // prev is set to temp
        temp = temp->next; // temp is set to the next node
    }


    if(temp != nullptr) // if the data is in the list
    {

        if(temp == this->head)// if the head is the thing that is wish to be deleted
        {
            this->head = temp->next; // head is set to next one after temp
        }
        else
        {
            prev->next = temp->next; // previous is set to temp
        }


        temp->next = nullptr; // the one after temp is set to nullptr
        delete temp; // temp is delelted

        this->size--; // size dreacese

// Node with the specified data not found

    /*
    Node* temp = this->head;
if (head->data == data) {
    // If the head node contains the data to be deleted
    head = head->next; // Update head to the next node
    delete temp; // Delete the original head node
    size--; // Decrease the size of the list
} else {
    while (temp->next != nullptr) {
        // Iterate through the list until the end
        if (temp->next->data == data) {
            // If the next node contains the data to be deleted
            Node* nodeToRemove = temp->next; // Store the node to be removed
            temp->next = temp->next->next; // Update the link to skip the node to be removed
            delete nodeToRemove; // Delete the node to be removed
            size--; // Decrease the size of the list
            break; // Exit the loop after deletion
        }
        temp = temp->next; // Move to the next node
    }
}

    */


    }
}


bool LinkedList::contains(int data)
{
    bool checker = false;
    Node* temp = this -> head; 
    
        while (temp != nullptr )
        {
            if(temp -> data == data)
            {
                checker = true;
                break;
            }
            temp = temp->next;

        }

        return checker;

}


int LinkedList::get_size(){
    return this->size;
}

// O(n)
std::string LinkedList::to_string(){
    std::string stringified;
    Node* tmp = this->head;

    while(tmp != nullptr){
        stringified += std::to_string(tmp->data) + " ";
        tmp = tmp->next;
    }

    return stringified;
}
