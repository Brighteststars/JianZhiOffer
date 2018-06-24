
#include <iostream>


struct Node
{
    int val;
    Node* next;
    Node(int v):val(v){}
};

Node* ListMerge(Node* head1,Node* head2)
{
    if(head1 == nullptr)
        return head2;
    if(head2 == nullptr)
        return head1;
    Node* head = nullptr;
    if(head1->val < head2->val)
    {
        head = head1;
        head->next = ListMerge(head1->next,head2);
    }
    else{
        head = head2;
        head->next = ListMerge(head1,head2->next);
    }

    return head;
}


Node* CreateList1()
{
    Node* n1 = new Node(1);
    Node* n3 = new Node(3);
    Node* n5 = new Node(5);
    Node* n7 = new Node(7);

    Node* head = n1;
    n1->next = n3;
    n3->next = n5;
    n5->next = n7;
    n7->next = nullptr;

    return head;
}

Node* CreateList2()
{
    Node* n2 = new Node(2);
    Node* n4 = new Node(4);
    Node* n6 = new Node(6);
    Node* n8 = new Node(8);

    Node* head = n2;
    n2->next = n4;
    n4->next = n6;
    n6->next = n8;
    n8->next = nullptr;

    return head;
}

void VisitList(Node* head)
{
    if(head)
    {
        printf("%d->",head->val);
        VisitList(head->next);
    }
    else{
        printf("%s\n","NULL");
    }
}

void FreeList(Node* head)
{
    if(head)
    {
        Node* pNext = head->next;
        delete head;
        FreeList(pNext);

    }
    else{
        return;
    }
}
