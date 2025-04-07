#include "Graph.h"

void Graph::InitializeGraph(int nodeCount)
{
    if (graph != nullptr)
    {
        cout << "이미 할당이 완료 되었습니다." << endl;
        return;
    }

    graph = new Node* [nodeCount];
    Count = nodeCount;
    for (int i = 0; i < nodeCount; i++)
    {
        graph[i] = CreateNode(i);
    }
}

void Graph::AddEdge(int from, int to)
{
    Node* newEdge = CreateNode(to);
    if (graph[from]->next == nullptr)
    {
        graph[from]->next = newEdge;
    }
    else
    {
        Node* temp = graph[from]->next;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newEdge;
    }
}

void Graph::DeleteEdge(int node, int deleteEdge)
{
    Node* del = graph[node]->next;
    Node* pre = graph[node];

    if (del == nullptr)
    {
        return;
    }
    if (del->data == deleteEdge)
    {
        pre->next = del->next;
        delete del;
        return;
    }

    while (del != nullptr)
    {
        if (del->data == deleteEdge)
        {
            pre->next = del->next;
            delete del;
            break;
        }
        pre = del;
        del = del->next; 
    }
}

void Graph::ShowGraphEdge(int node)
{
    Node* show = graph[node]->next;
    if (show == nullptr)
    {
        cout << node << " 비어있음" << endl;
        return;
    }

    while (show != nullptr)
    {
        cout << show->data << " ";
        show = show->next;
    }
    cout << "\n";
}

Node* Graph::CreateNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data + 1;
    newNode->next = nullptr;
    return newNode;
}

Graph::Graph()
{
    graph = nullptr;
}

Graph::~Graph()
{
    for (int i = 0; i < Count; i++)
    {
        Node* current = graph[i];
        while (current != nullptr)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] graph;
    graph = nullptr;
}
