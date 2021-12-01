#include<iostream>
using namespace std;

struct list{
    public:
    int data;
    list *next;
    
};

list *head = NULL;
list *rear = NULL;


list *createList(int data,list *head){
    //creating a new node
    list *temp = (list*)(malloc(sizeof(list)));
    temp->data = data;
    temp->next = NULL;

    //check if list is empty
    if (head == NULL){
        head  =  temp;
        rear = temp;
        
    }
    else {
        rear -> next = temp;
         rear = temp;
       
    }
    // cout << head -> data << endl;
    // cout << rear -> data << endl;
    return head;


}

void displayList(list *head){                  //O(n)
    list *temp = head;
    while (temp != NULL){
        cout  << temp->data << "->";
        temp = temp->next;
    } 
}

list *FindMethod(list *head,int find){          
    list *curr = head;
    list *prev = NULL;


    while(curr != NULL){                   //O(n)

        //if key is found
        if (curr->data == find){
            cout << "Element found" << endl;

            //if current is 1st node
            if (prev!= NULL){

                //rearrange list
                prev->next = curr->next;
                curr->next = head;
                head= curr;
            }
           
            return head;
        }
        prev = curr;
        curr = curr->next;

    }
    //key not found
      cout << "Element not found" << endl;
        return head;


}

int main()
{
   cout << "Enter number of elements in list" << endl;
    int n;
    cin >> n;
    list *head = NULL;
    cout << "Enter elements of list" << endl;
    for (int i = 0; i < n;i++){                    //O(n)
        int data;
        cin >> data;
        head = createList(data,head);
        
    }
    displayList(head);

    cout << endl <<  "Enter element to be searched" << endl;
    int find;
    cin >> find;
    head =FindMethod(head,find);
    displayList(head);

    return 0;
}

//Time complexity of function of finding and rearranging = O(n)