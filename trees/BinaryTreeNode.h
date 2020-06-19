using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
    T data;
    BinaryTreeNode * left;
    BinaryTreeNode * right;

    BinaryTreeNode (T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

    // every node delete its left and right node before deleting itself
    ~BinaryTreeNode (){
        // even if left or/and right is NULL, delete NULL gets ignored and doesn't cause any problems
        delete left;
        delete right;
    }

};