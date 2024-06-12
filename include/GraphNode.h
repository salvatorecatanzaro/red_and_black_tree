#ifndef GRAPHNODE_H
#define GRAPHNODE_H
#include <string>
using namespace std;

class GraphNode
{
    public:
        /** Default constructor */
        GraphNode();
        /** Default destructor */
        ~GraphNode();

        /** Access m_Counter
         * \return The current value of m_Counter
         */
        string getColor() { return color; }
        /** Set m_Counter
         * \param val New value to set
         */
        void setColor(string val) { color = val; }

    protected:

    private:
        string color;
};

#endif // GRAPHNODE_H
