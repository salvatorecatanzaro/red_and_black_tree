#include <iostream>
#include "RBGraph.h"
#include "LinkedListNode.h"
#include "Vertex.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void initRbGraph(RBGraph *rbgraph, ifstream *inputfile)
{
    int linecounter = 0;
    if (inputfile->is_open())
    {
        string line;
        while(getline(*inputfile, line) )
        {
            int space = line.find(" ");
            if (linecounter++ == 0)
            {
                string node_n = line.substr(0, space);
                string edge_n = line.substr(space, line.size());
                rbgraph->setVertexList(new Vertex*[stoi(node_n) + 1]());
                rbgraph->setSize(stoi(node_n) + 1);
                continue;
            }
            string node_s = line.substr(0, space);
            string node_d = line.substr(space, line.size());
            if(node_s.empty() || node_d.empty())
            {
                cout << "Skipping " <<"Node source " << node_s << " Node destination " << node_d << endl;
                continue; // Skipping this node, something wrong here
            }

            cout <<"Node source " << node_s << " Node destination " << node_d << endl;
            int i = stoi(node_s);
            int j = stoi(node_d);
            Vertex *vertex_i = rbgraph->getVertexList()[i];
            Vertex *vertex_j = rbgraph->getVertexList()[j];
            if (vertex_i == nullptr)
            {
                rbgraph->getVertexList()[i] = new Vertex(i);
                vertex_i = rbgraph->getVertexList()[i];
            }
            if (vertex_j == nullptr)
            {
                rbgraph->getVertexList()[j] = new Vertex(j);
                vertex_j = rbgraph->getVertexList()[j];
            }
            rbgraph->addEdge(vertex_i, vertex_j);
        }
        inputfile->close();
    }
    rbgraph->printRBGraph();
}


int main()
{
    RBGraph *rbgraph = new RBGraph();
    ifstream *inputfile = new ifstream("input.txt");
    initRbGraph(rbgraph, inputfile);
    cout << "TRACCIA 3" << endl;
    bool exit = false;
    while(!exit)
    {
        cout << "Scegli una delle opzioni" << endl;
        cout << "1. AddEdge" << endl;
        cout << "2. RemoveEdge" << endl;
        cout << "3. FindEdge" << endl;
        cout << "4. BFS" << endl;
        cout << "5. Esci" << endl;
        int x;
        cin >> x;
        if(x == 1)
        {
            int i, j;
            cout << "Inserire valore intero per la source" << endl;
            cin >> i;
            cout << "Inserire valore intero per la destination" << endl;
            cin >> j;
            if(i > rbgraph->getSize() || j > rbgraph->getSize())
            {
                cout << "inserire un valore 0 < \"i/j\"" << "< " << rbgraph->getSize() << endl;
                continue;
            }

            Vertex *vertex_i = rbgraph->getVertexList()[i];
            Vertex *vertex_j = rbgraph->getVertexList()[j];
            if (vertex_i == nullptr)
            {
                rbgraph->getVertexList()[i] = new Vertex(i);
                vertex_i = rbgraph->getVertexList()[i];
            }
            if (vertex_j == nullptr)
            {
                rbgraph->getVertexList()[i] = new Vertex(j);
                vertex_j = rbgraph->getVertexList()[j];
            }
            rbgraph->getVertexList()[j];
            rbgraph->addEdge(vertex_i, vertex_j);
            rbgraph->printRBGraph();
        }
        else if(x == 2)
        {
            int i, j;
            cout << "Inserire valore intero per la source" << endl;
            cin >> i;
            cout << "Inserire valore intero per la destination" << endl;
            cin >> j;
            if(i > rbgraph->getSize() || j > rbgraph->getSize())
            {
                cout << "inserire un valore 0 < \"i/j\"" << "< " << rbgraph->getSize() << endl;
                continue;
            }
            rbgraph->removeEdge(i, j);
            rbgraph->printRBGraph();
        }
        else if(x == 3)
        {
            int i, j;
            cout << "Inserire valore intero per la source" << endl;
            cin >> i;
            cout << "Inserire valore intero per la destination" << endl;
            cin >> j;
            if(i > rbgraph->getSize() || j > rbgraph->getSize())
            {
                cout << "inserire un valore 0 < \"i/j\"" << "< " << rbgraph->getSize() << endl;
                continue;
            }
            if(rbgraph->findEdge(i, j))
                cout <<"("<< i << ", " << j << ") esiste" << endl;
            else
                cout <<"("<< i << ", " << j << ") non esiste" <<endl;
        }
        else if(x == 4)
        {
            int i;
            cout << "Inserire valore intero per la source" << endl;
            cin >> i;
            if(i > rbgraph->getSize())
            {
                cout << "inserire un valore 0 < \"i\"" << "< " << rbgraph->getSize() << endl;
                continue;
            }
            Vertex *node = rbgraph->getVertexList()[i];
            rbgraph->BFS(node);
        }
        else if(x == 5)
            exit = true;
        else
        {
            cout << "Il valore non e' tra le opzioni, riprova" << endl;
        }
    }
    cout << "DONE";
    return 0;
}
