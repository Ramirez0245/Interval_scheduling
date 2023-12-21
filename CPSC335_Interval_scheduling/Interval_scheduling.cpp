#include <iostream>;
#include <algorithm>    
#include <vector>       

using namespace std;

struct myclass {
    bool operator() (vector<int> i, vector<int> j) { return ( i[1] < j[1]); }
} myobject;
vector<vector<int>> Greedy_Activity_Selector(vector<vector<int>> n);

int main() {
    int start, finished, n;
    bool checker = true;

    //Enter n actitivites. With limit checks
    while (checker) {
        cout << "Input the number activities, n: ";
        cin >> n;

        checker = false;
        if (n > 6 || cin.fail()) {
            cout << "To many activites or inccorect input, please keep it under 7" << endl;
            checker = true;
        }
        cin.clear();
        cin.ignore(256, '\n');
    }
    cout << endl;

    //Create entries for activities
    vector<vector<int>> activities;
    for (int i = 0; i < n; i++) {
        checker = true;
        while (checker) {
            cout << "Input the start time(0 < start < 60 ) of the " << i << " activity: ";
            cin >> start;
            checker = false;
            if (cin.fail() || start > 60 || start < 0) {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Incorrect input please try again" << endl;
                checker = true;
            }
        }
        checker = true;
        while (checker) {
            cout << "Input the finshed time(0 < finished < 60 ) and greater than start time for the  " << i << " activity: ";
            cin >> finished;
            checker = false;
            if (cin.fail() || finished > 60 || finished < 1 || finished <= start) {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Incorrect input please try again" << endl;
                cout << "The start time:  " << start << endl;
                checker = true;
            }
        }
        activities.push_back({ start, finished });
    }
    
    //Print unsorted vector
    cout << "My vector unsorted:" << endl;
    for (int i = 0; i < activities.size(); i++) { cout << "[" << activities[i][0] << "," << activities[i][1] << "] "; }
    cout << endl;

    //Sort O(n*log(n))
    sort(activities.begin(), activities.end(), myobject);
    cout << "My vector sorted by final time contains:" << endl;
    for (int i = 0; i < activities.size(); i++) { cout << "[" << activities[i][0] << "," << activities[i][1] << "] " ; }
    cout << endl << "Updated vector sorted by final time. maximum-size subset A º S" << endl;

    //Sort the data by the finish times. O(n)
    vector<vector<int>> greedy_result = Greedy_Activity_Selector(activities);
    for (int i = 0; i < greedy_result.size(); i++) { cout << "[" << greedy_result[i][0] << "," << greedy_result[i][1] << "] "; }

    return 0;
}

vector<vector<int>> Greedy_Activity_Selector(vector<vector<int>> activities) {
    vector<vector<int>> greedy_results;
    vector<vector<int>> current;
    greedy_results.push_back(activities[0]);
    current.push_back(activities[0]);

    // O(n), n = activites.size()
    for (int i = 0; i < activities.size(); i++) {
        if (activities[i][1] > current[0][1]) {
            greedy_results.push_back(activities[i]);
            current[0] = activities[i];
        }
    }
    return greedy_results;
}





//bool myfunction(vector<int> i, vector<int> j) { return (i < j); }
//struct activities {
//    int start;
//    int finished;
//};
//int* array_(int& size) {
//    std::cin >> size;
//
//    int* Array = new int[size];
//
//    for (int i = 0; i < size; ++i)
//        std::cin >> Array[i];
//
//    return Array;
//}
//int main2() {
//    int start;
//    int finished;
//    bool checker = true;
//    int n;
//
//    while (checker) {
//        cout << "Input the number activities, n: ";
//        cin >> n;
//
//        checker = false;
//        if (n > 6 || cin.fail())  {
//            cout << "To many activites or inccorect input, please keep it under 7" << endl;
//            checker = true;
//        }
//
//        cin.clear();
//        cin.ignore(256, '\n');
//    }
//    cout << endl;
//    activities* a = new activities[n];
//
//    for (int i = 0; i < n; i++) {
//        checker = true;
//        while (checker) {
//            cout << "Input the start time(0 < start < 60 ) of the " << i << " activity: ";
//            cin >> start;
//            checker = false;
//            if (cin.fail() || start > 60 || start < 0) {
//                cin.clear();
//                cin.ignore(256, '\n');
//                cout << "Incorrect input please try again" << endl;
//                checker = true;
//            }
//        }
//
//        checker = true;
//        while (checker) {
//            cout << "Input the finshed time(0 < finished < 60 ) and greater than start time for the  " << i << " activity: ";
//            cin >> finished;
//            checker = false;
//            if (cin.fail() || finished > 60 || finished < 1 || finished <= start) {
//                cin.clear();
//                cin.ignore(256, '\n');
//                cout << "Incorrect input please try again" << endl;
//                cout << "The start time:  " << start << endl;
//                checker = true;
//            }
//        }
//        cout << endl;
//        a[i].start = start;
//        a[i].finished = finished;
//    }
//
//    cout << "The activites are" << endl;
//    for (int i = 0; i < n; i++) {
//        cout << "[" << a[i].start << "," << a[i].finished << "] ";
//    }
//
//
//
//    delete[] a;
//	return 0;
//}
//
