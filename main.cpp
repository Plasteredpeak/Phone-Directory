#include <iostream>
#include <iomanip>
#include "fstream"
#include "cstring"
using namespace std;
class sta{  //Stack used for recently added!
    string *s;
    int size, top;
public:
    sta()
    {
        size=10;
        s=new string[size];
        top=-1;
    }
    sta (int s1)
    {
        size=s1;
        s=new string[size];
        top=-1;
    }
    void push(string x)
    {
        if(!isfull())
        {
            s[++top]=x;
        }
    }

    bool isfull()
    {
        if(top==size-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool is_empty()
    {
        if(top==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    string pop()
    {
        if(!is_empty())
        {
            return s[top--];
        }
        else
        {
            cout<<"\n Stack is already empty";
        }
    }
    void display()
    {
        if(!is_empty())
        {
            int c=1;
            cout<<"Recently Added:"<<endl;
            for(int i=top; i>=0; i--)
                cout<<"       ("<<c++<<")"<<s[i]<<"\n";
        }
        else
        {
            cout<<"\n No Recent Contacts Found";
        }
    }

};

struct info{ //Used for AVL insertion and deletion
    string name;
    string num;
    string city;
    int height;
    info* left=NULL;
    info* right=NULL;
};
info* root=NULL;

struct chain{ //Used for Hashing
    string name;
    string num;
    chain *next=NULL;
};
chain **ch;

info* insert(info*,info*,string); //Insert data in AVL
int height(info*); //Check height of AVL
int minDist(int *,bool *); // Finding min distance among vertices
int max(int n1,int n2); //Used for finding Max height
int Balance(info*); //Check Balance of AVL
info* rightR(info*); //Right rotation
info* leftR(info*);  //Left Rotation
void Display(info*); //Display Tree
info* Delete(info*,string); //Delete From AVL
void WriteToFile(info*); //Write Data to File
string* search(string,string*); //Search for a contact
string* Suggest(string*,string s); //Show Suggestions if the user enters a wrong input
void AddtoFav(string*); //Add a contact to FAv
void Dijkstra(int,int); //Used for finding distances between Cities
void ChainHashing(); //Used to Create a Hash Table of cities
void CDisplay(); //Used to Display Data in City Order
void Read(); // Read Data from file and insert it into AVL
void AddtoFav(string*); //Add contact to Fav
void Showfav(); //Display Fav Contacts;
bool DelFav(string); //Remove Contact from fav


//Global Variables

string cities[5]={"Islamabad","Lahore","Gujranwala","Karachi","Peshawar"};
int count=0;
#define INF 9999;
int vertices;

int Defgraph[5][5]={ { 0, 375, 220, 1500, 183},
                     { 375, 0, 96, 1200, 516},
                     { 220, 96, 0, 1269, 400},
                     { 1500, 1200, 1269, 0, 1550},
                     { 183, 516, 400, 1550, 0}
};
int **graph;
string fav[20][3];

//

string* Suggest(string *arr,string name){
    string data;
    fstream f("Phonebook.txt",ios::in);
    while(getline(f,data)) {
        char *slash;

        slash = strtok((char *) data.c_str(), "/");
        string n = slash;

        if(name.at(0)==n.at(0) && count<3){
            arr[count++]=n;
        }
    }
    return arr;
}

string* search(string name,string* arr){
    info* ptr=root;
    while (ptr!=NULL) {
        if (ptr->name==name) {
            arr[0]=ptr->name;
            arr[1]=ptr->num;
            arr[2]=ptr->city;
            return arr;
        }
        else if (name.compare(ptr->name) < 0)
            ptr = ptr->left;
        else if(name.compare(ptr->name)>0)
            ptr = ptr->right;
    }
    return arr;
}

void ChainHashing(){
    ch=new chain*[5];
    for(int i=0;i<5;i++){
        ch[i]=NULL;
    }
    string data;
    fstream f("Phonebook.txt",ios::in);
    while(getline(f,data)){
        char* slash;

        slash=strtok((char*)data.c_str(),"/");
        string name=slash;

        slash=strtok(NULL,"/");
        string num=slash;

        slash=strtok(NULL,"/");
        string city=slash;

        int v;
        for(int i=0;i<5;i++){
            if(city==cities[i])
                v=i;
        }
        int i=v%5;
        chain *ptr=new chain;

        ptr->name=name;
        ptr->num=num;
        ptr->next=NULL;
        if(ch[i]==NULL)
            ch[i]=ptr;
        else{
            ptr->next=ch[i];
            ch[i]=ptr;
        }
    }
    f.close();
}

void CDisplay(){
    for(int i=0;i<5;i++){
        if(ch[i]!=NULL) {
            chain *ptr = ch[i];
            cout << cities[i] << " :" << endl;
            while (ptr != NULL) {
                cout << "        " << ptr->name<<"         "<<ptr->num << endl;
                ptr = ptr->next;
            }
        }
    }
}

int minDist(int *d,bool *v){
    int min=INF;
    int index;
    for(int i=0;i<vertices;i++){
        if(d[i]<=min && !v[i])
            min=d[i], index = i;
    }
    return index;
}

void Dijkstra(int src,int dest){
    vertices=5;
    graph = new int *[vertices];
    for (int x = 0; x < vertices; x++)
        graph[x] = new int[vertices];
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (Defgraph[i][j] == 0) {
                graph[i][j] = INF;
            }
            else {
                graph[i][j] = Defgraph[i][j];
            }
        }
    }
    if(vertices==0 && src>=vertices){
        cout<<"\nGraph is empty";
        return;
    }
    int distance[vertices];
    bool visited[vertices];
    for(int i=0;i<vertices;i++){
        distance[i]=INF;
        visited[i]= false;
    }
    distance[src]=0;
    for(int c=0;c<vertices-1;c++) {
        int crrV = minDist(distance, visited);
        visited[crrV] = true;
        for (int i = 0; i < vertices; i++) {
            if (!visited[i] && graph[crrV][i] && distance[crrV] != 9999 && distance[crrV] + graph[crrV][i] < distance[i])
                distance[i] = distance[crrV] + graph[crrV][i];
        }
    }

    cout<<"\nThe sortest distance from "<<cities[src]<<" to "<<cities[dest]<<" is "<<distance[dest]<<" km."<<"\n";
    cout<<endl;

}
int height(info* ptr){
    if(ptr==NULL)
        return 0;
    else
        return ptr->height;
}
int max(int n1,int n2){
    return (n1>n2)?n1:n2;
}
int Balance(info* ptr){
    if(ptr==NULL)
        return 0;
    else
        return height(ptr->left)-height(ptr->right);
}
info* rightR(info* oldr){
    info* newr=oldr->left;
    info* temp=newr->right;

    newr->right=oldr;
    oldr->left=temp;

    oldr->height=max(height(oldr->right),height(oldr->left))+1;
    newr->height=max(height(newr->left),height(newr->right))+1;

    return newr;

}
info* leftR(info* oldr){
    info* newr=oldr->right;
    info* temp=newr->left;

    newr->left=oldr;
    oldr->right=temp;

    oldr->height=max(height(oldr->right),height(oldr->left))+1;
    newr->height=max(height(newr->left),height(newr->right))+1;

    return newr;

}

info* Delete(info* r,string n) {
    if (n.compare(r->name) < 0)
        r->left = Delete(r->left, n);
    else if (n.compare(r->name) > 0)
        r->right = Delete(r->right, n);
    else {
        if(r->left==NULL && r->right==NULL){
            delete r;
            r=NULL;
        }
        else if(r->left==NULL){
            info* ptr=r;
            r=r->right;
            delete ptr;
        }
        else if(r->right==NULL){
            info* ptr=r;
            r=r->left;
            delete ptr;
        }
        else {
            info *min = r->right;
            while (min->left != NULL)
                min = min->left;
            r->name = min->name;
            r->city = min->city;
            r->num = min->num;
            r->right = Delete(r->right, min->name);
        }
        if (r == NULL) {
            return r;
        }

        r->height = max(height(r->left), height(r->right)) + 1;
        int bf = Balance(r);

        if (bf > 1 && n.compare(r->left->name) < 0)
            return rightR(r);
        if (bf > 1 && n.compare(r->left->name) > 0) {
            r->left = leftR(r->left);
            return rightR(r);
        }

        if (bf < -1 && n.compare(r->right->name) > 0)
            return leftR(r);
        if (bf < -1 && n.compare(r->right->name) < 0) {
            r->right = rightR(r->right);
            return leftR(r);
        }
    }
    return r;

}

info* insert(info* r,info* node,string name){
    if(r==NULL){
        return node;
    }
    else if(name.compare(r->name)<0)
        r->left =insert(r->left,node,name);
    else if(name.compare(r->name)>0)
        r->right=insert(r->right,node,name);
    else {
        cout<<"Person with that name already exists"<<endl;
        return r;
    }

    r->height=max(height(r->left),height(r->right))+1;
    int bf=Balance(r);

    if(bf>1 && name.compare(r->left->name)<0)
        return rightR(r);
    if(bf>1 && name.compare(r->left->name)>0){
        r->left=leftR(r->left);
        return rightR(r);
    }

    if(bf<-1 && name.compare(r->right->name)>0)
        return leftR(r);
    if(bf<-1 && name.compare(r->right->name)<0){
        r->right=rightR(r->right);
        return leftR(r);
    }
    return r;
}

void Display(info* ptr){
    if (ptr == NULL) {
        return;
    }
    else {
        Display(ptr->left);
        count++;
        cout << count << setw(20) << ptr->name << setw(25) << ptr->num << setw(20) << ptr->city << endl;
        Display(ptr->right);
    }
}
void Read(){
    string data;
    fstream f("Phonebook.txt",ios::in);
    while(getline(f,data)){
        char* slash;
        info* node=new info;

        slash=strtok((char*)data.c_str(),"/");
        node->name=slash;

        slash=strtok(NULL,"/");
        node->num=slash;

        slash=strtok(NULL,"/");
        node->city=slash;

        node->height=1;

        root=insert(root,node,node->name);
    }
    f.close();

}
void WriteToFile(info* r){
    fstream f("Phonebook.txt",ios::app);
    if(r==NULL){
        f.close();
        return;
    }
    else{
        WriteToFile(r->left);
        string data=r->name+"/"+r->num+"/"+r->city+"\n";
        f<<data;
        WriteToFile(r->right);
    }
}

void AddtoFav(string* arr){
    fstream f("Favourites.txt",ios::app);
    string data=arr[0]+"/"+arr[1]+"/"+arr[2]+"\n";
    f<<data;
    f.close();
    cout<<"____Contact Added to Favourites!___"<<endl;
}

void Showfav(){
    string data;
    cout << "\nNo."<<setw(15)<<"Name"<<setw(28)<<"Phone no."<<setw(20)<<"City" << endl;
    int c=1;
    fstream f("Favourites.txt",ios::in);
    while(getline(f,data)){
        char* slash;

        slash=strtok((char*)data.c_str(),"/");
        string name=slash;

        slash=strtok(NULL,"/");
        string num=slash;

        slash=strtok(NULL,"/");
        string city=slash;

        cout << c++ << setw(20) << name << setw(25) << num << setw(20) << city << endl;
    }
    f.close();
}

bool DelFav(string n){
    bool flag=false;
    string data;
    fstream f("Favourites.txt",ios::in);
    int c=0;
    while(getline(f,data)){
        char* slash;

        slash=strtok((char*)data.c_str(),"/");
        string name=slash;

        slash=strtok(NULL,"/");
        string num=slash;

        slash=strtok(NULL,"/");
        string city=slash;

        if(name==n){
            flag=true;
        }
        else{
            fav[c][0]=name;
            fav[c][1]=num;
            fav[c++][2]=city;
        }
    }
    f.close();
    if(flag) {
        remove("Favourites.txt");
        fstream file("Favourites.txt", ios::app);
        for (int i = 0; i < c; i++) {
            string d = fav[i][0] + "/" + fav[i][1] + "/" + fav[i][2] + "\n";
            file << d;
        }
        file.close();
    }

    return flag;
}

int main() {
    sta R(5);
    Read();
    int c=-1;
    while(c!=0){
        cout<<"\n-------------------------Phone Book------------------------------\n";
        cout<<"\n                       (1) New Contact";
        cout<<"\n                       (2) Search for Contacts";
        cout<<"\n                       (3) Display Contacts";
        cout<<"\n                       (4) Show Favourites";
        cout<<"\n                       (5) Show Recently Added";
        cout<<"\nEnter 0 to exit";
        cout<<"\n\n>>>";
        cin>>c;
        switch(c){
            case 0: {
                remove("Phonebook.txt");
                WriteToFile(root);
                break;
            }
            case 1: {
                string name, num, city;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin,name);
                bool flag;
                do {
                    flag = true;
                    cout <<"Enter Phone no. :";
                    cin >> num;
                    for (char ch : num) {
                        if (!isdigit(ch))
                            flag = false;
                    }
                    if(!flag)
                        cout<<"Phone no can only have Digits"<<endl;
                    if(num.size()!=11 && flag){
                        flag= false;
                        cout<<"Phone no can only have 11 digits"<<endl;
                    }
                } while (!flag);

                cout<<"Choose a city:"<<endl;
                for(int j=0;j<5;j++){
                    cout<<"               ("<<j+1<<")"<<" "<<cities[j]<<endl;
                }
                while (true) {
                    int opt;
                    cout << ">>>";
                    cin >> opt;
                    if (opt == 1 || opt == 2 || opt == 3 || opt == 4 || opt == 5) {
                        city = cities[opt - 1];
                        break;
                    }
                    else {
                        cout << "Enter Correct city number !!" << endl;
                    }
                }
                info* newnode=new info;
                newnode->name=name;
                newnode->num=num;
                newnode->city=city;
                newnode->height=1;
                root=insert(root,newnode,newnode->name);
                remove("Phonebook.txt");
                WriteToFile(root);
                if(!R.isfull())
                    R.push(name);
                break;
            }
            case 2: {
                string n;
                cout<<"Enter Name:";
                cin.ignore();
                getline(cin,n);
                string arr[3];
                string *ptr=search(n,arr);
                if(ptr[0]!=(n)){
                    cout<<"No Person with that name exists"<<endl;
                    string sugg[3];
                    string *ptr2=Suggest(sugg,n);
                    cout<<"Suggestions:"<<endl;
                    for(int i=0;i<3;i++){
                        cout<<"             "<<ptr2[i]<<endl;
                    }
                }
                else {
                    int opt2=-1;
                    do {
                        cout<<"\n                  ---------___"<<ptr[0]<<"___----------\n";
                        cout<<"                  -------___"<<ptr[1]<<"___----------\n";
                        cout<<"                  -------___"<<ptr[2]<<"___----------\n";
                        cout<<"(1)Add to favourites"<<endl;
                        cout<<"(2)Delete Contact"<<endl;
                        cout<<"(3)Remove from Favourites"<<endl;
                        cout<<"(4)Find Shortest path to his/her City"<<endl<<endl;
                        cout<<"Enter 0 to go Back"<<endl<<endl;

                        cout<<">>>";
                        cin>>opt2;
                        switch (opt2) {
                            case 0:
                                break;
                            case 1:
                                AddtoFav(ptr);
                                break;
                            case 2:
                                root = Delete(root, ptr[0]);
                                cout<<"Deleted Successfully !"<<endl;
                                remove("Phonebook.txt");
                                WriteToFile(root);
                                DelFav(ptr[0]);
                                opt2=0;
                                break;
                            case 3: {
                                bool flag = DelFav(ptr[0]);
                                if (!flag)
                                    cout<<"Contact is not in your favourites"<<endl;
                                else
                                    cout<<"Removed from Favourites"<<endl;
                                break;
                            }
                            case 4:{
                                int src,dest;
                                cout<<"Choose Your city:"<<endl;
                                for(int j=0;j<5;j++){
                                    cout<<"               ("<<j+1<<")"<<" "<<cities[j]<<endl;
                                    if(ptr[2]==cities[j])
                                        dest=j;
                                }
                                while (true) {
                                    int opt;
                                    cout << ">>>";
                                    cin >> opt;
                                    if (opt == 1 || opt == 2 || opt == 3 || opt == 4 || opt == 5) {
                                        src = opt-1;
                                        break;
                                    }
                                    else {
                                        cout << "Enter Correct city number !!" << endl;
                                    }
                                }
                                Dijkstra(src,dest);

                            }
                                break;
                            default:
                                cout<<"Enter a Valid choice";
                                break;

                        }

                    } while (opt2 != 0);
                }
                break;
            }
            case 3: {
                while(true){
                    int opt;
                    cout<<"(1) Display Contacts Alphabetical Order\n(2) Display Contacts in City Order\n\n";
                    cout<<">>>";
                    cin>>opt;
                    if(opt==1){
                        cout << "\nNo."<<setw(15)<<"Name"<<setw(28)<<"Phone no."<<setw(20)<<"City" << endl;
                        Display(root);
                        count=0;
                    }
                    else if(opt==2){
                        ChainHashing();
                        CDisplay();
                    }
                    else
                        continue;
                    break;
                }
                break;
            }
            case 4:{
                Showfav();
                break;
            }
            case 5:
                R.display();
                break;
            default:
                cout<<"\nWrong choice! if u wanna exit enter 0\n";
                break;
        }
    }


}

