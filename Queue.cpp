//Test code Priority Queue

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <conio.h>

#define SP struct PriorityQueue

int NumQueue=0;

struct PriorityQueue{
    int x, DepthLeft, DepthRight;
    int count;
    SP *parent, *left, *right;
}*First;

int max(int x, int y) {
    return (x>y ? x : y);
}


// Reconstruct Tree 
SP *FixTree(SP *Node) {

    if (Node -> DepthRight > Node -> DepthLeft) {
        SP *ChildNode = Node -> right;
        
        // TH1
        if (ChildNode -> DepthRight > ChildNode -> DepthLeft) {
            SP *Old_Cur = Node, *New_Cur=ChildNode, *TempNode = ChildNode -> left;
            SP *Old_Cur_Parent = NULL;
            
            if (TempNode != NULL) 
                Old_Cur -> DepthRight = max(TempNode -> DepthLeft, TempNode -> DepthRight) + 1;
            else 
                Old_Cur -> DepthRight = 0;
            
            New_Cur -> DepthLeft = max(Old_Cur -> DepthLeft, Old_Cur -> DepthRight) + 1;
            
            bool is_left=false;
            if (Old_Cur -> parent != NULL) { 
                Old_Cur_Parent = Old_Cur -> parent;
                if (Old_Cur_Parent -> left != NULL  && Old_Cur_Parent -> left -> x == Old_Cur -> x)
                    is_left = true;

            }


            if (TempNode != NULL) {
                TempNode -> parent = Old_Cur;
                Old_Cur -> right = TempNode;
            }
            else 
                Old_Cur -> right = NULL;
            
            Old_Cur -> parent = New_Cur;
            New_Cur -> left = Old_Cur;
            
            if (Old_Cur_Parent == NULL) 
                New_Cur -> parent = NULL;
            
            else {
                New_Cur -> parent = Old_Cur_Parent;
                if (is_left) 
                    Old_Cur_Parent -> left = New_Cur;
                
                else
                    Old_Cur_Parent -> right = New_Cur;
            }
            
            return New_Cur;
        }

        //TH2 
        else {
            SP *NewNode = ChildNode -> left, *Old_Parent = NULL, *NewLeft = Node, *NewRight = ChildNode;
            SP *Right = NewNode -> right, *Left = NewNode -> left;
            bool is_left = false;
            if (Node -> parent != NULL) { 
                Old_Parent = Node -> parent;
                if (Old_Parent -> left != NULL  &&  Old_Parent -> left -> x == Node -> x)
                    is_left = true;

            }

            NewNode -> left = NewLeft;
            NewNode -> right = NewRight;

            if (Old_Parent == NULL)
                NewNode -> parent = NULL;
            
            else {
                NewNode -> parent = Old_Parent;
                if (is_left) 
                    Old_Parent -> left = NewNode;
                else 
                    Old_Parent -> right = NewNode;
            }

            NewLeft -> parent = NewRight -> parent = NewNode;

            if (Right != NULL) {
                NewRight -> left = Right;
                Right -> parent = NewRight;
                NewRight -> DepthLeft = max(Right -> DepthLeft, Right -> DepthRight) +1;
            }
            else {
                NewRight -> left = NULL;
                NewRight -> DepthLeft = 0;       
            }

            if (Left != NULL) {
                NewLeft -> right = Left;
                Left -> parent = NewLeft;
                NewLeft -> DepthRight = max(Left -> DepthLeft, Left -> DepthRight) +1;
            }
            else {
                NewLeft -> right = NULL;
                NewLeft -> DepthRight = 0;
            }

            NewNode -> DepthLeft = max(NewLeft -> DepthLeft, NewLeft -> DepthRight) +1;
            NewNode -> DepthRight = max(NewRight -> DepthLeft, NewRight -> DepthRight) +1;

            return NewNode;
        }
    }

    else {
        

        SP *ChildNode = Node -> left;
        
        // TH3
        if (ChildNode -> DepthLeft > ChildNode -> DepthRight) {
            SP *Old_Cur = Node, *New_Cur=ChildNode, *TempNode = ChildNode -> right;
            SP *Old_Cur_Parent = NULL;
            
            if (TempNode != NULL) 
                Old_Cur -> DepthLeft = max(TempNode -> DepthLeft, TempNode -> DepthRight) + 1;
            else 
                Old_Cur -> DepthLeft = 0;
            
            New_Cur -> DepthRight = max(Old_Cur -> DepthLeft, Old_Cur -> DepthRight) + 1;
            
            bool is_left=false;
            if (Old_Cur -> parent != NULL) { 
                Old_Cur_Parent = Old_Cur -> parent;
                if (Old_Cur_Parent -> left != NULL  && Old_Cur_Parent -> left -> x == Old_Cur -> x)
                    is_left = true;

            }


            if (TempNode != NULL) {
                TempNode -> parent = Old_Cur;
                Old_Cur -> left = TempNode;
            }
            else 
                Old_Cur -> left = NULL;
            
            Old_Cur -> parent = New_Cur;
            New_Cur -> right = Old_Cur;
            
            if (Old_Cur_Parent == NULL) 
                New_Cur -> parent = NULL;
            
            else {
                New_Cur -> parent = Old_Cur_Parent;
                if (is_left) 
                    Old_Cur_Parent -> left = New_Cur;
                
                else
                    Old_Cur_Parent -> right = New_Cur;
            }
            
            return New_Cur;
        }

        //TH4
        else {
            SP *NewNode = ChildNode -> right, *Old_Parent = NULL, *NewRight = Node, *NewLeft = ChildNode;
            SP *Right = NewNode -> right, *Left = NewNode -> left;

            
            
            bool is_left = false;
            if (Node -> parent != NULL) { 
                Old_Parent = Node -> parent;
                if (Old_Parent -> left != NULL  &&  Old_Parent -> left -> x == Node -> x)
                    is_left = true;

            }

            NewNode -> right = NewRight;
            NewNode -> left = NewLeft;

            if (Old_Parent == NULL)
                NewNode -> parent = NULL;
            
            else {
                NewNode -> parent = Old_Parent;
                if (is_left) 
                    Old_Parent -> left = NewNode;
                else 
                    Old_Parent -> right = NewNode;
            }

            NewRight -> parent = NewLeft -> parent = NewNode;

            if (Right != NULL) {
                NewRight -> left = Right;
                Right -> parent = NewRight;
                NewRight -> DepthLeft = max(Right -> DepthLeft, Right -> DepthRight) +1;
            }
            else {
                NewRight -> left = NULL;
                NewRight -> DepthLeft = 0;       
            }

            if (Left != NULL) {
                NewLeft -> right = Left;
                Left -> parent = NewLeft;
                NewLeft -> DepthRight = max(Left -> DepthLeft, Left -> DepthRight) +1;
            }
            else {
                NewLeft -> right = NULL;
                NewLeft -> DepthRight = 0;
            }

            NewNode -> DepthLeft = max(NewLeft -> DepthLeft, NewLeft -> DepthRight) +1;
            NewNode -> DepthRight = max(NewRight -> DepthLeft, NewRight -> DepthRight) +1;

            return NewNode;
        }
        
    }

    return NULL;    
}


