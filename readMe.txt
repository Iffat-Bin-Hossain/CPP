
***A class MyList is implemented by Array.Array is Consecutive Memory Aloocation.
***To Push something in the current position we shift every elements toward right from current position.Then put new-element at CurrPos. 
***for(i=Size;i>CurrPos;i--)
{
A[i+1]=A[i];
}
A[currPos]=new_element;
in worst case its Time complexity O(n).
***In case of Pushback new_data is appended on the last of the list.Its time Complexity O(1).because number of operation is input-independent.
***Most of the functions implemented in this file has a time complexity of O(1).Example:prev()[current Position--],next()[current Position++],Size()[return Size of the list],
setToPos(int pos)[set parameter as current position],setToBegin()[current position=0],setToEnd()[current position=Size-1],CurrPos()[return currPos],getValue()[data of currPos].
***Erase() is an O(n) Function.
for(i=currPos;i<Size;i++)
{
A[i]=A[i+1];
}
***Clear() is nothing but recurrent call of Erase();
***In linked list same operations are done by using Node(template data+Node pointer).

***[Head]->[data1,126356]->[data2,AB678C]->[data3,AF672C]->[NULL]
here push(),getValue(),Erase(),clear() and pushback() both has O(n) Time complexity.

LRU.cpp:-
here we need 2 Mylist(key) and mylist(value)
***put(key,value):-Time Complexity:-O(n)
if key exists from before then currpos shifted to the key and erase it.then (key+value) are pushed back.
else currpos=0 -> erase it -> push back(LRU shift to right)

***get(key):- Time Complexity:-O(n)
if key does not exist return -1
else (currpos->key)->Erase()->PushBack();
