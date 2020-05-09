//Singly Linked List 


//Refer for following functions
//1.find mid using fast and slow
//2. take input
//3. take input better
//4. insert node
//5. insert node recursively
//6. delete node
//7. delete node recursively
//8. delete specific node (not the tail)
//9. remove all nodes with a partical values
//10. insert at the end
//11. remove duplicates
//12. reverse a LL (none of these is the best approach)
//13. check if a LL is a palindrome
//14. find the intersection of two LLs (two approaches)


#include <iostream>

using namespace std;


class node{
    public:
    int data;
    node * next;

    node (int data){
        this -> data = data;
        next = NULL;
    }
};


//used for findmid function

struct mid{
    node * slow;
    int val;
};

//finding the mid point using slow and fast pointers

mid findmid(node * head){
    
    if (head == NULL){
        mid sol;
        sol.slow = NULL;
        sol.val = -1;
        return sol;
    }
    
    node * slow = head;
    node * fast = head;
    
    while (fast->next != NULL && fast->next->next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
  
    }

    mid sol;
    if (fast->next==NULL){
        //odd LL
        sol.val=1;

    }
    else {
        //even LL
        sol.val=0;
    }
    sol.slow=slow;

    return sol;
}



//function to add inout to the linked list
//current complexity O(n^2)
node * takeinput(){

    node * head = NULL;
    int data;
    cout<<"Enter data"<<endl;
    cin>>data;
    
    char ans = 'y';
    while (ans=='Y'||ans=='y'){
        

        node * n1 = new node(data);
        
        if (head == NULL)
            head = n1;

        else  {
            node * temp = head;
    
            while (temp -> next != NULL){
                temp = temp -> next;
            }

            temp -> next = n1;
        }


        cout<<"enter data"<<endl;
        
        cin>>data;

        cout<<"Want to enter more? (y/n)"<<endl;
        
        cin>>ans;

        if (ans == 'n' || ans == 'N'){
            node * n1 = new node(data);
        
        if (head == NULL)
            head = n1;

        else  {
            node * temp = head;
    
            while (temp -> next != NULL){
                temp = temp -> next;
            }

            temp -> next = n1;
        }
        }

    }

    return head;
}

//complexity O(n)
node * takeinput_better(){
    //instead of running a loop to find the tail we maintain it in a pointer called tail
    int data;
    cin>>data;
    node * head = NULL;
    node * tail = NULL;
    while (data != -1){
        node *newnode = new node(data);
        if (head == NULL){
            head = newnode;
            tail = newnode;
        }

        else {
            tail->next = newnode;
            tail = tail -> next;
        }

        cin>>data;
    }
    return head;
}


void print_ll(node *head){
    node *temp = head;

     while (temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }

    cout<<endl;

}


//inserting a new node at position pos with data data
node * insertnode(node * head , int pos , int data){

    
    
    node * newnode = new node(data);
    node * temp = head;
    
    //special case for adding to the 0th position
    if (pos == 0){
        newnode -> next = temp;
        head = newnode;
    }

    else {
        if (temp != NULL){
            for (int i=0 ; i<pos-1 ; ++i){
                temp = temp -> next;
            }

            //linking the newnode with its neighbours
            newnode -> next = temp -> next;
            temp -> next = newnode;
        }
    }

    return head;
}

node * insertnode_rec(node * head, int pos, int data){

    
    int flag = 0;
    //base case: if we have to insert at head
    if (pos == 0){
        node * newnode = new node(data);
        newnode -> next = head;
        head = newnode;
        return head;
    }

    else {
        if (pos == 1){
            node * newnode = new node(data);
            newnode -> next = head -> next;
            head -> next = newnode;
            return head;
        }

        else {
            pos--;
            head = head -> next;
            head = insertnode_rec(head, pos, data);
        }
    }

    return head;

    
    
}

node * deletenode(node * head, int pos){
    
    node * temp = head;
    if (pos == 0){
        head = head -> next;
        return head;
    }
    else {
       
        for (int i=0 ; i<pos-1 && temp!=NULL; ++i){
            temp = temp -> next;
        }

        if (temp!=NULL){    
            node * a = temp -> next;
            if (a -> next != NULL)
                temp -> next = a -> next;
            else 
                temp -> next = NULL;

            delete a;
        }
        else {
            cout<<"pos out of range"<<endl;
        }
    }

    return head;

}


//check again, problem with last node

node * deletenode_rec(node * head, int pos){

    if (pos==0){
        head = head -> next;
        return head;
    }
    
    else if (pos==1){
        node * temp = head -> next;
        head -> next = temp -> next;
        delete temp;
        return head;
    }

    else {
        pos--;
        head = head -> next;
        head = deletenode_rec(head , pos);

    }

}


//deleting node with just the address of that node
void deletenode_specific(node * x){
    if (x->next != NULL){
        x -> data = x -> next -> data;
        x -> next = x -> next -> next;
    }
    else {
        cout<<"Error: cannot delete tail"<<endl;
    }
}


//deleting all nodes with a particular value
node * removeval(node * head, int val){
    int count = 0;
    node * temp = head;
    while (temp != NULL){
        
        if (temp->data==val){
            node * waste = deletenode_rec(head , count);
        }
        count++;
        temp = temp->next;             
    }
    
    return head;
}


