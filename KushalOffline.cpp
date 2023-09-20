#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
class Studentinfo
{
    int studentId;
    string name;
    float onlineMarks[5];

public:
    Studentinfo()
    {
        for (int i = 0; i < 5; i++)
        {
            onlineMarks[i] = 0;
        }
    }
    Studentinfo(int studentId, string name)
    {
        this->studentId = studentId;
        this->name = name;
        for (int i = 0; i < 5; i++)
        {
            onlineMarks[i] = 0;
        }
    }
    Studentinfo(int studentId, string name, float *onlineMarks)
    {
        this->studentId = studentId;
        this->name = name;
        for (int i = 0; i < 5; i++)
        {
            this->onlineMarks[i] = onlineMarks[i];
        }
    }
    ~Studentinfo()
    {
        cout << "Destructor is called" << endl;
    }
    int getStudentId()
    {
        return studentId;
    }
    string getName()
    {
        return name;
    }
    float* getOnlineMarks()
    {
        return onlineMarks;
    }
    float bestThreeOnlineMarks(bool printMarks)
    {
        float tempOnlineMarks[5];
        for (int i = 0; i < 5; i++)
        {
            tempOnlineMarks[i] = onlineMarks[i];
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = i + 1; j < 5; j++)
            {
                if (tempOnlineMarks[j] > tempOnlineMarks[i])
                {
                    swap(tempOnlineMarks[i], tempOnlineMarks[j]);
                }
            }
        }

        if (printMarks)
        {
            cout << "Best Three Online Marks :";
            for (int i = 0; i < 3; i++)
            {
                cout << tempOnlineMarks[i] << " ";
            }
            cout << endl;
        }
        float bestSum = 0.0;
        for (int i = 0; i < 3; i++)
        {
            bestSum += tempOnlineMarks[i];
        }
        return bestSum;
    }
    void printStudentInfo()
    {
        cout << "Student Id:" << studentId << endl;
        cout << "Name:" << name << endl;
        cout << "Online Marks :";
        for (int i = 0; i < 5; i++)
        {
            cout << onlineMarks[i] << " ";
        }
        cout << endl;
    }
};
float calculateTotalMarks(Studentinfo student, int n)
{
    float *tempOnlineMarks = student.getOnlineMarks();
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (tempOnlineMarks[j] > tempOnlineMarks[i])
            {
                swap(tempOnlineMarks[i], tempOnlineMarks[j]);
            }
        }
    }
    float bestSum = 0.0;
    for (int i = 0; i < n; i++)
    {
        bestSum += tempOnlineMarks[i];
    }
    cout << endl;
    return bestSum;
}
float calculateTotalMarks(Studentinfo student)
{
    float *tempOnlineMarks = student.getOnlineMarks();
    float totalSum = 0.0;
    for (int i = 0; i < 5; i++)
    {
        totalSum += tempOnlineMarks[i];
    }
    cout << endl;
    return totalSum;
}
Studentinfo getBetterStudent(Studentinfo student1, Studentinfo student2)
{
    float totalSum1 = calculateTotalMarks(student1);
    float totalSum2 = calculateTotalMarks(student2);
    if (totalSum1 > totalSum2)
    {
        return student1;
    }
    else
    {
        return student2;
    }
}
void printRanking(Studentinfo students[], int numberOfStudents)
{
    for (int i = 0; i < numberOfStudents - 1; i++)
    {
        for (int j = i + 1; j < numberOfStudents; j++)
        {
            if (students[j].bestThreeOnlineMarks(false) > students[i].bestThreeOnlineMarks(false))
            {
                swap(students[i], students[j]);
            }
        }
    }
    cout << "Ranking:" << endl;
    for (int i = 0; i < numberOfStudents; i++)
    {
        students[i].printStudentInfo();
        cout<<"Best Three Online's Sum:"<<students[i].bestThreeOnlineMarks(true)<<endl;
    }
}
int main()
{
    ifstream fin;
    fin.open("studentInfo.txt");
    Studentinfo studentinfo[10];
    int id;
    string name;
    float marks[5];
    int studentCount = 0;
    while (!fin.eof())
    {
        string line;
        getline(fin, line);
        istringstream sso(line); // string stream object
        sso >> id >> name;
        for (int i = 0; i < 5; i++)
        {
            sso >> marks[i];
        }
        Studentinfo student(id, name, marks);
        studentinfo[studentCount] = student;
        studentCount++;
    }
    int n;
    cout<<"Enter the Online number that you want to consider:";
    cin>>n;

    for (int i = 0; i < studentCount; i++)
    {
        studentinfo[i].printStudentInfo();
        studentinfo[i].bestThreeOnlineMarks(true);
        cout << "Total Online Marks:"<<calculateTotalMarks(studentinfo[i]) << endl;
        cout << "Best "<<n<<" Online total:"<<calculateTotalMarks(studentinfo[i], n) << endl;
    }
    int id1, id2;
    cout << "Finding Better Student:" << endl;
    cout << "Enter 1st student Id:";
    cin >> id1;
    cout << "Enter 2nd student Id:";
    cin >> id2;
    int index1 = -1;
    int index2 = -1;
    for (int i = 0; i < studentCount; i++)
    {
        if (studentinfo[i].getStudentId() == id1)
        {
            index1 = i;
        }
        if (studentinfo[i].getStudentId() == id2)
        {
            index2 = i;
        }
    }
    if (index1 == -1 || index2 == -1)
    {
        cout << "Student not found" << endl;
    }
    else
    {
        Studentinfo betterStudent = getBetterStudent(studentinfo[index1], studentinfo[index2]);
        cout << "Better Student Info:" << endl;
        betterStudent.printStudentInfo();
    }

    printRanking(studentinfo, 10);
}
