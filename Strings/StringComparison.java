//we can compare string on the basis of content and reference

class StringComparison {
    public static void main(String[] args) {

        String str1 = "John";
        String str2 = "John";
        String str3 = new String("John");
        String str4 = "Dravid";
        String str5 = new String("jOHN");
        String str6 = "JOHN";
        String str7 = "john";

        // comparing string using equals method
        // compares content value of the string
        // 1.equals()
        System.out.println(str1.equals(str2)); // true
        System.out.println(str1.equals(str3)); // true
        System.out.println(str1.equals(str4)); // false

        // equals ignore case
        System.out.println(str1.equalsIgnoreCase(str5)); // true

        // BY using == operator
        // == compares references not values
        System.out.println(str1 == str2); // true
        System.out.println(str1 == str3); // false
        System.out.println(str1 == str5); // false

        // compareTo()
        /*
         * compares values lexicographically and returns
         * an integer value that describes if first string is less than,
         * equal to or greater than second string.
         */
        System.out.println(str1.compareTo(str2)); // 0
        System.out.println(str1.compareTo(str6)); // -1 i.e str1 < str6
        System.err.println(str6.compareTo(str7)); // 1 i.e str1 > str7
    }
}