//Add Node Priority Queue
void Add_Node(int x) {
    // Find place
    SP *TempNode = First;
    while (1) {
        // x must be left
        if (x < (TempNode -> x)) {
            if (TempNode -> left != NULL) 
                TempNode = TempNode -> left;
            
            else {
                SP *NewNode;
                NewNode = (SP *) malloc(sizeof(SP));
                NewNode -> x =x;
                NewNode -> DepthLeft = NewNode -> DepthRight = 0;
                NewNode -> count = 1;
                NewNode -> right = NewNode -> left = NULL;
                NewNode -> parent = TempNode;
                TempNode -> left = NewNode;
                TempNode -> DepthLeft = 1;
                break;
            } 
                
        }

        // x must be right
        if (x > (TempNode -> x)) {
            if (TempNode -> right != NULL)
                TempNode = TempNode -> right;
            
            else {
                SP *NewNode;
                NewNode = (SP *) malloc(sizeof(SP));
                NewNode -> x = x;
                NewNode -> DepthLeft = NewNode -> DepthRight = 0;
                NewNode -> count = 1;
                NewNode -> right = NewNode -> left = NULL;
                NewNode -> parent = TempNode;
                TempNode -> right = NewNode;
                TempNode -> DepthRight = 1;
                break;
            }
        }

        // x is already in priority_queue
        if (x == (TempNode -> x)) {
            (TempNode -> count) ++;
            break;
        }
        
    }


    if (TempNode -> parent == NULL)
        First = TempNode;

    if (abs(TempNode -> DepthLeft - TempNode -> DepthRight) > 1) 
        First = FixTree(First);


    // Find break Node
    while (TempNode -> parent != NULL) {
        
        // TempNode is left child
        if (TempNode -> parent ->left != NULL && TempNode -> parent -> left -> x == TempNode -> x)
            TempNode -> parent -> DepthLeft = max(TempNode -> DepthLeft, TempNode -> DepthRight) + 1;
        
        // TempNode is right child
        else 
            TempNode -> parent -> DepthRight = max(TempNode -> DepthLeft, TempNode -> DepthRight) + 1;

        TempNode = TempNode -> parent;

        // The Node is broken
        if (abs(TempNode -> DepthLeft - TempNode -> DepthRight) > 1) {
            SP *NewNode = TempNode;
            NewNode = FixTree(NewNode);

            if ((TempNode == First))
                First = NewNode;
            
            TempNode = NewNode;
        }

        if (TempNode -> parent == NULL) 
            First = TempNode;

    }
}


