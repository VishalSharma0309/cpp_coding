

class node{
    public:
    int data;
    node * next;

    //constructor for the class
    //everytime user creates an object, we take data and since its added to the end we take next as NULL
    node (int data){
        this -> data = data;
        next = NULL;
    }
};