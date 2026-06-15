
// Name: Aden Nguyen
// Date: 06/15/26
// Course: COSC 1437 C++ Programming Fundamentals II
// Desc: Chapter 7 Lab - Student Course Enrollment System

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

namespace EnrollmentSystem
{
    enum courseType
    {
        ENGLISH,
        MATH,
        HISTORY,
        CPP,
        BIOLOGY,
        ART
    } currentCourse;

    typedef int StudentID;
    typedef double CreditHours;

    void printCourse(courseType);
    courseType readCourse();
    double calcTuition(CreditHours);
    void printStudentInfo(string, string, courseType, StudentID, CreditHours);
}

using namespace EnrollmentSystem;


int main()
{

    string welcome = "!!!WELCOME USER!!!";
    string line = "===================================== " + welcome + "===================================== ";

    string firstName, lastName, fullName;
    string emailUser, email;

    cout << "Enter first name: ";
    cin >> firstName;
    cout << "Enter last name: ";
    cin >> lastName;

    
    fullName = firstName + " " + lastName;
    cout << "Your fullname is: " << fullName << endl;
    
    cout << "There are " << fullName.length() << " characters in your name" << endl;
    
    cout << "Your first name is " << fullName.substr(0, fullName.find(" ")) << endl;
   
    cout << "Your first inital is " << firstName.at(0) << endl;
  
    cout << "The space is at the " << fullName.find(" ") << " position" << endl;

    cout << "Enter email username (e.g. jsmith): ";
    cin >> emailUser;

    
    if (!emailUser.empty())
    {
      
        email = emailUser.insert(emailUser.length(), "@sanjac.edu");
        cout << "Email with typo: " << email << endl;
        
        email.replace(email.find("sanjac"),6, "SanJac");
        cout << "After fixing the typo " << email << endl;
        
        //removes trailing punctuaction
        email.erase(email.find(".edu") + 4);

        string lastName2 = "Smith";
        cout << "Names in alphabetical Order:" << endl;
        if (lastName.compare(lastName2) > 0)
        {
            cout << lastName2 << endl;
            cout << lastName << endl;
        }
        else if (lastName.compare(lastName2) < 0)
        {
            cout << lastName << endl;
            cout << lastName2 << endl;
        }
        else
        {
            cout << "The last names are the same" << endl;
        }
    }
    else
    {
        email = "N/A";
    }

    currentCourse = readCourse();
    courseType selectedCourse = currentCourse;
    cout << "You selected: ";
    printCourse(currentCourse);
    cout << endl;

    // TODO: Advance currentCourse by one using static_cast (check that it is not already ART first).
    if(currentCourse != ART)
    {
        currentCourse = MATH;
        currentCourse = static_cast<courseType>(currentCourse + 1);
        printCourse(currentCourse);
    }

    for (currentCourse = ENGLISH; currentCourse <= ART; currentCourse = static_cast<courseType>(currentCourse + 1))
    {
        printCourse(currentCourse);
    }
    cout << endl;

    courseType class1 = selectedCourse;
    courseType class2 = HISTORY;
    if (class1 < class2)
    {
        printCourse(class2);
        cout  << "comes later in the day " << endl;
    }
    else
    {   printCourse(class1);
        cout  << "comes later in the day " << endl;
    }

    CreditHours hours;
    StudentID sid = 10045;
    cout << "\nEnter credit hours: ";
    cin >> hours;

    double tuition = calcTuition(hours);
    cout << "Total Tuition is: $" << tuition << endl;

  
    printStudentInfo(fullName, email, selectedCourse, sid, hours);

    // I am using full scope resloution syntax because it directly tells the reader
    // where the source is and avoids naming conflicts.
    cout << "NameSpace Demo: ";
    EnrollmentSystem::printCourse(EnrollmentSystem::CPP);

    return 0;

    /*TEST RUN #1
        Enter first name: Aden
        Enter last name: Nguyen
        Your fullname is: Aden Nguyen
        There are 11 characters in your name
        Your first name is Aden
        Your first inital is A
        The space is at the 4 position
        Enter email username (e.g. jsmith): anguyen
        Email with typo: anguyen@sanjac.edu
        After fixing the typo anguyen@SanJac.edu
        Names in alphabetical Order:
        Nguyen
        Smith
        Enter course (english/math/history/cpp/biology/art): cpp
        You selected: C++ Programming

        U.S. History
        English Composition
        College Algebra
        U.S. History
        C++ Programming
        General Biology
        Art Appreciation

        C++ Programming
        comes later in the day 

        Enter credit hours: 20
        Total Tuition is: $3000

        --- Enrollment Summary ---
        Full Name: Aden Nguyen
        Email: anguyen@SanJac.edu
        Course: C++ Programming

        Student ID: 10045
        Credits: 20.00
        Tuition: $3000.00
        NameSpace Demo: C++ Programming    
    */

    /*TEST RUN #2
        Enter first name: John
        Enter last name: Doe
        Your fullname is: John Doe
        There are 8 characters in your name
        Your first name is John
        Your first inital is J
        The space is at the 4 position
        Enter email username (e.g. jsmith): jdoe
        Email with typo: jdoe@sanjac.edu
        After fixing the typo jdoe@SanJac.edu
        Names in alphabetical Order:
        Doe
        Smith
        Enter course (english/math/history/cpp/biology/art): art
        You selected: Art Appreciation

        English Composition
        College Algebra
        U.S. History
        C++ Programming
        General Biology
        Art Appreciation

        Art Appreciation
        comes later in the day 

        Enter credit hours: 15
        Total Tuition is: $2250

        --- Enrollment Summary ---
        Full Name: John Doe
        Email: jdoe@SanJac.edu
        Course: Art Appreciation

        Student ID: 10045
        Credits: 15.00
        Tuition: $2250.00
        NameSpace Demo: C++ Programming
    */
}

