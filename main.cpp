#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 //Task1
vector<int> findSameElements(vector<int> list1, vector<int> list2) {
    vector<int> list3;

    for (int element1: list1){
        for (int element2: list2) {
            if (element1 == element2)
                list3.push_back(element1);
        }
    }

    return list3;
}


 //Task2
 vector<string> findPalindromes(vector<string> list) {
    vector<string> palindromes;

    for (string words : list) {
        string reversing = "";
        for (int i = words.length()-1; i >= 0; i--) {
            reversing += words[i];
        }
        for (int i = 0; i < list.size(); i++) {
            if (reversing == list[i]){
                palindromes.push_back(list[i]);
            }
        }

    }
    return palindromes;
}

//Task3
vector<int> findPrimes(vector<int> list) {
    vector<int> primeList = list;

    for (int i = 2; i <= *max_element(primeList.begin(), primeList.end()); i++) {
        
        if (find(primeList.begin(), primeList.end(), i) != primeList.end()) {
            for (int j = i * 2; j <= *max_element(primeList.begin(), primeList.end()); j += i) {
                if (find(primeList.begin(), primeList.end(), j) != primeList.end()) {
                    primeList.erase(find(primeList.begin(), primeList.end(), j));
                }
            }
        }

    }

    return primeList;
}

//Task4
vector<string> anagrams(string word, vector<string> word_list) {
    vector<string> output;

    string sorted_input= word;
    sort(sorted_input.begin(), sorted_input.end());

    for (string targetWords : word_list) {
        string sorted_target_words = targetWords;
        sort(sorted_target_words.begin(), sorted_target_words.end());

        if (sorted_input == sorted_target_words) {
            output.push_back(targetWords);
        }
    }
    return output;
}


int main(){
    //Task1 in main
    vector<int> list1 = {1, 2, 3, 4, 5, 6};
    vector<int> list2 = {5, 6, 7, 8, 9, 10};
    vector<int> common_elements = findSameElements(list1, list2);

    cout << "Here are common elements of 'list1' and 'list2': ";
    for (int i = 0; i < common_elements.size(); i++) {
        cout << common_elements[i] << " ";
    }

    //Task2 in main
    vector<string> stringList = {"noon", "car", "cake", "tenet", "door", "level"};
    vector<string> palindromes = findPalindromes(stringList);

    cout<<"\nHere are palindromes from 'stringList': ";
    for (int i = 0; i < palindromes.size(); i++) {
        cout << palindromes[i] << " ";
    }

    //Task3 in main
    vector<int> numberList={2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
    vector<int> primeList = findPrimes(numberList);

    cout << "\nHere are prime numbers from 'numberList': ";
    for (int i = 0; i < primeList.size(); i++) {
        cout << primeList[i] << " ";
    }

    //Task4 in main
    string input_word = "live";
    vector<string> word_list = {"computer", "evil", "google", "pasta", "banana"};
    vector<string> anagramList = anagrams(input_word,word_list);

    cout << "\nHere are anagram(s) of "+input_word+": ";
    for (int i = 0; i < anagramList.size(); i++) {
        cout << anagramList[i] << " ";
    }

    return 0;
}
