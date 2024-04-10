//implementacion del Queue

#include <iostream>
#define SIZE 5

using namespace std;

class Queue{
    private: 
        int items[SIZE], front, rear;
    public:
        Queue( ){
            front = -1;
            rear =  -1;
        }

        bool isFull(){
            if (front == 0 && rear == SIZE -1 ){
                return true;
            }
            return false;
        }


        bool isEmpty(){
            if (front == -1 ){
                return true;
            }
            return false;
        }

        void enQueue(int element){
            if (isFull()){
                cout << "Queue lleno";
            }else {
                if (front == -1) front = 0;
                rear++;
                items[rear] = element;
                cout << endl;
                cout << "Insertar " << element << endl;
                
            }
            
        }

        int deQueue(){
            int element;
            if (isEmpty()){
                cout << "Queque vacio" << endl;
                return (-1);
            }else {
                element = items[front];
                if (front >= rear){
                    front = -1;
                    rear = -1;
                }//Q solo tiene un elemento, se resetea Queue despues de eliminarlo
                else{
                    front++;
                }
                cout << endl;
                cout << "eliminado-> " << element << endl;
                return(element);
            }
        }

        void display(){
        //se imprimen elementos
        int i;
        if (isEmpty()){
            cout << "Queue vacio" << endl;
        }else{
            cout << "Indice Front->" <<front << endl;
            cout << "Items" ;
            for (int i = 0; i <= rear; i++)
                cout << items[i] << " ";
            cout << endl;
            cout << "Indice Rear-> " << rear << endl;
        }
    }
};

// Función principal
int main() {
   
    Queue q;

    //No es posibile un Queue vacio
    q.deQueue();

    //Se agregan 5 elementos
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);

    //6to elemento no pued eser anadido xq Queue full
    q.enQueue(5);

    q.display();

    //se elimina 1er elemento
    q.deQueue();

    //quedan 4 elementos
    q.display();
    
    return 0;
}
