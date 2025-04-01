#include "Graph.h"

void Graph::InitializeGraph(int nodeCount)
{
    if (graph != nullptr)
    {
        cout << "이미 할당이 완료 되었습니다." << endl;
        return;
    }

    graph = new Node* [nodeCount];
    for (int i = 0; i < nodeCount; i++)
    {
        graph[i] = CreateNode(nodeCount);
    }
}

void Graph::AddEdge(int from, int to)
{
    Node* newEdge = new Node;
    newEdge->data = graph[to]->data;
    newEdge->next = nullptr;
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
    while (del->next != nullptr)
    {
        if (del->data == deleteEdge)
        {
            pre->next = del->next;
            delete del;
            break;
        }
        del = del->next;
        pre = pre->next;
    }
}

void Graph::ShowGraphEdge(int node)
{
    Node* show = graph[node]->next;
    while (show->next != nullptr)
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
    delete[] graph;
    graph = nullptr;
}
