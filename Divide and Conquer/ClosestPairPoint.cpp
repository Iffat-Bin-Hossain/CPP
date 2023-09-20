#include<iostream>
#include<cmath>
using namespace std;
class Point{
    public:
    int x,y;
    Point(){

    }
    Point(int x,int y){
        this->x=x;
        this->y=y;
    }
};
void printArray(Point Arr[], int size)
{
    for (int i = 0; i < size; i++){
      cout <<"("<< Arr[i].x<<","<<Arr[i].y<<")"<< " ";
    }
    cout<<endl;

}
void Merge(Point Arr[], int left, int mid,int right)
{
    int llen = mid-left + 1;
    int rlen = right - mid;
    Point leftArr[llen],rightArr[rlen];
    for (int i = 0; i < llen; i++)
        leftArr[i] = Arr[left + i];
    for (int j = 0; j < rlen; j++)
        rightArr[j] = Arr[mid + 1 + j];
    int i,j;
    int k= left;
    i=0;
    j=0;
    while (i <llen && j <rlen)
    {
        if (leftArr[i].x<=rightArr[j].x)
        {
            Arr[k]=leftArr[i];
            k++;
            i++;
        }
        else
        {
            Arr[k]=rightArr[j];
            j++;
            k++;
        }
    }
    while (i<llen)
    {
        Arr[k]=leftArr[i];
        k++;
        i++;
    }
    while (j<rlen)
    {
        Arr[k]=rightArr[j];
        k++;
        j++;
    }
}
void MergeSort(Point Arr[], int left, int right)
{
    if (left >= right){
       return;
    }
    int mid = (left+right)/2;
    MergeSort(Arr, left, mid);
    MergeSort(Arr, mid+1,right);
    Merge(Arr,left,mid,right);
}

float distance(Point p1,Point p2){
    float d=sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
    return d;
}
float bruteForce(Point P[], int n)
{

    float min =100000;

    for (int i = 0; i < n;i++) {

        for (int j = i+1; j < n; i++) {

            if (distance(P[i], P[j]) < min) {
                min = distance(P[i], P[j]);
            }
        }
    }
    return min;
}
float ClosestPair(Point P[],int size){

}

int main()
{
 Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
 int size = sizeof(P) / sizeof(P[0]);
 MergeSort(P, 0,size-1);
 float nearestDistance=ClosestPair(P,size);
}