//ques 1
//write a function to find n in the linked list



//ques 2
//given a linked list append the last 'n' elements to the front of the LL


 
//ques 3
//eliminate duplicates from the linked list

void insertend(node * head, int val){
    node * temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    node * newnode = new node(val);
    temp -> next = newnode;
}


node * removeDuplicates(node * head){

    if (head==NULL || head->next==NULL){
        return head;
    }
    
    
    
    node * sol = new node (head->data);

    node * i = head->next;
    

    while (i!=NULL){
        int temp = i->data;
        node * j = sol;
        int flag = 0;
        while (j!=NULL && flag == 0){
            
            if (temp == j->data){
                flag = 1;
                break;
            }

            else {
                j = j->next;
            }
            
        }

        if (flag==0){
            insertend(sol , temp);
        }

        i = i->next;

    }

    return sol;

}


//ques 4
//reverse a LL

//to improve complexity we maintain both head and tail of the reversed LL
//problem: returning two parameters from a single function
//soln: create a class and make the function return that class type

class revLLbetter_sol{
    public:
    node * head;
    node * tail;
};

revLLbetter_sol revLLbetter(node * head){

    if (head == NULL || head->next == NULL){
        revLLbetter_sol ans;
        ans.head = head;
        ans.tail = head;        
        return ans;
    }

    revLLbetter_sol smallans = revLLbetter(head->next);

    smallans.tail -> next = head;
    head -> next = NULL;

    revLLbetter_sol ans;
    ans.head = smallans.head;
    ans.tail = head;
    return ans;
}

//our main expects the result in form of head only so we have to convert this class type to node * type

node * revLL_better (node * head){
    return revLLbetter(head).head;
}

//reverse a linked list with better complexity



//ques 5
//check if a linked list is palindrome or not
bool ifpalindrome(node * head){
    
    //base cases
    if (head==NULL || head->next==NULL){
        return true;
    }
    
    
    //find the mid and reverse the second half of the LL
    mid x = findmid(head);
    node * sec = NULL;
    //odd LL
    if (x.val==1){
        sec = x.slow->next;
        node * temp = head;
        while(temp->next != x.slow){
            temp=temp->next;
        }

        temp->next = NULL;
    }
    else {
        sec = x.slow->next;
        x.slow->next = NULL;
    }

    //reverse the second LL
    sec = revLL_better(sec);

    while (head!=NULL){
        if (head->data != sec->data){
            return false;
        }
        else {
            head = head->next;
            sec = sec->next;
        }

    }

    return true;
}


//ques 6 
//intersection of two LLs

//sol1: complexity O(m*n)
node * findintersec(node * h1 , node * h2){
    
    if (h1==NULL || h2==NULL){
        return NULL;
    }
       
    node * i = h1;
    while (i!=NULL){
        node * j = h2;
        while (j!=NULL){
            if (i==j){
                return i;
            }
            j = j->next;
        }
        i = i->next;
    }
    return NULL;
}

//sol2: O(m+n)
node * findintersec2(node * h1 , node * h2){
    
    if (h1==NULL || h2==NULL){
        return NULL;
    }
    
    int l1=0 , l2=0;
    for (node * t1 = h1; t1!=NULL ; t1=t1->next){
        l1++;
    }

    for (node * t2 = h2; t2!=NULL ; t2=t2->next){
        l2++;
    }

    if (l2>l1){
        for(int i=0 ; i<l2-l1 ; ++i){
            h2=h2->next;
        }

        node * x1 = h1;
        node * x2 = h2;
        while (h2!=NULL){
            if (x1==x2){
                return x1;
            }
            else {
                x1 = x1->next;
                x2 = x2->next;
            }
        }
    }
    else {
        for (int i=0 ; i<l1-l2 ; ++i){
            h1=h1->next;
        }
        

        node * x1 = h1;
        node * x2 = h2;
        while (h1!=NULL){
            if (x1==x2){
                return x1;
            }
            else {
                x1 = x1->next;
                x2 = x2->next;
            }
        }
    }

    return NULL;

}














int main(){

    /*node n1(1);

    node *head = &n1;

    node n2(2);
    n1.next = &n2;

    node n3(3);
    n2.next = &n3;

    node n4(4);
    n3.next = &n4;

    node n5(5);
    n4.next = &n5;*/

    node * head = takeinput_better();


    print_ll(head);

    
    cout<<ifpalindrome(head)<<endl;
    
    
    //head = deletenode_rec(head , 1);
    //head = removeDuplicates(head);
    //print_ll(head);

    /*int pos, data;
    cin>>pos;
    cin>>data;
   
    
    
    //head = insertnode(head, pos, data);
    //inserting node recursively
    node * waste = insertnode_rec(head, pos, data);

    if (pos == 0){
        head = waste;
    }    

    print_ll(head);

    cin>>pos;
    //head = deletenode(head, pos);
    //deleting node recursively
    node * waste2 = deletenode_rec(head, pos);
    if (pos == 0){
        head = waste2;
    }
    print_ll(head);*/

    //node * mid = findmid(head);
    //cout<<mid -> data<<endl;

    return 0;
}