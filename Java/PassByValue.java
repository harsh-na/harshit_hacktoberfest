import javax.swing.plaf.basic.BasicInternalFrameTitlePane.SystemMenuBar;

// passing arguments byValue
public class PassByValue{
    public void setVal(int num1){
        num1=num1+10;
    }
    public static void main(String args[]){
int num1=10;
// Instantiate the PassByValue Class
PassByValue obj=new PassByValue();
// Invoke the setVal() method with num1 as parameter 
obj.setVal(num1);
// Print num1 to check its value
System.out.println("Value of num1 after invoking the setVal() is: "+num1) ;
    }
}