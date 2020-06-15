// class Route{
//     public: 
//         string GetSource(){ return source; }
//         string GetDestination(){ return destination; }
//         int GetLength(){ return length; }
//         void SetSource( const string& new_source )
//         { 
//             source = new_source;
//             UpdateLength();
//         }
//         void SetDestination( const string& new_destination )
//         { 
//             destination = new_destination;
//             UpdateLength();
//         }
//     private:
//         string source;
//         string destination;
//         int length;
//         void UpdateLength(){ length = ComputeDistance(source, destination); }
//         int ComputeDistance(const string& s, const string& d){ return 42; }
// };

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