class TestingStringImmutability {
    public static void main(String[] args) {
        /*
         * this will print sachin but still object as sachin tendulkar
         * is get created in string pool
         */
        String s = "sachin";
        s.concat("Tendulakar");
        System.out.println(s);

        /* explicitely changing reference of string toward another object */
        // this will print johncena as we have changed the reference
        String str = "john";
        String str1 = "cena";
        str = str.concat(str1);
        System.out.println(str);
    }
}