#include "fileInput.h"
#include "algorithms.h"

using namespace std;


int getAlgorithmChoice() {
    int choice;

    while (true) {
        cout << "\nSelect an algorithm:\n"
            << "1. Maximize Deliveries w/ 1 driver \n"
            << "2. Minimize # of drivers for all deliveries \n"
            << "3. Minimize # of deliveries rejected for 1 driver\n"
            << "0. Exit\n"
            << "Choice: ";

        if (cin >> choice && choice >= 0 && choice <= 3) {
            return choice;
        }

        cout << "Invalid choice. Please enter 0, 1, 2, or 3.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}


int main() {
    const int choice = getAlgorithmChoice();

    if (choice == 0) {
        cout << "Exiting.\n";
        return 0;
    }

    cout << "\nRunning algorithm " << choice << "...\n\n";

    for (int i = 0; i < TESTFILES.size(); i++)
    {
		vector<Delivery> deliveries = readEventsFromFile(TESTFILES[i]);
        switch (choice){

            case 1:
				if (TESTFILES[i] == "test5B_mixed_order.txt" || TESTFILES[i] == "test6B_partial_overlap.txt"
                    || TESTFILES[i] == "test5C_mixed_order.txt" || TESTFILES[i] == "test6C_partial_overlap.txt") {
					continue; // Skip non-required test files for algorithm 1
				}
				// Call the function for maximizing deliveries with 1 driver
				cout << "Maximizing deliveries for file: " << TESTFILES[i] << endl;
				maximizeDeliveries(deliveries);
				break;
			case 2:
                if (TESTFILES[i] == "test5A_mixed_order.txt" || TESTFILES[i] == "test6A_partial_overlap.txt"
                    || TESTFILES[i] == "test5C_mixed_order.txt" || TESTFILES[i] == "test6C_partial_overlap.txt") {
                    continue; // Skip non-required test files for algorithm 2
                }
				// Call the function for minimizing the number of drivers for all deliveries
				cout << "Minimizing number of drivers for file: " << TESTFILES[i] << endl;
				minimizeDrivers(deliveries);
				break;
			case 3:
                if (TESTFILES[i] == "test5B_mixed_order.txt" || TESTFILES[i] == "test6B_partial_overlap.txt"
                    || TESTFILES[i] == "test5A_mixed_order.txt" || TESTFILES[i] == "test6A_partial_overlap.txt") {
                    continue; // Skip non-required test files for algorithm 3
                }
				// Call the function for minimizing the number of deliveries rejected for 1 driver
				cout << "Minimizing deliveries rejected for file: " << TESTFILES[i] << endl;
                removeIncompatibleDeliveries(deliveries);
				break;
            default:
                break;
        }

    }

    return 0;
}
