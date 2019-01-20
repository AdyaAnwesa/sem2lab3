//Implementation of Doubly Linked List using C++

#include <iostream>
using namespace std;

class Node{
    	public:
    	//Data
    	int data;
   	 //Pointer to the next Node and previous Node
    	Node *pointer;
    	Node *previous;
    	//Constructor to make pointer and previous to null
    	Node(){
        	pointer=NULL;
       		previous=NULL;
    	}
};

class LinkedList{
    	public:

    	//Head-> circle type pointer
    	Node *head;
    	Node *tail;
    	//Constructor
    	LinkedList(){
        	head=NULL;
        	tail=NULL;
    	}
    	//Circles inside linked with each other
    	//Rules how circles will be linked

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
        	temp->previous=tail;
        	tail->pointer=temp;
        	}
        
        	this->tail=temp;
        
    	}

    	//Insert at 
    	void InsertAt(int pos,int data){
        	//Count numbers
        	int count=0;
        	Node *current=head;
        	for(int i=0;current!=NULL;i++){
           		count++;
            		current=current->pointer;
        	}

        	//Put condition position	
        	if(pos>0 && pos<=count){

            		//If position is 1st position
            		if(pos==1){
                		Node *current=head;
                		Node *kitty=new Node();
                		kitty->data=data;
                		kitty->pointer=current;
                		current->previous=kitty;
                		head=kitty;
            		}
            		else{
                		//Reach the place before pos
                		Node *current=head;
                		int i=1;
                		while(i<pos-1){
                  			i++;
                   			current=current->pointer;
                		}
	
                		//Create the node
                		Node *kitty=new Node();
                		kitty->data=data;
                		kitty->pointer=current->pointer;
                		current->pointer=kitty;
                		kitty->pointer->previous=kitty;
                		kitty->previous=current;
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
        //first tail has to point to NULL
         Node *current=head;
        while(current->pointer!=tail){
            	current=current->pointer;
        }
        current->pointer=NULL;
        temp->previous=NULL;
        //update tail
        tail=current;
        //delete temp
        delete temp;
    	}

    	//count items
    	int countItems(){
        	Node *current=head;
        	int length=0;
        	while(current!=NULL){
            		length++;
            		current=current->pointer;
        	}
        return length;
    	}

    	//Delete at position
    	void deleteAt(int pos){
        	//Count numbers
        	int count=0;
        	Node *current=head;
       		for(int i=0;current!=NULL;i++){
            		count++;
            		current=current->pointer;
        	}

        	//Condition for position
        	if(pos>0 && pos<=count){
            		//If pos is 1st position
            		if(pos==1){
                		Node *temp=head;
                		head=head->pointer;
                		temp->pointer=NULL;
                		head->previous=NULL;
                		delete temp;
            		}
            		else{
                		//Reach the place before pos
                		Node *current=head;
               			int i=1;
                		while(i<pos-1){
                   			i++;
                   			current=current->pointer;
                		}
                		//copy the node to be deleted
                		Node *temp=current->pointer;
                		current->pointer->pointer->previous=current;
                		current->pointer=current->pointer->pointer;
                		temp->pointer=NULL;
                		temp->previous=NULL;
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
        	Node *last;
        	while(current!=NULL){
            		cout<<current->data<<"->";
            		last=current;
			//Move to next node	
            		current=current->pointer; 
            
        	}
        	cout<<"NULL"<<endl;
        	cout<<endl;
        	cout << "Print in Reverse order : "<<endl;
        	while(last!=NULL){
            		cout <<last->data<< "->";
            		// Move backwards 
            		last = last->previous;
        	}
        	cout <<"NULL"<< endl;
    	}

};

int main(){
    	//Object of the class
    	LinkedList l1;
    	//Enter values
    	for(int i=1;i<6;i++){
        	l1.insert(i);
    	}

    	//Displaying output
    	cout<<"Initial Display is"<<endl;
    	l1.display();
    	cout<<"The number of items before deletion="<<l1.countItems()<<endl;
    	cout<<endl;
    
    	cout<<"Display after deletion of last element is"<<endl;
	//use of delete
    	l1.delet();
    	l1.display();
    	cout<<"The number of items after deletion="<<l1.countItems()<<endl;
    	cout<<endl;
    
    	cout<<"Display after insertion at particular position(valid example-1) is"<<endl;
	//use of insert at
    	l1.InsertAt(1,88);
    	l1.display();
    	cout<<"The number of items after insertion at position="<<l1.countItems()<<endl;
    	cout<<endl;
    
    	cout<<"Display after insertion at particular position(invalid example-1) is"<<endl;
	//use of insert at
    	l1.InsertAt(-2,88);
    	l1.display();
    	cout<<"The number of items after insertion at position="<<l1.countItems()<<endl;
    	cout<<endl;
    
    	cout<<"Display after insertion at particular position(invalid example-2) is"<<endl;
	//use of insert at
    	l1.InsertAt(88,88);
    	l1.display();
    	cout<<"The number of items after insertion at position="<<l1.countItems()<<endl;
    	cout<<endl;
    
    	cout<<"Display after insertion at particular position(valid example-2) is"<<endl;
    	//use of insert at
	l1.InsertAt(2,5);
    	l1.display();
    	cout<<"The number of items after insertion at position="<<l1.countItems()<<endl;
    	cout<<endl;
    
    	cout<<"Display after deletion at particular position(valid example-1) is"<<endl;
	//use of delete At
    	l1.deleteAt(1);
    	l1.display();
    	cout<<"The number of items after delete at position="<<l1.countItems()<<endl;
    	cout<<endl;
    
    	cout<<"Display after insertion at particular position(invalid example-1) is"<<endl;
	//use of delete At
    	l1.deleteAt(-1);
    	l1.display();
    	cout<<"The number of items after delete at position="<<l1.countItems()<<endl;
    	cout<<endl;
    
    	cout<<"Display after insertion at particular position(invalid example-2) is"<<endl;
	//use of delete At
    	l1.deleteAt(8998);
    	l1.display();
    	cout<<"The number of items after delete at position="<<l1.countItems()<<endl;
    	cout<<endl;
    
    	cout<<"Display after deletion at particular position(valid example-2) is"<<endl;
	//use of delete At
    	l1.deleteAt(4);
    	l1.display();
    	cout<<"The number of items after delete at position="<<l1.countItems()<<endl;
    	cout<<endl;
    
    return 3;
}

