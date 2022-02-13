#include "lib/tp3.h"
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;
using std::size_t;


void binarySearchAll(Array& array, int toSearch, int& indexMin, int& indexMax)
{

    int start = 0;
    int end = array.size();
    int mid=0;
    indexMin =-1;
    indexMax =-1;
    while(start < end && indexMin==-1 || indexMax==-1){
        mid=(start+end)/2;
        if(toSearch > array[mid]){
            start=mid+1;
        }
        else if(toSearch < array[mid]){
            end=mid;
        }
        else if(toSearch == array[mid]){ //TODO boucle infini
            indexMin=start;
            while(indexMin < end && array[indexMin] != toSearch){
                indexMin++;
            }
            indexMax = end;
            while(start < indexMax && array[indexMax] != toSearch){
                indexMax--;
            }
        }
        else{
            indexMin =-1;
            indexMax =-1;
        }
    }
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 500;
	w = new BinarySearchAllWindow(binarySearchAll);
	w->show();

	return a.exec();
}
