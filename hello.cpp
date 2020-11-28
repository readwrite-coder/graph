#include <iostream>
using namespace std;

class node{
public:
node(int val);
node* prev;
node* next;
node* toRight;
node* toLeft;
bool leaf;
int value;
};
node::node(int val){
value = val;
prev = NULL;
next = NULL;
}
class linkedList{
public:
linkedList();
bool add(int item);
//bool insert(int item, int loc);

node* head;
node* tail;
};
linkedList::linkedList(){
head = NULL;
tail = NULL;
}
bool linkedList::add(int item){
if(head == NULL){
node* new_node = new node(item);
head = new_node;
tail = new_node;
return true;
}
if(tail == NULL){
node* new_node = new node(item);
tail = new_node;
head->next = tail;
tail->prev = head;
return true;
}
node* new_node = new node(item);
tail->next = new_node;
new_node->prev = tail;
tail = new_node;
return true;
}
 

class graph{
public:
graph();
int getNumVertices();
int getNumEdges();
bool add(int vertexBegin, int vertexEnd, int edgeWeight);
bool remove(node* vertexBegin, node* vertexEnd); 
int getEdgeWeight(node* vertexBegin, node* vertexEnd);
void viewNeighbors(int vertex);
linkedList* vertices; 
int capacity;
int numItems;
};
graph::graph(){
int capacity = 7;
numItems = 0;
vertices = new linkedList[capacity];
}
int graph::getNumVertices(){
return numItems;
}
bool graph::add(int vertexBegin, int vertexEnd, int edgeWeight){
//check if the 2 vertices exist
linkedList myList;
myList.add(vertexBegin);
myList.add(vertexEnd);
vertices[numItems] = myList;
numItems++;
return true;
}
void graph::viewNeighbors(int vertex){
cout<<"Here"<<endl;

for(int i = 0; i < numItems; i++){
if(vertices[i].head->value == vertex){
cout<<"Here"<<endl;
node* temp = vertices[i].head;
while(temp->next != NULL){
cout<< temp->value <<endl;
temp = temp->next;
}
break;
}
}
return;
}

int main(){
cout<<"Hello world"<<endl;
linkedList myList;
for(int i = 0; i < 100; i++){
myList.add(i);
}
graph myGraph;
myGraph.add(1,33,10);
myGraph.add(37,47,10);
myGraph.viewNeighbors(37);
cout<<"Done."<<endl;
return 0;
}