void EnrollmentSystem::printCourse(courseType c)
{
    switch (c)
    {
    case ENGLISH:
        cout << "English Composition" << endl;
        break;
    case MATH:
        cout << "College Algebra" << endl;
        break;
    case HISTORY:
        cout << "U.S. History" << endl;
        break;
    case CPP:
        cout << "C++ Programming" << endl;
        break;
    case BIOLOGY:
        cout << "General Biology" << endl;
        break;
    case ART:
        cout << "Art Appreciation" << endl;
        break;
    default:
        cout << "ERROR: Unknown class" << endl;
        break;
    }
}

EnrollmentSystem::courseType EnrollmentSystem::readCourse()
{
    string input;
    cout << "Enter course (english/math/history/cpp/biology/art): ";
    cin >> input;

    if (input == "english")
    {
        return ENGLISH;
    }
    else if (input == "math")
    {
        return MATH;
    }
    else if (input == "history")
    {
        return HISTORY;
    }
    else if (input == "cpp")
    {
        return CPP;
    }
    else if (input == "biology")
    {
        return BIOLOGY;
    }
    else if (input == "art")
    {
        return ART;
    }
    else
    {
        cout << "ERROR: Unknown Class, defaulting to english" << endl;
        return ENGLISH;
    }
}

double EnrollmentSystem::calcTuition(CreditHours credits)
{
    return credits * 150.0;
}

void EnrollmentSystem::printStudentInfo(string fullName, string email, courseType course, StudentID id, CreditHours credits)
{
    cout << fixed << setprecision(2);
    cout << endl
         << "--- Enrollment Summary ---" << endl;
    cout << "Full Name: " << fullName << endl;
    cout << "Email: " << email << endl;
    cout << "Course: "; 
    printCourse(course);
    cout << endl;
    cout << "Student ID: " << id << endl;
    cout << "Credits: " << credits << endl;
    cout << "Tuition: $" << calcTuition(credits) << endl;
}
