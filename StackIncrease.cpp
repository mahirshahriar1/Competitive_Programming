#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl '\n'


void workCase() {

}

void main_(){
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int t = 1;
    cin >> t;
    while (t--) {
        workCase();
    }
}

static void run_with_stack_size(void (*func)(void), size_t stsize) {
    char *stack, *send;
    stack = (char *)malloc(stsize);
    send = stack + stsize - 16;
    send = (char *)((uintptr_t)send / 16 * 16);
    asm volatile(
        "mov %%rsp, (%0)\n"
        "mov %0, %%rsp\n"
        :
        : "r"(send));
    func();
    asm volatile("mov (%0), %%rsp\n" : : "r"(send));
    free(stack);
}

int main() {
	run_with_stack_size(main_, 1024 * 1024 * 1024);  

    return 0;
}
