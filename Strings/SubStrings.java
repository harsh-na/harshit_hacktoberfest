import java.util.*;

//*substring is a subset of another String */
class SubStrings {
    public static void main(String[] args) {
        /* substring() method startIndex is inclusive and endIndex is exclusive. */
        // substring(int startIndex)
        // substring of the given string from specified startIndex

        String str = "india is my country";
        System.out.println(str.substring(10)); // y country
        // substring(int startIndex, int endIndex)
        // startIndex: inclusive
        // endIndex: exclusive
        System.out.println(str.substring(0, 10));// india is m

        // using split() method
        // accepts arguments in the form of a regular expression. and return String
        // array

        String[] arr = str.split(" ");
        System.out.println(Arrays.toString(arr)); // [india, is, my, country]

    }
}