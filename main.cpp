#include<iostream>
using namespace std;
struct Node{
  int data;
  Node* left;
  Node* right;
};

Node* GetNewNode(int data){
  Node* newNode = new Node();
  newNode -> data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

Node* insert(Node* root, int data){
  if(root == NULL){
     root = GetNewNode(data);
     return root;
  }
  else if(data <= root->data){
    root->left = insert(root->left,data);
  }
  else{
    root->right = insert(root->right,data);
  }
  return root;
}

bool Search(Node* root, int data){
  if(root == NULL){
    return false;
  }
  else if(root->data == data){
    return true;
  }
  else if(data <= root->data){
    return Search(root->left, data);
  } 
  else{
    return Search(root->right, data);
  }
}

//used the same algorithim from Geeks for Geeks https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
void print(Node *root, int space)
{
    if (root == NULL)
        return;
    space += 10;
    print(root->right, space);
    cout<<endl;
    for (int i = 0; i < space; i++)
        cout<<" ";
    cout<<root->data<<"\n";
    print(root->left, space);
}

int main(){
  int* arr = new int[101];
  int numelements = 0;
  cout << "enter the number of elements you are inputting" << endl;
  cin >> numelements;
  cin.get();
  cout << "please enter your elements below. press enter between each one" << endl;       
          for(int i = 0; i < numelements; i++){
               int input;
               cin >> input;
               cin.get();
               arr[i] = input;
          }
            
          Node* rootP = NULL;
          for(int a = 0; a < numelements; a++){
            rootP = insert(rootP, arr[a])
          }
  
  int number;
  cout << "enter number to search?" <<endl;
  cin>>number;
  if(Search(rootP,number) == true){
    cout << "found" << endl;
  }else{
    cout << "not found" << endl;
  }
  
  print(rootP, -10);
}


