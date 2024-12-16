/*
    education centre
    Author: Soyabbir Abu Hanif
    Master's in Embedded  Systems
    Tampere University, Finland
    mdsoyabbir.abuhanif@tuni.fi
*/



#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

// Structure to represent a course
struct Course {
    string name;
    string theme;
    int enrollments;
};

// Alias for the course data structure
using CourseData = map<string, map<string, vector<Course>>>;

// Function to split a string based on a delimiter
vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    stringstream ss(s);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Function to read course data from a file
CourseData readCourseData(const string& filename) {
    CourseData courseData;
    ifstream inputFile(filename);

    // Check if the input file can be opened
    if (!inputFile.is_open()) {
        cerr << "Error: the input file cannot be opened" << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    while (getline(inputFile, line)) {
        vector<string> parts = split(line, ';');

        // Check for an empty field
        if (parts.size() == 4) {
            Course course{parts[2], parts[1], (parts[3] == "full") ? 50 : stoi(parts[3])};
            courseData[parts[0]][parts[1]].push_back(course);
        } else {
            cerr << "Error: empty field" << endl;
            exit(EXIT_FAILURE);
        }
    }

    return courseData;
}

// Function to print available locations
void printLocations(const CourseData& courseData) {
    for (const auto& location : courseData) {
        cout << location.first << endl;
    }
}

// Function to print themes in a specific location
void printThemesInLocation(const string& location, const CourseData& courseData) {
    auto it = courseData.find(location);
    if (it != courseData.end()) {
        for (const auto& theme : it->second) {
            cout << theme.first << endl;
        }
    } else {
        cout << "Error: unknown location" << endl;
    }
}

// Function to print courses in a specific location and theme
void printCourses(const string& location, const string& theme, const string& keyword, const CourseData& courseData) {
    auto locIt = courseData.find(location);
    if (locIt != courseData.end()) {
        auto themeIt = locIt->second.find(theme);
        if (themeIt != locIt->second.end()) {
            // Sort courses by name before printing
            auto sortedCourses = themeIt->second;
            sort(sortedCourses.begin(), sortedCourses.end(),
                 [](const Course& a, const Course& b) {
                     return a.name < b.name;
                 });

            for (const auto& course : sortedCourses) {
                // Check if the keyword is empty or matches the course name
                if (keyword.empty() || course.name == keyword) {
                    if (course.enrollments == 50) {
                        cout << course.name << " --- full" << endl;
                    } else {
                        cout << course.name << " --- " << course.enrollments << " enrollments" << endl;
                    }
                }
            }
        } else {
            // Check if the theme has quotes and remove them
            string cleanedTheme = theme;
            if (cleanedTheme.front() == '"' && cleanedTheme.back() == '"') {
                cleanedTheme = cleanedTheme.substr(1, cleanedTheme.size() - 2);
            }

            // Try to find the theme without quotes
            themeIt = locIt->second.find(cleanedTheme);
            if (themeIt != locIt->second.end()) {
                auto sortedCourses = themeIt->second;
                sort(sortedCourses.begin(), sortedCourses.end(),
                     [](const Course& a, const Course& b) {
                         return a.name < b.name;
                     });

                for (const auto& course : sortedCourses) {
                    // Check if the keyword is empty or matches the course name
                    if (keyword.empty() || course.name == keyword) {
                        if (course.enrollments == 50) {
                            cout << course.name << " --- full" << endl;
                        } else {
                            cout << course.name << " --- " << course.enrollments << " enrollments" << endl;
                        }
                    }
                }
            } else {
                cout << "Error: unknown theme" << endl;
            }
        }
    } else {
        cout << "Error: unknown location name" << endl;
    }
}


// Function to print available courses (enrollments less than 50)
void printAvailableCourses(const CourseData& courseData) {
    set<pair<string, string>> printedCourses; // To track printed courses by location

    for (const auto& location : courseData) {
        for (const auto& theme : location.second) {
            // Sort courses by name before printing
            auto sortedCourses = theme.second;
            sort(sortedCourses.begin(), sortedCourses.end(),
                 [](const Course& a, const Course& b) {
                     return a.name < b.name;
                 });

            for (const auto& course : sortedCourses) {
                // Check if the course has already been printed for this location
                if (printedCourses.find({location.first, course.name}) == printedCourses.end() && course.enrollments < 50) {
                    cout << location.first << " : " << theme.first << " : " << course.name << endl;
                    printedCourses.insert({location.first, course.name});
                }
            }
        }
    }
}




// Function to print courses in a specific theme across all locations
void printCoursesInTheme(const string& theme, const CourseData& courseData) {
    set<string> printedCourses; // To track printed courses
    vector<string> sortedCourseNames; // To store and sort course names alphabetically

    bool themeExists = false;

    for (const auto& location : courseData) {
        auto themeIt = location.second.find(theme);
        if (themeIt != location.second.end()) {
            themeExists = true;  // Set the flag if at least one course exists for the theme
            for (const auto& course : themeIt->second) {
                // Check if the course has already been printed
                if (printedCourses.find(course.name) == printedCourses.end()) {
                    sortedCourseNames.push_back(course.name);
                    printedCourses.insert(course.name);
                }
            }
        }
    }

    // Sort course names alphabetically
    sort(sortedCourseNames.begin(), sortedCourseNames.end());

    if (!themeExists) {
        cout << "Error: unknown theme" << endl;
    } else {
        for (const auto& courseName : sortedCourseNames) {
            cout << courseName << endl;
        }
    }
}



// Function to print the theme with the most enrollments
void printFavoriteTheme(const CourseData& courseData) {
    map<string, int> themeEnrollments;

    for (const auto& location : courseData) {
        for (const auto& theme : location.second) {
            for (const auto& course : theme.second) {
                themeEnrollments[theme.first] += course.enrollments;
            }
        }
    }

    if (!themeEnrollments.empty()) {
        auto maxIt = max_element(themeEnrollments.begin(), themeEnrollments.end(),
                                 [](const auto& a, const auto& b) {
                                     return a.second < b.second;
                                 });

        cout << maxIt->second << " enrollments in themes" << endl;
        // Sort themes by name before printing
        vector<pair<string, int>> sortedThemes(themeEnrollments.begin(), themeEnrollments.end());
        sort(sortedThemes.begin(), sortedThemes.end(),
             [](const auto& a, const auto& b) {
                 return a.first < b.first;
             });

        for (const auto& entry : sortedThemes) {
            if (entry.second == maxIt->second) {
                cout << "--- " << entry.first << endl;
            }
        }
    } else {
        cout << "No enrollments" << endl;
    }
}

// Function to process user commands
int processCommand(const vector<string>& args, const CourseData& courseData) {
    if (args.empty()) {
        return EXIT_FAILURE;
    }

    if (args[0] == "quit") {
        return EXIT_SUCCESS;
    } else if (args[0] == "locations") {
        printLocations(courseData);
    } else if (args[0] == "themes_in_location") {
        if (args.size() == 2) {
            printThemesInLocation(args[1], courseData);
        } else {
            cout << "Error: error in command " << args[0] << endl;
        }
    } else if (args[0] == "courses") {
        if (args.size() >= 3) {
            // Join the theme words back together if it has spaces
            string theme;
            for (size_t i = 2; i < args.size(); ++i) {
                theme += args[i];
                if (i < args.size() - 1) {
                    theme += " ";
                }
            }
            // Check if the theme has quotes and remove them
            if (!theme.empty() && theme.front() == '"' && theme.back() == '"') {
                theme = theme.substr(1, theme.size() - 2);
            }
            printCourses(args[1], theme, "", courseData);
        } else {
            cout << "Error: error in command " << args[0] << endl;
        }
    } else if (args[0] == "available") {
        printAvailableCourses(courseData);
    } else if (args[0] == "courses_in_theme") {
        if (args.size() == 2) {
            // Check if the theme has quotes and remove them
            string theme = args[1];
            if (!theme.empty() && theme.front() == '"' && theme.back() == '"') {
                theme = theme.substr(1, theme.size() - 2);
            }
            printCoursesInTheme(theme, courseData);
        } else {
            cout << "Error: error in command " << args[0] << endl;
        }
    } else if (args[0] == "favorite_theme") {
        printFavoriteTheme(courseData);
    } else {
        cout << "Error: Unknown command: " << args[0] << endl;
    }

    return EXIT_FAILURE;
}


// Main function
int main() {
    cout << "Input file: ";
    string filename;
    getline(cin, filename);

    CourseData courseData = readCourseData(filename);

    while (true) {
        cout << "> ";
        string input;
        getline(cin, input);

        vector<string> args = split(input, ' ');

        int result = processCommand(args, courseData);
        if (result == EXIT_SUCCESS) {
            break;
        }
    }

    return 0;
}
