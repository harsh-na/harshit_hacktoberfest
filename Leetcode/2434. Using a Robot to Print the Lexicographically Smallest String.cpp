// Problem Link : https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/

// Stack:  Stacks are a type of container adaptors with LIFO(Last In First Out) type of working, where a new element is added at one end (top) and an element is removed from that end only.  Stack uses an encapsulated object of either vector or deque (by default) or list (sequential container class) as its underlying container, providing a specific set of member functions to access its elements.

// unordered_map: unordered_map is an associated container that stores elements formed by the combination of key-value and a mapped value. The key value is used to uniquely identify the element and the mapped value is the content associated with the key. Both key and value can be of any type predefined or user-defined.
class Solution
{
public:
    // Find the smallest character currently present in the string
    char lowest(unordered_map<char, int> &um)
    {
        for (int i = 0; i < 26; i++)
        {
            if (um[i + 'a'] != 0)
                return 'a' + i;
        }
        return 'z';
    }
    string robotWithString(string s)
    {
        unordered_map<char, int> um;
        stack<char> stk;
        string result = "";
        // Calculate the frequency of every character in the string.
        for (int i = 0; i < s.size(); i++)
            um[s[i]]++;
        for (int i = 0; i < s.size(); i++)
        {
            stk.push(s[i]);
            um[s[i]]--;
            // If the current top element of the stack is smaller than the smallest character of the string present in the unordered_map. If yes then append it and pop the element from the stack;
            while (!stk.empty() && stk.top() <= lowest(um))
            {
                result += stk.top();
                stk.pop();
            }
        }
        // Return the final lexicographivally smallest string
        return result;
    }
};