#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

char getLetterGrade(double score)
{
    if (score >= 90) return 'A';
    if (score >= 80) return 'B';
    if (score >= 70) return 'C';
    if (score >= 60) return 'D';
    return 'F';
}   

int main () 
{
    const int NUM_QUIZZES = 5;
    double scores[NUM_QUIZZES];
    int gradeCount[5] = {0};

    cout << "QUIZ GRADE TRACKER" << endl;
    cout << "-------------------" << endl;

    for (int i = 0; i < NUM_QUIZZES; i++){
        do{
        cout << "Enter score for Quiz " << (i + 1) << " (0 - 100): ";
        cin >> scores[i];

        if (scores[i] < 0 || scores[i] > 100){
            cout << "Please enter a score within the range of 0-100!" << endl;
        }

        }while (scores[i] < 0 || scores[i] > 100);
    }

    cout << "\nQuiz Results: " << endl;

    int sum = 0;
    double min = scores[0], max = scores[0];

    for (int i = 0; i < NUM_QUIZZES; i++){
        char grade = getLetterGrade(scores[i]);
        cout << "Quiz " << (i + 1) << ": " << scores[i] << " (" << grade << ")" << endl;

        sum += scores[i];
        if (scores[i] < min) min = scores[i];
        if (scores[i] > max) max = scores[i];

        if ( grade == 'A') gradeCount[0]++;
        else if (grade == 'B') gradeCount[1]++;
        else if (grade == 'C') gradeCount[2]++;
        else if (grade == 'D') gradeCount[3]++;
        else gradeCount[4]++;
    }

    double avg = static_cast<double>(sum) / NUM_QUIZZES;

    cout << fixed << setprecision(2);
    cout << "\nStatistics:" << endl;
    cout << "Average score: " << avg << endl;
    cout << "Highest score: " << max << endl;
    cout << "Lowest score: " << min << endl;
    cout << "Overall grade: " << getLetterGrade(avg) << endl;

    cout << "\nGrade Distribution:" << endl;
    cout << "A: " << gradeCount[0] << endl;
    cout << "B: " << gradeCount[1] << endl;
    cout << "C: " << gradeCount[2] << endl;
    cout << "D: " << gradeCount[3] << endl;
    cout << "F: " << gradeCount[4] << endl;

    return 0;
}
