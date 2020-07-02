#include <map>
#include <iostream>

int main( )
{
    using namespace std;
    multimap <int, int> m1;

    multimap <int, int> :: iterator m1_Iter;
    multimap <int, int> :: const_iterator m1_cIter;
    multimap <int, int> :: const_iterator m1_eIter;
    typedef pair <int, int> Int_Pair;

    m1.insert ( Int_Pair ( 0, 0 ) );
    m1.insert ( Int_Pair ( 1, 1 ) );
    m1.insert ( Int_Pair ( 1, 3 ) );
    m1.insert ( Int_Pair ( 2, 4 ) );

    m1_cIter = m1.begin ( );
    cout << "The first element of m1 is " << m1_cIter -> first << endl;
    cout << "The second element of m1 is " << m1_cIter -> second << endl;
    // cout << "The third element of m1 is " << m1_cIter -> third << endl; // no third

    m1_Iter = m1.begin ( );
    m1.erase ( m1_Iter );

    // The following 2 lines would err because the iterator is const
    // m1_cIter = m1.begin ( );
    // m1.erase ( m1_cIter );

    m1_cIter = m1.begin( );
    cout << "The first element of m1 is now " << m1_cIter -> first << endl;

    // Keys must be unique in map, so duplicates are ignored
    int i = m1.count(1);
    cout << "The number of elements in m1 with a sort key of 1 is: " << i << "." << endl;

    i = m1.count(2);
    cout << "The number of elements in m1 with a sort key of 2 is: " << i << "." << endl;

    m1_Iter = m1.begin( );
    m1_eIter = m1.end();
    cout << "double each element in map:\n<key -> value>\n";
    while ( m1_Iter != m1_eIter)
    {
        m1_Iter -> second *= 2;
        cout << m1_Iter -> first << " -> " << m1_Iter -> second << "\n";
        m1_Iter++;
    }
    m1_Iter = m1.find(2);
    cout << "The number of element in map with a key 2 is: " << m1_Iter->second << endl;

    i = m1.size();
    m1.clear();
    cout << "The size of the map after clearing is " << m1.size() << ", whcih before is " << i << "." << endl;

}