# Education Center Course Management Program

This is a C++ program designed to manage course enrollment data for multiple education centers. The program reads course data from a file and provides various features for the user to search and display course information. The system supports multiple locations, themes, courses, and enrollments, and can handle commands to interact with this data.

## Features

- **File Input Handling**: 
  - The program reads course enrollment data from a CSV file.
  - It handles errors like missing fields or inability to open the file.
  - It uses the last occurrence of course data in case of duplicates for a location and course.
  
- **User Interaction**:
  - Command-line interface where users can:
    - View all locations (`locations` command).
    - View all themes in a location (`themes_in_location <location>` command).
    - View all courses in a specific theme and location (`courses <location> <theme>` command).
    - View available courses (those that are not full) (`available` command).
    - View all courses under a specific theme across all locations (`courses_in_theme <theme>` command).
    - Find the most popular theme based on total enrollments (`favorite_theme` command).
  
- **Error Handling**:
  - The program provides error messages for:
    - Unknown commands.
    - Incorrect command parameters.
    - Invalid location or theme names.
    - Data inconsistencies such as missing fields or files that cannot be opened.

## Data Structure

- **Input File Format**: 
  The data is stored in a CSV file, where each line is structured as:

<location>;<theme>;<course_name>;<number_of_enrollments>

