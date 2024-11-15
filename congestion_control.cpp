#include <bits/stdc++.h>

using namespace std;

int main()
{
    int no_of_queries, storage, output_pkt_size;
    int input_pkt_size, bucket_size, size_left;

    // Initial packets in the bucket
    storage = 0;

    // Total number of times bucket content is checked
    no_of_queries = 4;

    // Total number of packets that can be accommodated in the bucket
    bucket_size = 10;

    // Number of packets that enter the bucket at a time
    input_pkt_size = 4;

    // Number of packets that exit the bucket at a time
    output_pkt_size = 1;

    for (int i = 0; i < no_of_queries; i++)
    {
        size_left = bucket_size - storage;

        if (input_pkt_size <= size_left)
        {
            // Update storage
            storage += input_pkt_size;
        }
        else
        {
            // Packet loss occurs
            int packet_loss = input_pkt_size - size_left;
            printf("Packet loss = %d\n", packet_loss);

            // Only fill the remaining space
            storage = bucket_size;
        }

        printf("Buffer size = %d out of bucket size = %d\n", storage, bucket_size);

        // Output packets from the bucket
        storage -= output_pkt_size;

        // Ensure storage doesn't go negative
        if (storage < 0)
        {
            storage = 0;
        }
    }

    return 0;
}
