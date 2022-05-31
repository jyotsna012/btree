// used the following youtube videos as aid for part of this project
// https://www.youtube.com/watch?v=pYT9F8_LFTM - Data structures: Binary Search Tree
// https://www.youtube.com/watch?v=cySVml6e_Fc - 5.10 Binary Search Trees (BST) - Insertion and Deletion Explained
// https://www.youtube.com/watch?v=COZK7NATh4k - Binary search tree - Implementation

#include<iostream>
#include <fstream>

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

Node* FindMin(Node* root)
{
 while(root->left != NULL) root = root->left;
 return root;
}

Node* Delete(Node* root, int data){
	if(root == NULL){
		return root;
	}else if(data < root -> data){
		root -> left = Delete(root->left, data);
	}else if(data > root -> data){
		root -> right = Delete(root->right, data);
	}else{
		if(root -> left == NULL && root -> right == NULL){
			delete root;
			root = NULL;
		}else if(root -> left == NULL){
			Node* temp = root;
			root = root -> right;
			delete temp;
		}else if(root -> right == NULL){
			Node* temp = root;
			root = root -> right;
			delete temp;
		}else{
			Node* temp = FindMin(root->right);
			root->data = temp ->data;
			root -> right = Delete(root -> right, temp -> data);
		}
		
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
    space += 5;
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
  int option = 0;
  cout << "enter the number of elements you are inputting" << endl;
  cin >> numelements;
  cin.get();
  cout << "Type 1 below to enter elements maually and type 2 below to upload from a file" << endl;
  cin >> option;
  cin.get();
	
     if(option == 1){
	  //text input: reads numbers from user and adds to array   
          cout << "please enter your elements below. press enter between each one" << endl;       
          for(int i = 0; i < numelements; i++){
               int input;
               cin >> input;
               cin.get();
               arr[i] = input;
          }  
       } else if(option == 2){
	  //file input: reads numbers from file and add   
		  ifstream myFile;
		  myFile.open("numbers.txt");
		  int g = 0;
		  while (g < numelements) {
   		  myFile >> arr[g];
   		  g++;
		  }
		  myFile.close();
    }
	
    Node* rootP = NULL;
    for(int a = 0; a < numelements; a++){
        rootP = insert(rootP, arr[a]);
    }
     
    int choice = 0;
    bool tf = true;
    while(tf == true){
      cout << "What would you like to do? Type 1 to add, Type 2 to remove, Type 3 to search, Type 4 to print, Type 5 to quit" << endl;
      cin >> choice;
      cin.get();
      if(choice == 5){
          tf =false;
      }else if(choice == 4){
         print(rootP, -5);
      }else if(choice == 3){
          int number;
          cout << "enter number to search?" <<endl;
          cin>>number;
          if(Search(rootP,number) == true){
            cout << "found" << endl;
          }else{
            cout << "not found" << endl;
          }
      }else if(choice == 2){
	 Delete(rootP, 6);     
      }
	    
      else if(choice == 1){
          numelements++;
          int toAdd;
          cout << "what number do you want to add" << endl;
          cin >> toAdd;
          cin.get();
          rootP = insert(rootP, toAdd);
      }
   
}

}
	


