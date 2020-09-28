//This is a simpleprogram that creates a single linked list //It makes use of some of the object oriented programming techniques #include using namespace std;

//------------------------------Node Structure--------------------------------------// struct node{//structure of the node int data; struct node * next;//reference to the struct node itself };

//------------------------------linked list class--------------------------------------// class linked_list{// structure for the link list that will contain the functions for // creation, traversal, and delition. private: node *head,*tail;//set the structs for the head and tail public: linked_list();//constructor

void create_node(int n);//node creation method
void display();//data display method

void insertFront(int n);//insertion of a node on the front method
void insertMid(int pos, int n);
int nodecntr();

void delteAtBegi();//delition at head
void deleteAtEnd();//delition at the end
void deleteAtMid(int pos);

node* gethead();//get hed method

static void concentrate(node* a, node* b);//linked list combination method
};

//----------------------------methodes definition------------------------------------//

void linked_list::deleteAtMid(int pos){//deletion in a middle position

node *temp, *prev;
int nodcntr, cntr =1;

nodcntr = nodecntr();

if(nodcntr == 0){
    cout<<"\nLiked list is empty"<<endl;
    return;
}else if (pos > 1 && pos < nodcntr){
    temp = head;
    prev = head;
    while(cntr<pos){
        
        prev = temp;
        temp = temp->next;
        cntr++;
        
    }
    prev->next = temp->next;
    delete temp;
    cout<<"\nNode deleted at position "<<pos<<endl;
    return;
}else{
    
    cout<<"\nNode not in the middle"<<endl;
    return;
}
}

void linked_list::deleteAtEnd(){//deletion at the end of the list

if(head == NULL){
    cout<<"\nError: Empty linked list"<<endl;
    return;
}

node *prev, *temp;
prev = head;
temp = head;

while(temp->next != NULL){
    prev = temp;
    temp = temp->next;
}

prev->next=NULL;
cout<<"\nNode deleted"<<endl;
}

void linked_list::delteAtBegi(){ node *temp;

if(head == NULL){
    cout << "\nError: Linked List Empty"<<endl;
    return;
}
temp = head;
head = head->next;
delete temp;
cout<<"\nNode deleted"<<endl;
}

void linked_list::insertMid(int pos, int n){//inserts node in a middle position (position, data)

node *newnode, *temp, *prev;
int nodcntr, cntr =1;


newnode = new node;
newnode->data = n;

nodcntr = nodecntr();

if(nodcntr == 0){
    cout<<"\nLiked list is empty"<<endl;
    return;
}else if (pos > 1 && pos < nodcntr){
    temp = head;
    prev = head;
    while(cntr<pos){
        
        prev = temp;
        temp = temp->next;
        cntr++;
        
    }
    prev->next = newnode;
    newnode->next = temp;
    return;
}else{
    
    cout<<"\nNode not in the middle"<<endl;
    return;
}
}

int linked_list::nodecntr(){//counts the total number of nodes on the list

int count = 0;

node* temp = head;

if(head == NULL){
    return 0;
}
while(temp->next != NULL){
    
    count++;
    temp = temp->next;
}


return count;
}

void linked_list::insertFront(int n){//creates a temp node and links it to the head then,sets tmp as head

node* tmp = new node;
tmp->data=n;
tmp->next=head;
head = tmp;
}

linked_list::linked_list(){//set the head of the node to null atuomatically head=NULL; tail=NULL; }

void linked_list::create_node(int n){//create node function definition

node *tmp = new node;
tmp->data = n;
tmp->next = NULL;

if (head == NULL){//creates initial node
    
    head = tmp;
    tail = tmp;
}else{//adds a node to the tail
    
    tail->next = tmp;
    tail = tail->next;
}

cout<<"Node created"<<endl;
}

void linked_list::display(){

int count =1;
node* tmp; //creates a temporary node that will traverse the list
tmp = head;//set the addesss to the head of the list
if(tmp == NULL){//fail-safe in case the list is empty
    cout<<"\nThe list is empty"<<endl;
    return;
}
cout << "\n";
while(tmp != NULL){//the while loop will traverse the list
    
    cout <<"pos#"<<count<<": "<<tmp->data <<endl;//displays the data
    tmp = tmp->next;//moves to the next node
    count++;
}
}

node * linked_list:: gethead(){ return head; }

void linked_list::concentrate(node* a, node* b){

if(a != NULL && b!=NULL){
    if (a->next == NULL){
        a->next = b;
    }else{
        concentrate(a->next, b);
    }
}else{
    cout<<"\na or b is null"<<endl;
        
    }
    
}
//-------------------------------------Main Function------------------------------------------------// int main (){

linked_list a;//new linked list

a.create_node(1);//creates a node with data 1
a.create_node(2);//creates  node with data 2

a.display();//display method call

linked_list b;

for(int n = 0; n <= 10; n++){//creates 10 nodes
    
    b.create_node(n);//insert n
    
}

b.display();//display linked list b

linked_list::concentrate(a.gethead(),b.gethead());//concentrates a and b into one

a.display();//displays the concentration

a.insertMid(6, 13);//insertion into pos #6
a.display();
a.delteAtBegi();
a.deleteAtEnd();
a.display();//displays a again
a.deleteAtMid(6);
a.display();


linked_list c;
c.create_node(1);
c.create_node(2);
c.create_node(3);
c.create_node(4);

c.display();

c.deleteAtMid(2);

c.display();


return 0;
}
