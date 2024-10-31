#include <bits/stdc++.h>

#define SIZE 1e8

using namespace std;

int main(){

// With resize
    string s;

    auto start = chrono::high_resolution_clock::now();
    s.resize(SIZE);
    auto end = chrono::high_resolution_clock::now();

    double resize_time = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    resize_time /= 1e6;

    start = chrono::high_resolution_clock::now();
    for(int i = 0 ; i < SIZE ; i++){
        s[i] = 'a';
    }
    end = chrono::high_resolution_clock::now();
    double apnd_time_resize = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    apnd_time_resize /= 1e6;

// With reserve
    string str;
     start = chrono::high_resolution_clock::now();
    str.reserve(SIZE);
     end = chrono::high_resolution_clock::now();

    double reserve_time = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    reserve_time /= 1e6;

    // append the chars in the reserved string

    start = chrono::high_resolution_clock::now();
    for(int i = 0 ; i < SIZE ; i++){
        str.push_back('a');
    }
    end = chrono::high_resolution_clock::now();
    double apnd_time = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    apnd_time /= 1e6;


// Without resize and reserve
    string st;

    start = chrono::high_resolution_clock::now();
    for(int i = 0 ; i < SIZE ; i++){
        st.push_back('a');
    }
    end = chrono::high_resolution_clock::now();
    double apnd_time_w = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    apnd_time_w /= 1e6;

// Char Array

    char *str_arr;
    start = chrono::high_resolution_clock::now();
    str_arr = (char *)malloc(sizeof(char) * SIZE+1);
    end = chrono::high_resolution_clock::now();
    double malloc_time = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    malloc_time /= 1e6;

    start = chrono::high_resolution_clock::now();
    for(int i = 0 ; i < SIZE ; i++){
        str_arr[i] = 'a';
    }
    end = chrono::high_resolution_clock::now();
    double char_time = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    char_time /= 1e6;

    cout << "====================================== For Resize ===========================\n";
    cout << "\n" << "[+] Resize Time -> " << resize_time << " ms\n";
    cout << "[+] Append Time -> " << apnd_time_resize << " ms\n";

    cout << "====================================== For Reserve ===========================\n";
    cout << "\n" << "[+] Reserve Time -> " << reserve_time << " ms\n";
    cout << "[+] Append Time -> " << apnd_time << " ms\n";

    cout << "====================================== Without Reserve ===========================\n";
    cout << "\n[+] Append Time -> " << apnd_time_w << " ms\n";

    cout << "====================================== Char Array ===========================\n";
    cout << "\n" << "[+] Malloc Time -> " << malloc_time << " ms\n";
    cout << "[+] Append Time -> " << char_time << " ms\n";

    return 0;

}