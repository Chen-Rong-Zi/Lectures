#include <assert.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <malloc.h>

using namespace std;
struct Array{
    int* p;
    int size;
    int capacity;
};
Array *create_array(int value);
void push_back(Array* arr, int value);
void pop(Array *arr);
int get_size(Array *arr);
int get_capacity(Array *arr);

int main(){
    int n;
    cin >> n;
    if(n == 1){
        Array *arr = create_array(1);
        assert(arr->p[0] == 1);
        assert(get_size(arr) == 1);
    }
    if(n == 2){
        Array *arr = create_array(0);
        int s = get_size(arr);
        int c = get_capacity(arr);
        assert(c >= s && c <= 3 * s);
        assert(s == 1);
        for(int i = 1; i < 10000; i++){
            push_back(arr, i);
            int s = get_size(arr);
            int c = get_capacity(arr);
            assert(c >= s && c <= 3 * s);
            assert(c * 6 >= (malloc_usable_size(arr->p) / sizeof(int)));
            assert(s == i + 1);
        }
    }
    if(n == 3){
        Array *arr = create_array(0);
        int s = get_size(arr);
        int c = get_capacity(arr);
        assert(arr->p[0] == 0);
        for(int i = 1; i < 10000; i++){
            push_back(arr, i);
            int s = get_size(arr);
            int c = get_capacity(arr);
            assert(arr->p[i] == i && arr->p[i / 10 + i % 7] == i / 10 + i % 7);
        }
    }
    if(n == 4){
        Array *arrs[5]{};
        for(int j = 1; j < 5; j++){
            arrs[j] = create_array(0);
            int s = get_size(arrs[j]);
            int c = get_capacity(arrs[j]);
            assert(c * 6 >= malloc_usable_size(arrs[j]->p) / sizeof(int));
            assert(c >= s && c <= 3 * s);
            assert(s == 1);
            for(int i = 1; i < 10000; i++){
                push_back(arrs[j], i);
                int s = get_size(arrs[j]);
                int c = get_capacity(arrs[j]);
                assert(c >= s && c <= 3 * s);
                assert(c * 6 >= malloc_usable_size(arrs[j]->p) / sizeof(int));
                assert(s == i + 1);
                assert(arrs[j]->p[i] == i && arrs[j]->p[i / 10 + i % 7] == i / 10 + i % 7);
            }
        }
    }
    if(n == 5){
        int max_len = 0;
        Array *arr = create_array(1);
        for(int j = 1; j <= 100; j++){
            for(int i = 0; i < 10 * j; i++){
                push_back(arr, i);
                assert(arr->p[get_size(arr) - 1] == i);
                max_len = max(max_len, get_size(arr));
                if(i % 3 == 0)
                    pop(arr);
                int c = get_capacity(arr);
                assert(c >= max_len && c <= 3 * max_len);
                assert(c * 6 >= malloc_usable_size(arr->p) / sizeof(int));
            }
            for(int i = 0; i < 5 * j; j++){
                pop(arr);
            }
        }
    }
    if(n == 6){
        Array *arr = create_array(1000);
        auto v = vector<int> ();
        v.push_back(1000);
        for(int i = 1; i < 100; i++){
            for(int j = 0; j < 10; j++){
                push_back(arr, (i % (j+1)) * j + 2 - i * 10 - 3 * i / (j+2));
                v.push_back((i % (j+1)) * j + 2 - i * 10 - 3 * i / (j+2));
            }
            for(int j = 0; j < i % 10; j++){
                pop(arr);
                v.pop_back();
            }
            assert(get_size(arr) == v.size());
            for(int j = 0; j < v.size(); j++){
                assert(v[i] == arr->p[i]);
            }
        }
    }
    if (n == 7){
        Array *arr = create_array(0);
        int s = get_size(arr);
        int c = get_capacity(arr);
        assert(c >= s && c <= 3 * s);
        assert(s == 1);
        for(int i = 1; i < 10000000; i++){
            push_back(arr, i);
            int s = get_size(arr);
            int c = get_capacity(arr);
            assert(c >= s && c <= 3 * s);
            assert(c * 6 >= malloc_usable_size(arr->p) / sizeof(int));
            assert(s == i + 1);
            assert(arr->p[i] == i && arr->p[i / 10 + i % 7] == i / 10 + i % 7);
        }
    }
    cout << n << endl;
    return 0;
}
