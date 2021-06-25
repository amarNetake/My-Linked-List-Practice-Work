class Node {
    public:
        string content="";
        string key="";
        map<string,Node*> ma;
        Node(string key)
        {
            this->key=key;
        }
};

class FileSystem {
public:
    Node* root;
    
    FileSystem() {
        Node* new_node=new Node("/");
        root=new_node;
    }
    
    void getPathInQueue(queue<string>& q, string path)
    {
        string str="";
        for(int i=1;i<path.length();i++)
        {
            if(path[i]=='/')
            {
                if(str.length()>0) q.push(str);
                str="";
            }
            else
            {
                str.insert(str.end(),path[i]);
            }
        }
        if(str!="") q.push(str);
    }
    
    Node* goToPath(queue<string>& q)
    {
        Node* temp=root;
        while(q.empty()==false)
        {
            string curr=q.front();
            q.pop();
            if(temp->ma.find(curr)==temp->ma.end())
            {
                Node* new_node=new Node(curr);
                temp->ma[curr]=new_node;
                temp=new_node;
            }
            else
            {
                temp=temp->ma[curr];
            }
        }
        return temp;
    }
    
    vector<string> ls(string path) {
        queue<string> q;
        getPathInQueue(q,path);
        Node* temp=q.empty()==false?goToPath(q):root;
        vector<string> result;
        for(auto x: temp->ma)
        {
            result.push_back(x.first);
        }
        //If there were no directories in current location that is if it is inner most file 
        //Then push itself if the current folder has some content
        if(result.size()==0 && temp->content.length()>0) result.push_back(temp->key);
        return result;
    }
    
    void mkdir(string path) {
        queue<string> q;
        getPathInQueue(q,path);
        Node* temp=goToPath(q);
    }
    
    void addContentToFile(string filePath, string content) {
        queue<string> q;
        getPathInQueue(q,filePath);
        Node* temp=goToPath(q);
        temp->content.append(content);
    }
    
    string readContentFromFile(string filePath) {
        queue<string> q;
        getPathInQueue(q,filePath);
        Node* temp=goToPath(q);
        return temp->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */