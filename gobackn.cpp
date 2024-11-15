#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // Initialize random number generator
    int totalframe, windowsize, totaltransmission = 0;

    cout << "Enter the total frames: ";
    cin >> totalframe;
    cout << "Enter the window size: ";
    cin >> windowsize;

    int i = 1; // First frame to be sent

    while (i <= totalframe) {
        int framesToSend = min(windowsize, totalframe - i + 1); // Frames that can be sent within the window

        // Send frames in the current window
        for (int k = 0; k < framesToSend; k++) {
            cout << "Sending frame " << i + k << endl;
            totaltransmission++;
        }

        // Check for acknowledgments
        bool errorOccurred = false;
        int lastAckFrame = 0; // Track the last acknowledged frame within the window
        for (int k = 0; k < framesToSend; k++) {
            bool ackReceived = rand() % 2; // Random boolean (0 or 1)
            if (!ackReceived) {
                cout << "Error: Timeout. Retransmitting from frame " << i + k << endl;
                errorOccurred = true;
                break; // Break out and retransmit from the first error
            } else {
                cout << "Acknowledgment received for frame " << i + k << endl;
                lastAckFrame = k + 1; // Track successful frames
            }
        }

        // If an error occurred, retransmit starting from the first unacknowledged frame
        if (errorOccurred) {
            // Retransmit starting from the first unacknowledged frame (i)
            continue;
        } else {
            // All frames were acknowledged, move the window forward
            i += lastAckFrame;  // Move the window forward by the number of successfully acknowledged frames
        }

        cout << endl;
    }

    cout << "Transmission complete. Total transmissions: " << totaltransmission << endl;
    return 0;
}
