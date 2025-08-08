#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int numOfCourse = 0;
    double creditHour = 0.0, totalCreditsHours = 0.0, totalGradePoints = 0.0, grade = 0.0;
    cout << "Enter number of Courses you are enrolled in: ";
    cin >> numOfCourse;

    for (int i = 1; i <= numOfCourse; i++) {
        cout << "Course#" << i << ":" << endl;
        cout << "Enter Grade(on basis of 4.0 scale):";
        cin >> grade;
        if (grade < 0.0 || grade > 4.0) {
            cout << "Invalid grade. Must be between 0.0 and 4.0.\n";
            cin>>grade;
        }

        cout << "Enter credit hour of course(1-3 hours) " << i << ":";
        cin >> creditHour;
        if (creditHour < 1 || creditHour > 3) {
            cout << "Invalid credit hour. Must be between 1 and 3.\n";
            cin>>creditHour;
        }

        totalCreditsHours += creditHour;
        totalGradePoints += (grade*creditHour);
    }

    double CGPA = totalGradePoints / totalCreditsHours;
    cout << fixed << setprecision(2);
    cout << "Total Grade points are: " << totalGradePoints << endl;
    cout << "Total Credit Hours are: " << totalCreditsHours << endl;
    cout << "Your CGPA is: " << CGPA << endl;

    return 0;
}
