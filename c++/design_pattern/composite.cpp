#include<iostream>
#include<list>
#include<vector>

using namespace std;
class Component{
   public:
    virtual void Add(Component*ca){};
    virtual void Remove(){};
    virtual void Display(string st){return ;}
    string name ={};
    list<Component*> data;
    Component* parent;
};

class Composite:public Component{
    public:
        Composite(string name){
            this->name = name;
        }
        void Add(Component* ca){
            data.push_back(ca);
        }

        void Remove(Component* cr){
            data.remove(cr);
            this->parent = nullptr;
        }

        void SetParent(Component* cs){
            this->parent = cs;
        }

        void Display(string str){
            for(Component* ele : data){
                ele->Display(str + "-");
            }
            str+=this->name;
            cout<<str<<endl;
        }
};

class Leaf:public Component{
    public:
        Leaf(string name){
            this->name = name;
        }
        void Display(string str){
            for(Component* ele : data){
                ele->Display(str + "-");
            }
            str+=this->name;
            cout<<str<<endl;
        }
};

int main(){
    Component* c1 = new Composite("Composite");
    Component* c2 = new Composite("Composite");
    Component *root = new Composite("Root");

    Component* leaf_root = new Leaf("Leaf");
    Component* leaf_c1 = new Leaf("Leaf");

    c1->Add(leaf_c1);
    
    c2->Add(leaf_c1);

    root->Add(c1);

    root->Add(c2);

    root->Add(leaf_root);

    root->Display("");

    delete c1,c2,root,leaf_root,leaf_c1;

}