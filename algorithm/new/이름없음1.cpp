#include <iostream>
#include <string>
using namespace std;

class Person{
	public:
		friend void TEST(Person &p);
		Person();
		Person(const string name, const int age);
		string getName();
		int getAge();
		void setName(const string name);
		void setAge(const int age);
	private:
		string name;
		int age;
};

Person::Person():name("jane"), age(120){
}
Person::Person(const string name, const int age){
	this->name=name;
	this->age=age;
}

string Person::getName(){
	return name;
}
int Person::getAge(){
	return age;
}
void Person::setName(const string name){
	this->name=name;
}
void Person::setAge(const int age){
	this->age=age;
}

void TEST(Person &p){
	cout<<p.name<<endl;
	cout<<p.age<<endl;
	p.setAge(23);
	p.setName("love");
}

int main(){
	Person *pp1=new Person("jinyoung", 25);
	cout<<"name : "<<pp1->getName()<<endl;
	cout<<"age : "<<pp1->getAge()<<endl;
	delete(pp1);
	return 0;
}
