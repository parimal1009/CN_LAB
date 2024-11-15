#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int totalPacket = 10;
    int windowSize = 3;
    int totalTransmission = 0;
    int i = 1;
    bool ackReceived[totalPacket + 1] = {false};

    while (i <= totalPacket) {
        // Send packets in the current window
        for (int k = i; k < i + windowSize && k <= totalPacket; k++) {
            if (!ackReceived[k]) {
                cout << "Sending transmission for packet " << k << endl;
                totalTransmission++;
            }
        }

        // Acknowledge packets randomly
        for (int k = i; k < i + windowSize && k <= totalPacket; k++) {
            if (!ackReceived[k]) {
                bool ack = rand() % 2;
                if (ack) {
                    cout << "Acknowledgment received for packet " << k << endl;
                    ackReceived[k] = true;
                } else {
                    cout << "Retransmitting packet " << k << endl;
                }
            }
        }

        // Slide the window based on received acknowledgments
        while (i <= totalPacket && ackReceived[i]) {
            i++;
        }
    }

    cout << "Total transmissions: " << totalTransmission << endl;
    return 0;
}
