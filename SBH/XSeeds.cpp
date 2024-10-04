#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
using namespace std;

/*
  isValidTime is used to check if the time is valid or not

  Input:
  - timeStr: string, the time string
  - timeStruct: tm, the time struct

  Output:
  - bool: true if the time is valid, false otherwise
*/
bool isValidTime(const string& timeStr, tm& timeStruct) {
    istringstream ss(timeStr);
    ss >> get_time(&timeStruct, "%H:%M");
    return !ss.fail();
}

/*
  isValidDuration is used to check if the duration is valid or not

  Input:
  - durationStr: string, the duration string
  - hours: int, the hours
  - minutes: int, the minutes

  Output:
  - bool: true if the duration is valid, false otherwise
*/
bool isValidDuration(const string& durationStr, int& hours, int& minutes) {
    size_t colonPos = durationStr.find(':'); // Find the colon position
    if (colonPos == string::npos) return false; // If colon is not found, return false

    try { // Try to convert the hours and minutes to integers
        hours = stoi(durationStr.substr(0, colonPos));
        minutes = stoi(durationStr.substr(colonPos + 1));
    } catch (...) {
        return false;
    }

    return true;
}

/*
  addDuration is used to add the duration to the start time

  Input:
  - startTime: tm, the start time
  - hours: int, the hours
  - minutes: int, the minutes

  Output:
  - tm: the end time
 */
tm addDuration(const tm& startTime, int hours, int minutes) {
    tm endTime = startTime; // Copy the start time

    // Add the hours and minutes to the end time
    endTime.tm_hour += hours;
    endTime.tm_min += minutes;

    mktime(&endTime); // Normalize the time structure
    return endTime;
}

/*
  process_ticket_purchase is used to process the ticket purchase

  Input:
  - tickets: vector<string>, the tickets

  Output:
  - print: the result
*/
void process_ticket_purchase(const vector<string>& tickets) {
    //Declare ticket price
    const int ADULT_PRICE = 1800; 
    const int YOUNG_PRICE = 1200;
    const int CHILD_PRICE = 800;

    //Declare time constants
    const string CLOSING_TIME = "23:30";
    const string CHILD_RESTRICTED_TIME = "16:00";
    const string YOUNG_RESTRICTED_TIME = "18:00";

    int canBeBought = 1; // Check if the ticket can be bought or not, default is true

    if (tickets.empty()) cout << "No tickets provided"; // If no tickets are provided, return "No tickets provided"

    // Declare variables
    string movie_rating, start_time, duration;
    bool has_adult = false;
    vector<string> age_categories;
    vector<string> seat_numbers;

    // Process each ticket
    for (const string& ticket : tickets) {

        istringstream ss(ticket); // Create a string stream
        string age_category, seat_number; //Declare age_catogory and seat_number

        // Get the ticket details from the string stream
        getline(ss, age_category, ',');
        getline(ss, movie_rating, ',');
        getline(ss, start_time, ',');
        getline(ss, duration, ',');
        getline(ss, seat_number, ',');

        // Get the age category and seat number
        age_categories.push_back(age_category);
        seat_numbers.push_back(seat_number);

        // Check age category
        if (age_category == "Adult") {
            has_adult = true; // If the age category is Adult, set has_adult to true, since some films 
                              // require an adult to accompany children
        } else if (age_category == "Young") {
            // No additional action needed
        } else if (age_category == "Child") {
            // No additional action needed
        } else {
            cout << "Invalid age category";
        }

        // Check movie rating
        if (movie_rating == "R18+" && age_category != "Adult") {
            cout <<  "You cannot view this movie due to age restrictions.";
            canBeBought = 0;
        }

        if (movie_rating == "PG-12" && age_category == "Child" && !has_adult) {
            cout << "You cannot view this movie due to age restrictions.";
            canBeBought = 0;
        }

        if (age_category == "Child" && (seat_number[0] == 'J' || seat_number[0] == 'K' || seat_number[0] == 'L')) {
            cout << "You cannot use that seat with the ticket type you selected.";
            canBeBought = 0;
        }
    }

    // Check if the start time is valid
    tm startTimeStruct = {};
    if (!isValidTime(start_time, startTimeStruct)) {
        cout << "Invalid start time format";
    }

    // Check if the duration is valid
    int hours, minutes;
    if (!isValidDuration(duration, hours, minutes)) {
        cout << "Invalid duration format";
    }

    // Calculate the end time
    tm endTimeStruct = addDuration(startTimeStruct, hours, minutes);
    tm closingTimeStruct = {};
    isValidTime(CLOSING_TIME, closingTimeStruct);

    // Check if the movie ends after closing time
    if (mktime(&endTimeStruct) > mktime(&closingTimeStruct)) {
        cout << "Movie ends after closing time";
    }

    // Check if an adult is required or not
    tm childRestrictedTimeStruct = {};
    isValidTime(CHILD_RESTRICTED_TIME, childRestrictedTimeStruct);
    tm youngRestrictedTimeStruct = {};
    isValidTime(YOUNG_RESTRICTED_TIME, youngRestrictedTimeStruct);

    if (!has_adult) {
        if (mktime(&endTimeStruct) > mktime(&childRestrictedTimeStruct)) { // Check if the movie ends after the child restricted time
            for (const string& age_category : age_categories) {
                if (age_category == "Child") {
                    cout << ",An adult companion is required for admission to this movie." << endl;
                    canBeBought = 0;
                }
            }
        }
        if (mktime(&endTimeStruct) > mktime(&youngRestrictedTimeStruct)) { // Check if the movie ends after the young restricted time
            for (const string& age_category : age_categories) {
                if (age_category == "Young") {
                    cout << "An adult companion is required for admission to this movie." << endl;
                    canBeBought = 0;
                }
            }
        }
    }
    // If the ticket can be bought, print the price for each ticket separately
    if(canBeBought == 1){
      // Print the price for each ticket separately
      for (const string& age_category : age_categories) {
          if (age_category == "Adult") {
              cout << ADULT_PRICE << " yen" << endl;
          } else if (age_category == "Young") {
              cout << YOUNG_PRICE << " yen" << endl;
          } else if (age_category == "Child") {
              cout << CHILD_PRICE << " yen" << endl;
          }
      }
    }

}

int main() {
    // Declare variables
    string line;
    vector<string> s;

    // Read the input until an empty line is encountered
    while (getline(cin, line)) {
        if (line.empty()) {
            break;
        }
        s.push_back(line);
    }

    // Process the ticket purchase
    process_ticket_purchase(s);

    return 0;
}