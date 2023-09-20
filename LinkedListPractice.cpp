#include<iostream>
#include<typeinfo>
using namespace std;
template <class T>
class Node
{
public:
    T data;
    Node* next;
};
template<class T>
Node<T>* create_node(T d)
{
    Node<T>* new_node=new Node<T>;
    new_node->data=d;
    new_node->next=NULL;
    return new_node;
}
template<class T>
class LinkedList{
   Node<T> *head;
   int length;
public:
   LinkedList(){
       head=NULL;
       length=0;
   }
   void prepend(T d){
       Node<T>* new_node=create_node(d);
     if(length==0){
         head=new_node;
     }
     else{
         new_node->next=head;
         head=new_node;
     }
     length++;
   }
   void append(T d){
       Node<T>* new_node=create_node(d);
       if(length==0){
           head=new_node;
       }
       else{
           Node<T>* current_node=head;
           while(current_node->next!=NULL){
               current_node=current_node->next;
           }
           current_node->next=new_node;
       }
       length++;
   }
   void insert(T d,int pos){
       Node<T>* new_node=create_node(d);
       if(pos>=length || pos<1){
           cout<<"Invalid position"<<endl;
       }
       else if(pos==1){
           if(length==0){
               head=new_node;
           }
           else{
               new_node->next=head;
               head=new_node;
           }
           length++;
       }
       else{
           int i=0;
           Node<T> *current_node=head;
           while(i<pos-2){
               current_node=current_node->next;
               i++;
           }
           Node<T>* temp_node=current_node->next;
           new_node->next=temp_node;
           current_node->next=new_node;
           length++;
       }

   }
   T remove(int pos){
       if(pos>length){
           cout<<"Invalid Position"<<endl;
           if(typeid(T)==typeid(string))
           {
               return '/0';
           }
           return (T)NULL;

       }
       else if(length==0){
           cout<<"Empty list"<<endl;
           if(typeid(T)==typeid(string))
           {
               return '/0';
           }
           return (T)NULL;
       }
       else if(pos==1){
           T d=head->data;
           Node<T> *temp_node=head->next;
           delete head;
           head=temp_node;
           length--;
           return d;
       }
       else{
           int i=0;
           Node<T> *current_node=head;
           while(i<pos-2){
               current_node=current_node->next;
               i++;
           }
           Node<T>* temp_node=current_node->next;
           T d=temp_node->data;
           current_node->next=temp_node->next;
           delete temp_node;
           length--;
           return d;
       }

   }
   void clear(){
       int i=length;
       while(i>0){
           remove(i);
           i--;
       }
   }
void reverse(){
       if(length==0){
           cout<<"Empty list"<<endl;
       }
       else{
           T A[length];
           Node<T>* current_node=head;
           int i=0;
           while(current_node!=NULL){
              A[i]=current_node->data;
              current_node=current_node->next;
              i++;
           }
           i--;
           current_node=head;
           while(current_node!=NULL){
               current_node->data=A[i];
               current_node=current_node->next;
               i--;
           }
       }
   }
   void sort(){
       if(length==0){
           cout<<"Empty list"<<endl;
       }
       else
       {
           T A[length+1];
           Node<T>* current_node=head;
           int i=0;
           while(current_node!=NULL){
               A[i]=current_node->data;
               current_node=current_node->next;
               i++;
           }
           for(i=0;i<length;i++){
           for(int j=i+1;j<length;j++){


               if(A[i]>A[j])
               {
                  T temp=A[i];
                  A[i]=A[j];
                  A[j]=temp;
               }
           }
           }
           current_node=head;
            i=0;
           while(current_node!=NULL){
               current_node->data=A[i];
               current_node=current_node->next;
               i++;
           }
       }
   }
    void print()
    {
        Node<T>* current_node=head;
        cout<<"[";
        while(current_node!=NULL)
        {
            if(current_node==head){
                cout<<current_node->data;
            }
            else{
                cout<<" "<<current_node->data;
            }
            current_node=current_node->next;

        }
        cout<<"]"<<endl;
    }
    ~LinkedList()
    {
        Node<T>* new_node=head;
        while(new_node!=NULL)
        {
            Node<T>* temp_node=new_node->next;
            delete new_node;
            new_node=temp_node;
        }
        delete new_node;

    }

};
int main(){
    LinkedList<int> ll;
    ll.print();
    for(int i=1;i<10;i++){
            ll.append(i*i+4*i-6*i*i*i);


           // ll.prepend(i);

    }
    ll.print();
    ll.insert(10,10);
    ll.print();
    ll.remove(5);
    ll.print();
    ll.sort();
    ll.print();
    ll.reverse();
    ll.print();
    ll.clear();
    ll.print();

}
