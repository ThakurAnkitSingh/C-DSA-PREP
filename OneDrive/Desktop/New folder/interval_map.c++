#include <bits/stdc++.h>
using namespace std;


template <typename K, typename V>
class interval_map
{
    map<K, V> m_map;
public:

    // Constructor
    interval_map(V const &val)
    {
        m_map.insert(m_map.begin(), {numeric_limits<K>::lowest(), val});
    }

    void assign(K const &keyBegin, K const &keyEnd, V const &val)
    {

        if (!(keyBegin < keyEnd))
            return;

        pair<K, V> beginExtra;
        pair<K, V> endExtra;
        bool beginHasExtra = false;
        bool endHasExtra = false;

        typename map<K, V>::iterator itBegin = m_map.lower_bound(keyBegin);
        if (itBegin != m_map.begin() && keyBegin < itBegin->first)
        {
            beginHasExtra = true;
            --itBegin;
            beginExtra = *itBegin;
        }

        typename map<K, V>::iterator itEnd = m_map.lower_bound(keyEnd);
        if (itEnd != m_map.end() && keyEnd < itEnd->first)
        {
            endHasExtra = true;
            endExtra = *itEnd;
        }

        // inserting new interval
        m_map.erase(itBegin, itEnd);
        m_map[keyBegin] = val;

        // Exist then insert it
        if (beginHasExtra && beginExtra.second != val)
            m_map[keyBegin] = beginExtra.second;

        // Exist then insert it
        if (endHasExtra && endExtra.second != val)
            m_map[keyEnd] = endExtra.second;
    }

    // Print function of Interval Map
    void printMap()
    {
        for (const auto &duo : m_map)
        {
            cout << duo.first << " -> " << duo.second << endl;
        }
    }
};

int main()
{
    interval_map<int, char> myMap('C'); // Initialize with 'C'
    myMap.assign(1, 3, 'A');
    myMap.assign(5, 7, 'B');
    myMap.printMap();                   // Print the map
    return 0;
}
