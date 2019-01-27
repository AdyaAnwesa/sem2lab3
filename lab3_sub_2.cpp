/*
Implement Circular Linked List using C++. Make sure the following functions are implemented: 
insert(int data) - Adds a new element to the end of the linked list. 
insertAt(int pos, int data) - It includes the position at which the insertion happens. Positioning starts with 1.  
Example: insertAt(1, 3) - inserts 3 at the first position. 
    It should print a statement “Linked List does not have that many elements” if the position does not exist in the linked list.   
delete() - Deletes the element at the end of the list. 
deleteAt(int pos) - Deletes the element(or node) at the position pos)
countItems() - Returns the number of items in the linked list. 
display() - Displays all the elements in the linked list. Format should be followed as “1 -> 2 -> 3 -> 4 ” for a linked list holding integers in the order 1,2,3,4. 
*/

#include <iostream>
using namespace std;

class Node{
    	public:
    	//Data
    	int data;
    	//Pointer to the next Node
    	Node *ptr;
    	//Constructor to make ptr to null
    	Node(){
        	ptr=NULL;
    	}
};

class LinkedList{
    	public:

    	//Head-> circle type ptr
    	Node *head;
    	Node *tail;
    	//Constructor
    	LinkedList(){	
        	head=NULL;
        	tail=NULL;
    	}
    	//Circle inside linked with each other
    	//Rules how circle will be linked
    	//Insertion
    	void insert(int value){
        	//1st Node is added
        	Node *temp=new Node();
        	//Insert data in node
        	temp->data=value;
        	if(head==NULL){
            		//1st node only
            		this->head=temp;
        	}
        	else{
        		//Any other node
        		tail->ptr=temp;
        	}
        
        	this->tail=temp;
        	tail->ptr=head;
        
    	}

    	//Insert at 
    	void InsertAt(int pos,int data){
        	//Count numbers
        	int count=0;
        	Node *current=head;
        	for(int i=0;current->ptr!=head;i++){
            		count++;
            		current=current->ptr;
        	}
        	count++;
        	//Put conditionon pos
        	if(pos>0 && pos<=count){
            		//If position is 1st position
            		if(pos==1){
                		Node *current=head;
                		Node *kitty=new Node();
                		kitty->data=data;
                		kitty->ptr=current;
                		head=kitty;
                		tail->ptr=head;
            		}
            		else{
                		//Reach the place before pos
                		Node *current=head;
                		int i=1;
                		while(i<pos-1){
                   			i++;
                   			current=current->ptr;
                		}
                		//Create the node
                		Node *kitty=new Node();
                		kitty->data=data;
                		kitty->ptr=current->ptr;
                		current->ptr=kitty;
            		}
        	}
        	else{
            		cout<<pos<<" is invalid position"<<endl;
        	}
    	}
    
    	//Deletion of last element
    	void delet(){
        	//store tail in temp
        	Node *temp=tail;
        	//before tail has to point to NULL
         	Node *current=head;
        	while(current->ptr!=tail){
            		current=current->ptr;
        	}
        	current->ptr=head;
        	//update tail
        	tail=current;
        	//delete temp
        	delete temp;
        
    	}

    	//count items
    	int countItems(){
        	Node *current=head;
        	int length=0;
        	while(current->ptr!=head){
            		length++;
            		current=current->ptr;
        	}
        	length++;
        	return length;
    	}

    	//Delete at position
    	void deleteAt(int pos){
        	//Count numbers
        	int count=0;
        	Node *current=head;
        	for(int i=0;current->ptr!=head;i++){
            		count++;
            		current=current->ptr;
        	}
        	count++;
        	//Put condition for position
        	if(pos>0 && pos<=count){
            		//If pos is 1st position
            		if(pos==1){
                		Node *temp=head;
                		head=temp->ptr;
                		//temp->ptr=NULL;
                		tail->ptr=head;
                		delete temp;
            		}
            		else{
                		//Reach the place before pos
                		Node *current=head;
                		int i=1;
                		while(i<pos-1){
                   			i++;
                   			current=current->ptr;
                		}
                		//copy the node to be deleted
                		Node *temp=current->ptr;
                		//Pointer of the node before pos will point to the node after pos 
                		current->ptr=(current->ptr)->ptr;
                		//temp->ptr=NULL;
                		delete temp;
            		}
        	}
        	else{
            		cout<<pos<<" is invalid position"<<endl;
        	}
    	}

    	//Display
    	void display(){
        	Node *current=head;
        	while(current->ptr!=head){
            		cout<<current->data<<"->";
			//Move to next node
            		current=current->ptr;
        	}
        	cout<<current->data<<endl;
    	}
};

int main(){
    	//Object of the class
    	LinkedList l1;
    	//Enter values
    	for(int i=1;i<5;i++){
        	l1.insert(i);
    	}

    	//Displaying output
    	cout<<"Normal Display is"<<endl;
    	l1.display();
    	cout<<"The number of items before deletion="<<l1.countItems()<<endl;
    	cout<<endl;
    
    	cout<<"Display after deletion is"<<endl;
	//use of delete
    	l1.delet();
    	l1.display();
    	cout<<"The number of items after deletion="<<l1.countItems()<<endl;
    	cout<<endl;
    
    	cout<<"Display after insert at particular position: valid example 1 is"<<endl;
    	//use of insert at
	l1.InsertAt(1,88);
    	l1.display();
    	cout<<"The number of items after insertion at position="<<l1.countItems()<<endl;
    	cout<<endl;
    
    	cout<<"Display after insert at particular position: invalid example 1 is"<<endl;
    	//use of insert at
	l1.InsertAt(-2,88);
    	l1.display();
    	cout<<"The number of items after insertion at position="<<l1.countItems()<<endl;
    	cout<<endl;
    
    	cout<<"Display after insert at particular position: invalid example 1 is"<<endl;
    	//use of insert at
	l1.InsertAt(88,88);
    	l1.display();
    	cout<<"The number of items after insertion at position="<<l1.countItems()<<endl;
    	cout<<endl;
    
    	cout<<"Display after insert at particular position: valid example 2 is"<<endl;
    	//use of insert at
	l1.InsertAt(2,5);
    	l1.display();
    	cout<<"The number of items after insertion at position="<<l1.countItems()<<endl;
    	cout<<endl;
    
    	cout<<"Display after delete at particular position: valid example 1 is"<<endl;
    	//use of deleteAt
	l1.deleteAt(1);
    	l1.display();
    	cout<<"The number of items after delete at position="<<l1.countItems()<<endl;
    	cout<<endl;
    
    	cout<<"Display after delete at particular position: invalid example 1 is"<<endl;
    	//use of deleteAt
	l1.deleteAt(-1);
    	l1.display();
    	cout<<"The number of items after delete at position="<<l1.countItems()<<endl;
    	cout<<endl;
    
    	cout<<"Display after delete at particular position: invalid example 2 is"<<endl;
    	//use of deleteAt
	l1.deleteAt(8998);
    	l1.display();
    	cout<<"The number of items after delete at position="<<l1.countItems()<<endl;
    	cout<<endl;
    
    	cout<<"Display after delete at particular position: valid example 2 is"<<endl;
    	//use of deleteAt
	l1.deleteAt(3);
    	l1.display();
    	cout<<"The number of items after delete at position="<<l1.countItems()<<endl;
    
    	return 2;
}
