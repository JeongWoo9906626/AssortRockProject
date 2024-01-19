#include <iostream>

typedef int DataType;
class Node
{
public:
    Node* Next = nullptr;       // 8
    Node* Prev = nullptr;       // 8
    DataType Value;             // 4
};

// 24??->48

int main()
{
    Node Node0;
    Node Node1;
    Node Node2;
    Node Node3;
    Node Node4;
    Node Node5;
    Node Node6;

    Node0.Value = 0;
    Node1.Value = 1;
    Node2.Value = 2;
    Node3.Value = 3;
    Node4.Value = 4;
    Node5.Value = 5;
    Node6.Value = 6;

    int a = 0;

    Node0.Next = &Node1;
    Node1.Next = &Node2;
    Node2.Next = &Node3;
    Node3.Next = &Node4;
    Node4.Next = &Node5;
    Node5.Next = &Node6;

    Node1.Prev = &Node0;
    Node2.Prev = &Node1;
    Node3.Prev = &Node2;
    Node4.Prev = &Node3;
    Node5.Prev = &Node4;
    Node6.Prev = &Node5;

    Node* CurNode = &Node0;

    while (nullptr != CurNode)
    {
        std::cout << CurNode->Value << std::endl;
        CurNode = CurNode->Next;
    }

    CurNode = &Node6;

    while (nullptr != CurNode)
    {
        std::cout << CurNode->Value << std::endl;
        CurNode = CurNode->Prev;
    }
}