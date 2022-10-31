package com.company;


public class Remove_duplicates {

    public static boolean[] map = new boolean[26];

    public static void remove_duplicate_elements(String str, int index, String newstr)
    {
        if (index == str.length())
        {
            System.out.println(newstr);
            return;
        }
        char curchar = str.charAt(index);
        if (map[curchar - 'a'])// if we doesn't write true then it autometically catch
        {
            remove_duplicate_elements(str, index+1, newstr);
        }
        else {
            newstr += curchar;
            map[curchar - 'a'] = true;
            remove_duplicate_elements(str, index+1, newstr);
        }
    }
    public static void main(String[] args) {
        // write your code here
        remove_duplicate_elements("abcdavgdfdgtracvb", 0, "");
    }
}


