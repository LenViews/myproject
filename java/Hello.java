import java.util.Arrays;

public class Hello {
public static void main (String[]args){
int age = 19;
char bGroup = 'O';
String name = "Lenox";
System.out.println("You are "+name+", "+"Blood Group "+bGroup+", "+age+" of age.");
//Control statement
if(age > 18){
System.out.println("Where is your ID?");
} else {
System.out.println("Too Young");
}
//Array
String[] cars = {"Rolls Royce","Bentley","Mercedes","Porsche"};
int length = cars.length;
System.out.println("List before sort:");
for(int i =0; i<cars.length; i++){
System.out.println(cars[i]);
}
Arrays.sort(cars);
System.out.println("List after sort: ");
for(String car : cars){
System.out.println(car);
}
}
}