//Create Priority Queue
SP *AppendNode(SP *Node, int x) {
    SP *TempNode;
    TempNode = (SP *) malloc(sizeof(SP));

    TempNode -> x = x;
    TempNode -> DepthLeft = TempNode -> DepthRight = 0;
    TempNode -> count = 1;
    TempNode -> parent = TempNode -> right = TempNode -> left = NULL;
    First = TempNode;

    return First;
}

void DeleteNode(int x) {
    SP *TempNode = First, *Node;
    while (1) {
        // x must be left
        if (x < (TempNode -> x)) 
            TempNode = TempNode -> left;

        // x must be right
        if (x > (TempNode -> x))
            TempNode = TempNode -> right;

        // x is TempNode
        if (x == (TempNode -> x)) {


            int NumChild = (TempNode -> right != NULL) + (TempNode -> left != NULL);

            // x has 0 child        
            if (NumChild == 0) {
                Node = TempNode -> parent;
                
                if (Node != NULL) {
                    // x is left child
                    if (Node -> left != NULL && Node -> left -> x == TempNode -> x) {
                        Node -> DepthLeft --;
                        Node -> left = NULL;
                    }

                    // x is right child
                    else {
                        Node -> DepthRight --;
                        Node -> right = NULL;   
                    }
                }

                free(TempNode);
            }

            // x has 1 child
            if (NumChild == 1) {
                Node = TempNode -> parent;
                SP *Child = (TempNode -> left != NULL) ? (TempNode -> left) : (TempNode -> right);

                if (Node != NULL) {
                    // x is left child
                    if (Node -> left != NULL && Node -> left -> x == TempNode -> x) {
                        Node -> DepthLeft --;
                        Node -> left = Child;
                        Child -> parent = Node;
                    }

                    // x is right child
                    else {
                        Node -> DepthRight --;
                        Node -> right = Child; 
                        Child -> parent = Node;  
                    }
                }
                else {
                    Node = Child;
                    Node -> parent = NULL;
                }
                
                free(TempNode);
            } 


            // x has 2 children
            if (NumChild == 2) {
                Node = TempNode -> right;
                SP *Parent = TempNode -> parent;
                while (Node -> left != NULL) 
                    Node = Node -> left;

                //Nhanh cay suy bien
                if (Node -> parent == TempNode) {
                    Node -> parent = Parent;
                    Node -> left = TempNode -> left;
                    Node -> DepthLeft = TempNode -> DepthLeft;
                    TempNode -> left -> parent = Node;

                    if (Parent != NULL) {

                        if (Parent -> left != NULL && Parent -> left -> x == TempNode -> x) 
                            Parent -> left = Node;
                        
                        else 
                            Parent -> right = Node;

                    }

                
                }

                else {
// THIS IS WRONG
                    SP *OldNode_Parent = Node -> parent, *OldNode_right = Node -> right;
                    
                    if (Parent != NULL)
                        Node -> parent = Parent;
                    else 
                        Node -> parent = NULL;
                    

                    Node -> left = TempNode -> left;
                    Node -> DepthLeft = TempNode -> DepthLeft;
                    TempNode -> left -> parent = Node;
                    
                    if (Parent != NULL) {

                        if (Parent -> left != NULL && Parent -> left -> x == TempNode -> x) 
                            Parent -> left = Node;
                        
                        else 
                            Parent -> right = Node;

                    }

                    if (OldNode_right != NULL) {
                        OldNode_Parent -> left = OldNode_right;
                        OldNode_Parent -> DepthLeft = max(OldNode_right -> DepthLeft, OldNode_right -> DepthRight) +1;
                        OldNode_right -> parent = OldNode_Parent;
                    }
                    else {
                        OldNode_Parent -> left = NULL;
                        OldNode_Parent -> DepthLeft = 0;
                    }


                    while (OldNode_Parent != TempNode) {
                        OldNode_Parent = OldNode_Parent -> parent;
                        OldNode_Parent -> DepthRight = max(OldNode_Parent -> right -> DepthLeft, OldNode_Parent -> right -> DepthRight) +1;
                    }

                    Node -> right = TempNode -> right;
                    Node -> DepthRight = TempNode -> DepthRight;
                    Node -> right -> parent = Node;

                }

                free(TempNode);
            }

            break;  
        }
        
    }
    if (Node == NULL) 
        return;


    if (Node -> parent == NULL) 
        First = Node;
    if (abs(Node -> DepthLeft - Node -> DepthRight) > 1) 
        First = FixTree(First);    
    
    while (Node -> parent != NULL) {
        
        // Node is left child
        if (Node -> parent ->left != NULL && Node -> parent -> left -> x == Node -> x)
            Node -> parent -> DepthLeft = max(Node -> DepthLeft, Node -> DepthRight) + 1;
        
        // Node is right child
        else 
            Node -> parent -> DepthRight = max(Node -> DepthLeft, Node -> DepthRight) + 1;

        Node = Node -> parent;

        // The Node is broken
        if (abs(Node -> DepthLeft - Node -> DepthRight) > 1) {
            SP *NewNode = Node;
            NewNode = FixTree(NewNode);

            if ((Node == First))
                First = NewNode;
            
            Node = NewNode;
        }
        
        if (Node -> parent == NULL) { 
            First = Node;
        }
    }
}

int main() {
    srand(time(NULL));
    setvbuf(stdout, NULL, _IONBF, 0);

    First = AppendNode(First , 10);
    Add_Node(15);
    Add_Node(7);
    Add_Node(8);
    Add_Node(9);

    DeleteNode(9);
    DeleteNode(8);
    DeleteNode(7);
    
    DeleteNode(15);
    printf("\n");
    //Test
    printf("%d %d %d", First -> x ,First -> DepthLeft, First -> DepthRight);

    return 0;
}