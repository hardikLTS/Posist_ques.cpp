    #include<bits/stdc++.h>
    using namespace std;
    struct date{
        int date;
        int month;
        int year;
    };
    struct node{
        struct date *dt;
        int nodeNumber;
        int data;
        string nodeId;
        string referenceNodeId;
        map<node*,int>child;
        string genesisReferenceNodeId;
        node()
        {
            nodeNumber = 0;
            nodeId = NULL;
            referenceNodeId = NULL;
            genesisReferenceNodeId = NULL;
        }
    };
    // finding the parent of the newnode in the alrady existing tree using dfs
    void dfs(node *root,node *target)
    {
        if(root == target)
        {
            root->child
            return;
        }
        for(auto it = root->child.begin(); it != root->child.end(); ++it)
        {

            dfs(it,target);
        }
    }
    //encryption of a string is Caesar Cypher Algorithm
    string encrypt(string str)
    {
         for(i = 0; (i < 100 && str[i] != '\0'); i++)
                str[i] = str[i] + 2;
         return str;
    }
    void insert(node *temp, node *parent, node *root)
    {
        Node *curr = dfs(root, parent);

    }
    node *get_parentnode(string id, node* root)
    {
        if(root->id == id)
        {
            return root;
        }
        for(auto it = root->child.begin();it != root->child().end(); ++it)
            {
                return get_parentnode(id,it);
            }
    }
    // this function checks if the value of new node and its siblings is greater than it parents
    bool checkValid(int val,string id,node *root)
    {
        node *parentnode = get_parentnode(id, root);
        int sum = 0;
        for(auto it = parentnode->child.begin(); it != parentnode->child.end(); ++it)
        {
                sum += it->data;
        }
        if(val + val > parentnode->data)
            return false;
        else
            return true;
    }
    void dfs1(string val, string id)
    {


    }
    bool check_validity(string val,string id)
    {

    }
    int main()
    {
        node *genesis_root = new node(); // createing the genesis node
        char ch;
        cout << "Press 1 to create node" << endl; //  this step will cover all points from 1  to 4;
        cout  << "Press 5 to verify the owner of a data" << endl;
        cout << "Press 6 to edit value of node" << endl;
        cout << "Press 8 to longest chain genesis node" << endl;
        cout << "Press 9 to gest longest chain of any node" << endl;
        cout << "Press 10 to merge data of two nodes" << endl;
        cin >> ch;
        do{
            if(ch == 1)
            {
                cout << "enter data for new node" << endl;
                string s;
                cin >> s;
                int val;
                cout << "enter value for the new node" << endl;
                cin >> val;
                cout << "enter id of the parent node" << endl;
                string id;
                cin >> id;
                if(checkValid(val,id, root))
                {
                    node *newnode = new node();
                    id = encrypt(id);
                    newnode->referenceNodeId = id;
                    newnode->id = id;
                    if(root == NULL)
                    {
                        root = newnode;
                    }
                    else
                        insert(newnode, id, root);
                }

            }
            else if(ch == 5)
            {
                string x;
                cin >> x;
                string id;
                cin >> id;

                if(check_validity(x,id))
                {
                    cout << "The query is true" << endl;
                }
                else
                    cout << "The qury is false" << endl;
            }
            else if(ch == 8)
            {
                // to find the longest path from the genesis node we can do breadth first search;
                queue<node*>q;
                q.push(root);
                map<node*int>visit;
                while(!q.empty())
                {
                    node *temp = q.front;
                    q.pop();
                    for(auto it = temp->child.begin(); it != child.end(); ++it)
                    {
                        if(visit.find(it) != visit.end())
                        {
                            visit[it] = visit[temp] + 1;
                            q.push(it);
                        }
                    }
                }
                int ans = 0;
                for(auto it = visit.begin(); it != visit.end(); ++it)
                {
                    ans = max(ans,visit[it]);
                }

                cout << "maximum length from genesis node is: " << ans << endl;
            }
            else if (ch == 9)
            {
                string data;
                cin >> data;
                node * temp = get_parentnode(data,root);
                queue<node*>q;
                q.push(temp);
                map<node*int>visit;
                while(!q.empty())
                {
                    node *temp = q.front;
                    q.pop();
                    for(auto it = temp->child.begin(); it != child.end(); ++it)
                    {
                        if(visit.find(it) != visit.end())
                        {
                            visit[it] = visit[temp] + 1;
                            q.push(it);
                        }
                    }
                }
                int ans = 0;
                for(auto it = visit.begin(); it != visit.end(); ++it)
                {
                    ans = max(ans,visit[it]);
                }

                cout << "maximum length from the given node is: " << ans << endl;
            }

            cin >> ch;
        }while(ch != 'N')


        return 0;
    }
