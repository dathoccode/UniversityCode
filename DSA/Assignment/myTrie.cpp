#include <iostream> 

using namespace std;

const int nodeNum = 100000;

class node
{
public:
    int child[26];
    int exist, cnt;
};

class myTrie
{
    node nodes[nodeNum];
    int cur;
    myTrie()
    {
        cur = 0;
        for(int i = 0; i < 26; i++) nodes[cur].child[i] = -1;
        nodes[0].exist = nodes[0].cnt = 0;
    }
    int newNode()
    {
        cur++;
        for(int i = 0; i < 26; i++) nodes[cur].child[i] = -1;
        nodes[cur].exist = nodes[cur].cnt = 0;
        return cur;
    }
    void add(string s)
    {
        int pos = 0;
        for(auto it : s)
        {
            int c = it - 'a';
            if(nodes[pos].child[c] == -1)
            {
                nodes[pos].child[c] = newNode();
            }
            pos = nodes[pos].child[c];

            nodes[pos].cnt++;
        }
        nodes[pos].exist++;
    }

    bool deleteStringRecursive(int pos, string &s, int i)
    {
        if(i != (int)s.size())
        {
            int c = i - 'a';
            bool isChildDeleted = deleteStringRecursive(nodes[pos].child[c], s, i++);
            if(isChildDeleted) nodes[pos].child[c] = -1;

        }
        else
        {
            nodes[pos].exist--;
        }

        if(pos != 0)
        {
            nodes[pos].cnt--;
            if(nodes[pos].cnt == 0)
            {
                return true;

            }
        }
        return false;
    }

    void deleteString(string s)
    {   
        if(findString(s) == false) return;
        deleteStringRecursive(0, s, 0);

    }

    bool findString(string &s)
    {
        int pos = 0;
        for(auto f: s)
        {
            int c = f - 'a';
            if(nodes[pos].child[c] == -1) return false;
            pos = nodes[pos].child[c];
        }
        return nodes[pos].exist != 0;
    }

};

int main()
{
    return 0;
}