/**
    What is STL - https://www.geeksforgeeks.org/the-c-standard-template-library-stl/
    Some useful resources to learn STL in Bangla
        1. http://www.progkriya.org/gyan/stl.html
        2. https://zobayer2009.wordpress.com/
        3. https://www.youtube.com/watch?v=awY7oJ7wFhs&list=PLgLCjVh3O6Sgux985GYG22xkFt9z9Sq0_
*/
// constructing vectors
#include <iostream>
#include <vector>
using namespace std;

int main () {
    vector<int> first;
    cout << first.size() << endl;

    vector<int> second (4,200);
    cout << second.size() << endl;
    cout << "The contents of second are:";
    for(int i=0;i<second.size();i++)
        cout << " " << second[i];
    cout<<endl;

    vector<int> third (second.begin(),second.end());
    cout << third.size() << endl;
    cout << "The contents of third are:";
    for(int i=0;i<third.size();i++)
        cout << " " << third[i];
    cout<<endl;

    vector<int> fourth (third);// a copy of third
    cout << fourth.size() << endl;
    cout << "The contents of fourth are:";
    for(int i=0;i<fourth.size();i++)
        cout << " " << fourth[i];
    cout<<endl;

    // the iterator constructor can also be used to construct from arrays:
    int myints[] = {16,2,77,29};
    vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
    cout << fifth.size() << endl;

    cout << "The contents of fifth are:";
    for (int i=0; i < fifth.size(); i++)
        cout << " " << fifth[i];
    cout << endl;

    //copy a vector
    vector<int> sixth;
    sixth = fifth;
    cout << sixth.size() << endl;
    cout << "The contents of sixth are:";
    for (int i=0; i < sixth.size(); i++)
        cout << " " << sixth[i];
    cout << endl;

    //iterating through a vector
    /**
        1. using index
        2. using iterator
    */
    cout << "Using iterator:";
    vector<int> :: iterator it;
    for(it=sixth.begin();it<sixth.end();it++)
        cout<<" "<<*it;
    cout << endl;

    //some useful functions
    /**
        1. push_back()
        2. size()
        3. back()
        4. pop_back()
        5. empty()
    */

    sixth.push_back(27);
    cout << "inserting: " << sixth.back() << endl;
    sixth.push_back(72);
    cout << "inserting: " << sixth.back() << endl;
    cout << "-------------------\n";

    while(!sixth.empty()) {
        cout << "size: " << sixth.size();
        cout << " last element: " << sixth.back() << endl;
        sixth.pop_back();
    }
    cout << "vector empty\n";

    return 0;
}
