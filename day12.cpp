// Day 12: Inheritance

/*
You are given two classes, Person and Student, where Person is the base class
and Student is the derived class. Completed code for Person and a declaration
for Student are provided for you in the editor. Observe that Student inherits
all the properties of Person.
*/

#include <iostream>
#include <vector>

using namespace std;


class Person {
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification) {
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}

		void printPerson() {
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
		}
	
};

class Student : public Person {
	private:
		vector<int> testScores;  
	public:
    /*	
    *   Class Constructor
    *   
    *   Parameters:
    *   firstName - A string denoting the Person's first name.
    *   lastName - A string denoting the Person's last name.
    *   id - An integer denoting the Person's ID number.
    *   scores - An array of integers denoting the Person's test scores.
    */
    Student(string firstName, string lastName, int id, vector<int> scores): Person(firstName, lastName, id) {
      this->testScores = scores;
    }

    /*	
    *   Function Name: calculate
    *   Return: A character denoting the grade.
    */
    char calculate(void) {
      int sum = 0;
      for (int i = 0; i < this->testScores.size(); i++) {
        sum += this->testScores[i];
      }

      float average = sum / this->testScores.size();

      char result;
      if (average >= 90) {
        result = 'O';
      } else if (average >= 80) {
        result = 'E';
      } else if (average >= 70) {
        result = 'A';
      } else if (average >= 55) {
        result = 'P';
      } else if (average >= 40) {
        result = 'D';
      } else {
        result = 'T';
      }

      return result;
    }
};

int main(void) {
	string firstName;
  string lastName;
	int id;

  int numScores;
	cin >> firstName >> lastName >> id >> numScores;
  vector<int> scores;
  for (int i = 0; i < numScores; i++){
    int tmpScore;
    cin >> tmpScore;
    scores.push_back(tmpScore);
	}

	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout << "Grade: " << s->calculate() << "\n";

	return 0;
}