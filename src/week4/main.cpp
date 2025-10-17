#include <iostream>
#include "symbolTableLinkedList.cpp"
using namespace std;

int main() {
    SymbolTableLinkedList st;
    st.put("A", 10);
    st.put("C", 30);
    st.put("B", 20);
    st.put("E", 50);
    st.put("D", 40);
    st.put("S", 100);
    st.put("Cd", 80);

    cout << "min = " << st.min() << endl;
    cout << "max = " << st.max() << endl;
    cout << "floor(Cd) = " << st.floor("Cd") << endl;
    cout << "ceiling(Cd) = " << st.ceiling("Cd") << endl;
    cout << "rank(C) = " << st.rank("C") << endl;
    cout << "select(2) = " << st.select(2) << endl;

    cout << "\n\nKeys between B and D: ";
    st.keys("B", "D");

    cout << "\nDeleteMin(); DeleteMax();\n";
    st.deleteMin();
    st.deleteMax();
    st.keys();
}
