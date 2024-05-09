#include <iostream>
using namespace std;

// Constants for salary adjustments
const int SALARY_INCREMENT = 100000;
const int SALARY_DECREMENT = 100000;

// Constants for performance evaluation
const int MIN_TASKS_WEB = 7;
const int MIN_TASKS_TESTING = 8;
const int MIN_TASKS_DESIGN = 6;
const int MIN_HOURS_WEB = 37;
const int MIN_HOURS_TESTING = 40;
const int MIN_HOURS_DESIGN = 37;
const int MAX_SALARY_WEB = 800000;
const int MAX_SALARY_TESTING = 500000;
const int MAX_SALARY_DESIGN = 1000000;
const int MIN_SALARY_WEB = 1500000;
const int MIN_SALARY_TESTING = 1000000;
const int MIN_SALARY_DESIGN = 1800000;

// Constants for performance evaluation criteria
const int MIN_PRESENTATIONS_FOR_RATING = 10;
const int MAX_LEAVES_FOR_RATING = 20;
const int HIGH_PERFORMANCE_THRESHOLD = 8;
const int HIGH_HOURS_THRESHOLD = 49;

// Function to recommend salary adjustment based on performance
void recommendSalary(string name, string domain, int tasksCompleted, int avgHoursWorked, int salary) {
    cout << "According to the performance of " << name << ", ";
    if (avgHoursWorked >= MIN_HOURS_WEB && tasksCompleted >= MIN_TASKS_WEB && domain == "web" && salary <= MAX_SALARY_WEB) {
        cout << "the salary is recommended to be incremented by " << SALARY_INCREMENT << "." << endl;

    } else if (avgHoursWorked >= MIN_HOURS_TESTING && tasksCompleted > MIN_TASKS_TESTING && domain == "testing" && salary <= MAX_SALARY_TESTING) {
        cout << "the salary is recommended to be incremented by " << SALARY_INCREMENT << "." << endl;

    } else if (avgHoursWorked >= MIN_HOURS_DESIGN && tasksCompleted > MIN_TASKS_DESIGN && domain == "design" && salary <= MAX_SALARY_DESIGN) {
        cout << "the salary is recommended to be incremented by " << SALARY_INCREMENT << "." << endl;

    } else if ((avgHoursWorked < MIN_HOURS_WEB || tasksCompleted < MIN_TASKS_WEB) && domain == "web" && salary >= MIN_SALARY_WEB) {
        cout << "the salary is recommended to be decremented by " << SALARY_DECREMENT << "." << endl;

    } else if ((avgHoursWorked < MIN_HOURS_TESTING || tasksCompleted <= MIN_TASKS_TESTING) && domain == "testing" && salary >= MIN_SALARY_TESTING) {
        cout << "the salary is recommended to be decremented by " << SALARY_DECREMENT << "." << endl;

    } else if ((avgHoursWorked < MIN_HOURS_DESIGN || tasksCompleted <= MIN_TASKS_DESIGN) && domain == "design" && salary > MIN_SALARY_DESIGN) {
        cout << "the salary is recommended to be decremented by " << SALARY_DECREMENT << "." << endl;
        
    } else {
        cout << "the salary is recommended to remain the same." << endl;
    }
}

// Function to evaluate employee performance
void evaluatePerformance(string name, int tasksCompleted, int avgHoursWorked, int previousRating, int presentationsGiven, int age, int experience, int leavesTaken) {
    int rating = 0;

    if (presentationsGiven >= MIN_PRESENTATIONS_FOR_RATING) rating++;
    if (leavesTaken <= MAX_LEAVES_FOR_RATING) rating++;
    if (tasksCompleted > HIGH_PERFORMANCE_THRESHOLD) rating += 2;
    if (avgHoursWorked > HIGH_HOURS_THRESHOLD) rating++;

    cout << "The evaluation of " << name << ":\n";
    cout << "This year's rating is " << rating << " out of 5." << endl;

    if (rating > previousRating) {
        cout << "The rating of " << name << " has increased. They have performed well this year." << endl;
    } else if (rating < previousRating && age < 25) {
        cout << "The employee has underperformed but can be trained for effective performance." << endl;
    } else if (rating < previousRating && age > 25) {
        cout << "The employee has underperformed and proved to be unproductive for the company." << endl;
    } else {
        cout << "The performance of the employee is maintained." << endl;
    }

    if (experience > 8 && previousRating == 5) {
        cout << name << " is recommended to get a promotion in the company." << endl;
    }
}

int main() {
    string name, domain, gender;
    int tasksCompleted, avgHoursWorked, salary, previousRating, presentationsGiven, age, experience, leavesTaken;

    cout << "Enter the Name of the Employee: ";
    cin >> name;

    cout << "In which domain " << name << " is working (web/testing/design): ";
    cin >> domain;

    cout << "What is the gender of " << name << " (M/F): ";
    cin >> gender;

    cout << "Let's evaluate the performance of " << name << endl << endl;

    cout << "What is the number of tasks successfully completed by " << name << " out of 10: ";
    cin >> tasksCompleted;

    cout << "What is the average hours " << name << " has worked each week: ";
    cin >> avgHoursWorked;

    cout << "What is the salary of " << name << " per year: ";
    cin >> salary;

    cout << "What is the previous rating of " << name << " out of 5: ";
    cin >> previousRating;

    cout << "How many presentations did " << name << " give last year: ";
    cin >> presentationsGiven;

    cout << "What is the age of the employee: ";
    cin >> age;

    cout << "What is the experience of " << name << ": ";
    cin >> experience;

    cout << "How many leaves did " << name << " take last year: ";
    cin >> leavesTaken;

    cout << endl;

    recommendSalary(name, domain, tasksCompleted, avgHoursWorked, salary);
    evaluatePerformance(name, tasksCompleted, avgHoursWorked, previousRating, presentationsGiven, age, experience, leavesTaken);

    return 0;
}
