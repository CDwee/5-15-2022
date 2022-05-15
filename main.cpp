// Started at 10:48 5-15-2022

// Section 11
// Section Challenge
#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

void display_menu();
char get_selection();

void handle_display(const vector<int> &v);
void handle_add(vector<int> &v);
void handle_mean(const vector<int> &v);
void handle_smallest(const vector<int> &v);
void handle_largest(const vector<int> &v);
void handle_find(const vector<int > &v);
void handle_quit();
void handle_unknown();

void display_list(const vector<int> &v);
double calculate_mean(const vector<int> &v);
int get_smallest(const vector<int> &v);
int get_largest(const vector<int> &v);
bool find(const vector<int> &v, int target);

int main() {
    
    vector<int> numbers;  
    char selection {};
    
    do {
        display_menu();
        selection = get_selection();
        switch (selection) {
            case 'P': 
                handle_display(numbers); 
                break;
            case 'A': 
                handle_add(numbers);
                break;
            case 'M':
                handle_mean(numbers);
                break;
            case 'S':
                handle_smallest(numbers);
                break;
            case 'L':
                handle_largest(numbers);
                break;
            case 'F':
                handle_find(numbers);
                break;
            case 'Q':
                handle_quit();
                break;
            default:
                handle_unknown();
        }
    } while (selection != 'Q');
    cout << endl;
    return 0;
}

void display_menu() {
        cout << "\nP - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number"<< endl;
        cout << "F - Find a number" << endl;
        cout << "Q - Quit" << endl;
        cout << "\nEnter your choice: ";
}

char get_selection() {
    char selection {};
    cin >> selection;
    return toupper(selection);
}

void handle_display(const vector<int> &v) {
    if (v.size() == 0)
        cout << "[] - the list is empty" << endl;
    else    
        display_list(v);
}

void handle_add(vector<int> &v) {
    int num_to_add {};
    cout << "Enter an integer to add to the list: ";
    cin >> num_to_add;
    v.push_back(num_to_add);
    cout << num_to_add << " added" << endl;
}

void handle_mean(const vector<int> &v) {
    if (v.size() == 0)
        cout << "Unable to calculate mean - list is empty" << endl;
    else    
        cout << "The mean is " << calculate_mean(v) << endl;
}

void handle_smallest(const vector<int> &v) {
     if (v.size() == 0)
        cout << "Unable to determine the smallest - list is empty" << endl;
    else    
        cout << "The smallest element in the list is " << get_smallest(v) << endl;
}

void handle_largest(const vector<int> &v) {
     if (v.size() == 0)
        cout << "Unable to determine the largest - list is empty" << endl;
    else    
        cout << "The largest element in the list is " << get_largest(v) << endl;
}

void handle_find(const vector<int> &v) {
    int target{};
    cout << "Enter the number to find: ";
    cin >> target;
    if(find(v, target))
        cout << target << " was found" << endl;
    else
        cout << target << " wasn't found" << endl;
    
}

void handle_quit() {
    cout << "Goodbye" << endl;
}

void handle_unknown() {
    cout << "Unknown selection - try again" << endl;
}

void display_list(const vector<int> &v) {
    cout << "[ ";
    for (auto num: v)
        cout << num << " ";
    cout << "]" << endl;
}

double calculate_mean(const vector<int> &v) {
    int total {};
    for (auto num: v)
        total += num;
    return static_cast<double>(total)/v.size();
}

int get_largest(const vector<int> &v) {
    int largest = v.at(0);
    for (auto num: v) 
        if (num > largest)
            largest = num;
    return largest;
}

int get_smallest(const vector<int> &v) {
    int smallest = v.at(0);
    for (auto num: v) 
        if (num < smallest)
            smallest = num;
    return smallest;
}

bool find(const vector<int> &v, int target) {
    for (auto num: v)
        if(num == target)
            return true;
    return false;
}


// Section 12
// Simple pointers

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    
    int num{10};
    cout << "Value of num is: " << num << endl;
    cout << "sizeof of num is: " << sizeof num << endl;
    cout << "Address of num is: " << &num << endl;
    
    int *p;
    cout << "\nValue of p is: " << p << endl;   // garbage
    cout << "Address of p is: " << &p << endl;
    cout << "sizeof of p is: " << sizeof p << endl;

    p = nullptr;
    cout << "\nValue of p is: " << p << endl;
    
    
    int *p1 {nullptr};
    double *p2 {nullptr};
    unsigned long long *p3 {nullptr};
    vector<string> *p4 {nullptr};
    string *p5 {nullptr};
    
    cout << "\nsizeof p1 is: " << sizeof p1 << endl;
    cout << "sizeof p2 is: " << sizeof p2 << endl;
    cout << "sizeof p3 is: " << sizeof p3 << endl;
    cout << "sizeof p4 is: " << sizeof p4 << endl;
    cout << "sizeof p5 is: " << sizeof p5 << endl;
    
    int score{10};
    double high_temp{100.7};
    
    int *score_ptr {nullptr};
    
    score_ptr = &score;
    cout << "Value of score is: " << score << endl;
    cout << "Address of score is: " << &score << endl;
    cout << "Value of score_ptr is: " << score_ptr << endl;
    
//    score_ptr = &high_temp;   // Compiler error
    
    cout << endl;
    return 0;
}

// Ended at 12:50 5-15-2022
