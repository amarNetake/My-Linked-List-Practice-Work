class Node{
    public:
        int value;
        int key;
        Node* left;
        Node* right;
        Node(int key,int value)
        {
            this->key=key;
            this->value=value;
            left=NULL;
            right=NULL;
        }
};
class LRUCache {
public:
    int capacity;
    
    unordered_map<int,Node*> ma;
    Node* head=NULL;
    Node* front=NULL;
    Node* rear=NULL;
    
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    void insertEnd(int key,int value,Node** rear_ref)
    {
        Node* new_node=new Node(key,value);
        (*rear_ref)->right=new_node;
        new_node->left=rear;
        *rear_ref=new_node;
    }
    
    void deleteNode(Node* temp)
    {
        if(temp->left!=NULL) temp->left->right=temp->right;
        else if(temp->left==NULL) front=temp->right; //So temp was starting node so make front point to new start
        temp->right->left=temp->left;
        delete(temp);
    }
    
    int get(int key) {
        //Since we are accessing the 'key' now the corresponding key->value pair must be pushed to the end
        if(ma.find(key)==ma.end()) return -1;
        int value=ma[key]->value;
        
        //Insert the node with new value in the end
        insertEnd(key,value,&rear);
        
        //Delete the node at current position
        Node* temp=ma[key];
        deleteNode(temp);
        
        //make ma[key] to point to new address i.e. rear
        ma[key]=rear;
        
        return ma[key]->value;
    }
    
    void put(int key, int value) {
        //If the cache is empty
        if(head==NULL)
        {
            Node* new_node=new Node(key,value);
            head=new_node;
            ma[key]=new_node;
            front=new_node,rear=new_node;
        }
        //If key already exist in cache(no matter if cache is empty or full)
        else if(ma.find(key)!=ma.end())
        {
            //Insert the node with new value in the end
            insertEnd(key,value,&rear);
            
            //Remove the node from the existing position with the given key
            Node* temp=ma[key];
            deleteNode(temp);
            
            //Add new address of ma[key]
            ma[key]=rear;
        }
        else if(ma.size()<capacity)
        {
            //Insert the node with new value in the end
            insertEnd(key,value,&rear);
            
            //Store the address of it in map
            ma[key]=rear;
        }
        
        else if(ma.size()==capacity)
        {
            //Insert the node with new value in the end
            insertEnd(key,value,&rear);
            
            //Store the key value to remove the item from the map after removing the element
            int k=front->key;
            
            //Remove the element from the front
            deleteNode(front);
            
            //Remove the key from the map
            ma.erase(k);
            
            //Add the new key with its address in the map
            ma[key]=rear;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */