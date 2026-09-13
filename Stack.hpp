#pragma once
#include "Node.hpp"

template <class T>
class Stack 
{   
    private:
        Node <T>* tope;
    public:
        Stack() { this->tope = nullptr; }
        bool isEmpty() { return this->tope == nullptr; }
        
        void push(T value) 
        {
            Node<T>* nuevo = new Node<T>(value);
            nuevo->next = this->tope;
            this->tope = nuevo;
        }

        T top()
        {
            if (this->isEmpty()) 
            {
                throw "La pila está vacía";
            }
            return this->tope->getValue();
        }

        void pop() 
        {
            if (this->isEmpty()) 
            {
                throw "La pila está vacía";
                return;
            }
            Node<T>* nodoABorrar = this->tope;
            this->tope = this->tope->next;
            delete nodoABorrar;
        }

        void clear() 
        {
            while (!this->isEmpty()) 
            {
                this->pop();
            }
        }

        ~Stack() 
        {
            this->clear();
        }

};
