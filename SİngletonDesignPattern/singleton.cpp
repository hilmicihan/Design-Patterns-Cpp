#include <iostream>
using namespace std;

class Singleton {
    static Singleton* instance;
    int data;

    // Private constructor so that no objects can be created.
    Singleton() {
        data = 0;
    }

public:
    // Static method to get the instance of the Singleton class.
    static Singleton* getInstance() {
        if (instance == NULL) {
            instance = new Singleton();
        }
        return instance;
    }

    void setData(int data) {
        this->data = data;
    }

    int getData() {
        return data;
    }
};

// Initialize pointer to zero so that it can be initialized in first call to getInstance()
Singleton* Singleton::instance = 0;

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    s1->setData(100);
    cout << "Data from s1: " << s1->getData() << endl;
    cout << "Data from s2: " << s2->getData() << endl;

    s2->setData(200);
    cout << "Data from s1: " << s1->getData() << endl;
    cout << "Data from s2: " << s2->getData() << endl;

    return 0;
}
