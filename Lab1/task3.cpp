#include<iostream>
#include<string>
using namespace std;
class Document{
    string *text;
    public:
    Document(string userText){
        text = new string(userText);
    }
    Document(const Document&obj){
        text = new string(*obj.text);
    }
    Document& operator=(const Document&obj){
        this->text = new string(*obj.text);
        return *this;
    }
    ~Document(){
        cout<<"Destructor called with the text: "<<*text<<endl;
        delete text;
    }
    void display(){
        cout<<"Text: "<<*text<<endl;
    }
};

int main(){
    Document doc1("FAST NUCES Is a renowned university");
    Document doc2(doc1);
    doc1.display();
    doc2.display();
    Document doc3("FAST Offers multiple computing programs");
    doc3.display();
    doc3 = doc1;
    doc3.display();
    return 0;

}