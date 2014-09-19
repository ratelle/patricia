#include "patricia.h"
#include <vector>
#include <iostream>
using namespace std;

typedef uint32_t Ipv4Ip;

typedef PatriciaPair<Ipv4Ip, int> Ipv4List;
typedef PatriciaKey<Ipv4Ip> Ipv4Mask;
typedef Patricia<Ipv4Ip, int> Ipv4Index;

int main(int argc, const char* argv[])
{
    std::vector<Ipv4List> ip_lists;

    std::vector<Ipv4Mask> masks1;
    masks1.push_back(Ipv4Mask(0x33440000, 16));
    masks1.push_back(Ipv4Mask(0x31440000, 17));
    Ipv4List list1(masks1, 1);

    std::vector<Ipv4Mask> masks2;
    masks2.push_back(Ipv4Mask(0x33441000, 12));
    masks2.push_back(Ipv4Mask(0x31440000, 17));
    Ipv4List list2(masks2, 2);

    ip_lists.push_back(list1);
    ip_lists.push_back(list2);

    Ipv4Index index(ip_lists);

    unsigned ips_length = 5;
    Ipv4Ip ips[] = {0x33440101, 0x554201a1, 0x31441111, 0x33441abc, 0x314b0123};

    for (unsigned i = 0; i < ips_length; i++)
    {
        std::vector<int> results;
        index.lookup(ips[i], results);

        cout << "Results for " << ips[i] << " " << results.size() << " :";

        for (unsigned j = 0; j < results.size(); j++)
            cout << " " << results[j];

        cout << std::endl;
    }

}
