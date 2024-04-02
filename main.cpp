///Bin heap and dynamic heapsort
//#include <algorithm> (with this library is gonna be easier)
//[[ void push_heap(iterator.begin, iterator.end);  void pop_heap(--||--) ]]
//[[ void make_heap(--||--); bool is_heap(--||--) ]]

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Heap{
    vector <int> array; //Keepin heaps elements

    void goingUp(int i){ //(HELP FUNC for push)Taking index(for priorities)
        while (i != 0 && array[i] > array[(i - 1)/2]) {  // (i-1)/2 - dads index
            swap(array[i], array[(i - 1) / 2]);
            i = (i - 1) / 2; //Keeping priority
        }
    }

    void goingDown(int i){ //(HELP FUNC for pop)Taking index of element which needs to be downed(for priorities)
        while (2 * i + 1 < array.size()) { //dokud nejsme list(mame aspon jednoho leveho syna)
            int maxChild = 2 * i + 1; //taking left son for max for beggining
            if (maxChild + 1 < array.size() && array[maxChild] < array[maxChild + 1]) //if we have R son and L son < R
                maxChild++; //maxChild now is a R son (Its the index of max child)

            if (array[i] >=array[maxChild]) //OK
                break;

            swap(array[i],array[maxChild]);
            i = maxChild; //Keeping prioroty index
        }
    }
public:
    void push(int value){
        array.push_back(value); //Pushing el value the end of array
        goingUp(array.size() - 1); //Heaps refactoring(taking the last el)
    }             ///goingUp() == push_heap(array.begin(), array.end())

    int pop(){
        int value = array[0]; // Saving root
        array[0] = array[array.size() - 1]; //Swap first and last values / (1)
        array.pop_back(); //array.size --
        goingDown(0); /// (2) / (1)(2) == pop_heap(array.begin(), array.end())
        return value;
    }

};


int main() {
    Heap heap;
    int count;
    cout << "How big will be your array?" << endl;
    cin >> count;
    for (int i = 0; i < count; i++)
        heap.push(rand() % 100 + 1);
    for (int i = 0; i < count; i++)
        cout << heap.pop() << " ";

    return 0;
}
