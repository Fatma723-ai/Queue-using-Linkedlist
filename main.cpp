#include<bits/stdc++.h>

using namespace std;
class node
{
    public:
    int date;
    node *next ;
   node()
   {
       date=0;
       next = NULL;
   }
};
class Queue
{
    node *Front;
    node * rear;
public :
    Queue()
    {
        Front = rear= NULL;
    }
    bool isempty()
    {
        return Front== NULL;
    }

    void Enqueue(int item)
    {
      if ( isempty())
      {
          node *newnode = new node;
          newnode->date = item;
          Front = rear= newnode;
      }else
      {
          node *newnode = new node;
          newnode->date = item;
             rear->next = newnode;
             rear= newnode;
      }
    }
 void Dnqueue ()
    {
        if (isempty())
        {
            cout<<"Not Possible- The Queue Is Empty "<<endl;
        } else if (Front == rear)
        {
            delete Front;
            Front = rear =NULL;
        }else
        {

        int value;
      node *delptr=Front;

    Front = Front->next;
      delete delptr;

        }
    }
    int peek()
    {
        return   Front->date;
    }

    void display()
    {
        if (isempty())
        {
               cout<<"The Queue Is Empty"<<endl;
        }else {
            node *temp =Front;
            while(temp != NULL)
            {
            cout<<temp->date<<" ";
          temp = temp->next;
            }
            cout<<endl;
    }
    }
       int Count()
    {
        int counter=0;
            node *temp =Front;
            while(temp != NULL)
            {
          counter++;
          temp = temp->next;
            }
          return counter;
    }
    bool isfound(int item)
    {
    bool found= false;
      node *temp = Front;
      while(temp != NULL)
      {
          if(temp->date == item)
            found = true;

          temp = temp->next;
      }
      return found;
    }
  void Clear()
  {
     while (!isempty())
      {
         Dnqueue();

      }

  }
};
int main()
{
    int item;
     Queue q;
    for (int i=0; i<3; i++)
    {
           cout <<"Enter Item to push"  << endl;
           cin >>item;
           q.Enqueue(item);

    }
     q.display();
/*
     q.Dnqueue();
     cout<<"After Dequeue"<<endl;
        q.display();
         q.Dnqueue();
           cout<<"After Dequeue"<<endl;
        q.display();
    */
    /*
     cout<<"Enter Item for Search for"<<endl;
     cin>>item;
   if  ( q.isfound(item))
   {
       cout<< "Is Found"<<endl;
   } else
   {
         cout<< "Is Not Found"<<endl;
   }
   cout <<"Count= "<<q.Count()<<endl;
*/


cout<<" After Clear All Item"<<endl;
q.Clear();
  q.display();
    return 0;
}
