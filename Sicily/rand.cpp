#include <iostream>
#include <vector>

using namespace std;

static unsigned long int next_num = 1;

int rand(void) // RAND_MAX assumed to be 32767
{
    next_num = next_num * 1103515245 + 12345;
    return (unsigned int)(next_num/65536) % 32768;
}

void srand(unsigned int seed)
{
    next_num = seed;
}

void random_shuffle_self(vector<int>::iterator first, vector<int>::iterator last) {
    srand(time(0));
    if (first == last) return;  
    for (vector<int>::iterator i = first + 1; i != last; ++i) {
        iter_swap(i, first + (rand() % ((i - first) + 1)));
    }
}

int main(int argc, char *argv[]) {
    vector<int> temp;
    for (int i = 0; i < 10; i++) {
        temp.push_back(i+1);
    }
    
    random_shuffle_self(temp.begin(), temp.end());
    
    for (int i = 0; i < 10; i++) {
            printf("%d ", temp[i]);
    }
    printf("\n");
    
    return 0;
    
}