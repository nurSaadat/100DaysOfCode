#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Route{
    public: 
        string GetSource(){ return source; }
        string GetDestination(){ return destination; }
        int GetLength(){ return length; }
        void SetSource( const string& new_source )
        { 
            source = new_source;
            UpdateLength();
        }
        void SetDestination( const string& new_destination )
        { 
            destination = new_destination;
            UpdateLength();
        }
    private:
        string source;
        string destination;
        int length;
};

/* Struct */
// struct LectureTitle{
//     string author;
//     string specialization;
//     string week;
// };

// struct DetailedLecture{
//     LectureTitle title;
//     int duration;
// };

// struct Lecture{
//     string title;
//     int duration;
//     string author;
// };

// void PrintLecture(const Lecture& lecture)
// {
//     cout << "Lecture: " << lecture.title << ", duration: " << lecture.duration << ", author: " << lecture.author << endl;
// }

// void PrintCourse(const vector<Lecture>& lectures)
// {
//     for (const Lecture& lecture : lectures)
//     {
//         PrintLecture(lecture);
//     }
// }

// int
// main()
// {
//     int x = 5;
//     /* Ternary operator */
//     string str = (x % 2 == 0) ? "even" : "odd";

// }


/* Functions */
// bool Gt2(int x)
// {
//     if (x > 2)
//     {
//         return true;
//     }
//     return false;
// }

// void PrintVector(const vector<int>& v, const string& title)
// {
//     cout << title << ": ";
//     for (const auto& e : v)
//     {
//         cout << e << " ";
//     }
//     cout << endl;
// }

// int
// main()
// {
//     cout << "min of 2 and 3: " << min(2, 3) << endl;
//     cout << "max of 2 and 3: " << max(2, 3) << endl;
//     vector<int> v {
//         1, 3, 2, 4, 5, 2
//     };
//     PrintVector(v , "init");
//     sort(begin(v), end(v));
//     PrintVector(v , "sort");

//     cout << "count 2: " << count(begin(v), end(v), 2) << endl;
//     /* Count if */
//     cout << "count greater than 2: " << count_if(begin(v), end(v), Gt2) << endl;
//     /* Lambda function with Custom threshold */
//     int thr;
//     cin >> thr;
//     cout << "count less than " << thr << ": " << count_if(begin(v), end(v), [thr](int x){
//         if (x < thr)
//         {
//             return true;
//         }
//         return false;
//     }) << endl;

//     /* Modifying range-base for */
//     for (auto& i : v)
//     {
//         ++i;
//     }
//     PrintVector(v, "incr");
// }