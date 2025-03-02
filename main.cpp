#include "linked_list.h"
#include "node.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

int main(int argc, char* argv[]) {
    LinkedList* list; // Declare a pointer to a LinkedList

    std::string file_name(argv[1]); // Get the file name from the command line arguments

    std::vector<int> file_data; // Vector to store data read from the file
    std::string line;

    std::ifstream file(file_name); // Open the file

    // Read the first line from the file & store into vector
    std::getline(file, line);

    std::stringstream ss(line);

    int temp_int;
    while(ss >> temp_int) {
        file_data.push_back(temp_int);
    }

    // Create a linked_list based on what was in the first line of the file
    if(file_data.size() == 0) {
        list = new LinkedList(); // Create an empty list
    }
    else if (file_data.size() == 1) {
        list = new LinkedList(file_data[0]); // Create a list with a single element
    }
    else {
        list = new LinkedList(file_data); // Create a list from the vector
    }                                                                                                                                                                                                                                                                                                                                                                                                                          

    std::cout << list->to_string() << std::endl; // Print the initial state of the list

    while(std::getline(file, line))
    { // Read lines from the file

        std::stringstream ss(line);
        std::string temp;
        std::vector<std::string> line_vals;

        while(ss >> temp)
         {
            line_vals.push_back(temp); // Split the line into vector of strings
        }

        if(line_vals.size() == 2)
        {
            // assgins values and call insert method on the list
            int val = std::stoi(line_vals[0]);
            int idx = std::stoi(line_vals[1]);
            list->insert(val, idx);
        }
        else {
            if (line_vals[0][line_vals[0].size() - 1] == '?') {
                // Check if a value exists in the list
                int temp = std::stoi(line_vals[0].substr(0, line_vals[0].size() - 1));
                std::cout << list->contains(temp) << std::endl;
                continue;
            } else
             {
                int temp = std::stoi(line_vals[0]);
                if (temp > 0) {
                    if (temp % 2 == 0)
                    {
                        list->push_back(temp); // Push even number to the back of the list

                    }
                    else
                    {
                       list->push_front(temp); // Push odd number to the front of the list
                    }
                }
                else
                {
                    list->remove(std::abs(temp)); // Remove the absolute value of the negative number from the list
                }
            }
        }
        std::cout << list->to_string() << std::endl; // Print the current state of the list
    }

    delete list; // Clean up the allocated memory
}





    //delete link;

    /*
    push back
    insert
    push front
    delelte point
    delelte point
    contians
    contians
    delete
    insert
    contians




    */

